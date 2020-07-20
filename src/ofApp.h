#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxOpenCv.h"
#include "ofxCv.h"
#include "image_generator.h"
#include "image.hpp"
#include "model.hpp"

class ofApp : public ofBaseApp{
private:
	const double kWindowSize = ofGetWindowWidth();
	const double kPixelCount = 28;
	const double kThickness = 2;
	const double kBrushSize = kWindowSize / (kPixelCount / kThickness);
	const int kTestingSize = 96;
	const int kTrainingSize = 2400;
	const int kNumCharacters = 24;
	const int kMinBrightness = 180;
	
	const std::string kFontPath = "../../hanguldata/fonts";
	const std::string kLabelsPath = "../../hanguldata/labels.txt";
	const std::string kTestingLabelsPath = "../../hanguldata/testing_labels.txt";
	const std::string kTestingImagesPath = "../../hanguldata/test_images/";
	const std::string kProbabilityModel = "../../hanguldata/probability_model.txt";
	
	image_generator H;
	
public:
	void setup();
	void draw();

	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	
	void CreateProbabilityModel();
	void TestModelAccuracy();
	
	ofFbo fbo;
	
	ofxButton clear_button;
	ofxButton analyze_button;
	ofxPanel gui;
	ofTrueTypeFont print;
	std::string line;

};
