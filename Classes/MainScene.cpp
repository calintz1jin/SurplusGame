//
//  MainScene.cpp
//  SurplusGame
//
//  Created by JungTaekjin on 2016. 9. 23..
//
//

#include "MainScene.h"
#include "TitleScene.h"

MainScene::MainScene()
: rootNode(nullptr)
, spr_target(nullptr)
, spr_target_inner(nullptr)
, stack_time(0.f)
, spr_background(nullptr)
, limit_time(MAX_LIMIT_TIME)
{
    
}

MainScene::~MainScene()
{
    
}

Scene* MainScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MainScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MainScene::init()
{
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    rootNode = CSLoader::createNode("MainScene.csb");
    
    addChild(rootNode);
    
    spr_target = (Sprite*)rootNode->getChildByName("spr_target");
    spr_target_inner = (Sprite*)spr_target->getChildByName("spr_target_inner");
    spr_background = (Sprite*)rootNode->getChildByName("spr_background");
    
    //! Touch Event add Listener...
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    
    listener->onTouchBegan = CC_CALLBACK_2(MainScene::onTouchBegan, this);
    listener->onTouchEnded = CC_CALLBACK_2(MainScene::onTouchEnded, this);
    listener->onTouchCancelled = CC_CALLBACK_2(MainScene::onTouchCancelled, this);
    listener->onTouchMoved = CC_CALLBACK_2(MainScene::onTouchMoved, this);
    
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    
    auto btn_retry = (Button*)rootNode->getChildByName("btn_retry");
    if(btn_retry)
        btn_retry->addTouchEventListener(CC_CALLBACK_2(MainScene::onButtonTouchFunction, this));
    
    GameSystem::getInstance()->setCurrentScene(this);
    GameSystem::getInstance()->setGameState(TS_WAIT);
    setVisibleRetryButton(false);
    
    return true;
}

bool MainScene::onTouchBegan(Touch* touch, Event* unused_event)
{
    int gameState = GameSystem::getInstance()->getGameState();
    if(gameState == TS_OVER) return true;
    
    Vec2 pt = touch->getLocation();
    CCLOG("Began Pos : %f, %f", pt.x, pt.y);
    
    if(isInArea(pt))
    {
        CCLOG("INTERSECT RECT BEGAN");
        GameSystem::getInstance()->setGameState(TS_NORMAL);
    }
    
    return true;
}

void MainScene::onTouchCancelled(Touch* touch, Event* unused_event)
{
    CCLOG("!!!!!!!!!!!!!!!!!!!!!!!!!!!");
    
    if(isInArea(touch->getLocation()))
        CCLOG("Cancelled Pos");
    
}

void MainScene::onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* unused_event)
{
    Vec2 pt = touch->getLocation();
    
    CCLOG("Moved Point");
    
    int gameState = GameSystem::getInstance()->getGameState();
    if(gameState == TS_WAIT || gameState == TS_OVER) return;
    
    if(isInArea(pt))
    {
        CCLOG("IN-----------");
        GameSystem::getInstance()->setGameState(TS_NORMAL);
    }
    else
    {
        CCLOG("OUT ==============");
        GameSystem::getInstance()->setGameState(TS_WARNING);
    }
}

void MainScene::onTouchEnded(Touch* touch, Event *unused_event)
{
    Vec2 pt = touch->getLocation();
    
    CCLOG("Ended Pos : %f, %f", pt.x, pt.y);
    
    if(isInArea(pt))
        CCLOG("INTERSECT RECT ENDED");
    
    int gameState = GameSystem::getInstance()->getGameState();
    if(gameState != TS_WAIT && gameState != TS_OVER)
        GameSystem::getInstance()->setGameState(TS_WARNING);
}

void MainScene::update(float dt)
{
    stack_time += dt;
    setTimer(stack_time);
    
    int gameState = GameSystem::getInstance()->getGameState();
    if(gameState == TS_WARNING)
    {
        limit_time -= dt;
        setTimeLimitLabel(limit_time);
        
        GameSystem::getInstance()->checkGameOver(limit_time);
    }
    else
    {
        limit_time = MAX_LIMIT_TIME;
    }
    
    Text* Label_timeLimit = (Text*)spr_target->getChildByName("Label_timeLimit");
    if(gameState == TS_NORMAL || gameState == TS_WAIT)
        Label_timeLimit->setVisible(false);
    else
        Label_timeLimit->setVisible(true);
}

void MainScene::setTimer(float deltaTime)
{
    if(rootNode == nullptr) return;
    
    ui::Text* Label_time = (ui::Text*)rootNode->getChildByName("Label_time");
    if(Label_time == nullptr) return;
    
    Label_time->setString(std::to_string((int)stack_time));
}

bool MainScene::isInArea(cocos2d::Vec2 pos)
{
    if(spr_target == nullptr) return false;
    
    Rect rc = spr_target->getBoundingBox();
    
    if(rc.containsPoint(pos))
        return true;
    else
        return false;
}

void MainScene::changeTargetColor(int state)
{
    switch(state)
    {
        case TS_NORMAL:
            spr_target->setColor(Color3B::WHITE);
            spr_background->setColor(Color3B::WHITE);
            break;
        case TS_WARNING:
            spr_target->setColor(Color3B::YELLOW);
            spr_background->setColor(Color3B::YELLOW);
            break;
        case TS_OVER:
            spr_target->setColor(Color3B::RED);
            spr_background->setColor(Color3B::RED);
            break;
        default:
            spr_target->setColor(Color3B::WHITE);
            spr_background->setColor(Color3B::WHITE);
            break;
    }
}

void MainScene::setUpdate(bool isStart)
{
    stack_time = 0.f;
    
    if(isStart)
        schedule(schedule_selector(MainScene::update));
    else
        unschedule(schedule_selector(MainScene::update));
}

void MainScene::setTimeLimitLabel(float limitTime)
{
    Text* Label_timeLimit = (Text*)spr_target->getChildByName("Label_timeLimit");
    if(Label_timeLimit == nullptr) return;
    
    int limit = limitTime;
    
    if(limitTime <= 0)
        limit = 0;
    else if(limit >= 0)
        limit += 1;
    
    
    CCLOG("!!!!!!~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    CCLOG("float : %f", limitTime);
    CCLOG("int : %d", limit);
    
    Label_timeLimit->setString(to_string(limit));
}

void MainScene::onButtonTouchFunction(Ref *sender, ui::Widget::TouchEventType event)
{
    if(rootNode == nullptr) return;
    
    auto btn_retry = (Button*)sender;
    
    if(btn_retry->getName() == "btn_retry")
    {
        Director::getInstance()->replaceScene(TransitionFade::create(1.f, TitleScene::createScene()));
    }
}

void MainScene::setVisibleRetryButton(bool isvisible)
{
    auto btn_retry = (Button*)rootNode->getChildByName("btn_retry");
    if(btn_retry == nullptr) return;
    
    btn_retry->setVisible(isvisible);
}












