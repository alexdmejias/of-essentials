#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    gui.setup("parameters", "settings.xml");
    gui.add(countX.setup("countX", 50, 0, 200));
    gui.add(stepX.setup("StepX", 20, 0, 200));
    gui.add(twistX.setup("Twist X", 5 , -45, 45));
    
    globalGroup.setup("Global");
    globalGroup.add(Scale.setup("Scale", 1, 0.0, 1));
    globalGroup.add(Rotate.setup("Rotate", 0, -180, 180));
    globalGroup.add(Background.setup("Background", 255, 0, 255));
    gui.add(&globalGroup);
    
    primGroup.setup("Primitive");
    primGroup.add(shiftY.setup("ShiftY", 0.0, -1000.0, 1000.0));
    primGroup.add(rotate.setup("Rotate", 0.0, -180.0, 180.0));
    primGroup.add(size.setup("Size", ofVec2f(6, 6), ofVec2f(0, 0), ofVec2f(20, 20)));
    primGroup.add(color.setup("Color", ofColor::black, ofColor(0, 0, 0, 0), ofColor::white));
    primGroup.add(filled.setup("Filled", false));
    primGroup.add(type.setup("Type", false));
    gui.add(&primGroup);
    
    gui.loadFromFile("settings.xml");
    
    showGui = true;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(Background);
    ofPushMatrix();
    ofTranslate(ofGetWidth() / 2, ofGetHeight() /2 );
    
    float Scl = pow(Scale, 4.0f);
    ofScale(Scl, Scl);
    ofRotate(Rotate);
    
    ofApp::drawStripes();
    ofPopMatrix();
    
    if (showGui) {
        gui.draw();        
    }

}

void ofApp::keyPressed(int key) {
    if(key == 'z' ) {
        showGui = !showGui;
    }
    
    if(key == OF_KEY_RETURN) {
        ofSaveScreen("screenshot.png");
    }
    
    if(key == 's') {
        ofFileDialogResult res;
        
        res = ofSystemSaveDialog("preset.xml", "Saving Preset");
        if (res.bSuccess) {
            gui.saveToFile(res.filePath);
        }
    }
    
    if (key == 'l') {
        ofFileDialogResult res;
        res = ofSystemLoadDialog("Loading Preset");
        if (res.bSuccess) {
            gui.loadFromFile(res.filePath);
        }
    }
}


void ofApp::drawStripes() {
    ofSetColor(color);
    ofSetLineWidth(1);
    
    if( filled) {
        ofFill();
    } else {
        ofNoFill();
    }
    
    
    for(int i = -countX; i <= countX; i++) {
        ofPushMatrix();
        ofTranslate(i * stepX, 0);
        ofRotate(i * twistX);
        
        ofTranslate(0, shiftY);
        ofRotate(rotate);
        ofScale(size->x, size->y);
        
        if (type) {
            ofDrawRectangle(-50, -50, 100, 100);
        } else {
            ofDrawTriangle(0, 0, -50, 100, 50, 100);
        }
    
//        ofScale(6, 6);
//        ofDrawTriangle(0, 0, -50, 100, 50, 100);
        
        ofPopMatrix();
        
    }
}

void ofApp::exit() {
    gui.saveToFile("settings.xml");
}