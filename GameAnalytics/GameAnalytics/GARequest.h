//
//  GARequest.h
//  GameAnalytics
//
//  Created by Aleksandras Smirnovas on 2/4/13.
//  Copyright (c) 2013 Aleksandras Smirnovas. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "GARequestDelegate.h"

typedef enum : NSInteger
{
    GAErrorBadRequest = 400,//Bad Request/Game not found/Data not found
    GAErrorUnauthorized = 401,//Unauthorized/Signature not found in request
    GAErrorForbidden = 403,
    GAErrorGameKeyNotFound = 404,//Game key not found/Method not found
    GAErrorInternalServerError = 500,
    GAErrorNotImplemented = 501
} GAError;

typedef enum : NSInteger
{
    GARequestStatusNotStarted = 0,
    GARequestStatusStarted,
    GARequestStatusCompleted,
    GARequestStatusFailed,
    GARequestStatusCancelled
} GARequestStatus;


@interface GARequest : NSObject <NSURLConnectionDelegate, NSURLConnectionDataDelegate, NSCoding, NSCopying>

@property (weak, nonatomic) id<GARequestDelegate> delegate;

-(id)initWithURLRequest:(NSURLRequest *)urlRequest;

-(BOOL)isFinished;

-(void)start;

-(void)cancel;

@end