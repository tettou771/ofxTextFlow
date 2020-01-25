#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	// set font to customize. not required
	ofxTextFlow::loadFont("mono.ttf", 8);

	// set line height. default is 14
	//ofxTextFlow::setLineHeight(12);

	// set text color if needed
	//ofxTextFlow::setTextColor(ofColor(255));

	// set max line num if needed
	ofxTextFlow::setMaxLineNum(40);

	// set position
	// default: (10, 10)
	ofxTextFlow::setPosition(5, 5);

	// show all text
	// hidden by default
	ofxTextFlow::setShowing(true);

	// set bg bbox width. 400 by default
	ofxTextFlow::setBBoxWidth(200);

	// show bg bbox. hidden by default 
	ofxTextFlow::setShowingBBox(true);

	// hide text. showing by default
	//ofxTextFlow::setShowing(false);

	// set margin borders
	// default 5
	ofxTextFlow::setMarginBorders(10);

	// round bbox
	ofxTextFlow::setRounded(true, 5);

	//// tab labels and values
	//ofxTextFlow::setTabbed(true, 1);

	//// float decimals
	//ofxTextFlow::setFloatResolution(1);

	// show fps
	ofxTextFlow::setShowFPS(true);

	///-

	//set title
	ofxTextFlow::setTitle("MIDI-Key LOG:");

	//add lines
	ofxTextFlow::addText("This is ofxTextFlow example");
	ofxTextFlow::addText("Let's try press any key");
	ofxTextFlow::addText("or BACKSPACE to clear box.");
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
	}
	else {
		ofxTextFlow::addText("key code: " + ofToString((char)key));
	}
}