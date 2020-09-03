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
- install GL2Webcam
https://www.dropbox.com/s/pgc66jkmbwqkyw8/GL2Webcam.pkg.zip?dl=0



- project settings -> target -> Frameworks, Libraries & Embedded Content
  * add GL2Webcam.framework to the list (with [+] button)
  * keep "Embed & Sign"
- project settings -> target -> Build Settings
  * Framework Search Paths: add "../../../addons/ofxGL2Webcam/libs/osx"
  * Header Search Paths: add "../../../addons/ofxGL2Webcam/libs/osx/GL2Webcam.framework/Headers"
- add 2 flags to "Other C++ Flags" (in build settings)
  * -x
  * objective-c++
