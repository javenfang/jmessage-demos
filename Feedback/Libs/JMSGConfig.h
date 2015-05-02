//
//  JMSGConfig.h
//  JPush IM
//
//  Created by Apple on 15/1/20.
//  Copyright (c) 2015年 Apple. All rights reserved.
//

#ifndef JPush_IM_JMSGConfig_h
#define JPush_IM_JMSGConfig_h
#import "JMSGCommon.h"
#import "JMSGIMRequest.h"

static short JMessageVersion = 101;
static short JMessageBuildVersion = 100;

/**服务器地址**/
#define serverIP @"https://sdksecure.im.jpush.cn"
//#define serverIP @"http://192.168.2.103:8080"
#define httpToken @"token"
//#define serverIP @"https://api.im.jpush.cn/IMHTTP/"
//#define serverIP @"https://183.232.25.237:8080/IMHTTP/"
#define tokenIP @"https://sdksecure.im.jpush.cn/token"

#define serverHttpIP @"http://sdk.im.jpush.cn"



//gwml.jpushoa.com
//#define serverIP @"http://114.119.7.195:8080"
//#define serverIP @"http://gwml.jpushoa.com:3101/"
//#define serverIP @"http://192.168.2.148:3100/"


#define chatServerV1 @"/chat-server-v1"
#define usercenterServerV1 @"/user-center-server-v1"
#define mediaServerV1 @"/media-storage-server-v1"
#define uploadToken @"/uploadToken"
#define photoPath @"http://cimage.b0.upaiyun.com/"
#define uploadToken @"/uploadToken"
#define qiniuImgToken @"qiniuImgToken"
#define qiniuVoiceToken @"qiniuVoiceToken"
#define AuthorizationToken @"httpAuthorizationToken"
#define Authorization @"Authorization"
#define LOGIN_USER_INFO @"JMSGLoginUserInfo"

// block self
#define JMSGWEAKSELF typeof(self) __weak weakSelf = self;
#define JMSGSTRONGSELF typeof(weakSelf) __strong strongSelf = weakSelf;

//server name
#define QINIU  @"qiniu"
#define YOUPAI @"upyun"

/**自定义Log调试***/

#ifdef DEBUG
#define JMSGLog(...) NSLog(@"JMSGInLog DEBUG :%s [Line %d] %@", __PRETTY_FUNCTION__,__LINE__,[NSString stringWithFormat:__VA_ARGS__])
#define DEBUGSTATE YES
#else
#define JMSGLog(...) do { } while (0)
#define DEBUGSTATE NO
#endif

#define kJMSGScreenWidth          [[UIScreen mainScreen] bounds].size.width           //(e.g. 320)
#define DOWNLOAD_TIMEOUT  (30)

/**
 *  声明单列
 */
#define DEFINE_SINGLETON_FOR_HEADER(className) \
\
+ (className *)shared##className;

#define DEFINE_SINGLETON_FOR_CLASS(className) \
static className *shared##className = nil; \
static dispatch_once_t onceToken; \
\
+ (className *)shared##className { \
dispatch_once(&onceToken, ^{ \
shared##className = [[self alloc] init]; \
}); \
return shared##className; \
}

#define JPUSHIM_DISPATCH_SEL_TO_MYSEL_ON_MANAGER_THREAD_WITH_ARG(handler,sel, arg) \
[handler performSelector:(sel)                   \
onThread:g_pService.JMSGThread              \
withObject:(arg)                               \
waitUntilDone:NO];

#define JPUSHIM_DISPATCH_SEL_TO_MYSEL_ON_MANAGER_THREAD(handler,sel) \
[handler performSelector:(sel)                 \
onThread:g_pService.JMSGThread            \
withObject:nil                   \
waitUntilDone:NO];

#define JMSGMAINTHEAD(block) dispatch_async(dispatch_get_main_queue(), block)

#pragma mark -callback
typedef void (^FailCallback)(NSError *callback);

NS_ENUM(NSInteger , kJMessageRequestType){
  kJMessageNone          = 100,
  kJMSGRegister          = 115,
  kJMSGGetUserInfo       = 116,
  kJMSGGetUserAvatar     = 117,
  kJMSGUpdatePassword    = 118,
  kJMSGUpdateUserInfo    = 119,
  kJMSGGetFriendList     = 120,
};

/**
 *  发送和接收消息
 */
typedef NS_ENUM(NSInteger, JMSGInsertType) {
  kSendInsert = 0,
  kReceiveInsert,
};

/**
*  获取多媒体消息内容类型
*/
typedef NS_ENUM(NSInteger, JMSGMediaType) {
  kCrc32Media,
  kNoCrc32Media,
};

NS_ENUM(NSUInteger , JMSGediaIDIndex){
  kJMSGediaServerName = 0,
  kJMSGediaType,
  kJMSGmediaUniqueID,
}JMSGediaIDIndex;

//thumb size setting
static Point thumbSize = {200,200};

//limit message length
#define JMSGMaxMessageLenth  (2000)

#pragma mark ---thumb
#define kYoupai2xWidth @"IOS2XWidthThumb"
#define kYoupai2xhigh @"IOS2XHightThumb"
#define kYoupai3xWidth @"IOS3XWidthThumb"
#define kYoupai3xhigh @"IOS3XHightThumb"

#define kVoicePath @"voiceResource"
#define kVoiceDuration @"duration"
#define kMediaId @"media_id"
#define kTextContent @"text"
#define kExtra   @"extra"
#define kMediaCrc32 @"media_crc32"
#define kFormat @"format"
#define kThumbPath @"thumbPath"
#define kImgResource @"imgresource"
#define kImgWidth @"width"
#define kImgHeight @"height"

#define KdataNull @"(null)"
#define klatest_displayName @"latest_displayName"
#define kuserArchive @"/user.archive"


//folder name(image)
#define kThumbFolder  @"thumbFolder"
#define kOriginFolder  @"originFolder"

#pragma mark - UserInfo
static BOOL isDataBaseUserInfo = NO;

#define kUID                    (@"uid")
#define kUSERNAME               (@"username")
#define kNICKNAME               (@"nickname")
#define kNOTENAME               (isDataBaseUserInfo ? @"note_name" : @"notename")
#define kNOTETEXT               (isDataBaseUserInfo ? @"note_text" : @"notetext")
#define kSTAR                   (@"star")
#define kBLACKLIST              (@"blacklist")
#define kAVATAR                 (@"avatar")
#define kBIRTHDAY               (@"birthday")
#define kSIGNATURE              (@"signature")
#define kGENDER                 (@"gender")
#define kREGION                 (@"region")
#define kPASSWORD               (@"password")
#define kAVATARRESOURCEPATH     (@"avatarResourcePath")
#define kAVATARTHUMBPATH        (@"avatarThumbPath")
#define kMEDIAID                (@"mediaID")

#define kToken                  (@"token")

#pragma mark - conversation Notification
//name
#define kJMSGConversationChanged @"kJMSGConversationChanged"

#endif
