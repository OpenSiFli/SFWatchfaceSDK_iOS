//
//  SFWatchfaceStatus.h
//  SFWatchfaceSDK
//
//  Created by Sean on 2023/11/6.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
typedef NS_ENUM(NSUInteger, SFWatchfaceStatus) {
    //空闲
    SFWatchfaceStatusNone = 0,
    //搜索设备
    SFWatchfaceStatusSearching = 1,
    //连接设备
    SFWatchfaceStatusConnecting = 2,
    //模块工作中
    SFWatchfaceStatusModuleWorking = 3
};

NS_ASSUME_NONNULL_END
