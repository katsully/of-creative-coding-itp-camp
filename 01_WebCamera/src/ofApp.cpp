#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	// set size of application window
	ofSetWindowShape(640, 480);

	// camera setup - set resolution of camera
	camera.setup(640, 480);
}

//--------------------------------------------------------------
void ofApp::update() {
	// get current frame from camera
	camera.update();
}

//--------------------------------------------------------------
void ofApp::draw() {
	// draw image from camera to your application
	camera.draw(0, 0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
