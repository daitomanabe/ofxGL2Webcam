#pragma once

#include "ofMain.h"
#include "ofxGL2Webcam.h"

class ofApp : public ofBaseApp{
    ofxGL2Webcam glwc;

	public:
		void setup();
        void update();
		void draw();
};
