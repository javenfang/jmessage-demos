//
// Created by Javen on 15/4/27.
// Copyright (c) 2015 HEXG. All rights reserved.
//

#import "JMFBRegisterViewController.h"
#import "JMFBMyAdditions.h"


@interface JMFBRegisterViewController ()

@end


@implementation JMFBRegisterViewController {

}

- (void)viewDidLoad {
    [super viewDidLoad];
    NSLog(@"action - registerView:viewDidLoad");

    self.title = @"注册用户名";
    self.navigationItem.hidesBackButton = TRUE;

    self.navigationItem.rightBarButtonItem = [[UIBarButtonItem alloc]
            initWithTitle:@"Register"
                    style:UIBarButtonItemStyleBordered
                   target:self
                   action:@selector(registerButton)];
}

- (void)registerButton {
    NSLog(@"action - registerButton");

    NSString *username = _UsernameTextField.text;

    NSString *password = username.md5;

    NSLog(@"Will register with - username:%@, password:%@", username, password);

    [JMSGUserManager registerWithUsername:username
                                 password:password
                        completionHandler:^(JMSGUser *jmsgUser, NSError *error) {
                            if (nil == error) {
                                [self registerSucceed:username
                                         withPassword:password];
                            } else {
                                NSLog(@"Regsiter error with %d, %@", error.code, error.description);
                            }
                        }];
}

- (void)registerSucceed:(NSString *)username
           withPassword:(NSString *)password {
    NSLog(@"action - registerSucceed");

    [[NSUserDefaults standardUserDefaults] setObject:username
                                              forKey:JMSG_USERNAME];


    [self.navigationController popViewControllerAnimated:TRUE];

}


@end