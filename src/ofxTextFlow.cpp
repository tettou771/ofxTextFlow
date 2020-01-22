#include "ofxTextFlow.h"

ofxTextFlow *ofxTextFlow::singleton;

ofxTextFlow::ofxTextFlow() {
	singleton = this;
	showing = true;
	BBoxShowing = false;
	textColor.set(255);
	bgColor.set(0);
	maxLineNum = 30;

	position = glm::vec2(10, 10);

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
	if (showing)
	{
		ofPushStyle();
		ofPushMatrix();

		mutex.lock();

		int yPadTitle = fontSize + lineHeight;//y pad below title
		int heightMax = fontSize + lineHeight * maxLineNum + yPadTitle;

		//-

		//bbox
		if (BBoxShowing)
		{
			ofSetColor(bgColor);
			ofFill();

			//bbox
			rectBB = ofRectangle(position.x, position.y, BBoxWidth, heightMax);
			rectBB.x -= margin;
			rectBB.y -= margin;
			rectBB.height += 2 * margin;
			rectBB.width += 2 * margin;

			//to compensate pos after margin
			ofPushMatrix();
			ofTranslate(margin, margin);

			//rounded
			if (bRounded)
			{
				ofDrawRectRounded(rectBB, roundedSize);
			}
			else
			{
				ofDrawRectangle(rectBB);
			}
		}

		//print title
		ofSetColor(textColor);
		ofTranslate(position.x, position.y + fontSize);

		string str = title;
		if (showFPS)
		{
			str += "\t\t";
			str += ofToString(ofGetFrameRate(), 0);
			str += " FPS";
		}
		if (font.isLoaded()) {
			font.drawString(str, 0, 0);
		}
		else
		{
			ofDrawBitmapString(str, 0, 0);
		}

		ofTranslate(0, yPadTitle);

		//print lines
		for (auto &l : lines) {
			if (font.isLoaded()) {
				font.drawString(l, 0, 0);
			}
			else
			{
				ofDrawBitmapString(l, 0, 0);
			}
			ofTranslate(0, lineHeight);
		}

		mutex.unlock();

		if (BBoxShowing)
		{
			ofPopMatrix();
		}
		
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

void ofxTextFlow::setMaxLineNum(int _maxLineNum) {
	singletonGenerate();
	singleton->maxLineNum = _maxLineNum;
}

int ofxTextFlow::getMaxLineNum() {
	singletonGenerate();
	return singleton->maxLineNum;
}

void ofxTextFlow::setShowing(bool _showing) {
	singletonGenerate();
	singleton->showing = _showing;
}

void ofxTextFlow::setShowingBBox(bool _showing) {
	singletonGenerate();
	singleton->BBoxShowing = _showing;
}

bool ofxTextFlow::getShowing() {
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

//colors
void ofxTextFlow::setTextColor(ofColor _color) {
	singletonGenerate();
	singleton->textColor.set(_color);
}

ofColor ofxTextFlow::getTextColor() {
	singletonGenerate();
	return singleton->textColor;
}

void ofxTextFlow::setBackgroundColor(ofColor _color) {
	singletonGenerate();
	singleton->bgColor = _color;
}

ofColor ofxTextFlow::getBackgroundColor() {
	singletonGenerate();
	return singleton->bgColor;
}

void ofxTextFlow::setTitle(string _title) {
	singletonGenerate();
	singleton->title = _title;
}

void ofxTextFlow::loadFont(string _path, float _size) {
	singletonGenerate();
	singleton->fontSize = _size;
	singleton->font.load(_path, _size);
}

//layout
void ofxTextFlow::setPosition(float _x, float _y) {
	singletonGenerate();
	singleton->position = glm::vec2(_x, _y);
}

void ofxTextFlow::setPosition(glm::vec2 _position) {
	singletonGenerate();
	singleton->position = _position;
}

void ofxTextFlow::setBBoxWidth(int w) {
	singletonGenerate();
	singleton->BBoxWidth = w;
}

void ofxTextFlow::setLineHeight(float h) {
	singletonGenerate();
	singleton->lineHeight = h;
}

void ofxTextFlow::setMarginBorders(int _margin) {
	singletonGenerate();
	singleton->margin = _margin;
}

void ofxTextFlow::setRounded(bool b, float size) {
	singletonGenerate();
	singleton->bRounded = b;
	singleton->roundedSize = size;
}

void ofxTextFlow::setTabbed(bool b, int num) {
	singletonGenerate();
	singleton->bTabbed = b;
	singleton->tabsNum = num;
}

void ofxTextFlow::setFloatResolution(int res) {
	singletonGenerate();
	singleton->fRes = res;
}

void ofxTextFlow::setShowFPS(bool _showing) {
	singletonGenerate();
	singleton->showFPS = _showing;
}