//
//  HttpEngine.h
//  SMProject
//
//  Created by shiliuhua on 17/3/16.
//  Copyright © 2017年 石榴花科技. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ProjectList.h"
#import "BasicsRootClass.h"
#import "GusetListRootClass.h"
#import "GuestInfoRootClass.h"

//POST
#define GetGuestBuyItemGidPost @"GetGuestBuyItemGidPost"
#define GetGuestInfoGidPost @"GetGuestInfoGidPost"
#define GetGuestListExpphonePost @"GetGuestListExpphonePost"
#define GetGuestListGidPost @"GetGuestListGidPost"
#define GetGuestListNamePost @"GetGuestListNamePost"
#define GetGuestPost @"GetGuestPost"
#define GetGuestSeviceGidPost @"GetGuestSeviceGidPost"
#define GetItemPost @"GetItemPost"
#define GetItemTypePost @"GetItemTypePost"
#define GetKzPost @"GetKzPost"
#define GetMembertPost @"GetMembertPost"
#define GetProductPost @"GetProductPost"
#define SetServerMapPost @"SetServerMapPost"
//GET
#define DelServerMap @"DelServerMap"
#define GetGuest @"GetGuest"
#define GetGuestBuyItemGid @"GetGuestBuyItemGid"
#define GetGuestInfoGid @"GetGuestInfoGid"
#define GetGuestListExpphone @"GetGuestListExpphone"
#define GetGuestListGid @"GetGuestListGid"
#define GetGuestListName @"GetGuestListName"
#define GetGuestSeviceGid @"GetGuestSeviceGid"
#define GetItem @"GetItem"
#define GetItemType @"GetItemType"
#define GetKz @"GetKz"
#define GetMembert @"GetMembert"
#define GetProduct @"GetProduct"
#define SetServerMap @"SetServerMap"



@interface HttpEngine : NSObject
//得到项目列表
+ (void)getProjectList:(NSString *)gid complete:(void (^) (NSMutableArray *tempArray))complete;
//根据会员号上传首次服务小票
+ (void)uploadSmlTicketOfFirstSer:(NSString *)serNum upImageState:(int)upImageState setDelegateVC:(UIViewController *)DelegateVC complete:(void (^) (NSString *str))complete;
//得到首次服务小票list
+ (void)getFirstSerTicketList:(NSString *)serNum complete:(void (^) (NSMutableArray *tempArray))complete;
//得到服务记录list（新）
+ (void)getSerRecordListNew:(NSString *)serNum complete:(void (^) (NSMutableArray *tempArray))complete;
//得到项目列表新
+ (void)getProjectListNew:(NSString *)serNum complete:(void (^) (NSMutableArray *tempArray))complete;
//上传项目服务前的图片
+ (void)uploadProductSerPhoto:(NSString *)serNum proId:(NSString *)proId proName:(NSString *)proName proStyleName:(NSString *)proStyleName proBuyArea:(NSString *)proBuyArea proTime:(NSString *)proTime setDelegateVC:(UIViewController *)DelegateVC complete:(void (^) (NSString *errorCode,NSString *msg))complete;
//获取项目服务前的图片列表
+ (void)getProSerBeforePhotoList:(NSString *)serNum proId:(NSString *)proId complete:(void (^) (NSMutableArray *tempArray))complete;

//json
+ (void)requestJsonWithReqStr:(NSString *)reqStr withComplete:(void (^) (NSDictionary *responseObj))complete dic:(NSDictionary *)dic;
//post
+ (void)requestPostWithReqStr:(NSString *)reqStr withComplete:(void (^) (NSDictionary *responseObj))complete dic:(NSDictionary *)dic;
//GET
+ (void)requestGETWithReqStr:(NSString *)reqStr withComplete:(void (^) (NSDictionary *responseObj))complete dic:(NSDictionary *)dic;

@end
