#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    ofEnableAlphaBlending();
    ofEnableSmoothing();
    
    numSeeds = (int)ofRandom(50,70);
    for (int i = 0; i < numSeeds; i++){
        Seed tempSeed;
        tempSeed.setup();
        seeds.push_back(tempSeed);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i = 0; i < numSeeds; i++){
        seeds[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i = 0; i < numSeeds; i++){
        seeds[i].draw();
    }
    
    ofColor(255,255,255,80);
    ofCircle(ofGetWidth()/2,ofGetHeight()/2,20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
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
    seeds.clear();
    setup();
    
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
