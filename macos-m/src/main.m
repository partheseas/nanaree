#import <Cocoa/Cocoa.h>
#import <Foundation/Foundation.h>

int main(int argc, const char* argv[]) {
	@autoreleasepool {
		NSLog(@"Starting app...");
		[NSApplication sharedApplication];

		id window = [[NSWindow alloc] initWithContentRect:NSMakeRect(0, 0, 400, 240)
												styleMask:NSWindowStyleMaskTitled
												  backing:NSBackingStoreBuffered
													defer:NO];

		[window cascadeTopLeftFromPoint:NSMakePoint(20, 20)];
		[window makeKeyAndOrderFront:nil];
		[window setTitle:@"McKayla"];

		[NSApp setActivationPolicy:NSApplicationActivationPolicyRegular];
		[NSApp activateIgnoringOtherApps:YES];
		[NSApp run];
	}

	return 0;
}
