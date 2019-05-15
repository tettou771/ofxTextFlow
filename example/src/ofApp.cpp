#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofxTextFlow::addText("This is ofxTextFlow example");
	ofxTextFlow::addText("Let's try press any key, or BACKSPACE");

	// set text color if needed
	ofxTextFlow::setTextColor(ofColor(50, 50, 50));

	// set max line num if needed
	//ofxTextFlow::setMaxLineNum(50);

	// show text
	ofxTextFlow::setShowing(true);

	// hide text
	//ofxTextFlow::setShowing(false);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (key == OF_KEY_BACKSPACE) {
		ofxTextFlow::clear();
	} else {
		ofxTextFlow::addText("key code: " + ofToString(key));
	}
}