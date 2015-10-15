//
//  balls.cpp
//  fireworks
//
//  Created by Lim Si Ping on 8/10/15.
//
//
//

#include "balls.hpp"

Balls::Balls(ofVec2f _pos) {
    pos.set(_pos);
    vel.x = ofRandom(-3, 3);
    vel.y = ofRandom(-1, -6);
    time = 200;
}

void Balls::setup() {
    
}

void Balls::resetForces() {
    acc *= 0;
}

void Balls::applyForce(ofVec2f force) {
    acc += force;
}

void Balls::update() {
    vel += acc;
    pos += vel;
    
    if (time > 0) time -= 1.0;
    
}

void Balls::draw() {
    ofSetColor(ofRandom(time), ofRandom(255), ofRandom(255));
    ofCircle(pos, 2);
}



