#import "JMSGBridgeProtocol.h"

//notification
extern NSString *const kJPFNetworkDidReceiveIMMessageNotification; //收取IM和Event消息
extern NSString *IMMessageKey; //通过key获取IM消息
extern NSString *IMEventKey;  //通过key获取Event事件

@class JPUSHIMRequestArg;

//return block type define
typedef void (^commonBlock)(id<JMSGResponseArgProtocol> result);

@interface JMSGBridge : NSObject

 + (void)setupWithOption:(NSDictionary *)launchingOption appKey:(NSString *)appKey channel:(NSString *)channel apsForProduction:(BOOL)isProduction imSupport:(BOOL)isImSupport;

 + (void)IMRequestWithParameter:(id <JMSGRequestArgProtocol>)request
                  succeeedBlock:(commonBlock)succeedBlock
                   failureBlock:(commonBlock)failureBlock;

 + (BOOL)checkVersionSupport:(float)minVersion;

 + (BOOL)getServerTimeInterval:(NSTimeInterval *)interval;

@end