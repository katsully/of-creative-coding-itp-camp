#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	// setup window resolution
	ofSetWindowShape(1280, 480);

	// set up camera resolution
	camera.setup(640, 480);

	// this will 'hold' the image from the color
	color.allocate(camera.getWidth(), camera.getHeight());
	// this will 'hold' the image once it is converted to black and white
	gray.allocate(camera.getWidth(), camera.getHeight());

	// give the algorithm the dataset
	haar.setup("haarcascade_frontalface_default.xml");
}

//--------------------------------------------------------------
void ofApp::update(){
	// get current frame
	camera.update();

	// pass image from camera to color holder
	color.setFromPixels(camera.getPixels());
	// this converts the RGB image to Black and White
	gray = color;

	// find faces in the gray image
	haar.findHaarObjects(gray);
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(ofColor::white);

	// draw RGB image
	color.draw(0, 0);
	// draw black and white image
	gray.draw(640, 0);

	// iterate through all faces
	for (int i = 0; i < haar.blobs.size(); i++) {
		ofRectangle rect;
		rect = haar.blobs[i].boundingRect;
		ofSetColor(ofColor::red);
		ofNoFill();
		// draw red square around face
		ofDrawRectangle(rect);
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
