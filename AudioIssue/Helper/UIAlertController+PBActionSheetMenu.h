//
//  PBAudioSessionPlayground.h
//  Pods
//
//  Created by qinhong on 11/11/21.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

// UIAlertController style must be UIAlertControllerStyleActionSheet.
@interface UIAlertController (PBActionSheetMenu)

- (void)addActions:(NSArray <UIAlertAction *> *)actions;
- (void)addSubMenu:(NSString *)title message:(NSString * _Nullable)message controller:(UIViewController *)controller actions:(NSArray <UIAlertAction *> *)actions;
- (void)addCancelActionWithTitle:(NSString *)title;

@end

NS_ASSUME_NONNULL_END
