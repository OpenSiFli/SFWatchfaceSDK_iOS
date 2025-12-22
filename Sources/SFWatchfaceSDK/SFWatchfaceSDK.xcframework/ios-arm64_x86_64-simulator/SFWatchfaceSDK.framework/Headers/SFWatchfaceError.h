//
//  SFWatchfaceError.h
//  SFWatchfaceSDK
//
//  Created by Sean on 2023/11/3.
//

#import <Foundation/Foundation.h>
#import <SifliOCore/SFCoreError.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, SFWatchfaceErrorType) {
    //转义SFCoreError
//    SFWatchfaceErrorTypeUnkown = 0,
//    SFWatchfaceErrorTypeConnectTimeout = 1,
//    SFWatchfaceErrorTypeConnectionCanceled = 2,
//    SFWatchfaceErrorTypeDisconnected = 3,
//    SFWatchfaceErrorTypeFailedToConnect = 4,
    //搜索设备超时
    SFWatchfaceErrorTypeSearchTimeout = 100,
    //请求超时
    SFWatchfaceErrorTypeRequestTimeout = 110,
    //设备错误码 errorType 为此值时，devErrorCode有值。
    SFWatchfaceErrorTypeErrorCodeFromDevice = 120,
    //蓝牙状态异常
    SFWatchfaceErrorTypeUnavailableBleStatus = 130,
    //无效参数
    SFWatchfaceErrorTypeInvalidParams = 140,
    //数据超出范围
    SFWatchfaceErrorTypeOutOfRange = 150,
    //解析响应数据失败
    SFWatchfaceErrorTypeFailToParsePacket = 160,
    //用户主动停止
    SFWatchfaceErrorTypeUserStop = 170,
    //手表用户主动停止
    SFWatchfaceErrorTypeRemoteAbort = 180,
    //解压失败
    SFWatchfaceErrorTypeFailToUnzip = 190,
    //解压失败
    SFWatchfaceErrorTypeNoFileInZip = 200,
    //读取文件失败
    SFWatchfaceErrorTypeFailToReadFile = 210,
    //调试期间才可能出现的错误，正式版不应当出现
    SFWatchfaceErrorTypeDebug = 220,
    //设备返回无效的最大切片长度
    SFWatchfaceErrorTypeInvalidMaxDataLen = 230,
    //设备返回无效的块长度
    SFWatchfaceErrorTypeInvalidBlockLength = 240,
    //设备返回无效的期望索引
    SFWatchfaceErrorTypeInvalidExpectIndex = 250,
    ///lose check 返回错误码2，通信错误次数超过3
    ///可能是切片太大
    SFWatchfaceErrorTypePushSliceTooLarge = 260,
};

@interface SFWatchfaceError : SFCoreError
//@property (nonatomic,assign) SFWatchfaceErrorType errorType;
//@property (nonatomic,copy) NSString *errorDes;

///  /// 当errType为SFWatchfaceErrorTypeErrorCodeFromDevice(12)时，可从该属性获取到设备返回的错误码值，Int类型
/// 已知设备端定义如下，可能随升级变更
/// typedef enum
///    {
///        BLE_WATCHFACE_STATUS_OK =0 ,
///        BLE_WATCHFACE_STATUS_GENERAL_ERROR =1,
///        BLE_WATCHFACE_STATUS_RECEIVE_ERROR =2,
///        BLE_WATCHFACE_STATUS_LEN_ERROR=3,/
///        BLE_WATCHFACE_STATUS_INDEX_ERROR=4,
///        BLE_WATCHFACE_STATUS_STATE_ERROR=5,/
///        BLE_WATCHFACE_STATUS_DISCONNECT=6,
///        BLE_WATCHFACE_STATUS_DOWNLOAD_NOT_ONGOING=7,
///        BLE_WATCHFACE_STATUS_REMOTE_ABORT =8,
///        BLE_WATCHFACE_STATUS_REMOTE_FILE_SIZE_CHECK_ERROR=9
///
///        BLE_WATCHFACE_STATUS_APP_ERROR = 20,
///        BLE_WATCHFACE_STATUS_FILE_SIZE_ALIGNED_MISSING =21,
///        BLE_WATCHFACE_STATUS_FILE_PATH_ERROR=22,
///        BLE_WATCHFACE_STATUS_FILE_TYPE_ERROR=23,
///        BLE_WATCHFACE_STATUS_MEM_MALLOC_ERROR=24,
///        BLE_WATCHFACE_STATUS_FILE_OPEN_ERROR=25,
///        BLE_WATCHFACE_STATUS_FILE_INFO_ERROR=26,
///        BLE_WATCHFACE_STATUS_FILE_WRITE_ERROR=27,
///        BLE_WATCHFACE_STATUS_FILE_CLOSE_ERROR=28,
///        BLE_WATCHFACE_STATUS_FILE_EXTENSION_ERROR=29,
///        BLE_WATCHFACE_STATUS_MKDIR_ERROR=30,
///        BLE_WATCHFACE_STATUS_SWITCH_DIRECTORY_ERROR=31,
///        BLE_WATCHFACE_STATUS_BLE_PARAMETERS_NULL=32,
///        BLE_WATCHFACE_STATUS_MEM_NOT_CONTINUOUS=33,
///        BLE_WATCHFACE_STATUS_FILE_SIZE_ERROR=34,
///        BLE_WATCHFACE_STATUS_CRC_INIT_ERROR=35,
///        BLE_WATCHFACE_STATUS_CRC_CALCULATE_ERROR=36,
///        BLE_WATCHFACE_STATUS_SPACE_ERROR=37,
///        BLE_WATCHFACE_STATUS_TIMEOUT_ERROR=38,
///        BLE_WATCHFACE_STATUS_UI_INVALID=39,
///        BLE_WATCHFACE_STATUS_BLE_DISCONNECT = 40,
///        BLE_WATCHFACE_STATUS_USER_ABORT = 41,
///        BLE_WATCHFACE_STATUS_RECV_DATA_TIMEOUT = 42
///    } ble_watchface_status_id_t;
@property (nonatomic,assign)NSInteger devErrorCode;
- (instancetype)initWithSFCoreError:(SFCoreError *)coreError;
- (instancetype)initWithErrorType:(SFWatchfaceErrorType)errorType desc:(NSString *)desc;
- (instancetype)initWithDeviceCode:(uint16_t)code;
@end

NS_ASSUME_NONNULL_END
