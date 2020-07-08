//
//  Created by Siddharth Gupta
//
//
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <Security/Security.h>
typedef void(^SharingDetails)(NSMutableDictionary* _Nullable);
typedef void(^TrackingCompletionHandler)(NSMutableDictionary *_Nullable);
typedef void(^getReferrerCodeCompletionHandler)(NSString *_Nullable);

@protocol InviteReferralsDelegate <NSObject>
@optional
-(void)HandleDoneButtonActionWithUserInfo:(NSMutableDictionary *_Nullable)userInfo;
@end


@interface InviteReferrals : NSObject
//@property (nonatomic, strong)id <InviteReferralsDelegate> _Nullable irDelegate;

+ (void)setupWithBrandId: (int) brandId encryptedKey: (NSString * _Nonnull) encryptedKey;
+ (void) setupUserID:(NSString*_Nullable)email mobile:(NSString*_Nullable)mobile name:(NSString*_Nullable)name gender:(NSString*_Nullable)gender shareLink:(NSString*_Nullable)shareLink shareTitle:(NSString*_Nullable)shareTitle shareDesc:(NSString*_Nullable)shareDesc shareImg:(NSString*_Nullable)shareImg customValue:(NSString*_Nullable)customValue campaignID:(NSString*_Nullable)campaignID flag:(NSString *_Nullable)flag SubscriptionID:(NSString *_Nullable)subscriptionID;

+ (void) launch:(NSString*_Nullable)campaignID Email:(NSString*_Nullable)email mobile:(NSString*_Nullable)mobile name:(NSString*_Nullable)name SubscriptionID:(NSString *_Nullable)subscriptionID;

+ (void) showSharePopup:(NSString*_Nullable)page Email:(NSString*_Nullable)email mobile:(NSString*_Nullable)mobile name:(NSString*_Nullable)name SubscriptionID:(NSString *_Nullable)subscriptionID;

+ (void) welcomeMessage;


+ (void)tracking:(NSString*_Nullable)eventName orderID:(NSString*_Nullable)orderID purchaseValue:(NSString*_Nullable)purchaseValue email:(NSString *_Nullable)email mobile:(NSString *_Nullable)mobile name:(NSString *_Nullable)name referCode:(NSString *_Nullable)ReferCode uniqueCode:(NSString *_Nullable)unique_code isDebugMode:(BOOL)debugMode ComplitionHandler:(TrackingCompletionHandler _Nullable)complitionHandler;

//+(void)application:(UIApplication *_Nullable)application openURL:(NSURL *_Nullable)url sourceApplication:(NSString *_Nullable)sourceApplication annotation:(id   _Nullable )annotation;

+(void)OpenUrlWithApplication:(UIApplication *_Nullable)application Url:(NSURL *_Nullable)url;
+(void)getReferrerCode:(getReferrerCodeCompletionHandler _Nullable)referrerCode;

+(void)GetShareDataWithCampaignID:(NSString *_Nullable)campaignID Email:(NSString *_Nullable)email mobile:(NSString *_Nullable)mobile name:(NSString*_Nullable)name  SubscriptionID:(NSString *_Nullable)irSubscriptionID ShowErrorAlerts:(BOOL)irShowAlerts ShowActivityIndicatorViewWhileLoading:(BOOL)irShowActivityIndicator SharingDetails:(SharingDetails _Nullable)irSharingDetails;

+(void)setDelegate:(id _Nullable)aDelegate;
+(void)sendDataToDelegate:(NSMutableDictionary *_Nullable)userInfo;

+(void)continueUserActivityWith:(NSUserActivity *_Nullable)userActivity;
+(void)setLocalizationLanguage:(NSString *_Nullable)irLanguageCode;
//(void(^_Nullable)(NSArray<id<UIUserActivityRestoring>> * __nullable restorableObjects))restorationHandler;

+(void)setDefaultNavigationController:(UINavigationController *_Nullable)navController BarStyle:(UIBarStyle)navBarStyle PreferedStatusBarStyleLightContent:(BOOL)navCustomStatusBarStyleLightContent BarSetTranslucent:(BOOL)navSetBarTranslucent BarLoginScreenTitle:(NSString *_Nullable)navBarLoginScreenTitle BarShareScreenTitle:(NSString *_Nullable)navBarShareScreenTitle BarTitleTextAttributes:(NSDictionary<NSAttributedStringKey,id> * _Nullable)navBarTitleTextAttributes BarTitleColor:(NSString *_Nullable)navBarTitleColor BarBackground:(NSString *_Nullable)navBarBackground BarButtonPosition:(NSString *_Nullable)navBarButtonPosition BarButtonTitle:(NSString *_Nullable)navBarButtonTitle BarTextFontName:(NSString *_Nullable)navBarTextFontName BarTitleFontSize:(float)navBarTitleFontSize BarButtonTextAttributes:(NSDictionary<NSAttributedStringKey,id> * _Nullable)navBarButtonTextAttributes BarButtonFontSize:(float)navBarButtonFontSize BarButtonIconWidth:(float)navBarButtonIconWidth BarButtonIconHeight:(float)navBarButtonIconHeight BarButtonTintColor:(NSString *_Nullable)navBarButtonTintColor;

@end
