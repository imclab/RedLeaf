#include "ofMain.h"
#include "testApp.h"
#include "ofAppGlutWindow.h"

//========================================================================
int main( ){

    ofAppGlutWindow window;
//    window.setGlutDisplayString("double depth rgba samples>=8");
//	ofSetupOpenGL(&window, 1024+300,768, OF_WINDOW);			// <-------- setup the GL context
	ofSetupOpenGL(&window, 1440+1280,1024, OF_WINDOW);			// <-------- setup the GL context
	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp( new RedLeafApp());

}
