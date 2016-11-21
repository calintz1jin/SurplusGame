//
//  MainScene.h
//  SurplusGame
//
//  Created by JungTaekjin on 2016. 9. 23..
//
//

#ifndef MainScene_h
#define MainScene_h

#include "Include.h"

class MainScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(MainScene);
    
public:
    //! @brief touch Event functions...
    virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* unused_event);
    virtual void onTouchCancelled(cocos2d::Touch* touch, cocos2d::Event* unused_event);
    virtual void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event *unused_event);
    virtual void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* unused_event);
    
    void onButtonTouchFunction(Ref *sender, ui::Widget::TouchEventType event);
    void setVisibleRetryButton(bool isvisible);
    
    //! @brief 업데이트 함수. 시간 업데이트를 위해서 사용함. 
    void update(float dt);
    //! @brief 시간 레이블 함수.
    void setTimer(float deltaTime);
    
    //! @brief 원 안에 있는지 검사.
    //! @param pos Vec2 포시션.
    //! @return 안에 있으면 true, 아니면 false.
    bool isInArea(cocos2d::Vec2 pos);
    
    //! @brief 배경화면 색 변경 함수.
    //! @param state 현재 상태를 지정
    void changeTargetColor(int state);
    
    //! @brief 업데이트 스케쥴 시작, 중단.
    void setUpdate(bool isStart);
    
    //! @brief 타겟 안에 타임 레이블 지정 함수.
    void setTimeLimitLabel(float limitTime);
    
private:
    Node* rootNode;
    //! @brief 경과 시간.
    float stack_time;
    //! @brief 리미트 시간.
    float limit_time;
    //! @brief 터치 타겟 포인터.
    Sprite* spr_target;
    Sprite* spr_target_inner;
    //! @brief 배경
    Sprite* spr_background;
    
public:
    MainScene();
    ~MainScene();
};

#endif /* MainScene_h */
