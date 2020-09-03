#ifndef ofxGL2Webcam_h
#define ofxGL2Webcam_h
#include "GL2Webcam.h"

// main tcp listening port
static const char *zmqAddr = "tcp://localhost:46664";

class ofxGL2Webcam{
    GL2Webcam gl2wc;
    ofFbo fbo;
public:
    void setup(const char * clientName, uint32_t webcamWidth, uint32_t webcamHeight){
        fbo.allocate(webcamWidth, webcamHeight);
        gl2wc.setup(zmqAddr, clientName, webcamWidth, webcamHeight, GL_TEXTURE_RECTANGLE);
    }
    void begin(){
        fbo.begin();
    }
    void end(){
        fbo.end();
        ofTextureData & texData = fbo.getTexture().getTextureData();
        gl2wc.publishTextureRect(texData.textureID, texData.width, texData.height);
    }
    void draw(){
        fbo.draw(0, 0, ofGetWidth(), ofGetHeight());
    }
};
#endif /* ofxGL2Webcam_h */
