//
//  ofxGL2Webcam.h
//  MIT License
//  Copyright (c) 2020 Rhizomaiks

//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:

//  The above copyright notice and this permission notice shall be included in all
//  copies or substantial portions of the Software.

//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//  SOFTWARE.

#ifndef ofxGL2Webcam_h
#define ofxGL2Webcam_h

#include "ofFbo.h"
#include <cstdint>
#include <cstddef>

// main tcp listening port
static const char *zmqAddr = "tcp://localhost:46664";

class ofxGL2Webcam{
    void *gl2wc;
    ofFbo fbo;
public:
    virtual ~ofxGL2Webcam();
    void setup(const char * clientName, uint32_t webcamWidth, uint32_t webcamHeight);
    void begin();
    void end();
    void draw();
};
#endif /* ofxGL2Webcam_h */
