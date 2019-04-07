#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openframeworks");

	ofBackground(239);
	ofSetColor(39);
	ofSetLineWidth(2);
	ofNoFill();
	ofSetRectMode(ofRectMode::OF_RECTMODE_CENTER);
	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();
	ofRotateY(ofGetFrameNum() * 0.25);
	
	int size = 30;
	for (int i = 0; i < 4; i++) {

		float noise_param = ofRandom(100);
		for (int x = -150; x <= 150; x += size) {

			for (int y = -300; y <= 300; y += size) {

				int z = 165;
				float noise_value = ofNoise(noise_param, x * 0.005, y * 0.005, ofGetFrameNum() * 0.005);
				if (noise_value > 0.6) {

					z += ofMap(noise_value, 0.6, 1.0, 0, 300);
				}

				auto location = glm::vec3(x, y, z);

				ofFill();
				ofSetColor(239);
				ofDrawRectangle(location, size - 2, size - 2);

				ofNoFill();
				ofSetColor(39);
				ofDrawRectangle(location, size, size);
			}
		}

		ofRotateY(90);
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}