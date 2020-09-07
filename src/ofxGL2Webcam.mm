//
//  ofxGL2Webcam.mm
//
//  Created by 2bit on 2020/09/07.
//

#include "ofxGL2Webcam.h"
#include "GL2Webcam.h"
#include "ofMain.h"

#define GL2WC ((GL2Webcam *)gl2wc)

ofxGL2Webcam::~ofxGL2Webcam() {
    auto ptr = GL2WC;
    delete ptr;
}

void ofxGL2Webcam::setup(const char * clientName, uint32_t webcamWidth, uint32_t webcamHeight) {
    fbo.allocate(webcamWidth, webcamHeight);
    gl2wc = new GL2Webcam();
    GL2WC->setup(zmqAddr, clientName, webcamWidth, webcamHeight, GL_TEXTURE_RECTANGLE);
}

void ofxGL2Webcam::begin() {
    fbo.begin();
}

void ofxGL2Webcam::end() {
    fbo.end();
    ofTextureData & texData = fbo.getTexture().getTextureData();
    GL2WC->publishTextureRect(texData.textureID, texData.width, texData.height);
}

void ofxGL2Webcam::draw() {
    fbo.draw(0, 0, ofGetWidth(), ofGetHeight());
}
