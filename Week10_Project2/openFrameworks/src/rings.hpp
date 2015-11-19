//
//  rings.hpp
//  pSpace
//
//  Created by x on 29/9/15.
//
//

#ifndef rings_hpp
#define rings_hpp

#include "ofMain.h"

class rings {
public:
    static void draw (ofFbo& _fbo, ofPoint _point, float _radius, ofColor _color, bool _alpha = true);
};

#endif /* rings_hpp */
