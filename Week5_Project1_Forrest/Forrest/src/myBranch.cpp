//
//  myBranch.cpp
//  dandelionTree
//
//  Created by Lim Si Ping on 23/9/15.
//
//

#include "myBranch.hpp"

void myBranch::setup (  float _x,
                      float _y,
                      float _width,
                      float _height,
                      float _splitRatio,
                      int _totalSegments,
                      int _maxSegments,
//                      int _maxDivisions,
                      ofColor _color,
                      float _angle,
                      float _curve) {
    x = _x;
    y = _y;
    height = _height;
    width = _width;
    splitRatio = _splitRatio;
    totalSegments = _totalSegments;
    maxSegments = _maxSegments;
//    maxDivisions = _maxDivisions;
    color = _color;
    angle = _angle;
    curve = _curve;
    
    drawSelf();
    changeSelf();
    newBranch();
}
void myBranch::drawSelf () {
    ofSetColor(color);
    ofSetLineWidth((int)width);
    ofLine(x, y, x + height*cos(angle), y + height*sin(angle));
}
void myBranch::changeSelf () {
    x += height*cos(angle);
    y += height*sin(angle);
    
    //golden ratio!!
    width = width*(ofRandom(0.61804697157-0.1, 0.61804697157+0.1));
    height = height * (ofRandom(0.61804697157+0.1, 0.61804697157+0.2 ));
    totalSegments += 1;
    
//    curve += ofRandom(0- curve/2, (float)(2*PI)/360.0);
    curve = ofRandom(0- curve/2, curve/2);
    angle += curve;
}
void myBranch::newBranch () {
    if (totalSegments <= maxSegments) {
        if(ofRandom(0, 1) > splitRatio){
            myBranch subBranch;

            subBranch.setup(x, y, width, height, splitRatio, totalSegments, maxSegments, color, angle, curve);
        } else { 
            myBranch subBranch1;
            float angle1 = angle + ofRandom(0, 3*(PI/8));
            myBranch subBranch2;
            float angle2 = angle - ofRandom(0, 3*(PI/8));
            if (ofRandom(0, 1) > splitRatio) {
                totalSegments -= 1;
            }
            subBranch1.setup(x, y, width, height, splitRatio, totalSegments, maxSegments, color, angle1, curve);
            
            subBranch2.setup(x, y, width, height, splitRatio, totalSegments, maxSegments, color, angle2, curve);
        }
    }
}