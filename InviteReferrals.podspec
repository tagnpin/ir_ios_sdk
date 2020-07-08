#
# Be sure to run `pod lib lint InviteReferrals.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'InviteReferrals'
  s.version          = '4.4.0.1'
  s.summary          = 'InviteReferrals is best referral software for mobile application'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
InviteReferrals is a powerful and yet simple to integrate referral software that helps to grow your business and acquire new customers through Referral Marketing. It is the simplest software to run customer referral program campaigns. We let customers become the Brand Ambassadors
                       DESC

  s.homepage         = 'https://github.com/tagnpin/ir_ios_sdk'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'Mohammad Ashraf Ali' => 'ashraf@notifyvisitors.com' }
  s.source           = { :git => 'https://github.com/tagnpin/ir_ios_sdk.git', :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.platform = :ios
  s.ios.deployment_target = '8.0'
  s.source_files = 'InviteReferrals/Classes/**/*.h'
  s.resources = ['InviteReferrals/Assets/**/*.png', 'InviteReferrals/Classes/IR_UserResources.plist']
  s.frameworks = 'Foundation', 'UIKit', 'Security', 'Social', 'MessageUI'
  s.vendored_library = 'InviteReferrals/Classes/**/*.a'
  s.pod_target_xcconfig = { 'OTHER_LDFLAGS' => '-lObjC' }
end
