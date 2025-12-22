//
//  SFFile.h
//  SFWatchfaceSDK
//
//  Created by Sean on 2023/12/22.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
typedef NS_ENUM(NSUInteger, SFWatchfaceFileType) {
    SFWatchfaceFileTypeDiaplate = 0,//表盘
    SFWatchfaceFileTypeMutilLanguage = 1,//多语言
    SFWatchfaceFileTypeBgImage = 2,//背景图
    SFWatchfaceFileTypeCustom = 3,//自定义
    SFWatchfaceFileTypeBgMusic = 4,//背景音乐
    SFWatchfaceFileTypeJS = 5,//JavaScript
    SFWatchfaceFileType4GModule = 8//4g模块，无需加crc
  
};

@interface SFFile : NSObject
@property (nonatomic,copy,readonly)NSString *fileName;
@property (nonatomic,strong,readonly)NSData *fileData;
@property (nonatomic,strong,readonly)NSArray<NSData *> *fileSlice;
@property (nonatomic,assign)BOOL isSend;
- (instancetype)initWithFileName:(NSString *)fileName fileData:(NSData *)fileData;
- (void)reSliceFileWithMaxDataLen:(NSInteger)maxDataLen;
- (void)paddingByte:(uint8_t)paddingByte;
- (NSString *)briefDes;

- (NSInteger)getSliceLen:(NSInteger)index;
- (BOOL)hasSlice;
@end

NS_ASSUME_NONNULL_END
