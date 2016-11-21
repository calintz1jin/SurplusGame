//
//  PlatformManager.h
//  SurplusGame
//
//  Created by JungTaekjin on 2016. 9. 27..
//
//

#import <Foundation/Foundation.h>
#import <GameKit/GameKit.h>

//! @brief 리더보드 ID
#define LEADER_ID       @"SurplusLadderID"

@interface PlatformManager : NSObject
<GKLeaderboardViewControllerDelegate>

+ (BOOL) startGameCenter;

//! @brief 게임센터 사용 가능 여부.
+ (BOOL) isGameCenterAPIAvailable;

//! @brief 접속, 인증.
+ (void) authenticateLocalPlayer;

// !@brief 점수 요청.
+ (void) reportScore:(int64_t)score;

//! @brief 리더보드 보기.
+ (void) showLeaderboard;

@end
