//
//  JPFIMBridgeProtocol.h
//  PushIM-1.0.0
//
//  Created by zhang on 15/1/22.
//  Copyright (c) 2015年 hxhg. All rights reserved.
//

#ifndef PushIM_1_0_0_JPIMBridgeProtocol_h
#define PushIM_1_0_0_JPIMBridgeProtocol_h
#import <Foundation/Foundation.h>

//timeout error
#define kJPUSHIMRequestTimeout   (6002)

//require type
typedef NS_ENUM(NSUInteger,JMSGRequestType){
    kJMSGNone              = 0,
    kJMSGLogin             = 1,
    kJMSGLogout            = 2,
    kJMSGSendMessageSingle = 3,
    kJMSGSendMessageGroup  = 4,
    kJMSGAddFriend         = 5,
    kJMSGDeleteFriend      = 6,
    kJMSGUpdateMember      = 7,
    kJMSGCreateGroup       = 8,
    kJMSGExitGroup         = 9,
    kJMSGAddGroupMember    = 10,
    kJMSGDeleteGroupMember = 11,
    kJMSGUpdateGroupInfo   = 12,
    kJMSGSyncEvent         = 13,
    kJMSGSyncMessage       = 14,
};

//event answer类型
typedef NS_ENUM(NSUInteger , JpushIMEventAnswer){
    kJpushIMEventRecv = 1,
    kJpushIMEventYES  = 2,
    kJpushIMEventNO   = 3,
};

#pragma mark -  JPushIM TCP request Model

/**
 *  会话类型
 */
typedef NS_ENUM(NSInteger, MessageType) {
    kSingleSendMessage,
    kGroupSendMessage,
    kSingleReceiveMessage,
    kGroupReceiveMessage,
};


/*******************************************************************************
 Function:       request & response protocol
 Description:    every IM request not only need to conform JMSGRequestArgProtocol,but also need conform the specific protocol
 every IM response not only need to conform JMSGResponseArgProtocol,but also need conform the specific protocol
 Input:          N/A
 Return:         N/A
 Others:
 ********************************************************************************/
@protocol JMSGRequestArgProtocol <NSObject,NSCopying>

 @required
 @property(nonatomic, assign)UInt64   rid;
 @property(nonatomic, assign)SInt64   uid;
 @property(nonatomic, assign)SInt32   type;
 @property(nonatomic, assign)NSInteger timeOutTimes;

@end

@protocol JMSGResponseArgProtocol <NSObject,NSCopying>

 @required
 @property(nonatomic, assign)UInt64   rid;

@end

//specific protocol
@protocol JMSGUserInfoProtocol <NSObject>

 @optional
 @property (nonatomic, copy)NSString *username;
 @property (nonatomic, copy)NSString *password;
 @property (nonatomic, assign)SInt64   gid;
 @property (nonatomic, assign)SInt64   uid;

@end

@protocol JMSGGroupProtocol <NSObject>

 @required
 @property (nonatomic, strong)NSString *groupName;
 @property (nonatomic, strong)NSString *groupDescription;
 @property (nonatomic, assign)SInt32   groupLevel;
 @property (nonatomic, assign)SInt32   flag;
 @property (nonatomic, assign)SInt64   gid;

@end

@protocol JMSGMessageProtocol <NSObject>

 @required
 @property (nonatomic, strong)NSDictionary *text;
 @property (nonatomic, assign)SInt32        ctime;

 @optional
 @property (nonatomic, assign)SInt64 targetUid;
 @property (nonatomic, assign)SInt64 fromUid;
 @property (nonatomic, assign)SInt32 type;
 @property (nonatomic, assign)SInt64 msgid;

@end

@protocol JMSGEventNotificationProtocol <NSObject>

 @required
 @property (nonatomic, assign)SInt64 eventID;
 @property (nonatomic, assign)SInt64 fromUid;
 @property (nonatomic, assign)SInt32 type;
 @property (nonatomic, assign)SInt64 gid;
 @property (nonatomic, assign)SInt32 ctime;
 @property (nonatomic, copy)NSString *eventDescription;
 @property (nonatomic, copy)NSArray  *toUidList;

@end

@protocol JMSGMemberProtocol <JMSGGroupProtocol>

 @required
 @property (nonatomic, assign)NSArray *memberList;

@end

@protocol JMSGFailedProtocol <NSObject>

 @required
 @property (nonatomic, assign)SInt32 statusCode;
 @property (nonatomic, strong)NSString *errorDescription;
 @property (nonatomic, assign)UInt64   rid;

@end

//ensure request sent succeed
NS_ENUM(NSUInteger , EnsureType){
  kAppActiveEnsure = 1<<0,
  kAppStartEnsure  = 1<<1,
  kAllEnsure       = kAppActiveEnsure | kAppStartEnsure,
};

@protocol JMSGEnsureRequest

 @required
 @property (nonatomic, assign) enum EnsureType ensureType;

@end

#endif
