//
//  PBAudioSessionPlayground.m
//  Pods
//
//  Created by qinhong on 11/11/21.
//

#import "PBAudioSessionPlayground.h"

@implementation UIAlertController (PBActionSheetMenu)

- (void)addActions:(NSArray <UIAlertAction *> *)actions
{
    for (UIAlertAction *action in actions)
    {
        [self addAction:action];
    }
}

- (void)addSubMenu:(NSString *)title message:(NSString * _Nullable)message controller:(UIViewController *)controller actions:(NSArray <UIAlertAction *> *)actions
{
    UIAlertAction *subMenuAction = [UIAlertAction actionWithTitle:title style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        UIAlertController *subMenu = [UIAlertController alertControllerWithTitle:title message:nil preferredStyle:UIAlertControllerStyleActionSheet];
        if (action)
        {
            [subMenu addActions:actions];
        }
        [subMenu addCancelActionWithTitle:@"Cancel"];
        [controller presentViewController:subMenu animated:YES completion:nil];
    }];
    [self addAction:subMenuAction];
}

- (void)addCancelActionWithTitle:(NSString *)title
{
    UIAlertAction *cancelAction = [UIAlertAction actionWithTitle:title style:UIAlertActionStyleCancel handler:^(UIAlertAction * _Nonnull action) {
        
    }];
    [self addAction:cancelAction];
}

@end
