#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    gui.setup("parameters", "settings.xml");
    gui.add(countX.setup("countX", 50, 0, 200));
    gui.add(stepX.setup("StepX", 20, 0, 200));
    gui.add(twistX.setup("Twist X", 5 , -45, 45));
    gui.loadFromFile("settings.xml");    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofPushMatrix();
    ofTranslate(ofGetWidth() / 2, ofGetHeight() /2 );
    ofApp::drawStripes();
    ofPopMatrix();
    
    gui.draw();
}


void ofApp::drawStripes() {
    ofSetColor(ofColor::black);
    ofSetLineWidth(3.0);
    ofNoFill();
    for(int i = -countX; i <= countX; i++) {
        ofPushMatrix();
        ofTranslate(i * stepX, 0);
        ofRotate(i * twistX);
        ofScale(6, 6);
        ofDrawTriangle(0, 0, -50, 100, 50, 100);
        ofPopMatrix();
        
    }
}

void ofApp::exit() {
    gui.saveToFile("settings.xml");
}