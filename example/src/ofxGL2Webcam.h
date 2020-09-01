#ifndef ofxGL2Webcam_h
#define ofxGL2Webcam_h
#include "GL2Webcam.h"

class ofxGL2Webcam{
    GL2Webcam gl2wc;
    ofFbo fbo;
public:
    void setup(){
        printf("%s\n", glGetString(GL_VENDOR));
        printf("%s\n", glGetString(GL_RENDERER));
        printf("%s\n", glGetString(GL_VERSION));
        ofSetFrameRate(60);
        fbo.allocate(800, 600);
        gl2wc.setup("tcp://localhost:46664", 800, 600, GL_TEXTURE_RECTANGLE);

    }
    void begin(){
        fbo.begin();
    }
    void end(){
        fbo.end();
        
        ofTexture tex = fbo.getTexture();
        ofTextureData texData = tex.getTextureData();

        gl2wc.publishTextureRect(texData.textureID, texData.width, texData.height);
    }
    void draw(){
        ofSetColor(255, 255, 255);
        fbo.draw(0, 0, ofGetWidth(), ofGetHeight());
    }
};
#endif /* ofxGL2Webcam_h */
