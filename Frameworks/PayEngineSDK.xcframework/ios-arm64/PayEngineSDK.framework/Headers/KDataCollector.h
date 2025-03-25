//
//  KDataCollector.h
//  Kount Data Collector SDK
//
//  Copyright © 2016 Kount Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN



// Configuration settings for location collection
typedef NS_ENUM(NSInteger, KLocationCollectorConfig) {
    
    // Request permission if not currently authorized (default)
    KLocationCollectorConfigRequestPermission = 0, 
    
    // Only collect if app already has location permissions
    // (use in cases where requesting permission is done by the app itself)
    KLocationCollectorConfigPassive,           
    
    // Skip location collection
    KLocationCollectorConfigSkip,          
};


// Configuration settings Kount collection environment
typedef NS_ENUM(NSInteger, KEnvironment) {
    
    // Unknown Environment
    KEnvironmentUnknown = 0,
    
    // Test Environment
    KEnvironmentTest,
    
    // Production Environment
    KEnvironmentProduction,
};



// KDataCollector enables you to collect device information for the given session
//
// First, configure the collector during the initialization of your application
// Second, call collectForSession when you start the payment checkout process
//
@interface KDataCollector : NSObject

// Get the shared instance of the Data Collector
+ (KDataCollector *)sharedCollector;

//
// Configuration
//

// The Kount Merchant ID
@property NSInteger merchantID;
// The configuration of the location collector to determine if and how it goes about collection location
@property KLocationCollectorConfig locationCollectorConfig;
// Debug logging to the console
@property BOOL debug;
// Timeout in MS for the collection
@property NSInteger timeoutInMS;
// The Kount environment
@property KEnvironment environment;
// Device Data Sending to Analytics SDK
@property NSDictionary *deviceDataForAnalytics;

//
// Collection
//

// Collect data for the session.
//
// @param sessionID A unique session ID that should match the sessionID for the payment transaction
// @param completionBlock This completion block will be called when the collection has completed or an error occurs.
- (void)collectForSession:(NSString *)sessionID completion:(nullable void (^)(NSString *_Nonnull sessionID, BOOL success, NSError *_Nullable error))completionBlock;

NS_ASSUME_NONNULL_END

@end


