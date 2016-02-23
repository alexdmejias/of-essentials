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
    
        ofxGuiGroup globalGroup;
        ofxFloatSlider Scale;
        ofxFloatSlider Rotate;
        ofxFloatSlider Background;
    
        ofxGuiGroup primGroup;
        ofxFloatSlider shiftY, rotate;
        ofxVec2Slider size;
        ofxColorSlider color;
        ofxToggle filled, type;
    
    
    
        void exit();
		
};
