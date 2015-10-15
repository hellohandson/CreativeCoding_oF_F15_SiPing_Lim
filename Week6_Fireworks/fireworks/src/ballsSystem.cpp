//
//  ballsSystem.cpp
//  fireworks
//
//  Created by Lim Si Ping on 13/10/15.
//
//

#include "ballsSystem.hpp"

ballsSystem::ballsSystem(ofVec2f _pos){
    pos = _pos;
    time = 2000;
}

//--------------------------------------------------------------
void ballsSystem::update(ofVec2f _force){
    
    if (time > 1000 ) {
        for (int i = 0; i < 10; i++) {
            Balls balls(pos);
            ballsList.push_back(balls);
            
        }
    }
   
    
    for (int i = 0; i < ballsList.size(); i++) {
        ballsList[i].resetForces();
        ballsList[i].applyForce(_force);
        ballsList[i].update();
        if (ballsList[i].time <= 0) {
            ballsList.erase( ballsList.begin()+i);
        }
    }
    
    while (ballsList.size() > 1000) {
        ballsList.erase(ballsList.begin());
    }
    
    if (time >0) {
        time -= 10;
    }
}

//--------------------------------------------------------------
void ballsSystem::draw(){
    for (int i = 0; i < ballsList.size(); i++) {
        ballsList[i].draw();
    }
    
}