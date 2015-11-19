#include "ofApp.h"
#include "ofxBlobsManager.h"
#include "blobCircle.hpp"
#include "math.h"
#include "ofxPS3EyeGrabber.h"


using namespace ofxCv;
using namespace cv;


//--------------------------------------------------------------
void ofApp::setup(){
    width = ofGetWidth();
    height = ofGetHeight();
    displayArea = width*height;
    
    ofSetFrameRate(100);
    ofSetVerticalSync(false);
    ofBackground(00);
    
    //set usePS3 = true; if want to use PS3 Camera
    usePS3 = false;
    inputWidth = 100;
    inputHeight = 100;
    
    initVideo();
    setupTracker();
    blobManager.init();
    
    circleManager.setup();
    
    //convert to grayscale
    colorImg.allocate(width,height);
    grayImage.allocate(width,height);
    grayBg.allocate(width,height);
    grayDiff.allocate(width,height);
}

void ofApp::initVideo () {
    if (usePS3) {
        vidGrabber.setGrabber(ofPtr<ofxPS3EyeGrabber>(new ofxPS3EyeGrabber()));
        vidGrabber.initGrabber(ofGetWindowWidth(), ofGetWindowHeight());
    } else {
        movie.loadMovie("mockvideo5.mp4");
        movie.play();
    }
    
}
void ofApp::setupTracker () {
    contourFinder.setMinAreaRadius(10);
    contourFinder.setMaxAreaRadius(100);
    contourFinder.setThreshold(10);
    contourFinder.getTracker().setPersistence(15);
    contourFinder.getTracker().setMaximumDistance(64);
    
//    blobsManager.normalizePercentage = 0.7;
//    blobsManager.giveLowestPossibleIDs = true;
//    blobsManager.maxUndetectedTime = 500;
//    blobsManager.minDetectedTime = 2000;
//    blobsManager.debugDrawCandidates = true;
}

//--------------------------------------------------------------
void ofApp::update(){
    
    //ps3eye camera
    ofSetWindowTitle(ofToString(ofGetFrameRate()));

    if (usePS3) {
        vidGrabber.update();
        if(vidGrabber.isFrameNew()) {
            blur(vidGrabber, 10);
            //find the blobs
            contourFinder.findContours(vidGrabber);
            //pass blobs to blobManger to keep track of
            inputWidth = vidGrabber.width;
            inputHeight = vidGrabber.height;
            blobManager.update (contourFinder);
        }
    } else {
        movie.update();
        if(movie.isFrameNew()) {
            blur(movie, 10);
            //find the blobs
            contourFinder.findContours(movie);
            //pass blobs to blobManger to keep track of
            inputWidth = movie.width;
            inputHeight = movie.height;
            blobManager.update (contourFinder);
            
            
        }

    }
   
    circleManager.update (blobManager.blobsManager.blobs, inputWidth, inputHeight);
    updateCircleRadius();
}
void ofApp::updateCircleRadius () {

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetBackgroundAuto(showLabels);
    //draw the ps3eye camera

    drawVideo(showLabels);
    circleManager.draw();
    
    drawDebug();
}

//--------------------------------------------------------------

void ofApp::drawVideo (bool _show) {
    
    if (usePS3) {
        if(_show) {
            ofSetColor(0);
            ofEnableAlphaBlending();
            ofSetColor(255,255,255,120);
            vidGrabber.draw(0, 0);
            ofDisableAlphaBlending();
        }
    } else {
        if(_show) {
            ofSetColor(0);
            ofEnableAlphaBlending();
            ofSetColor(255,255,255,120);
            movie.draw(0, 0);
            ofDisableAlphaBlending();
        }
    }
    
}
//--------------------------------------------------------------


// old OOP method to draw circles individually, unable to "split" circles
void ofApp::drawCircles () {
    blobCircles.clear();
    ofxBlobsManager	_blobsManager = blobManager.blobsManager;
    for(int i = 0; i < _blobsManager.blobs.size(); i++) {
        blobCircles.push_back(blobCircle());
        blobCircles[i].setup(_blobsManager.blobs[i].centroid, _blobsManager.blobs[i].id, _blobsManager.blobs[i].iniDetectedTime);
        blobCircles[i].draw();
    }
    if (blobCircles.size()>0) {
        ofSetHexColor(0xffffff);
        char reportStr[1024];
        sprintf(reportStr, "blob opacity: %f, fps: %f", blobCircles[0].opacity, ofGetFrameRate());
        ofDrawBitmapString(reportStr, 20, 600);
    }
    
    
}
//--------------------------------------------------------------

void ofApp::drawDebug () {
    ofSetHexColor(0xffffff);
    char reportStr[1024];
    sprintf(reportStr, "fps: %f", ofGetFrameRate());
    ofDrawBitmapString(reportStr, 20, 600);
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    blobManager.keyPressed(key);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}


