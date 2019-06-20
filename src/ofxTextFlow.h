#pragma once
#include "ofMain.h"

class ofxTextFlow {
public:
	ofxTextFlow();
	~ofxTextFlow();

	void update(ofEventArgs &e);
	void draw(ofEventArgs &e);

	static void addText(string txt);
	static void clear();

	// setter
	static void setShowing(bool _showing);
	static void setTextColor(ofColor _color);
	static void setMaxLineNum(int _maxLineNum);
	static int getMaxLineNum();
	static bool getSwhoing();
	static void toggleShowing();

	static void setPosition(glm::vec2 position);
	static void setTitle(string title);

private:
	static ofxTextFlow *singleton;
	static void singletonGenerate();

	vector<string> lines;
	int maxLineNum;
	bool showing;
	bool initialized;
	ofColor textColor;
	ofMutex mutex;

	glm::vec2 position;
	string title;
};

