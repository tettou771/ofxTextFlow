#include "ofxTextFlow.h"

ofxTextFlow *ofxTextFlow::singleton;

ofxTextFlow::ofxTextFlow() {
	singleton = this;
	showing = true;
	textColor.set(180);
	maxLineNum = 30;

	ofAddListener(ofEvents().update, this, &ofxTextFlow::update);
	ofAddListener(ofEvents().draw, this, &ofxTextFlow::draw);
}


ofxTextFlow::~ofxTextFlow() {
	singleton = nullptr;

	ofRemoveListener(ofEvents().update, this, &ofxTextFlow::update);
	ofRemoveListener(ofEvents().draw, this, &ofxTextFlow::draw);
}

void ofxTextFlow::update(ofEventArgs & e) {
}

void ofxTextFlow::draw(ofEventArgs & e) {
	if (showing) {
		float lineHeight = 14;
		ofVec2f pos(2, ofGetHeight() + lineHeight);

		ofPushStyle();
		ofSetColor(textColor);
		ofPushMatrix();
		ofTranslate(pos);
		ofTranslate(0, -lineHeight * lines.size());

		mutex.lock();
		for (auto &l : lines) {
			ofDrawBitmapString(l, 0, 0);
			ofTranslate(0, lineHeight);
		}
		mutex.unlock();

		ofPopMatrix();
		ofPopStyle();
	}
}

void ofxTextFlow::addText(string txt) {
	singletonGenerate();

	singleton->mutex.lock();
	auto lines = ofSplitString(txt, "\n");
	for (int i = 0; i < lines.size(); ++i) {
		auto &line = lines[i];
		if (line == "" && i == lines.size() - 1) break;

		singleton->lines.push_back(line);
		if (singleton->lines.size() > singleton->maxLineNum) {
			singleton->lines.erase(singleton->lines.begin());
		}
	}
	singleton->mutex.unlock();

}

void ofxTextFlow::clear() {
	singletonGenerate();
	singleton->lines.clear();
}

void ofxTextFlow::setShowing(bool _showing) {
	singletonGenerate();
	singleton->showing = _showing;
}

void ofxTextFlow::setTextColor(ofColor _color) {
	singletonGenerate();
	singleton->textColor.set(_color);
}

void ofxTextFlow::setMaxLineNum(int _maxLineNum) {
	singletonGenerate();
	singleton->maxLineNum = _maxLineNum;
}

int ofxTextFlow::getMaxLineNum() {
	singletonGenerate();
	return singleton->maxLineNum;
}

bool ofxTextFlow::getSwhoing() {
	singletonGenerate();
	return singleton->showing;
}

void ofxTextFlow::toggleShowing() {
	singletonGenerate();
	singleton->showing = !singleton->showing;
}

void ofxTextFlow::singletonGenerate() {
	if (singleton == nullptr) {
		singleton = new ofxTextFlow();
	}
}
