//
//  AppDelegate.h
//  Feedback
//
//  Created by Javen on 15/4/24.
//  Copyright (c) 2015 HEXG. All rights reserved.
//


#import <UIKit/UIKit.h>
#import <CoreData/CoreData.h>

#import "JMFBConfig.h"


@interface AppDelegate : UIResponder <UIApplicationDelegate>

@property (strong, nonatomic) UIWindow *window;

@property (readonly, strong, nonatomic) NSManagedObjectContext *managedObjectContext;
@property (readonly, strong, nonatomic) NSManagedObjectModel *managedObjectModel;
@property (readonly, strong, nonatomic) NSPersistentStoreCoordinator *persistentStoreCoordinator;

- (void)saveContext;
- (NSURL *)applicationDocumentsDirectory;


@end
