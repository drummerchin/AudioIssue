//
//  PBAudioSessionUtils.h
//  PedalBoard
//
//  Created by Qin Hong on 2021/6/10.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import "PBBase.h"

NS_ASSUME_NONNULL_BEGIN

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct PBAudioSessionContext_t
{
    AVAudioSessionCategory category;
    AVAudioSessionCategoryOptions options;
    AVAudioSessionMode mode;
} PBAudioSessionContext;

PB_OVERLOADABLE NSError * _Nullable PBAudioSessionSetCategory(AVAudioSessionCategory category, AVAudioSessionMode mode, AVAudioSessionCategoryOptions options) NS_AVAILABLE_IOS(10.0);

PB_OVERLOADABLE NSError * _Nullable PBAudioSessionSetCategory(AVAudioSessionCategory category, AVAudioSessionCategoryOptions options);

PB_OVERLOADABLE NSError * _Nullable PBAudioSessionSetCategory(AVAudioSessionCategory category);

NSError *_Nullable PBAudioSessionSetMode(AVAudioSessionMode mode);

PB_OVERLOADABLE BOOL PBAudioSessionSetPreferrences(float sampleRate);

PB_OVERLOADABLE BOOL PBAudioSessionSetPreferrences(float sampleRate, float IOBufferDuration);

PB_OVERLOADABLE BOOL PBAudioSessionSetPreferrences(float sampleRate, float IOBufferDuration, NSUInteger inputChannels);

NSError * _Nullable PBAudioSessionSetActive(BOOL active);

void PBAudioSessionGetCurrentContext(PBAudioSessionContext *outContext);

void PBAudioSessionSetContext(PBAudioSessionContext ctx);

#ifdef __cplusplus
}
#endif

NS_ASSUME_NONNULL_END
