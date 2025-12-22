//
//  SFWatchfacepPushFileManager.h
//  SFWatchfaceSDK
//
//  Created by Sean on 2023/12/21.
//

#import <Foundation/Foundation.h>
#import <SifliOCore/SifliOCore.h>
#import <SFWatchfaceSDK/SFFile.h>
#import <SFWatchfaceSDK/SFWatchfaceError.h>

NS_ASSUME_NONNULL_BEGIN
@class SFWatchfacePushFileManager;
@protocol SFWatchfacePushFileManagerDelegate <NSObject>

- (void)pushFileManager:(SFWatchfacePushFileManager *)manager updateBleState:(SFBleCoreManagerState)state;
- (void)pushFileManager:(SFWatchfacePushFileManager *)manager
               progress:(NSUInteger)completedBytes
              total:(NSUInteger)totalBytes;

/// 视频预览完成回调
/// - Parameters:
///   - manager:
///   - success:是否成功，失败时error有值。
///   - error: @see SFWatchfaceError
- (void)pushFileManager:(SFWatchfacePushFileManager *)manager success:(BOOL)success errror:(nullable SFWatchfaceError *)error;
- (void)pushFileManager:(SFWatchfacePushFileManager *)manager updateManagerState:(SFBleShellStatus)state;

@end
@interface SFWatchfacePushFileManager : NSObject
@property (nonatomic,weak) id<SFWatchfacePushFileManagerDelegate> delegate;
- (BOOL)isBusy;
///  创建共享实例，初始化蓝牙模块
+ (SFWatchfacePushFileManager *)shared;


/// 推送表盘文件
/// - Parameters:
///   - identifier: 目标设备的identifier字符串。通过CBPeripheral.identifier.uuidString获取
///   - type: 文件类型。0-表盘，1-多语言，2-背景图，3-自定义，4-音乐,5-JS,8-4g模块。其它类型查阅文档。@see SFWatchfaceFileType
///   - zipPath: zip格式的升级文件位于本地的url
///   - maxFileSliceLength: 文件切片长度，默认1024字节。数值越大速度越快，但可能造成设备无法响应。该值应视具体设备而定。
///   - withByteAlign: 是否对文件进行CRC和字节对齐处理，需要依据具体的设备支持情况来决定该参数的取值。默认false。PS：当type为3时，总是会进行CRC和对齐操作，与该参数取值无关。当type=8 时，该参数无效，不会添加CRC和对齐
- (void)pushWatchfaceFileWithIdentifier:(NSString *)identifier
                                   type:(NSInteger)type
                                zipPath:(NSString *)zipPath
                     maxFileSliceLength:(NSInteger)maxFileSliceLength
                          withByteAlign:(BOOL)withByteAlign;
/// 推送表盘文件
/// - Parameters:
///   - identifier: 目标设备的identifier字符串。通过CBPeripheral.identifier.uuidString获取
///   - type: 文件类型。0-表盘，1-多语言，2-背景图，3-自定义，4-音乐,8-4g模块。其它类型查阅文档。@see SFWatchfaceFileType
///   - files: 所推送的文件序列。
///   - maxFileSliceLength: 文件切片长度，默认1024字节。数值越大速度越快，但可能造成设备无法响应。该值应视具体设备而定。
///   - withByteAlign: 是否对文件进行CRC和字节对齐处理，需要依据具体的设备支持情况来决定该参数的取值。默认false。PS：当type为3时，总是会进行CRC和对齐操作，与该参数取值无关。当type=8 时，该参数无效，不会添加CRC和对齐
- (void)pushWatchfaceFileWithIdentifier:(NSString *)identifier
                                   type:(NSInteger)type
                                  files:(NSArray<SFFile *> *)files
                     maxFileSliceLength:(NSInteger)maxFileSliceLength
                          withByteAlign:(BOOL)withByteAlign;

///终止推送,并断开蓝牙连接
///如果正在推送会给手表发送一个terminate 10 命令
- (void)stop;

@end

NS_ASSUME_NONNULL_END
