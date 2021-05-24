//
//  CustomerController.m
//  SMProject
//
//  Created by arvin yan on 10/29/14.
//  Copyright (c) 2014 石榴花科技. All rights reserved.
//

#import "CustomerController.h"
#import "CustomerCell.h"
#import "CustomerTitleCell.h"
#import "XMLmanage.h"
#import "MemberController.h"
#import "ASIFormDataRequest.h"
#import "Reachability.h"
@interface CustomerController ()
{
    NSMutableArray *_tempArray;
}
@end

@implementation CustomerController
@synthesize customerTableView = customerTableView_;
@synthesize array = array_;

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    _tempArray = [NSMutableArray arrayWithCapacity:0];
    // Do any additional setup after loading the view from its nib.
#warning 客户状态01.空账户；02.正常账户；03.余零账户；04.冻结账户；05.新客账户
    for (int i = 0; i<self.array.count; i++) {
        GusetListData * customer = [self.array objectAtIndex:i];
        if (([customer.gueststate integerValue] == 2 || [customer.gueststate integerValue] == 3) && [customer.usid isEqualToString:[self getStoresID]]) {
            [_tempArray addObject:customer];
        }
    }
    
}
- (NSString *)getStoresID
{
    NSUserDefaults *prefs = [NSUserDefaults standardUserDefaults];
    NSString * uName = [prefs objectForKey:@"name"];
    NSLog(@"storeId=%@",uName);
    return uName;
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
    return 1;
}

// Customize the number of rows in the table view.
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
	return [_tempArray count] + 1;
}

// Customize the appearance of table view cells.
- (UITableViewCell *)tableView:(UITableView *)tableView
		 cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    static NSString * ID = @"mycell";
    static NSString * ident = @"titlecell";
    
    if (indexPath.row == 0) {
		CustomerTitleCell *cell = (CustomerTitleCell *)[tableView dequeueReusableCellWithIdentifier:ident];
		if (cell == nil) {
			NSArray * nib = [[NSBundle mainBundle] loadNibNamed:@"CustomerTitleCell" owner:self options:nil];
			for (id oneObject in nib) {
				if ([oneObject isKindOfClass:[CustomerTitleCell class]]) {
					cell = (CustomerTitleCell *)oneObject;
				}
			}
		}
        cell.selectionStyle = UITableViewCellSelectionStyleNone;
     
        return cell;
    }
    

    CustomerCell *custom = (CustomerCell *)[tableView dequeueReusableCellWithIdentifier:ID];
    if (custom == nil)
    {
        NSArray * nib = [[NSBundle mainBundle] loadNibNamed:@"CustomerCell" owner:self options:nil];
        for (id oneObject in nib)
        {
            if ([oneObject isKindOfClass:[CustomerCell class]])
            {
                custom = (CustomerCell *)oneObject;
            }
        }
    }
    GusetListData * customer = [_tempArray objectAtIndex:indexPath.row - 1];
    custom.cardLab.text = customer.gid;
    custom.nameLab.text = customer.gname;
    custom.phoneNumLabel.text = customer.gexpphone;
    custom.selectionStyle = UITableViewCellSelectionStyleBlue;
//    custom.accessoryType = UITableViewCellAccessoryDisclosureIndicator;
    //if ([order.type isEqualToString:@"7"])
    //{
    
    return custom;
}
-(BOOL) isConnectionAvailable{
    
    BOOL isExistenceNetwork = YES;
    Reachability *reach = [Reachability reachabilityWithHostName:@"www.apple.com"];
    switch ([reach currentReachabilityStatus]) {
        case NotReachable:
            isExistenceNetwork = NO;
            //NSLog(@"notReachable");
            break;
        case ReachableViaWiFi:
            isExistenceNetwork = YES;
            //NSLog(@"WIFI");
            break;
        case ReachableViaWWAN:
            isExistenceNetwork = YES;
            //NSLog(@"3G");
            break;
    }
    
    if (!isExistenceNetwork) {
        UIAlertView *alert=[[UIAlertView alloc] initWithTitle:@"提示" message:@"网络不通畅，请检查网络" delegate:self cancelButtonTitle:@"确定" otherButtonTitles:nil, nil];
        [alert show];
        return NO;
    }
    
    return isExistenceNetwork;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
   // int section = indexPath.section;
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
    if (indexPath.row == 0)
    {
        
    }
    else
    {
        if ([self isConnectionAvailable] == NO) {
            
        }else{
            GusetListData * customer = [_tempArray objectAtIndex:indexPath.row -1];
            MemberController * member  = [[MemberController alloc] init];
            member.query = customer.gid;
            member.phoneNum = customer.gexpphone;
            member.cardState=customer.gueststate;
            if (customer.gid!=nil) {
                [self.navigationController pushViewController:member animated:YES];
            }
        }
    
    }
}

- (IBAction)back:(id)sender
{
    [self.delegate changeText];
    [self.navigationController popViewControllerAnimated:YES];
}

@end
