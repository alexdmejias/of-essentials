#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

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
}


void ofApp::drawStripes() {
    ofSetColor(ofColor::black);
    ofSetLineWidth(3.0);
    for(int i = -50; i < 50; i++) {
        ofPushMatrix();
        ofTranslate(i * 20, 0);
        ofRotate(i * 5);
        ofDrawLine(0, -100, 0, 100);
        ofPopMatrix();
        
    }
}