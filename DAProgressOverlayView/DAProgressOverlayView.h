//
//  DAProgressOverlayView.h
//  DAProgressOverlayView
//
//  Created by Daria Kopaliani on 8/1/13.
//  Copyright (c) 2013 Daria Kopaliani. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef enum {
    DAProgressOverlayAnimationBegin,
    DAProgressOverlayAnimationFinish
} DAProgressOverlayAnimationType;

/**
 * View for displaying pie progress view like installing ios application
 */
@interface DAProgressOverlayView : UIView <CAAnimationDelegate>
@property (strong, nonatomic) UIColor *overlayColor;
@property (copy, nonatomic) void (^animationCompletionHandler)(DAProgressOverlayAnimationType type);
/**
 * The ratio of the inner circle to the minimum side of DAProgressOverlayView,
 * 0 ≤ innerRadiusRatio ≤ 1,
 * This is #000000 with alpha equal 0.5 by default.
 */
@property (assign, nonatomic) CGFloat innerRadiusRatio;

/**
 * The ratio of the outer circle to the minimum side of DAProgressOverlayView,
 * 0 ≤ outerRadiusRatio ≤ 1,
 * This is 0.7 by default.
 */
@property (assign, nonatomic) CGFloat outerRadiusRatio;

/**
  * The float value used to for calculate the `filled in` fraction of the inner circle,
  * 0 ≤ progress ≤ 1.
 */
@property (assign, nonatomic) CGFloat progress;

/**
 The duration for animations displayed after calling `displayOperationWillTriggerAnimation` method
 */
@property (readonly, nonatomic) CGFloat beginAnimationDuration;

/**
 The duration for animations displayed after calling `displayOperationDidFinishAnimation` method.
 */
@property (readonly, nonatomic) CGFloat finishAnimationDuration;

/**
 * This flag indicates wheter or not 'displayDownloadDidFinishAnimation' method is called when 'progress' property is set to 1.,
 * This is YES by default.
 */
@property (assign, nonatomic) BOOL triggersDownloadDidFinishAnimationAutomatically;

/**
 * Makes the outer faded out circle radius expand until it circumscribes the DAProgressOverlayView bounds
 */
- (void)displayOperationDidFinishAnimation;

/**
 * Changes radiuses of the inner and outer circles from zero to the corresponding values, calculated from 'innerRadiusRatio' and 'outerRadiusRatio' properties.
 */
- (void)displayOperationWillTriggerAnimation;

@end
