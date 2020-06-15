#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	csv.load("Z_Solo_Best.csv");
	int curr_row = 6;

	numCols = csv.getNumCols();

	for (int row = curr_row; row < csv.getNumRows(); row += 3) {
		for (int col = 2; col < numCols; col += 3) {
			// very first time, initialize values
			if (row == 7 && col == 2) {
				xMin = ofToFloat(csv[row][col]);
				xMax = ofToFloat(csv[row][col]);
				yMin = ofToFloat(csv[row][col + 1]);
				yMax = ofToFloat(csv[row][col + 1]);
			}
			else {
				if (ofToFloat(csv[row][col]) < xMin) {
					xMin = ofToFloat(csv[row][col]);
				}
				if (ofToFloat(csv[row][col]) > xMax) {
					xMax = ofToFloat(csv[row][col]);
				}
				if (ofToFloat(csv[row][col + 1]) < yMin) {
					yMin = ofToFloat(csv[row][col + 1]);
				}
				if (ofToFloat(csv[row][col]) > yMax) {
					yMax = ofToFloat(csv[row][col + 1]);
				}
			}
		}
	}

	ofSetFrameRate(30);
}

//--------------------------------------------------------------
void ofApp::update(){
	positions.clear();
	for (int j = 2; j < csv.getNumCols(); j += 3) {
		positions.push_back(ofVec2f(ofMap(ofToFloat(csv[curr_row][j]), xMin, xMax, 0, ofGetWindowWidth()), ofMap(ofToFloat(csv[curr_row][j + 1]), yMax, yMin, 0, ofGetWindowHeight())));
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	for (int i = 0; i < positions.size(); i++) {
		ofDrawCircle(positions[i], 10);
	}

	if (curr_row < csv.getNumRows()) {
		++curr_row;
	}
	else {
		ofExit();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
