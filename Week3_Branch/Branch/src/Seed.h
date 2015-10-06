//
//  Seed.h
//  Dandelion
//
//  Created by Lim Si Ping on 14/9/15.
//
//

#ifndef __Dandelion__Seed__
#define __Dandelion__Seed__

#include <stdio.h>
#include "ofMain.h"

class Seed {
    
public:
    
    void setup();
    void update();
    void draw();
    void drawLine(float angle);
    
private:
    
    ofColor stemColor;
    ofColor seedColor;
    float xPos, yPos;
    float scaleFactor;
    float rotation;
    
    float stemLength, stemWidth;
    float seedLength, seedWidth;
    float seedCurvature;
    
    float lineLength;
    float numLines;
    
};

#endif /* defined(__Leaves__Leaf__) */
