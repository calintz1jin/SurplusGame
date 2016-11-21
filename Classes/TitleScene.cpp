//
//  TitleScene.cpp
//  SurplusGame
//
//  Created by JungTaekjin on 2016. 9. 23..
//
//

#include "TitleScene.h"
#include "MainScene.h"

#include "PlatformManager.h"

TitleScene::TitleScene()
: rootNode(nullptr)
{
    
}

TitleScene::~TitleScene()
{
    
}

Scene* TitleScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = TitleScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool TitleScene::init()
{
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    rootNode = CSLoader::createNode("TitleScene.csb");
    
    addChild(rootNode);
    
    auto btn_start = (Button*)rootNode->getChildByName("btn_start");
    auto btn_Leader = (Button*)rootNode->getChildByName("btn_Leader");
    
    if(btn_start == nullptr) return false;
    
    btn_start->addTouchEventListener(CC_CALLBACK_2(TitleScene::onButtonTouchFunction, this));
    btn_Leader->addTouchEventListener(CC_CALLBACK_2(TitleScene::onButtonTouchFunction, this));
    
    return true;
}

void TitleScene::onButtonTouchFunction(Ref *sender, ui::Widget::TouchEventType event)
{
    if(rootNode == nullptr) return;
    
    auto btn_start = (Button*)sender;
    
    if(btn_start->getName() == "btn_start")
    {
        //GameSystem::getInstance()->startGame();
        Director::getInstance()->replaceScene(TransitionFade::create(1.f, MainScene::createScene()));
    }
    else if(btn_start->getName() == "btn_Leader")
    {
#if(CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
        [PlatformManager showLeaderboard];
#endif
    }
}
