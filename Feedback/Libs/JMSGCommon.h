//
//  JMSGcommon.h
//  JPush IM
//
//  Created by Apple on 14/12/19.
//  Copyright (c) 2014年 Apple. All rights reserved.
//

#ifndef JPush_IM_JMSGcommon_h
#define JPush_IM_JMSGcommon_h
#import "JMSGBridgeProtocol.h"

/***************************************声明枚举类型*********************************************/

typedef void (^JMSGCompletionHandler)(id resultObject, NSError *error);
typedef void (^JMSGSpecificFailHandler)();

/**
*  JMessage 请求超时
*/
#define kJMSGRequestTimeout (16002)


/**
*  收取收到消息通知
*/
extern NSString *KJMSG_ReceiveMessage;

/**
 *  会话类型
 */
typedef NS_ENUM(NSInteger, ConversationType) {
  kSingle = 0,
  kGroup,
};

/**
*  消息内容类型
*/
typedef NS_ENUM(NSInteger, MessageContentType) {
  kTextMessage = 0,
  kImageMessage,
  kVoiceMessage,
  kCustomMessage,
  kLocationMessage,
  kCmdMessage,
  kTimeMessage,
};

/**
 *  消息状态类型
 */
typedef NS_ENUM(NSInteger, MessageStatusType) {
  kNone,
  kSendSucceed ,
  kSendFail,
  kSending,
  kUploadSucceed,
  kSendDraft,
  kReceiving,
  kReceiveSucceed,
  kReceiveFailed,
  kReceiveDownloadFailed,
};

/**
*  消息类型
*/
typedef NS_ENUM(NSInteger, MessageMetaType) {
  kSendType,
  kReceiveType,
};

/**
 *  上传文件类型
 */
typedef NS_ENUM(NSInteger, FileType) {
  kTextFileType,
  kImageFileType,
  kVoiceFileType,
  kCustomFileType,
};

/**
 *  消息下载回调block
 */
typedef void (^JMSGonProgressUpdate)(float percent);

/**
 *  更新用户信息类型
 */
typedef NS_ENUM(NSUInteger,JMSGUpdateUserInfoType){
    kJMSGNickname  = 0,
    kJMSGBirthday  = 1,
    kJMSGSignature = 2,
    kJMSGGender    = 3,
    kJMSGRegion    = 4,
    kJMSGAvatar    = 5,
};

/*******************************************************************************************/

#endif
