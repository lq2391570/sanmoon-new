//
//	GusetListRootClass.m
//	Model file generated using JSONExport: https://github.com/Ahmed-Ali/JSONExport



#import "GusetListRootClass.h"

NSString *const kGusetListRootClassCode = @"code";
NSString *const kGusetListRootClassData = @"data";
NSString *const kGusetListRootClassMsg = @"msg";

@interface GusetListRootClass ()
@end
@implementation GusetListRootClass




/**
 * Instantiate the instance using the passed dictionary values to set the properties values
 */

-(instancetype)initWithDictionary:(NSDictionary *)dictionary
{
	self = [super init];
	if(![dictionary[kGusetListRootClassCode] isKindOfClass:[NSNull class]]){
		self.code = dictionary[kGusetListRootClassCode];
	}	
	if(dictionary[kGusetListRootClassData] != nil && [dictionary[kGusetListRootClassData] isKindOfClass:[NSArray class]]){
		NSArray * dataDictionaries = dictionary[kGusetListRootClassData];
		NSMutableArray * dataItems = [NSMutableArray array];
		for(NSDictionary * dataDictionary in dataDictionaries){
			GusetListData * dataItem = [[GusetListData alloc] initWithDictionary:dataDictionary];
			[dataItems addObject:dataItem];
		}
		self.data = dataItems;
	}
	if(![dictionary[kGusetListRootClassMsg] isKindOfClass:[NSNull class]]){
		self.msg = dictionary[kGusetListRootClassMsg];
	}	
	return self;
}


/**
 * Returns all the available property values in the form of NSDictionary object where the key is the approperiate json key and the value is the value of the corresponding property
 */
-(NSDictionary *)toDictionary
{
	NSMutableDictionary * dictionary = [NSMutableDictionary dictionary];
	if(self.code != nil){
		dictionary[kGusetListRootClassCode] = self.code;
	}
	if(self.data != nil){
		NSMutableArray * dictionaryElements = [NSMutableArray array];
		for(GusetListData * dataElement in self.data){
			[dictionaryElements addObject:[dataElement toDictionary]];
		}
		dictionary[kGusetListRootClassData] = dictionaryElements;
	}
	if(self.msg != nil){
		dictionary[kGusetListRootClassMsg] = self.msg;
	}
	return dictionary;

}

/**
 * Implementation of NSCoding encoding method
 */
/**
 * Returns all the available property values in the form of NSDictionary object where the key is the approperiate json key and the value is the value of the corresponding property
 */
- (void)encodeWithCoder:(NSCoder *)aCoder
{
	if(self.code != nil){
		[aCoder encodeObject:self.code forKey:kGusetListRootClassCode];
	}
	if(self.data != nil){
		[aCoder encodeObject:self.data forKey:kGusetListRootClassData];
	}
	if(self.msg != nil){
		[aCoder encodeObject:self.msg forKey:kGusetListRootClassMsg];
	}

}

/**
 * Implementation of NSCoding initWithCoder: method
 */
- (instancetype)initWithCoder:(NSCoder *)aDecoder
{
	self = [super init];
	self.code = [aDecoder decodeObjectForKey:kGusetListRootClassCode];
	self.data = [aDecoder decodeObjectForKey:kGusetListRootClassData];
	self.msg = [aDecoder decodeObjectForKey:kGusetListRootClassMsg];
	return self;

}

/**
 * Implementation of NSCopying copyWithZone: method
 */
- (instancetype)copyWithZone:(NSZone *)zone
{
	GusetListRootClass *copy = [GusetListRootClass new];

	copy.code = [self.code copy];
	copy.data = [self.data copy];
	copy.msg = [self.msg copy];

	return copy;
}
@end