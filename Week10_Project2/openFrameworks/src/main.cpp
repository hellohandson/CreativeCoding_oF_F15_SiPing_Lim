#include "ofMain.h"
#include "ofApp.h"

#include "ofAppGlutWindow.h"

//========================================================================
int main( ){
    ofAppGlutWindow window;
    //window.setGlutDisplayString("rgba double samples>=4");
    window.setGlutDisplayString("rgba double samples>=4 depth");
	ofSetupOpenGL(1280,720,OF_FULLSCREEN);
	// can be OF_WINDOW or OF_FULLSCREEN
	ofRunApp(new ofApp());

}
