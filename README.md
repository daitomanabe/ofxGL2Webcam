GL2Webcam for openFrameworks
==========================

![gl2webcamdemo](https://user-images.githubusercontent.com/72069/92401639-0373c400-f169-11ea-9a25-87df2ac22839.gif)


About
-----
GL2Webcam addon

Inspired by ofxSyphon

You can publish your openFrameworks texture to virtual webcam device with this addon.

Work in progress!

Licensing
--------
See the included License.txt file

Requirements
---------
GL2Webcam and openFrameworks 011 or better

Installation
------------
- The installer for GL2Webcam is available at
  * https://www.dropbox.com/s/obrk676wcg0rxw4/GL2Webcam.pkg.zip?dl=0
  
- Download and install openFramworks
  * https://openframeworks.cc/

- Create a new ofxGL2Webcam openFrameworks project 
  * https://openframeworks.cc/learning/#how_tos

- Add GL2Webcam.framework to your XCode project
  * settings -> target -> Frameworks, Libraries & Embedded Content
  * add GL2Webcam.framework to the list (with [+] button)
  * keep "Embed & Sign"
- Change project settings -> target -> Build Settings
  * Framework Search Paths: add "../../../addons/ofxGL2Webcam/libs/osx"
  
Instruction
-----------


- Your GL2Webcam-plugin-assistant automatically launches GL2Webcam when you login. 
  
- After your GLWebcam-plugin starts, it is listening at port 46664 (default).There is no new virtual-webcam-device created in a system
  
- When you start your virtual-webcam-app, it tells GLWebcam-plugin to generate new port to receive texture data from this app.
    (starting from listeningPort+1 until listeningPort+1+maxFramePortsTry)

- When you start your virtual-webcam-app-1 with resolution 1920x1080, new virtual-webcam-device that streams only from this app should appear immediately.

- When you start your virtual-webcam-app-2 with resolution 1920x1080, new virtual-webcam-device that streams only from this app should appear immediately.

- When you close one of the consumer app, its stream will display splash screen for 10 seconds.

- After 10 seconds of inactivity, the device will be destroyed.

- The name of virtual-webcam-device is GL2Webcam Virtual Camera + id now. will be updated soon..

