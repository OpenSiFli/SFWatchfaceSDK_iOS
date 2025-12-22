//
//  SFWatachfaceManager.h
//  SFWatchfaceSDK
//
//  Created by Sean on 2023/11/6.
//

#import <Foundation/Foundation.h>
#import <SifliOCore/SFBleCoreManagerState.h>
#import <SifliOCore/SFBleShell.h>
#import <SFWatchfaceSDK/SFWatchfaceError.h>
#import <SFWatchfaceSDK/SFPreviewVideoConfigration.h>
#import <SFWatchfaceSDK/SFWatchfaceStatus.h>
#import <AVFoundation/AVFoundation.h>

NS_ASSUME_NONNULL_BEGIN
@class SFPreviewVideoManager;
@protocol SFPreviewVideoManagerDelegate <NSObject>

/// 更新蓝牙状态
/// @param manager self
/// @param state 蓝牙状态
- (void)previewVideoManager:(SFPreviewVideoManager *)manager updateBleState:(SFBleCoreManagerState)state;


/// 视频预览完成回调
/// - Parameters:
///   - manager: self
///   - error: @see SFWatchfaceError
- (void)previewVideoManager:(SFPreviewVideoManager *)manager completeWitherror:(nullable SFCoreError *)error;

/// 视频预览模块状态
/// @param manager self
/// @param state  0 空闲 1 搜索中 2 连接中 3工作中
- (void)previewVideoManager:(SFPreviewVideoManager *)manager updateManagerState:(SFBleShellStatus)state;
@optional
/// 实时帧率
/// @param manager self
/// @param fps 帧率
- (void)previewVideoManager:(SFPreviewVideoManager *)manager fps:(float)fps;

/// 即将发送的图片数据
/// @param manager self
/// @param jpgData jpg数据
- (void)previewVideoManager:(SFPreviewVideoManager *)manager onImageMake:(NSData *)jpgData;

@end

@interface SFPreviewVideoManager : NSObject
@property (nonatomic,weak) id<SFPreviewVideoManagerDelegate> delegate;

/// 帧旅
@property (nonatomic,assign) float fps;

///  创建共享实例，初始化蓝牙模块
+ (SFPreviewVideoManager *)shared;


/// 发起视频预览
/// 发起蓝牙连接，之后初始化传输，在状态未就绪前发送到priviewVideoSample的采样数据会被丢弃
/// - Parameter configration: 配置参数
- (void)startPreviewVideo:(SFPreviewVideoConfigration *)configration targetIdentifier:(NSString *)identifier;

/// 向手表端发送视频采样
/// sdk根据SFPreviewVideoConfigration 的配置对采样进行处理，之后将jpeg数据通过蓝牙发送到手表端
/// - Parameter sample: 视频数据采样，通过AVCaptureVideoDataOutput 获得;
- (void)previewVideoSample:(CMSampleBufferRef)sample;

/// 结束预览视频,保持连接
- (void)endPreviewVideo;
/// 停止传输, 关闭连接
- (void)stop;

@end

NS_ASSUME_NONNULL_END
