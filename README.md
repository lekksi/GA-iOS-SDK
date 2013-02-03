#[Game Analytics REST API](https://beta.gameanalytics.com/docs/restful.html) wrapper for iOS


The Game Analytics API iOS Wrapper is designed to send game event data to the Game Analytics service for visualization. By collecting data from players playing your game you will be able to identify bugs and balance issues, track purchases, and determine how the players really play your game.

The code for the Game Analytics API iOS Wrapper is open source - feel free to create your own fork, or use the code to develop your own wrapper.

## Game Analytics Full Documentation

You can find the [full documentation](http://beta.gameanalytics.com/docs) on the Game Analytics website for wrappers, RESTful API, as well as information about how to collect useful data for your game.

## Game Analytics Website

The Game Analytics website can be found [here](http://beta.gameanalytics.com/).
To start using the iOS API Wrapper you will have to create an account on the website and add your game.


##Requirements

- iOS 5 or later
- ARC
- XCode 4.4 is required for auto-synthesis.

##Installation

1. Download latest version of Games Analytics iOS Wrapper binaries.
	The archive should contain these files:

	* `GameAnalytics.h`: The required header file containing methods for Games Analytics.
	* `libGameAnalytics.a`: The required static library for Games Analytics.
	
	Alternatively, you can use source code and build it yourself. 
	In case you already have the older version of the binaries, remove them from your project.

2. Click on your project's Frameworks > Add Files to "Your project name".

	![Add Files to](https://github.com/saleksandras/GA-iOS-Wrapper/raw/master/Screenshots/addfiles.png)
	
	Find and select the folder that contains the file named `libGameAnalytics.a`.
	The checkbox "Copy items into destination folder (if needed)" must be checked.
	Choose "Create groups for any added folders" and click Add.  
	
	![Select folder](https://github.com/saleksandras/GA-iOS-Wrapper/raw/master/Screenshots/selectfolder.png)
	
	The files `GameAnalytics.h` and `libGameAnalytics.a` should now be in your project.
	
	![Files added](https://github.com/saleksandras/GA-iOS-Wrapper/raw/master/Screenshots/filesadded.png)

3. Select your project, target and choose "Build Phases" tab.
	Expand the "Link Binary With Libraries" group and check if it contains `libGameAnalytic.a` library.
	
	![Link Binary With Libraries](https://github.com/saleksandras/GA-iOS-Wrapper/raw/master/Screenshots/linkbinary.png)
	
	In case it is not present there, drag and drop the library from your Project Navigator to the "Link Binary With Libraries" group.

4. In the "Link Binary With Libraries" group click the "+" to add new framework.
	Find the `SystemConfiguration.framework` in the list and click Add.
	
	![Add framework](https://github.com/saleksandras/GA-iOS-Wrapper/raw/master/Screenshots/addframework.png)
	
	`SystemConfiguration.framework` now should be listed under the "Link Binary With Libraries" group.
	
	![SystemConfiguration.framework](https://github.com/saleksandras/GA-iOS-Wrapper/raw/master/Screenshots/systemconfig.png)
	
	This is required for Reachability to manage network operations efficiently.

5. Select your project, target and choose "Build Settings" tab.
	Under "Linking" group click on "Other Linker Flags" and add `-ObjC` flag. 
	
	![ObjC flag](https://github.com/saleksandras/GA-iOS-Wrapper/raw/master/Screenshots/objc.png)


##Usage

Add the following line into your pre-compiled header file (`<projectname>_Prefix.pch`) 

    #import "GameAnalytics.h"

In your application delegate's `application:didFinishLaunchingWithOptions:` method, add the following line to set your Game keys and Secret keys:

    [GameAnalytics setGameKey:@"__CHANGE_ME__" secretKey:@"__CHANGE_ME__" build:@"__CHANGE_ME__"];

Go to the [Game Analytic](https://beta.gameanalytics.com) to register your Game keys and Secret keys.

There are four different types of events to log: user, design, business, quality.
Each of these categories have different purposes, accept different values, and have certain required fields. 
Check the [full documentation](http://beta.gameanalytics.com/docs) for more details. 
Add these method calls to your code to register every occurrence of the events.

###User data

Used to mark messages that are related to tracking demographic information about individual users (players). 
Log User data example:

    [GameAnalytics logUserDataWithParams:@{@"gender" : @"M", @"birth_year" : @1981, @"country" : @"LT", @"state" : @"VNO", @"friend_count" : @10}];

###Game design data

Used for messages related to tracking game design events, for example level completion time.
Log Game design data example:

    [GameAnalytics logGameDesignDataEvent:@"PickedUpAmmo:Shotgun" withParams:@{@"area" : @"Level 1", @"x" : @1.0f, @"y" : @1.0f, @"z" : @1.0f, @"value" : @1.0f}];

###Business data

Used to track business related events, such as purchases of virtual items.
Log Business data example:

    [GameAnalytics logBusinessDataEvent:@"PurchaseWeapon:Shotgun" withParams:@{@"area" : @"Level 1", @"x" : @1.0f, @"y" : @1.0f, @"z" : @1.0f, @"currency" : @"LTL", @"amount" : @1000 }];

###Quality Assurance data

Used for tracking events related to quality assurance, such as crashes, system specifications, etc.
Log Quality Assurance data example:

    [GameAnalytics logQualityAssuranceDataEvent:@"Exceptaion:NullReferenceException" withParams:@{ @"area" : @"Level 1", @"x" : @1.0f, @"y" : @1.0f, @"z" : @1.0f, @"message" : @"at Infragistics.Windows.Internal.TileManager.ItemRowColumnSizeInfo.."}];

###Update session ID

To update the session ID when you need to start a new session use the following method:     

    [GameAnalytics updateSessionID];
    
    
###Optional Settings

####Set custom user ID

Set custom user ID, if you don't want to use default OpenUDID.
The default setting for this method is NO.

	+ (void)setCustomUserID:(NSString *)udid;

####Enable debug logs to console

Enabling this option will cause the Game Analytics wrapper to print additional debug information, such as the status of each submit to the server.

	+ (void)setDebugLogEnabled:(BOOL)value;

####Archive data

If enabled data will be archived when an internet connection is not available.
The number of events to be archived is limited.
The next time an internet connection is available any archived data will be sent.
The default setting for this method is NO.

	+ (void)setArchiveDataEnabled:(BOOL)value;


##Todo

- Exception Handling support
- Finish tests
- Feedback GUI

## License

[MIT](http://opensource.org/licenses/MIT)