//
//  PBAudioSessionUtils.m
//  PedalBoard
//
//  Created by Qin Hong on 2021/6/10.
//

#import "PBAudioSessionUtils.h"

PB_OVERLOADABLE NSError * _Nullable PBAudioSessionSetCategory(AVAudioSessionCategory category, AVAudioSessionMode mode, AVAudioSessionCategoryOptions options)
{
    AVAudioSession *audioSession = [AVAudioSession sharedInstance];
    AVAudioSessionCategory currentCategory = audioSession.category;
    AVAudioSessionMode currentMode = audioSession.mode;
    AVAudioSessionCategoryOptions currentOptions = audioSession.categoryOptions;
    NSError *error;
    if (![currentCategory isEqualToString:category]
        || ![currentMode isEqualToString:mode]
        || currentOptions != options)
    {
        [[AVAudioSession sharedInstance] setCategory:category mode:mode options:options error:&error];
    }
    return error;
}

PB_OVERLOADABLE NSError * _Nullable PBAudioSessionSetCategory(AVAudioSessionCategory category, AVAudioSessionCategoryOptions options)
{
    AVAudioSession *audioSession = [AVAudioSession sharedInstance];
    AVAudioSessionCategory currentCategory = audioSession.category;
    AVAudioSessionCategoryOptions currentOptions = audioSession.categoryOptions;
    NSError *error;
    if (![currentCategory isEqualToString:category]
        || currentOptions != options)
    {
        [[AVAudioSession sharedInstance] setCategory:category withOptions:options error:&error];
    }
    return error;
}

PB_OVERLOADABLE NSError * _Nullable PBAudioSessionSetCategory(AVAudioSessionCategory category)
{
    AVAudioSession *audioSession = [AVAudioSession sharedInstance];
    AVAudioSessionCategory currentCategory = audioSession.category;
    NSError *error;
    if (![currentCategory isEqualToString:category])
    {
        [[AVAudioSession sharedInstance] setCategory:category error:&error];
    }
    return error;
}

NSError *_Nullable PBAudioSessionSetMode(AVAudioSessionMode mode)
{
    AVAudioSession *audioSession = [AVAudioSession sharedInstance];
    AVAudioSessionMode currentMode = audioSession.mode;
    NSError *error;
    if (![currentMode isEqualToString:mode])
    {
        [[AVAudioSession sharedInstance] setMode:mode error:&error];
    }
    return error;
}

PB_OVERLOADABLE BOOL PBAudioSessionSetPreferrences(float sampleRate)
{
    BOOL ret = YES;
    NSError *error;
    [[AVAudioSession sharedInstance] setPreferredSampleRate:sampleRate error:&error];
    if (error) ret = NO;
    return ret;
}

PB_OVERLOADABLE BOOL PBAudioSessionSetPreferrences(float sampleRate, float IOBufferDuration)
{
    BOOL ret = YES;
    NSError *error;
    [[AVAudioSession sharedInstance] setPreferredSampleRate:sampleRate error:&error];
    if (error) ret = NO;
    [[AVAudioSession sharedInstance] setPreferredIOBufferDuration:IOBufferDuration error:&error];
    if (error) ret = NO;
    return ret;
}

PB_OVERLOADABLE BOOL PBAudioSessionSetPreferrences(float sampleRate, float IOBufferDuration, NSUInteger inputChannels)
{
    BOOL ret = YES;
    NSError *error;
    [[AVAudioSession sharedInstance] setPreferredSampleRate:sampleRate error:&error];
    if (error) ret = NO;
    [[AVAudioSession sharedInstance] setPreferredIOBufferDuration:IOBufferDuration error:&error];
    if (error) ret = NO;
    [[AVAudioSession sharedInstance] setPreferredInputNumberOfChannels:inputChannels error:&error];
    if (error) ret = NO;
    return ret;
}

NSError * _Nullable PBAudioSessionSetActive(BOOL active)
{
    NSError *error;
    [[AVAudioSession sharedInstance] setActive:active error:&error];
    return error;
}

void PBAudioSessionGetCurrentContext(PBAudioSessionContext *outContext)
{
    if (!outContext) return;
    
    AVAudioSession *audioSession = [AVAudioSession sharedInstance];
    AVAudioSessionCategory currentCategory = audioSession.category;
    AVAudioSessionCategoryOptions currentOptions = audioSession.categoryOptions;
    AVAudioSessionMode currentMode = audioSession.mode;

    outContext->category = currentCategory;
    outContext->options = currentOptions;
    outContext->mode = currentMode;
}

void PBAudioSessionSetContext(PBAudioSessionContext ctx)
{
    PBAudioSessionSetCategory(ctx.category, ctx.options);
    PBAudioSessionSetMode(ctx.mode);
}
