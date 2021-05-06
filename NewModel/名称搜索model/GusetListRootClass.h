#import <UIKit/UIKit.h>
#import "GusetListData.h"

@interface GusetListRootClass : NSObject

@property (nonatomic, strong) NSString * code;
@property (nonatomic, strong) NSArray * data;
@property (nonatomic, strong) NSString * msg;

-(instancetype)initWithDictionary:(NSDictionary *)dictionary;

-(NSDictionary *)toDictionary;
@end