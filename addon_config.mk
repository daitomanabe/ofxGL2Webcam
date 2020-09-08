meta:
    ADDON_NAME = ofxGL2Webcam
    ADDON_DESCRIPTION = GL2Webcam for openFrameworks
    ADDON_AUTHOR = Daito Manabe
    ADDON_TAGS = "virtual webcam"
    ADDON_URL = https://github.com/daitomanabe/ofxGL2Webcam

osx:
	ADDON_LDFLAGS = -Xlinker -rpath -Xlinker @executable_path/../Frameworks
