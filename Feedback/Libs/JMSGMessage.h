#import <Foundation/Foundation.h>
#import "JMSGCommon.h"
#import <UIKit/UIKit.h>

@class JMSGConversation;

@interface JMSGMessage : NSObject <NSCopying>

 @property (atomic, strong, readonly) NSString            *messageId;   //聊天ID
 @property (atomic, strong) NSString                    *target_name;
 @property (atomic, strong, getter=display_name) NSString *display_name;

 @property (atomic, strong)   NSDictionary                *extra;
 @property (atomic, strong)   NSDictionary                *custom;

 @property (assign, readonly) MessageContentType           messageType;
 @property (atomic, strong  ) JMSGConversation            *conversation;
 @property (atomic, strong  ) NSNumber                    *timestamp;  //消息时间戳
 @property (strong, readonly) NSNumber                    *status;     //消息的状态


 - (instancetype)init;

@end

@interface JMSGMediaMessage : JMSGMessage <NSCopying>

 @property (atomic, strong)JMSGonProgressUpdate   progressCallback;
 @property (atomic, strong)NSString              *resourcePath;
 @property (atomic, assign)CGSize                 imgSize;

@end

@interface JMSGContentMessage : JMSGMessage <NSCopying>

 @property(atomic, strong)NSString                *contentText;

@end

@interface JMSGImageMessage : JMSGMediaMessage <NSCopying>

 @property(atomic, strong)NSString                *thumbPath;

@end

@interface JMSGVoiceMessage : JMSGMediaMessage <NSCopying>

 @property(atomic, strong)NSString                *duration;

@end
