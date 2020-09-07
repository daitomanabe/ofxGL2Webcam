GL2Webcam for openFrameworks
==========================

About
-----
GL2Webcam addon

Inspired by ofxSyphon

Work in progress!

Licensing
--------
See the included License.txt file

Requirements
---------
GL2Webcam and openFrameworks 011 or better

Installation
------------
- Download and install GL2Webcam
  * https://www.dropbox.com/s/pgc66jkmbwqkyw8/GL2Webcam.pkg.zip?dl=0
  
- Download and install openFramworks
  * https://openframeworks.cc/

- Create a new ofxGL2Webcam openFrameworks project 
  * https://openframeworks.cc/learning/#how_tos

- Add GL2Webcam.framework to your XCode project
  * settings -> target -> Frameworks, Libraries & Embedded Content
  * add GL2Webcam.framework to the list (with [+] button)
  * keep "Embed & Sign"
- project settings -> target -> Build Settings
  * Framework Search Paths: add "../../../addons/ofxGL2Webcam/libs/osx"
  * Header Search Paths: add "../../../addons/ofxGL2Webcam/libs/osx/GL2Webcam.framework/Headers"

Instruction
------------
- Your GL2Webcam plugin assistant automatically launches GL2Webcam plugin when you login. There is no new virtual webcam camera device created in a system

- When you start app1-openFrameworks with resolution 800x600, there should appear new virtual webcam camera device that streams only from this app

- When you start app2-openFrameworks with resolution 1920x1080, there should appear new virtual webcam that streams only from this app

- When you stop any of the app, the stream will display splash screen for 10 seconds

- After 10 seconds it will remove the device associated with this app

