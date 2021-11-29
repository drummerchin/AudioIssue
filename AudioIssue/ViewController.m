//
//  ViewController.m
//  AudioIssue
//
//  Created by Qin Hong on 2021/11/26.
//

#import "ViewController.h"
#import <AVFoundation/AVFoundation.h>
#import <AudioToolbox/AudioToolbox.h>
#import "PBAudioSessionPlayground.h"
#import "UIAlertController+PBActionSheetMenu.h"
#import "PBAudioSessionUtils.h"

@interface ViewController ()
{
    AudioUnit _vpioAudioUnit;
}

@property (nonatomic, strong) AVPlayer *avPlayer;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    [self setupUI];
    
    PBAudioSessionSetCategory(AVAudioSessionCategoryPlayAndRecord, AVAudioSessionCategoryOptionDefaultToSpeaker);
}

- (void)setupUI
{
    UIBarButtonItem *menuItem = [[UIBarButtonItem alloc] initWithTitle:@"DEBUG" style:UIBarButtonItemStylePlain target:self action:@selector(menuAction:)];
    self.navigationItem.rightBarButtonItems = @[menuItem];
}

#pragma mark - actions

- (void)menuAction:(UIBarButtonItem *)barButtonItem
{
    NSArray<UIAlertAction *> *actions = [PBAudioSessionPlayground audioSessionActionsWithController:self];
    UIAlertController *menu = [UIAlertController alertControllerWithTitle:@"Menu" message:nil preferredStyle:UIAlertControllerStyleActionSheet];
    [menu addActions:actions];
    [menu addCancelActionWithTitle:@"Cancel"];

    [self presentViewController:menu animated:YES completion:nil];
}

- (IBAction)onEnterChatRoom:(UIButton *)sender {
    if (_vpioAudioUnit)
    {
        NSLog(@"You've already in chatroom.");
        return;
    }
    
    // open VPIO
    AudioComponentDescription componentDesc = {
        .componentType = kAudioUnitType_Output,
        .componentSubType = kAudioUnitSubType_VoiceProcessingIO,
        .componentManufacturer = kAudioUnitManufacturer_Apple,
        .componentFlags = 0,
        .componentFlagsMask = 0,
    };
    AudioComponent comp = AudioComponentFindNext(NULL, &componentDesc);

    OSStatus status = AudioComponentInstanceNew(comp, &_vpioAudioUnit);
    if (status != noErr)
    {
        int fourCC = CFSwapInt32HostToBig(status);
        NSLog(@"Failed to open VPIO, '%4.4s'", (char *)&fourCC);
    }
    // initialize VPIO
    status = AudioUnitInitialize(_vpioAudioUnit);
    if (status != noErr)
    {
        int fourCC = CFSwapInt32HostToBig(status);
        NSLog(@"Failed to initialize VPIO, '%4.4s'", (char *)&fourCC);
    }
}

- (IBAction)onLeaveChatRoom:(UIButton *)sender {
    if (!_vpioAudioUnit) return;
    
    // uninitialize VPIO
    OSStatus status = AudioUnitUninitialize(_vpioAudioUnit);
    if (status != noErr)
    {
        int fourCC = CFSwapInt32HostToBig(status);
        NSLog(@"Failed to uninitialize VPIO, '%4.4s'", (char *)&fourCC);
    }
    
    // close VPIO
    status = AudioComponentInstanceDispose(_vpioAudioUnit);
    if (status != noErr)
    {
        int fourCC = CFSwapInt32HostToBig(status);
        NSLog(@"Failed to close VPIO, '%4.4s'", (char *)&fourCC);
    }
    _vpioAudioUnit = NULL;
    
    // set Audio Session
    PBAudioSessionSetCategory(AVAudioSessionCategoryPlayback);
    PBAudioSessionSetMode(AVAudioSessionModeDefault);
    PBAudioSessionSetCategory(AVAudioSessionCategoryPlayAndRecord, AVAudioSessionCategoryOptionDefaultToSpeaker);
}

- (IBAction)onNewAVPlayer:(UIButton *)sender {
    NSURL *musicURL = [[NSBundle mainBundle] URLForResource:@"Synth" withExtension:@"aif"];
    self.avPlayer = [[AVPlayer alloc] initWithURL:musicURL];
}

- (IBAction)onDestroyAVPlayer:(UIButton *)sender {
    self.avPlayer = nil;
}

- (IBAction)onPlay:(UIButton *)sender {
    [self.avPlayer seekToTime:kCMTimeZero];
    [self.avPlayer play];
}

- (IBAction)onPause:(UIButton *)sender {
    [self.avPlayer pause];
}

@end
