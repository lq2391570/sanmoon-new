//
//	GusetListData.m
//	Model file generated using JSONExport: https://github.com/Ahmed-Ali/JSONExport



#import "GusetListData.h"

NSString *const kGusetListDataGexpphone = @"gexpphone";
NSString *const kGusetListDataGid = @"gid";
NSString *const kGusetListDataGname = @"gname";
NSString *const kGusetListDataGueststate = @"gueststate";
NSString *const kGusetListDataUsid = @"usid";

@interface GusetListData ()
@end
@implementation GusetListData




/**
 * Instantiate the instance using the passed dictionary values to set the properties values
 */

-(instancetype)initWithDictionary:(NSDictionary *)dictionary
{
	self = [super init];
	if(![dictionary[kGusetListDataGexpphone] isKindOfClass:[NSNull class]]){
		self.gexpphone = dictionary[kGusetListDataGexpphone];
	}	
	if(![dictionary[kGusetListDataGid] isKindOfClass:[NSNull class]]){
		self.gid = dictionary[kGusetListDataGid];
	}	
	if(![dictionary[kGusetListDataGname] isKindOfClass:[NSNull class]]){
		self.gname = dictionary[kGusetListDataGname];
	}	
	if(![dictionary[kGusetListDataGueststate] isKindOfClass:[NSNull class]]){
		self.gueststate = dictionary[kGusetListDataGueststate];
	}	
	if(![dictionary[kGusetListDataUsid] isKindOfClass:[NSNull class]]){
		self.usid = dictionary[kGusetListDataUsid];
	}	
	return self;
}


/**
 * Returns all the available property values in the form of NSDictionary object where the key is the approperiate json key and the value is the value of the corresponding property
 */
-(NSDictionary *)toDictionary
{
	NSMutableDictionary * dictionary = [NSMutableDictionary dictionary];
	if(self.gexpphone != nil){
		dictionary[kGusetListDataGexpphone] = self.gexpphone;
	}
	if(self.gid != nil){
		dictionary[kGusetListDataGid] = self.gid;
	}
	if(self.gname != nil){
		dictionary[kGusetListDataGname] = self.gname;
	}
	if(self.gueststate != nil){
		dictionary[kGusetListDataGueststate] = self.gueststate;
	}
	if(self.usid != nil){
		dictionary[kGusetListDataUsid] = self.usid;
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
	if(self.gexpphone != nil){
		[aCoder encodeObject:self.gexpphone forKey:kGusetListDataGexpphone];
	}
	if(self.gid != nil){
		[aCoder encodeObject:self.gid forKey:kGusetListDataGid];
	}
	if(self.gname != nil){
		[aCoder encodeObject:self.gname forKey:kGusetListDataGname];
	}
	if(self.gueststate != nil){
		[aCoder encodeObject:self.gueststate forKey:kGusetListDataGueststate];
	}
	if(self.usid != nil){
		[aCoder encodeObject:self.usid forKey:kGusetListDataUsid];
	}

}

/**
 * Implementation of NSCoding initWithCoder: method
 */
- (instancetype)initWithCoder:(NSCoder *)aDecoder
{
	self = [super init];
	self.gexpphone = [aDecoder decodeObjectForKey:kGusetListDataGexpphone];
	self.gid = [aDecoder decodeObjectForKey:kGusetListDataGid];
	self.gname = [aDecoder decodeObjectForKey:kGusetListDataGname];
	self.gueststate = [aDecoder decodeObjectForKey:kGusetListDataGueststate];
	self.usid = [aDecoder decodeObjectForKey:kGusetListDataUsid];
	return self;

}

/**
 * Implementation of NSCopying copyWithZone: method
 */
- (instancetype)copyWithZone:(NSZone *)zone
{
	GusetListData *copy = [GusetListData new];

	copy.gexpphone = [self.gexpphone copy];
	copy.gid = [self.gid copy];
	copy.gname = [self.gname copy];
	copy.gueststate = [self.gueststate copy];
	copy.usid = [self.usid copy];

	return copy;
}
@end