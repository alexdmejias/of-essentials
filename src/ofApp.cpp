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
    ofNoFill();
    for(int i = -50; i < 50; i++) {
        ofPushMatrix();
        ofTranslate(i * 20, 0);
        ofRotate(i * 5);
        ofScale(6, 6);
        ofDrawTriangle(0, 0, -50, 100, 50, 100);
        ofPopMatrix();
        
    }
}