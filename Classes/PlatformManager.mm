//
//  PlatformManager.m
//  SurplusGame
//
//  Created by JungTaekjin on 2016. 9. 27..
//
//

#import "PlatformManager.h"
#import "platform/ios/CCEAGLView-ios.h"

USING_NS_CC;

@implementation PlatformManager


+ (BOOL) startGameCenter
{
    if( [self isGameCenterAPIAvailable] == NO )
    {
        //CCLOG("startGameCenter Faile");
        return NO;
    }
    [self authenticateLocalPlayer];
    //CCLOG("startGameCenter OK");
    return YES;
}

+ (BOOL) isGameCenterAPIAvailable
{
    // Check for presence of GKLocalPlayer class.
    BOOL localPlayerClassAvailable = (NSClassFromString(@"GKLocalPlayer")) != nil;
    
    // The device must be running iOS 4.1 or later.
    NSString *reqSysVer = @"4.1";
    NSString *currSysVer = [[UIDevice currentDevice] systemVersion];
    BOOL osVersionSupported = ([currSysVer compare:reqSysVer options:NSNumericSearch] != NSOrderedAscending);
    
    return (localPlayerClassAvailable && osVersionSupported);
}

+ (void) authenticateLocalPlayer
{
    GKLocalPlayer* localPlayer = [GKLocalPlayer localPlayer];
    [localPlayer authenticateWithCompletionHandler:^(NSError *error) {
        if( localPlayer.isAuthenticated )
        {
            /*
             ///< NSString를 char*로 컨버팅을 해야...
             CCLOG("Alias : %s", localPlayer.alias);
             CCLOG("Player ID : %s", localPlayer.playerID);
             */
            NSLog(@"Alias : %@", localPlayer.alias);
            NSLog(@"Player ID : %@", localPlayer.playerID);
        }
    }];
}

+ (void) reportScore:(int64_t)score
{
    GKScore* scoreReporter = [[[GKScore alloc] initWithCategory:LEADER_ID] autorelease];
    scoreReporter.value = score;
    [scoreReporter reportScoreWithCompletionHandler:^(NSError *error) {
        if( error != nil )
        {
            //CCMessageBox("reportScore Error", "Game Center");
        }
    }];
}

UIViewController* tempUIView;
+ (void) showLeaderboard
{
    GKLeaderboardViewController* pController = [[[GKLeaderboardViewController alloc] init] autorelease];
    
    if( pController != nil )
    {
        pController.leaderboardDelegate = self;
        
        tempUIView = [[UIViewController alloc] init];
        [[CCEAGLView sharedEGLView] addSubview:tempUIView.view];
        [tempUIView presentModalViewController:pController animated:YES];
    }
}

- (void) leaderboardViewControllerDidFinish:(GKLeaderboardViewController *)viewController
{
    [viewController dismissModalViewControllerAnimated:YES];
    [viewController.view.superview removeFromSuperview];
    [viewController release];
}

@end
