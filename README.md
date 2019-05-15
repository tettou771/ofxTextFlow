# ofxTextFlow

## Overview

This is an addon for openFrameworks.
I made it to show debug message on window (not console) easily.

## Requirement

ofxTextFlow doesn't depend other addons.

## Tested system

- OSX Mojave + Xcode + of0.10.1
- Windows 10 + VS2017 +  of0.10.1 .

I think compatible almost all versions, because it's simple addon.

## Usage

1. Add this addon.
1. Include `ofxTextFlow.h`.
1. Put the static method `ofxTextFlow::addText("My text")`  when you need.

It's gonna delete old message when over the max num (default: 30 lines).

You can use some method to change appearance.
For example.

```cpp
ofxTextFlow::setMaxLineNum(100); // set max line num 100
ofxTextFlow::setShowing(true); // show text
ofxTextFlow::setTextColor(ofColor(0)); // set text color as black
```

