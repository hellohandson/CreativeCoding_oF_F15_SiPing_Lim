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
    stemColor = ofColor(255, 255, 255, 50);
    seedColor = ofColor(255, 255, 255, 80);
    scaleFactor = ofRandom(.8,1.0);
    ofSetRectMode(OF_RECTMODE_CENTER);
    stemLength = ofRandom(90,100);
    stemWidth = ofRandom(2,4);
    seedLength = ofRandom(190,250);
    seedWidth = ofRandom(5,30);
    seedCurvature = ofRandom(1, 5);
    rotation = ofRandom(0, 360);
}

void Seed::update(){
    
}

void Seed::draw(){
    
    ofPushMatrix();
    ofTranslate(xPos, yPos);
    ofScale(scaleFactor, scaleFactor);
    ofRotateZ(rotation);

    
    //draw leaf
    
    ofSetColor(seedColor);
    
    ofBeginShape();
    
    //time to draw the petals on the left

    float x0 = 0;
    float x1 = x0 - seedWidth;
    float x2 = x0 - seedWidth/seedCurvature;
    float x3 = x0;
    
    float y0 = 0 - stemLength;
    float y1 = y0 - seedLength/3;
    float y2 = y1 - seedLength/3;
    float y3 = y0 - seedLength;
    
    ofVertex(x0,y0);
    ofBezierVertex(x1,y1,x2,y2,x3,y3);
    
    ofEndShape();
    
    
    //now the petals on the right
    
    ofBeginShape();
    
    x0 = 0;
    x1 = x0 + seedWidth;
    x2 = x0 + seedWidth/seedCurvature;
    x3 = x0;
    
    y0 = 0 - stemLength;
    y1 = y0 - seedLength/3;
    y2 = y1 - seedLength/3;
    y3 = y0 - seedLength;
    
    ofVertex(x0,y0);
    ofBezierVertex(x1,y1,x2,y2,x3,y3);
    
    ofEndShape();
    
    
    //draw stem of seed
    
    ofSetColor(stemColor);
    ofRect(0,0 - (stemLength/2), stemWidth, stemLength);
    ofTriangle(0 - stemWidth/2, 0 - stemLength, 0 + stemWidth/2, 0 - stemLength, 0, 0 - stemLength - 3*(seedLength/4));
    
    
    //part of seed
    float xseed = 0;
    float yseed = 0 - seedWidth;
    ofTranslate(xseed,yseed);
    ofRotate(45);
    ofRect(0, 0, 2, 550);
    
    ofRotate(45, xseed, yseed, 0);
    ofRect(0, 0, 2, 350);
    
    ofRotate(65);
    ofRect(0, 0, 2, 250);
    ofRotate(75);
    ofRect(0, 0, 2, 250);
    ofPopMatrix();
    
    
}











