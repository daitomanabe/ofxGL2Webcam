#include "ofApp.h"

void ofApp::setup() {
    printf("%s\n", glGetString(GL_VENDOR));
    printf("%s\n", glGetString(GL_RENDERER));
    printf("%s\n", glGetString(GL_VERSION));

    ofSetFrameRate(60);
    // name, width, height
    glwc.setup("ofx_gl2webcam", 800, 600);
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
