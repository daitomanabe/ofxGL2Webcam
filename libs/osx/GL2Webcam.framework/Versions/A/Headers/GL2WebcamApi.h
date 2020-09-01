//
//  GL2WebcamApi.h
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


#ifndef GL2WebcamApi_h
#define GL2WebcamApi_h

class vImage_ARGBToYpCbCr;
class vImage_Buffer;
namespace zmq { class context_t; class socket_t; }

class GL2Webcam {
public:
    GL2Webcam();
    ~GL2Webcam();
    void setup(const char * zmqAddr, // "tcp://localhost:46664"
               const char * clientName,
               uint32_t webcamWidth,
               uint32_t webcamHeight,
               GLenum fboTextureTarget /* GL_TEXTURE_2D or GL_TEXTURE_RECTANGLE */ );
    void beginRender();
    void endRender();
    
    void publishTexture2D(GLuint texId); // Cinder
    void publishTextureRect(GLuint texId, GLint texWidth, GLint texHeight); // openFrameworks
private:
    
    void initRgbToYuvConversion();
    void initOpenGLContext();
    void initShaders();
    GLuint compileShader(const char * source, GLenum type);
    void initZmqSocket(const char * addr,
                       const char * clientName,
                       uint32_t webcamWidth,
                       uint32_t webcamHeight);
    
    void captureTextureRgbFrameBuffer(GLuint texId, GLenum texTarget);
    void convertRgbToYuvFrameBuffer();
    void sendYuvFrameBufferToZmq();

    uint32_t width;
    uint32_t height;
    GLenum textureTarget;
    uint8_t * rgbFrameBuffer;
    
    zmq::context_t * ctx;
    zmq::socket_t * frameSocket;
    
    GLuint fbo;
    GLuint renderBuffer;
    GLuint program;
    
    GLuint vao, vbo;
    
    vImage_ARGBToYpCbCr * info;
    vImage_Buffer *rgbImageBuffer, *yuvImageBuffer;
};

#endif /* GL2WebcamApi_h */
