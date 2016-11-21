//
//  GameSystem.cpp
//  SurplusGame
//
//  Created by JungTaekjin on 2016. 9. 23..
//
//

#include "GameSystem.h"
#include "MainScene.h"

GameSystem* GameSystem::m_Instance = nullptr;

GameSystem::GameSystem()
: currentScene(nullptr)
, gameState(TS_WAIT)
{
}

GameSystem::~GameSystem()
{
    
}

void GameSystem::startGame()
{
    if(currentScene == nullptr) return;
    
    MainScene* mainScene = dynamic_cast<MainScene*>(currentScene);
    
    mainScene->setUpdate(true);
}

void GameSystem::stopGame()
{
    if(currentScene == nullptr) return;
    
    MainScene* mainScene = dynamic_cast<MainScene*>(currentScene);
    
    mainScene->setUpdate(false);
}

void GameSystem::pauseGame()
{
    
}

void GameSystem::setGameState(int state)
{
    if(currentScene == nullptr) return;
    
    if(gameState == TS_WAIT)
        GameSystem::getInstance()->startGame();
    
    if(gameState == TS_WAIT && state != TS_NORMAL) return;
    
    gameState = state;
    
    MainScene* mainScene = dynamic_cast<MainScene*>(currentScene);
    
    if(mainScene == nullptr) return;
    
    mainScene->changeTargetColor(state);
}

void GameSystem::setCurrentScene(Node* scene)
{
    currentScene = nullptr;
    
    currentScene = scene;
}

void GameSystem::checkGameOver(float limitTime)
{
    if(limitTime > 0.f) return;
    // 0초 아래이면 게임 오버로 판단합니다.
    
    // 게임 상태를 변경.
    setGameState(TS_OVER);
    
    // 게임을 멈춤.
    stopGame();
    
    // 재시도 버튼을 보여줌.
    if(currentScene == nullptr) return;
    MainScene* mainScene = dynamic_cast<MainScene*>(currentScene);
    if(mainScene == nullptr) return;
    
    mainScene->setVisibleRetryButton(true);
}


















