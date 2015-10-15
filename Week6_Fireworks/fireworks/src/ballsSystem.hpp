//
//  ballsSystem.hpp
//  fireworks
//
//  Created by Lim Si Ping on 13/10/15.
//
//

#pragma once

#include "ofMain.h"
#include "balls.hpp"


class ballsSystem {
public:
    
    ballsSystem(ofVec2f _pos);
    void update(ofVec2f _force);
    void draw();
    
    vector<Balls> ballsList;
    ofVec2f pos;
    
    float time = 5000;
};

