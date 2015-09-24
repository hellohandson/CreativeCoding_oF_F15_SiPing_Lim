//
//  myBranch.hpp
//  dandelionTree
//
//  Created by Ping on 23/9/15.
//
//

#ifndef myBranch_hpp
#define myBranch_hpp

#include "ofMain.h"

class myBranch : public ofBaseApp{
    
public:
    void setup(float _x,
               float _y,
               float _width,
               float _height,
               float _splitRatio,
               int _totalSegments,
               int _maxSegments,
//               int _maxDivisions,
               ofColor _color,
               float _angle,
               float _curve);
    
private:
    void drawSelf ();
    void changeSelf ();
    void newBranch ();
    float x;
    float y;
    float height;
    float width;
    int totalSegments;
    int maxSegments;
//    int maxDivisions;
    float splitRatio;
    ofColor color;
    float angle;
    float curve;
};

#endif /* myBranch_hpp */
