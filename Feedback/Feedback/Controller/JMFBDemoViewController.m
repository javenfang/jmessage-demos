//
//  JMFBDemoViewController.m
//  Feedback
//
//  Created by Javen on 15/4/24.
//  Copyright (c) 2015 HEXG. All rights reserved.
//


#import "JMFBDemoViewController.h"
#import "JMFBRegisterViewController.h"



@interface JMFBDemoViewController ()

@end



// 考虑一般的 App 嵌入 Feedback 场景：用户名与 App 里的用户名一致；密码不需要单独输入。
// 作为独立的 Demo，需要让用户输入 username
@implementation JMFBDemoViewController



- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.

    NSLog(@"action - demoView:viewDidLoad");
    self.title = @"JMessage Feedback";

}

- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];

    // 如果未注册，则需要发起注册，输入 username
    [self checkRegister];

}

- (void)checkRegister {
    NSUserDefaults *defaults = [NSUserDefaults standardUserDefaults];
    NSInteger uid = [defaults integerForKey:JMSG_UID];
    if (nil == uid) {
        // not registered, go to register view
        UIStoryboard *uiStoryboard = [UIStoryboard storyboardWithName:@"Main" bundle:nil];
        UIViewController *vc = [uiStoryboard instantiateViewControllerWithIdentifier:@"Register"];
        [self.parentViewController showViewController:vc sender:nil];
    }
}










- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end