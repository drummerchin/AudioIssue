//
//  PBAudioSessionPlayground.m
//  Pods
//
//  Created by qinhong on 11/11/21.
//

#import "PBAudioSessionPlayground.h"
#import "PBBase.h"
#import "PBAudioSessionUtils.h"
#import "UIAlertController+PBActionSheetMenu.h"
#import <AVFoundation/AVFoundation.h>

@implementation PBAudioSessionPlayground

+ (NSArray<UIAlertAction *> *)audioSessionActionsWithController:(UIViewController *)vc
{
    PB_WEAKIFY(vc)
    return @[
        
        [UIAlertAction actionWithTitle:@"Input Data Source ..." style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
            
            UIAlertController *menu = [UIAlertController alertControllerWithTitle:@"Input Data Source" message:nil preferredStyle:UIAlertControllerStyleActionSheet];
            NSArray<AVAudioSessionDataSourceDescription *> *inputDataSources = [[AVAudioSession sharedInstance] inputDataSources];
            AVAudioSessionDataSourceDescription *currentInputDataSource = [AVAudioSession sharedInstance].inputDataSource;
            for (int i = 0; i < inputDataSources.count; i++)
            {
                AVAudioSessionDataSourceDescription *dataSource = inputDataSources[i];
                NSString *title = [NSString stringWithFormat:@"%@", dataSource.dataSourceName];
                UIAlertAction *dataSourceAction = [UIAlertAction actionWithTitle:title style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
                    NSError *error;
                    [[AVAudioSession sharedInstance] setInputDataSource:dataSource error:&error];
                    if (error)
                    {
                        NSLog(@"Failed to set input data source: %@", error);
                    }
                }];
                [menu addAction:dataSourceAction];
                dataSourceAction.enabled = [currentInputDataSource isEqual:dataSource]? NO : YES;
            }
            [menu addCancelActionWithTitle:@"Cancel"];

            [vc presentViewController:menu animated:YES completion:nil];
        }],
        [UIAlertAction actionWithTitle:@"Polar Pattern" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
            
            UIAlertController *polarPatternMenu = [UIAlertController alertControllerWithTitle:@"Polar Pattern" message:nil preferredStyle:UIAlertControllerStyleActionSheet];
            AVAudioSessionDataSourceDescription *inputDataSource = [AVAudioSession sharedInstance].inputDataSource;
            AVAudioSessionPolarPattern currentPattern = inputDataSource.selectedPolarPattern;
            for (int i = 0; i < inputDataSource.supportedPolarPatterns.count; i++)
            {
                AVAudioSessionPolarPattern polarPattern = inputDataSource.supportedPolarPatterns[i];
                NSString *title = [NSString stringWithFormat:@"%@", polarPattern];
                UIAlertAction *polarPatternAction = [UIAlertAction actionWithTitle:title style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
                    
                    NSError *error;
                    [inputDataSource setPreferredPolarPattern:polarPattern error:&error];
                    if (error)
                    {
                        NSLog(@"Failed to set polar pattern: %@", error);
                    }
                }];
                [polarPatternMenu addAction:polarPatternAction];
                polarPatternAction.enabled = [currentPattern isEqualToString:polarPattern] ? NO : YES;
            }
            [polarPatternMenu addCancelActionWithTitle:@"Cancel"];
            
            [vc presentViewController:polarPatternMenu animated:YES completion:nil];
        }],
        
        [UIAlertAction actionWithTitle:@"Sample Rate: 44100" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
            PBAudioSessionSetPreferrences(44100, 0.005);
        }],
        [UIAlertAction actionWithTitle:@"Sample Rate: 48000" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
            PBAudioSessionSetPreferrences(48000, 0.005);
        }],
        [UIAlertAction actionWithTitle:@"Mode ..." style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
            PB_STRONGIFY(vc)
            if (!vc) return;
            
            UIAlertController *modeMenu = [UIAlertController alertControllerWithTitle:@"Mode" message:nil preferredStyle:UIAlertControllerStyleActionSheet];
            NSArray<AVAudioSessionMode> *modes = @[
                AVAudioSessionModeDefault,
                AVAudioSessionModeVoiceChat,
                AVAudioSessionModeGameChat,
                AVAudioSessionModeVideoRecording,
                AVAudioSessionModeMeasurement,
                AVAudioSessionModeMoviePlayback,
                AVAudioSessionModeVideoChat,
            ];

            if (@available(iOS 9.0, *))
            {
                NSMutableArray *mutableArr = [NSMutableArray arrayWithArray:modes];
                [mutableArr addObject:AVAudioSessionModeSpokenAudio];
                modes = [mutableArr copy];
            }
            
            if (@available(iOS 12.0, *))
            {
                NSMutableArray *mutableArr = [NSMutableArray arrayWithArray:modes];
                [mutableArr addObject:AVAudioSessionModeVoicePrompt];
                modes = [mutableArr copy];
            }

            AVAudioSessionMode currentMode = [AVAudioSession sharedInstance].mode;
            for (AVAudioSessionMode mode in modes)
            {
                NSString *title = mode;
                if ([mode isEqualToString:currentMode])
                {
                    //modeAction.enabled = NO;
                    title = [NSString stringWithFormat:@"* %@",mode];
                }
                UIAlertAction *modeAction = [UIAlertAction actionWithTitle:mode style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
                    NSError *error;
                    [[AVAudioSession sharedInstance] setMode:mode error:&error];
                }];
                [modeMenu addAction:modeAction];
            }
            //*/
            [modeMenu addCancelActionWithTitle:@"Cancel"];
            
            [vc presentViewController:modeMenu animated:YES completion:nil];
        }],
        [UIAlertAction actionWithTitle:@"Override: None" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
            NSError *error;
            [[AVAudioSession sharedInstance] overrideOutputAudioPort:AVAudioSessionPortOverrideNone error:&error];
        }],
        [UIAlertAction actionWithTitle:@"Override: Speaker" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
            NSError *error;
            [[AVAudioSession sharedInstance] overrideOutputAudioPort:AVAudioSessionPortOverrideSpeaker error:&error];
        }],
        [UIAlertAction actionWithTitle:@"Active: YES" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
            NSError *error;
            [[AVAudioSession sharedInstance] setActive:YES error:&error];
        }],
        [UIAlertAction actionWithTitle:@"Active: NO" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
            NSError *error;
            [[AVAudioSession sharedInstance] setActive:NO error:&error];
        }],
    ];
}

@end
