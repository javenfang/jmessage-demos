//
//  JMSGUser.h
//  JPush IM
//
//  Created by Apple on 15/1/27.
//  Copyright (c) 2015年 Apple. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JMSGConfig.h"
@interface JMSGUser : NSObject

 @property (atomic,strong, readonly) NSString *address;
 @property (atomic,strong, readonly) NSString *avatarResourcePath;
 @property (atomic,strong, readonly) NSString *avatarThumbPath;
 @property (atomic,strong, readonly) NSString *birthday;
 @property (atomic,strong, readonly) NSNumber *userGender;
 @property (atomic,strong, readonly) NSString *cTime;

 @property (atomic,assign, readonly) NSInteger star;
 @property (atomic,assign, readonly) NSInteger blackList;
 @property (atomic,strong, readonly) NSString *region;
 @property (atomic,strong, readonly) NSString *nickname;
 @property (atomic,strong, readonly) NSString *noteName;
 @property (atomic,strong, readonly) NSString *noteText;
 @property (atomic,strong, readonly) NSString *signature;
 @property (atomic,assign, readonly) SInt64    uid;
 @property (atomic,strong, readonly) NSString *username;
 @property (atomic,strong, readonly) NSString *password;

@end
