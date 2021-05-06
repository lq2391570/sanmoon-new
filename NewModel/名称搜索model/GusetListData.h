#import <UIKit/UIKit.h>

@interface GusetListData : NSObject

@property (nonatomic, strong) NSString * gexpphone;
@property (nonatomic, strong) NSString * gid;
@property (nonatomic, strong) NSString * gname;
@property (nonatomic, strong) NSString * gueststate;
@property (nonatomic, strong) NSString * usid;

-(instancetype)initWithDictionary:(NSDictionary *)dictionary;

-(NSDictionary *)toDictionary;
@end