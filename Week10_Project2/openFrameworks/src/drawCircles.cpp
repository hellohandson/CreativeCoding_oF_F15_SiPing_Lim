//
//  drawCircles.cpp
//  pSpace
//
//  Created by x on 12/10/15.
//
//

#include "drawCircles.hpp"
#include <math.h>

void drawCircles::setup(ofFbo & _fbo){
    fbo = _fbo;
    baseFbo.allocate(width, height, GL_RGBA, 4);
    clearFbo(baseFbo);
    maskFbo.allocate(width, height, GL_RGBA, 4);
    clearFbo(maskFbo);
    setupParticles();
   // myFont.loadFont("blender.ttf", 10);
    
};
void drawCircles::setupParticles () {
    int num = 2500;
    //change amount here
    p.assign(num, dotParticle());
    //currentMode = PARTICLE_MODE_REPEL;
    currentMode = PARTICLE_MODE_NEAREST_POINTS;
    for(int i = 0; i < 4; i++){
        ofPoint t = ofPoint( ofMap(i, 0, 4, 100, ofGetWidth()-100) , ofRandom(100, ofGetHeight()-100) );
        attractPoints.push_back( t );
    }
    
    attractPointsWithMovement = attractPoints;
    
    for(unsigned int i = 0; i < p.size(); i++){
        p[i].setMode(currentMode);
        p[i].setAttractPoints(&attractPointsWithMovement);;
        p[i].reset();
    }
}

void drawCircles::update (vector<circleInfo>  & _circleInfo, float _goRadius){
    circles = _circleInfo;
    radius = _goRadius;
    updateParticles();
    clearFbo(fbo);    
};
void drawCircles::updateParticles () {
    attractPoints.clear();
    for(int i = 0; i < circles.size(); i++){
        ofPoint t = circles[i].getPoint();
        attractPoints.push_back( t );
    }
    
    attractPointsWithMovement = attractPoints;
    
    for(unsigned int i = 0; i < p.size(); i++){
        p[i].setAttractPoints(&attractPointsWithMovement);
        p[i].repelSize = radius;
        p[i].update();
    }
    
    
}
void drawCircles::updateCircleRadius () {

}

void drawCircles::drawParticles () {
    
    glDisable(GL_BLEND);
    for(unsigned int i = 0; i < p.size(); i++){
        p[i].draw();
    }
}

void drawCircles::draw () {
    
    //change no of rings here
    rings = 3;
    float _radiusStep = radius / rings;
    
    
    for (int i=rings *2 ; i >1 ; i--){ //int i=rings* 2 + 1
        clearFbo(baseFbo);
        clearFbo(maskFbo);
        int tIndex = ceil(i/2 );
        float myRadius =  _radiusStep * tIndex;
        
        for (int j = 0; j < circles.size(); j++) {
            circleInfo & circle = circles[j];
            myRadius =  _radiusStep * tIndex;
            if (circle.amFlagToRemove || circle.amRemove){
                myRadius =  radius - radius * circle.animationStep;
            }
            
            ofColor myColor = ofColor (255,255, 255, circle.opacity);
            ofPoint myPoint = circle.getPoint();

            if (i%2 >0 ) {
                    if (circle.collided &&  !circle.amFlagToRemove) {
                        if (true) {
                            bool distanceLess = false;
                            float shortestDist = 0;
                            for (int k = 0; k< circle.collidedDist.size(); k++) {
                                if (circle.collidedDist[k]  < myRadius * 2 + _radiusStep *2) {
                                    distanceLess = true;
                                }
                            }
                            if (distanceLess) {
                                //change the color over the overlay
                                myColor = ofColor (255, 255 - (tIndex-1) * 100, 255- (tIndex-1) * 120, circle.opacity);
                                drawCircle (baseFbo, myPoint, myRadius+_radiusStep-3, myColor, true);
                                drawCircle (maskFbo, myPoint, myRadius + 2, myColor);
                            }
                        }
                }
                
            } else {
                drawCircle (baseFbo, myPoint, myRadius, myColor, true);
                drawCircle (maskFbo, myPoint, myRadius-2, myColor);
            }
            
            
        }
        
        
        
        
        fbo.begin(); //start drawing to finalFBO layer
            glEnable (GL_BLEND); //prep blend modes for FUTURE drawing func
            glBlendFunc (GL_ONE, GL_ONE);
                baseFbo.draw(0, 0); //draw main circle to temp Final FBO layer
            //glEnable (GL_BLEND); //prep blend modes for FUTURE drawing func
            glBlendFunc (GL_ZERO, GL_ONE_MINUS_SRC_COLOR); //define how openGL should "blend"
                maskFbo.draw(0,0);
            glDisable(GL_BLEND); //disable blend mode, if not future drawing will be affected
        
        fbo.end(); //end drawing
        
        for (int j = 0; j < circles.size(); j++) {
            circleInfo & circle = circles[j];
            //
            ofPoint _point = circle.getPoint();
            fbo.begin();
            ofDrawBitmapString("INTIMATE", _point.x, _point.y);
            ofDrawBitmapString("NOPE. TOO CLOSE", _point.x+_radiusStep, _point.y+_radiusStep);
            ofDrawBitmapString("YOU MAY SPEAK TO ME NOW", _point.x+_radiusStep*2-10, _point.y+_radiusStep*2-10);
            fbo.end();
        }
        
        //create a for loop to count no of blobs then add draw code here.
    }
    
    drawParticles();
}

void drawCircles::drawCircle (ofFbo & _fbo, ofPoint _point, float _radius, ofColor _color, bool _alpha) {
    _fbo.begin();// beging drawing to FBO
    ofPath circlePath;
    circlePath.setFillColor(_color);
    circlePath.setCircleResolution (64);
    circlePath.arc(_point, _radius, _radius, 0, 360);
    circlePath.close();
    if (_alpha) {
        ofEnableAlphaBlending();
    }
    circlePath.draw();
    _fbo.end(); //end drawing to FBO
    glDisable(GL_BLEND);
}

void drawCircles::clearFbo (ofFbo & _fbo) {

    _fbo.begin();
    ofClear(0,0,0,0);
    _fbo.end();
    
}
circleInfo& drawCircles::getCircle (int id) {
    for (int j=0; j< circles.size(); j++) {
        if (circles[j].id == id) {
            return circles[j];
        }
    }
}
