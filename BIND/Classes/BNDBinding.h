//
//  BNDBinding.h
//  BIND
//
//  Created by Marko Hlebar on 27/10/2014.
//  Copyright (c) 2014 Marko Hlebar. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, BNDBindingInitialAssignment) {
    /**
     *  -> initial value is assigned from object to otherObject
     */
    BNDBindingInitialAssignmentLeftToRight = 0,
    
    /**
     *  <- initial value is assigned from otherObject to object
     */
    BNDBindingInitialAssignmentRightToLeft = 1,
    
    /**
     *  <> initial value is not assigned
     */
    BNDBindingInitialAssignmentNone = 2,
};

typedef NS_ENUM(NSInteger, BNDBindingTransformDirection) {
    /**
     *  Transform direction is executed from object to otherObject.
     */
    BNDBindingTransformDirectionLeftToRight = 0,
    
    /**
     *  Transform direction is executed from otherObject to object.
     */
    BNDBindingTransformDirectionRightToLeft = 1,
};

@interface BNDBinding : NSObject

/**
 *  BIND is a special syntax to bind values at keyPath for an object
 *  to another object's value at keyPath.
 *  The syntax is objectKeyPath->otherObjectKeyPath|MHFloatToStringTransformer
 *  where MHFloatToStringTransformer is the optional NSValueTransformer subclass you want to use,
 *  objectKeyPath is the keyPath of bound object, otherObjectKeyPath is the key path of other bound object.
 */
@property (nonatomic, copy) NSString *BIND;

/**
 *  Initial assignment determines which value is assigned as initial value.
 *  You can set the initial assignment value by using BIND initial assignment modifiers:
 *  -> initial value is assigned from object to otherObject
 *  <- initial value is assigned from otherObject to object
 *  <> initial value is not assigned
 *
 */
@property (nonatomic, readonly) BNDBindingInitialAssignment initialAssignment;

/**
 *  Transform direction determines in which way the transform is executed.
 *  You can change the direction of the transform using the BIND syntax ! modifier before declaring
 *  the Transformer class i.e. 
 *  keyPath <- otherKeyPath | !Transformer
 *  
 *  @default BNDBindingTransformDirectionLeftToRight
 */
@property (nonatomic, readonly) BNDBindingTransformDirection transformDirection;

/**
 *  A bound object.
 */
@property (nonatomic, weak, readonly) id leftObject;

/**
 *  An object's keyPath.
 */
@property (nonatomic, readonly) NSString *leftKeyPath;

/**
 *  Other bound object.
 */
@property (nonatomic, weak, readonly) id rightObject;

/**
 *  An other bound object's keyPath.
 */
@property (nonatomic, readonly) NSString *rightKeyPath;

/**
 *  Value transfromer for transforming values coming from object to other object and reverse.
 *  Transforms are executed as follows;
 *  When object assigns value to otherObject, transformValue: is called.
 *  When otherObject assigns value to object, reverseTransformValue: is called.
 */
@property (nonatomic, readonly) NSValueTransformer *valueTransformer;

/**
 *  Builds a binding using BIND syntax.
 *
 *  @param BIND a BIND expression
 *
 *  @return a binding.
 */
+ (BNDBinding *)bindingWithBIND:(NSString *)BIND;

/**
 *  Binds the left object in BIND expression with the right object.
 *  This removes all previous bindings on previously set objects,
 *  and builds bindings for keyPaths with new objects.
 *  This is useful in situations where you want to reuse the binding,
 *  and just update the objects being bound i.e. on UITableViewCell reuse.
 *
 *  @param leftObject  left object in the bind expression
 *  @param rightObject right object in the bind expression
 */
- (void)bindLeft:(id)leftObject
       withRight:(id)rightObject;

/**
 *  Removes all bindings and references to leftObject and rightObject.
 */
- (void)unbind;

@end
