//
//  InviteReferrals.h
//  InviteReferrals
//
//  Created by Tagnpin Web Solutions LLP Macbook Air-3 on 23/03/22.
//  Copyright © 2022 Tagnpin Web Solutions LLP. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void(^campaignCompletion)(NSDictionary*);
typedef void(^trackingCompletionHandler)(NSMutableDictionary *);
typedef void(^referringParams)(NSDictionary*);
typedef void(^getReferrerCodeCompletionHandler)(NSString *);
typedef void(^sharingDetails)(NSDictionary*);


@protocol InviteReferralsDelegate <NSObject>
@optional
-(void)InviteReferralsTrackingFinishedforEventInfo: (NSDictionary *)trackingResponse;
-(void)InviteReferralsOnSharingIconClickCallback:(NSDictionary *)sharingIconClickInfo;
-(void)InviteReferralsLeadSentResponseCallback:(NSDictionary *)sentLeadResponse;

-(void)InviteReferralsOnDoneButtonActionWithUserInfo:(NSDictionary *)userInfo;
@end

@interface IRCampaignInfo : NSObject
@property (nonatomic, assign)NSInteger campaignID;
@property (nonatomic, assign)NSInteger templateID;
@end

@interface IRUserInfo : NSObject
@property (nonatomic, strong)NSString *name;
@property (nonatomic, strong)NSString *email;
@property (nonatomic, strong)NSString *mobileNo;
@property (nonatomic, strong)NSString *subscriptionID;
@property (nonatomic, strong)NSString *customValueOne;
@property (nonatomic, strong)NSString *customValueTwo;
@end

@interface IREventInfo : NSObject
@property (nonatomic, strong)NSString *eventName;
@property (nonatomic, strong)NSString *orderID;
@property (nonatomic, assign)double purchaseValue;
@property (nonatomic, strong)NSString *referrerCode;
@property (nonatomic, strong)NSString *uniqueCode;
@property (nonatomic, strong)NSString *orderCustomValue;
@end


@interface InviteReferrals : NSObject

@property (nonatomic, weak)id <InviteReferralsDelegate> delegate;
+(instancetype)sharedInstance;

#pragma mark - INITIAL INTEGRATION METHODS

/* Initialise the SDK using setupWithBrandId() function   */
-(void)setupWithBrandId:(NSInteger)brandId encryptedKey:(NSString *)encryptedKey;

/* Deeplinking Delegate Function   */
-(void)openUrlWithUrl:(NSURL *)url;

/*App-Universal-Link Delegate Function */
-(void)continueUserActivityWith:(NSUserActivity*)userActivity;


#pragma mark - USER DETAILS AND CAMPAIGN METHODS

/*UserDetails Function */

-(void)campaign:(IRCampaignInfo*)campaignInfo userInfo:(IRUserInfo *)userInfo campaignCompletion:(campaignCompletion)completionHandler;

-(void)campaignPopupForRuleName:(NSString *)ruleName campaignInfo:(IRCampaignInfo*)campaignInfo userInfo:(IRUserInfo *)userInfo;

-(void)trackingforEventInfo:(IREventInfo*)eventInfo userInfo:(IRUserInfo *)userInfo;

-(void)getSharingDetailsWithCampaignInfo:(IRCampaignInfo*)campaignInfo userInfo:(IRUserInfo *)userInfo sharingData:(sharingDetails)irSharingDetails;
-(void)trackInviteWithSourceName:(NSString *)sourceName campaignID:(NSInteger)campaignID;

#pragma mark - OTHER USEFUL METHODS

-(void)showWelcomeMessage;
-(void)getReferrerCode:(getReferrerCodeCompletionHandler)referrerCode;
-(void)getReferringParams:(referringParams)referringParameters;
-(void)setLocalizationLanguage:(NSString *)irLanguageCode;
-(void)logout;

@end
