//
//  Seed.cpp
//  Dandelion
//
//  Created by Lim Si Ping on 14/9/15.
//
//

#include "Seed.h"

void Seed::setup(){
    xPos = ofGetWidth()/2;
    yPos = ofGetHeight()/2;
    stemColor = ofColor(255, 255, 255, 80);
    seedColor = ofColor(255, 255, 255, 80);
    scaleFactor = ofRandom(.8,1.0);
    ofSetRectMode(OF_RECTMODE_CENTER);
    stemLength = ofRandom(90,100);
    stemWidth = ofRandom(2,4);
    seedLength = ofRandom(150,300);
    seedWidth = ofRandom(20,50);
    rotation = ofRandom(0, 360);
    lineLength = ofRandom(50,100);
    numLines = (int)ofRandom(3,7);
}

void Seed::update(){
    
}

void Seed::draw(){
    
    ofPushMatrix();
        ofTranslate(xPos, yPos);
    //ofScale(scaleFactor, scaleFactor);
        ofRotateZ(rotation);
        ofSetColor(seedColor);
        float x0 = 0;
        float y0 = 0 - seedLength;
        //ofCircle(x0, y0, seedWidth);
    
        ofRect(0,0 - (stemLength/2), stemWidth, stemLength);
        //ofSetColor(ofColor(255, 0, 0, 100));
        ofTriangle(0 - stemWidth/2, 0 - stemLength, 0 + stemWidth/2, 0 - stemLength, 0, 0 - stemLength - 3*(seedLength/4));
    cout << x0;
    cout << y0 << endl;
    
    ofPopMatrix();    
   
    //draw stem of seed
    
    ofSetColor(stemColor);

    
    for (int i = 0; i < numLines; i++){
        float lineAngle = 180/numLines ;
        float startAngle = -90;
        float goAngle = lineAngle*i +startAngle + lineAngle/2;
        drawLine (goAngle);
    }
    
}


void Seed::drawLine (float angle) {
    
    ofPushMatrix();
    
    ofTranslate(xPos, yPos);
    ofRotateZ(rotation);
    ofTranslate(0,0-seedLength);
    ofRotate(angle, 0, 0, 1);
    ofTranslate(0,0-lineLength/2);
    ofRect(0,0 , 2, lineLength);

    ofPopMatrix();
    
}







