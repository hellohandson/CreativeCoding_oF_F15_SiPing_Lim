//
//  balls.hpp
//  fireworks
//
//  Created by Lim Si Ping on 8/10/15.
//
//

#include "ofMain.h"


class Balls {
public:
    
    Balls(ofVec2f _pos);
    
    void setup();
    
    void resetForces();
    void applyForce(ofVec2f force);
    
    void update();
    void draw();
    
    ofVec2f pos, vel, acc;
    float time;
    
};
