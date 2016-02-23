#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        void drawStripes();
        ofxPanel gui;
        ofxIntSlider countX;
        ofxFloatSlider stepX;
        ofxFloatSlider twistX;
        void exit();
		
};
