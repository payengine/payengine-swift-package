//
//  KountPrivate.h
//  PayEngineSDK
//
//  Created by Saim Irfan on 17/02/2025.
//

#ifndef KountPrivate_h
#define KountPrivate_h

extern NSString *const KDataCollectorErrorDomain;

// Version of the Kount Data Collector SDK
extern NSString *const KDataCollectorVersion;

// Error Codes
typedef NS_ENUM(NSInteger, KDataCollectorErrorCode) {
    
    KDataCollectorErrorCodeUnknown = 0,
    
    // A system error occurred
    KDataCollectorErrorCodeNSError,
    
    // A required collector timed out
    KDataCollectorErrorCodeTimeout,
    
    // A bad parameter was passed into the data collector
    KDataCollectorErrorCodeBadParameter,
    
    // A network connection isn't available
    KDataCollectorErrorCodeNoNetwork,
    
    // An error occurred while validating a response from the server
    KDataCollectorErrorCodeResponseValidation,
};


// DMD-352: Device Collection Status
typedef NS_ENUM(NSInteger, KDataCollectorStatus) {
    
    // A device data collection not started
    KDataCollectorStatusNotStarted = 0,
    
    // A device data collection started
    KDataCollectorStatusStarted,
    
    // A device data collection completed successfully
    KDataCollectorStatusCompleted,
    
    // A device data collection failed with error
    KDataCollectorStatusFailedWithError,
    
    // A device data collection failed without error
    KDataCollectorStatusFailedWithOutError,
    
};




#endif /* KountPrivate_h */
