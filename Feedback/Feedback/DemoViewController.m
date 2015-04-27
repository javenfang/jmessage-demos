//
//  DemoViewController.m
//  Feedback
//
//  Created by Javen on 15/4/24.
//  Copyright (c) 2015 HEXG. All rights reserved.
//


#import "DemoViewController.h"


@interface DemoViewController ()

@end

// 考虑一般的 App 嵌入 Feedback 场景：用户名与 App 里的用户名一致；密码不需要单独输入。
// 作为独立的 Demo，需要让用户输入 username
@implementation DemoViewController

#define JMSG_UID @"jmessage_uid";

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.

    NSLog(@"action - demoView:viewDidLoad");
    self.title = @"JMessage Feedback";

    // 如果未注册，则需要发起注册，输入 username


    // 注册过则进入聊天页
}

- (BOOL)needRegister {
    NSUserDefaults *defaults = [NSUserDefaults standardUserDefaults];
    NSInteger *uid = [defaults integerForKey:JMSG_UID];

    return False;
}











- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end