#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	
	// set font
	// draw with ofTrueTypeFont if loaded
	//ofxTextFlow::loadFont("mono.ttf", fontSize);

	// set text color if needed
	//ofxTextFlow::setTextColor(ofColor(255));

	// set max line num if needed
	//ofxTextFlow::setMaxLineNum(50);
	
	// set position
	// default: (10, 10)
	ofxTextFlow::setPosition(0, 0);

	// show all text
	//hidden by default
	ofxTextFlow::setShowing(true);
	
	// set bg bbox width
	ofxTextFlow::setBBoxWidth(280);

	// show bg bbox
	ofxTextFlow::setShowingBBox(true);

	// hide text
	//ofxTextFlow::setShowing(false);

	// set margin borders
	// default 5
	//ofxTextFlow::setMarginBorders(20);

	//// tab labels and values
	//ofxTextFlow::setTabbed(true, 1);

	//// float decimals
	//ofxTextFlow::setFloatResolution(1);

	// round bbox
	ofxTextFlow::setRounded(true);

	// show fps
	ofxTextFlow::setShowFPS(true);

	///-

	//set title
	ofxTextFlow::setTitle("MIDI DEBUG:");
	
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
	} else {
		ofxTextFlow::addText("key code: " + ofToString(key));
	}
}