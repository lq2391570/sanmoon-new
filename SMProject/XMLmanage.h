//
//  XMLmanage.h
//  SMProject
//
//  Created by 石榴花科技 on 14-7-9.
//  Copyright (c) 2014年 石榴花科技. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GDataXMLNode.h"
#import "ImageModelBaseClass.h"



#define GETITEMTPROMOTION [NSString stringWithFormat:@"%@GetData.asmx/GetItemtPromotion?",RIP]
#define GETUSERINFON [NSString stringWithFormat:@"%@GetData.asmx/VerGuest?",RIP]
#define GETPRODUCTROMOTION [NSString stringWithFormat:@"%@GetData.asmx/GetProductPromotion?",RIP]
#define EMPURL [NSString stringWithFormat:@"%@GetData.asmx/GetSaleEmp?",RIP]
#define ADVURL [NSString stringWithFormat:@"%@GetData.asmx/GetAdvance?",RIP]
#define SaleURL [NSString stringWithFormat:@"%@GetData.asmx/SaleProduct?",RIP]
#define QueryID [NSString stringWithFormat:@"%@GetData.asmx/GetGuestListCid?",RIP]
//根据手机号获取客户信息列表
#define QueryPhoneNum [NSString stringWithFormat:@"%@GetData.asmx/GetGuestListExpphone?",RIP]

#define QueryNumber [NSString stringWithFormat:@"%@GetData.asmx/GetGuestInfoCid?",RIP]
#define QueryService [NSString stringWithFormat:@"%@GetData.asmx/GetGuestSeviceCid?",RIP]
#define QueryName [NSString stringWithFormat:@"%@GetData.asmx/GetGuestListName?",RIP]

#define QueryServiceImage [NSString stringWithFormat:@"%@memberarchive_findMemberArchiveForNumberToIpad?",LocationIp]

#define QueryUserImage [NSString stringWithFormat:@"%@memberinfo_findMemberInfoForMemberCardToIpad?",LocationIp]
#define QueryBodyDescription [NSString stringWithFormat:@"%@findBodyCareProjectToIpad?",LocationIp]
#define QueryCustomerSrc [NSString stringWithFormat:@"%@GetData.asmx/Getxkly?",RIP]
#define QueryPeople [NSString stringWithFormat:@"%@GetData.asmx/Getkfzy?",RIP]

@interface Information : NSObject
{
   
}
@property (nonatomic , strong) NSString * name;
@property (nonatomic , strong) NSString * price;
@property (nonatomic , strong) NSString * rate;
@property (nonatomic , strong) NSString * ID;
@property (nonatomic, strong) NSArray * produceDate;
@property (nonatomic, strong) NSString * times;
@property (nonatomic, strong) NSString * skpmount;

- (Information *)init;
@end

@interface CustomerSrc : NSObject

@property (nonatomic , retain) NSString * tname;
@property (nonatomic , retain) NSString * tkey;

- (CustomerSrc *)init;
@end

@interface CustomersQuery : NSObject

@property (nonatomic , strong) NSString * cardstate;
@property (nonatomic , strong) NSString * cid;
@property (nonatomic , strong) NSString * gsname;
@property (nonatomic , strong) NSString * usid;
@property (nonatomic,strong)NSString * gexpphone;


- (CustomersQuery *)init;

@end

@interface CustomersInfo : NSObject

@property (nonatomic , strong) NSString * gid;
@property (nonatomic , strong) NSString * dabh;
@property (nonatomic , strong) NSString * jdsj;
@property (nonatomic , strong) NSString * gname;
@property (nonatomic , strong) NSString * gfancy;
@property (nonatomic, strong) NSString * lasttime;
@property (nonatomic, strong) NSString * sfgm;
@property (nonatomic, strong) NSString * grequest;


- (CustomersInfo *)init;
@end

@interface ServiceInfo : NSObject

@property (nonatomic , strong) NSString * fwsj;

@property (nonatomic , strong) NSString * gsnumber;
@property (nonatomic , strong) NSString * iname;
@property (nonatomic , strong) NSString * sename;
@property (nonatomic , strong) NSString * uname;

@property (nonatomic , strong) NSString * cardNo;
@property (nonatomic , strong) NSString * cardState;




- (ServiceInfo *)init;
@end

@interface ServicePhotoInfo : NSObject

@property (nonatomic , weak) NSString * archiveImageUrl;
@property (nonatomic , weak) NSString * archiveState;

- (ServicePhotoInfo *)init;
@end


@interface PayInfo : NSObject

@property (nonatomic , weak) NSString * usid;
@property (nonatomic , weak) NSString * umid;
@property (nonatomic , weak) NSString * cid;
@property (nonatomic , weak) NSString * seid;
@property (nonatomic , weak) NSString * seid2;
@property (nonatomic , weak) NSString * seid3;
@property (nonatomic , weak) NSString * semoney2;
@property (nonatomic , weak) NSString * semoney3;
@property (nonatomic , weak) NSString * zje;
@property (nonatomic , weak) NSString * yfkje;
@property (nonatomic , weak) NSString * ssje;
@property (nonatomic , weak) NSString * stkje;
@property (nonatomic , weak) NSString * qtje;
@property (nonatomic , weak) NSString * xjje;
@property (nonatomic , weak) NSString * yhkje;
@property (nonatomic , weak) NSString * zlje;


- (PayInfo *)init;
@end


@interface XMLmanage : NSObject
{
    NSArray *_array;
    NSMutableArray *_tempArray;
}
@property (nonatomic,strong)NSArray *array;
+ (id)shardSingleton;
- (Information *)analysisXMLWithID:(NSString *)ID withtype:(int)type;
- (NSString *)CheckUserInfonWithCid:(NSString *)cid withPassWord:(NSString *)Password;
- (NSArray *)getSalers:(NSString *)no withUsername:(NSString *)username withPwd:(NSString *)pwd;
- (NSString *)getAdvance:(NSString *)no withUsername:(NSString *)username withPwd:(NSString *)pwd;
- (Information *)analysisXMLWithID:(NSString *)ID withUSID:(NSString *)usid withtype:(int)type;
- (NSString *)submitPayment:(NSString *)pay;
//店内查询
- (NSArray *)getGuestInfoWithPhone:(NSString *)no withUsername:(NSString *)username withPwd:(NSString *)pwd;

- (NSArray *)getGuestInfo:(NSString *)no withUsername:(NSString *)username withPwd:(NSString *)pwd;
//- (NSArray *)getGSNumber:(NSString *)no withUsername:(NSString *)username withPwd:(NSString *)pwd;
- (NSArray *)getService:(NSString *)no withUsername:(NSString *)username withPwd:(NSString *)pwd;

//- (NSMutableArray *)getGuestInfoWithName:(NSString *)name withUsername:(NSString *)username withPwd:(NSString *)pwd;
//精确查询接口
- (NSMutableArray *)getGuestInfoWithName2:(NSString *)name withUsername:(NSString *)username withPwd:(NSString *)pwd cardNum:(NSString *)cardNum;
- (NSMutableArray *)getGuestInfoWithNamePhone2:(NSString *)name withUsername:(NSString *)username withPwd:(NSString *)pwd cardNum:(NSString *)cardNum;
- (NSArray *)getServiceImage:(NSString *)serviceID;
- (NSString *)getUserImage:(NSString *)ID;
- (NSString *)getBodyDescription:(NSString *)ID;
- (NSDictionary *)getBodySummary:(NSString *)ID;
- (NSMutableArray *)getCustomerSrc;
- (NSMutableArray *)getPeopleWithCID:(NSString *)cid;
- (NSString *)getBodyDescription:(NSString *)ID withColor:(NSString *)color;
- (NSDictionary *)getBodySummary:(NSString *)ID withColor:(NSString *)color;
//xiaotu
+ (void)xiaotu:(void (^)(NSMutableArray *array))complete gusNum:(NSString *)gusNum;

- (void)getGuestInfoWithName:(NSString *)name withUsername:(NSString *)username withPwd:(NSString *)pwd withCompleteBlock:(void (^) (GusetListRootClass *bassClass))completeBlock;
- (void)getGSNumber:(NSString *)no withUsername:(NSString *)username withPwd:(NSString *)pwd withCompleteBlock:(void (^) (GuestInfoRootClass *bassClass))completeBlock;
- (void)getGuestInfo:(NSString *)no withUsername:(NSString *)username withPwd:(NSString *)pwd withCompleteBlock:(void (^) (GusetListRootClass *bassClass))completeBlock;
- (void)getGuestInfoWithPhone:(NSString *)no withUsername:(NSString *)username withPwd:(NSString *)pwd withCompleteBlock:(void (^) (GusetListRootClass *bassClass))completeBlock;
- (void)getGuestInfoWithNamePhone2:(NSString *)name withUsername:(NSString *)username withPwd:(NSString *)pwd cardNum:(NSString *)cardNum withCompleteBlock:(void (^) (GusetListRootClass *bassClass))completeBlock;
- (void)getGuestInfoWithName2:(NSString *)name withUsername:(NSString *)username withPwd:(NSString *)pwd cardNum:(NSString *)cardNum withCompleteBlock:(void (^) (GusetListRootClass *bassClass))completeBlock;
@end
