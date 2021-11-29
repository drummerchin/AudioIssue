//
//  PBAudioSessionPlayground.h
//  Pods
//
//  Created by qinhong on 11/11/21.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface PBAudioSessionPlayground : NSObject

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

+ (NSArray <UIAlertAction *> *)audioSessionActionsWithController:(UIViewController *)vc;

@end

NS_ASSUME_NONNULL_END
