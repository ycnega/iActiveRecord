//
//  ActiveRecord_Private.h
//  iActiveRecord
//
//  Created by Alex Denisov on 28.04.12.
//  Copyright (c) 2012 CoreInvader. All rights reserved.
//

#import "ActiveRecord.h"

@class ARColumn;

@interface ActiveRecord ()

{
@private
    BOOL isNew;
    NSMutableSet *errors;
}

@property (nonatomic, retain) NSMutableSet *updatedColumns;

#pragma mark - Validations Declaration

+ (void)validateUniquenessOfField:(NSString *)aField;
+ (void)validatePresenceOfField:(NSString *)aField;
+ (void)validateField:(NSString *)aField withValidator:(NSString *)aValidator;

- (void)resetErrors;

#pragma mark - SQLQueries

+ (const char *)sqlOnDeleteAll;
+ (const char *)sqlOnAddColumn:(NSString *)aColumn;
- (const char *)sqlOnDelete;
//- (const char *)sqlOnSave;
//- (const char *)sqlOnUpdate;

#pragma mark - ObserveChanges

- (void)didChangeField:(NSString *)aField;

#pragma mark - IgnoreFields

+ (void)initIgnoredFields;
+ (void)ignoreField:(NSString *)aField;

#pragma mark - TableName

+ (NSString *)recordName;
- (NSString *)recordName;

+ (NSArray *)tableFields;

#pragma mark - Relationships

#pragma mark BelongsTo

- (id)belongsTo:(NSString *)aClassName;
- (void)setRecord:(ActiveRecord *)aRecord belongsTo:(NSString *)aRelation;

#pragma mark HasMany

- (ARLazyFetcher *)hasManyRecords:(NSString *)aClassName;
- (void)addRecord:(ActiveRecord *)aRecord;
- (void)removeRecord:(ActiveRecord *)aRecord;

#pragma mark HasManyThrough

- (ARLazyFetcher *)hasMany:(NSString *)aClassName 
                   through:(NSString *)aRelationsipClassName;
- (void)addRecord:(ActiveRecord *)aRecord 
          ofClass:(NSString *)aClassname 
          through:(NSString *)aRelationshipClassName;
- (void)removeRecord:(ActiveRecord *)aRecord through:(NSString *)aClassName;

#pragma mark - register relationships

+ (void)registerRelationships;
+ (void)registerBelongs:(NSString *)aSelectorName;
+ (void)registerHasMany:(NSString *)aSelectorName;
+ (void)registerHasManyThrough:(NSString *)aSelectorName;

+ (NSArray *)relationships;
- (NSArray *)relationships;

#pragma mark - private before filter

- (void)privateAfterDestroy;

#pragma mark - New Logic

- (void)registerColumnObservers;
- (void)removeColumnObservers;

+ (NSArray *)columns;
- (NSArray *)columns;

+ (NSArray *)ignoredFields;

+ (ARColumn *)columnNamed:(NSString *)aColumnName;
- (ARColumn *)columnNamed:(NSString *)aColumnName;

@end
