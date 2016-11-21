//
//  TitleScene.h
//  SurplusGame
//
//  Created by JungTaekjin on 2016. 9. 23..
//
//

#ifndef TitleScene_h
#define TitleScene_h

#include "Include.h"

class TitleScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(TitleScene);
    
public:
    void onButtonTouchFunction(Ref *sender, ui::Widget::TouchEventType event);
    
private:
    Node* rootNode;
    
public:
    TitleScene();
    ~TitleScene();
};

#endif /* TitleScene_h */
