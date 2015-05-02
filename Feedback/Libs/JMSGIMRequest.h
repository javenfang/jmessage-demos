//
//  JMSGRequestProtocol.h
//  JPush IM
//
//  Created by Apple on 15/2/27.
//  Copyright (c) 2015年 Apple. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JMSGBridgeProtocol.h"
#import "JMSGBridge.h"

@class JMSGMessage;

NS_ENUM(NSInteger , kJMSGRequestControl){
  kIMLoginRequired = 1<<0,
};

/**
*   timeout times
*/
#define COMMAND_TIMEOUT_TIMES (60)
#define MESSAGE_TIMEOUT_TIMES (5*60)
#define DEFAULT_TIMEOUT_TIMES (30)
#define INFINITE_TIMEOUT_TIMES (1000000)

//request
@interface JMSGInnerRequestArg :NSObject <JMSGRequestArgProtocol>{
   UInt8                   _controlFlag;
 }

 @property (nonatomic, assign)UInt64   rid;
 @property (nonatomic, assign)SInt64   uid;
 @property (nonatomic, assign)SInt32   type;
 @property (nonatomic, assign)NSInteger timeOutTimes;

 @property (nonatomic, copy) commonBlock succeedBlock;
 @property (nonatomic, copy) commonBlock failedBlock;

 - (BOOL)send;

 - (BOOL)isLoginRequired;

@end

@interface JMSGInnerLogin : JMSGInnerRequestArg <NSCopying,JMSGUserInfoProtocol>

 @property (nonatomic, copy)NSString *username;
 @property (nonatomic, copy)NSString *password;

 - (SInt32)type;

@end

@interface JMSGInnerLogout : JMSGInnerRequestArg <NSCopying,JMSGUserInfoProtocol,JMSGEnsureRequest>

 @property (nonatomic, copy)NSString *username;
 @property (nonatomic, copy)NSString *password;
 @property (nonatomic, assign)SInt64  gid;
 @property (nonatomic, assign) enum EnsureType ensureType;//ensure

 - (SInt32)type;

@end

@interface JMSGInnerGroup : JMSGInnerRequestArg <NSCopying,JMSGGroupProtocol>

 @property (nonatomic, strong)NSString *groupName;
 @property (nonatomic, strong)NSString *groupDescription;
 @property (nonatomic, assign)SInt32   groupLevel;
 @property (nonatomic, assign)SInt32   flag;
 @property (nonatomic, assign)SInt64   gid;

 - (SInt32)type;

@end

@interface JMSGInnerMessage : JMSGInnerRequestArg <NSCopying,JMSGMessageProtocol>

 @property (nonatomic, assign)SInt64 targetUid;
 @property (nonatomic, assign)SInt64 fromUid;
 @property (nonatomic, strong)NSMutableDictionary *text;
 @property (nonatomic, assign)SInt32 type;
 @property (nonatomic, assign)SInt64 msgid;
 @property (nonatomic, strong)NSString *resourcePath;
 @property (nonatomic, strong)NSString *thumbPath;
 @property (nonatomic, strong)NSString *duration;
 @property (nonatomic, assign)SInt32   ctime;

 @property (nonatomic, strong)JMSGMessage *originMessage;

 - (SInt32)type;

@end

@interface JMSGInnerEvent : JMSGInnerRequestArg <NSCopying,JMSGEventNotificationProtocol>

 @property (nonatomic, assign)SInt64 eventID;
 @property (nonatomic, assign)SInt64 fromUid;
 @property (nonatomic, assign)SInt32 type;
 @property (nonatomic, assign)SInt64 gid;
 @property (nonatomic, copy)NSString *eventDescription;

 - (SInt32)type;

@end

@interface JMSGInnerMember : JMSGInnerGroup <NSCopying,JMSGMemberProtocol>

 @property (nonatomic, assign)NSArray *memberList;

 - (SInt32)type;

@end

//response
@interface JMSGInnerResponseArg:NSObject <NSCopying,JMSGResponseArgProtocol>

 @property (nonatomic, assign)UInt64   rid;

@end

@interface JMSGInnerFailedResponse:JMSGInnerResponseArg <NSCopying>

 @property (nonatomic, assign)SInt32 statusCode;
 @property (nonatomic, strong)NSString *errorDescription;

@end

@interface JMSGInnerLoginResponse:JMSGInnerResponseArg <NSCopying>

 @property (nonatomic, assign)SInt64 uid;

@end

@interface JMSGInnerGroupResponse:JMSGInnerResponseArg <NSCopying>

 @property (nonatomic, strong)NSString *groupName;
 @property (nonatomic, strong)NSString *groupDescription;
 @property (nonatomic, assign)SInt32   groupLevel;
 @property (nonatomic, assign)SInt32   flag;
 @property (nonatomic, assign)SInt64   gid;

@end

