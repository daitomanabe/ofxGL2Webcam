#include "ofApp.h"
#include "ofxGL2Webcam.h"
ofxGL2Webcam glwc;

void ofApp::setup() {
    glwc.setup();
}

void ofApp::update(){
    glwc.begin();
    ofBackground(255,0,120);
    ofSetColor(10,100,40);
    ofDrawCircle(mouseX, mouseY, 100);
    glwc.end();
}

void ofApp::draw(){
    glwc.draw();
}
