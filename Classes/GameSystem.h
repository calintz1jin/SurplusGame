//
//  GameSystem.h
//  SurplusGame
//
//  Created by JungTaekjin on 2016. 9. 23..
//
//

#ifndef GameSystem_h
#define GameSystem_h

#include "Include.h"

class GameSystem
{
public:
    //! @brief 게임을 시작하는 함수.
    void startGame();
    //! @brief 게임을 중단하는 함수.
    void stopGame();
    //! @brief 게임을 일시 정지하는 함수.
    void pauseGame();
    
    void setGameState(int state);
    void setCurrentScene(cocos2d::Node* scene);
    
    //! @brief 현재 게임 상태를 반환합니다.
    inline int getGameState() { return gameState; };
    
    //! @brief 게임 상태를 체크합니다.(warning 상태에서 over인지 체크)
    void checkGameOver(float limitTime);
    
private:
    //! @brief 현재 Scene.
    cocos2d::Node* currentScene;
    //! @brief 게임 상태.
    int gameState;
    
    
    
///-------------------- singleton... -------------------------//
public:
    static GameSystem* getInstance()
    {
        if(m_Instance == nullptr)
        {
            m_Instance = new GameSystem();
            
            return m_Instance;
        }
        else
            return m_Instance;
    }
    void destroyInstance()
    {
        if(m_Instance)
        {
            delete m_Instance;
            m_Instance = nullptr;
        }
    }
    
private:
    static GameSystem* m_Instance;
    
private:
    GameSystem();
public:
    ~GameSystem();
};

#endif /* GameSystem_h */
