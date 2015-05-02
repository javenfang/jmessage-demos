#import "JMSGCommon.h"

@class JMSGMessage;
@class JMSGConversationModel;

extern NSString *kJMSGConversationInfoChanged;

@interface JMSGConversation : NSObject

@property(readonly, strong, nonatomic) NSString *targetName;
@property(readonly, strong, nonatomic) NSString *avatarThumb;
@property(readonly, assign, nonatomic) ConversationType chatType;
@property(readonly, strong, atomic) JMSGConversationModel *conversationModel;



/**
 *  获取指定消息id的消息
 *
 *  @param messageId  消息ID
 *  @param handler    用户获取消息回调接口(resultObject为JMSGMessage类型)
 *
 */
- (void)getMessage:(NSString *)messageId
 completionHandler:(JMSGCompletionHandler)handler;

/**
*  获取Conversation信息
*
*  @param handler    用户获取Conversation信息回调接口(resultObject为JMSGConversationModel类型)
*
*/
- (void)getConversationInfoWithCompletionHandler:(JMSGCompletionHandler)handler;

/**
 *  获取会话所有消息
 *
 *  @param handler    用户获取所有消息回调接口(resultObject为JMSGMessage类型的数组)
 *
 */
- (void)getAllMessageWithCompletionHandler:(JMSGCompletionHandler)handler;


/**
 *  删除会话所有消息
 *
 *  @param handler    删除所有消息回调接口
 *
 */
- (void)deleteAllMessageWithCompletionHandler:(JMSGCompletionHandler)handler;

/**
 *  将会话中的未读消息数清零
 *
 *  @param handler    清空未读消息回调接口
 *
 */
- (void)resetUnreadMessageCountWithCompletionHandler:(JMSGCompletionHandler)handle;

@end
