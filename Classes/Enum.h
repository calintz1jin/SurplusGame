//
//  Enum.h
//  SurplusGame
//
//  Created by JungTaekjin on 2016. 9. 23..
//
//

#ifndef Enum_h
#define Enum_h

const float MAX_LIMIT_TIME = 2.f;

//! @brief 타겟의 종류.
enum TARGET_KIND
{
    TK_TARGET = 0,
    TK_BACKGROUND,
    
    TK_MAX
};

//! @brief 현재 게임 상태.
enum TARGET_STATE
{
    TS_WAIT = -1,   // 게임 시작 전 대기 상태.
    TS_NORMAL = 0,  // 보통.
    TS_WARNING,     // 게임오버 카운트 상태.
    TS_OVER,        // 게임 오버.
    
    TS_MAX
};


#endif /* Enum_h */
