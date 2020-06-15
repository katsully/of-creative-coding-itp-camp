#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowShape(640, 480);
	camera.setup(640, 480);

	color.allocate(camera.getWidth(), camera.getHeight());
	gray.allocate(camera.getWidth(), camera.getHeight());

	haar.setup("haarcascade_frontalface_default.xml");

	// default 1.2, 1 is more accurate, 2 is faster
	// haar.setScaleHaar(2)

}

//--------------------------------------------------------------
void ofApp::update(){
	camera.update();

	if (camera.isFrameNew()) {
		color.setFromPixels(camera.getPixels());
		gray = color;
		haar.findHaarObjects(gray);
	}
}

//--------------------------------------------------------------
void ofApp::draw(){

	for (int i = 0; i < haar.blobs.size(); i++) {
		ofRectangle rect;
		rect = haar.blobs[i].boundingRect;
		cout << haar.blobs.size() << endl;

		ofPixels myFace = color.getPixels();
		myFace.crop(rect.x, rect.y, rect.width, rect.height);
		// pixels CPU, texture GPU, we use texture to output to the of app
		ofTexture tex;
		tex.allocate(rect.width, rect.height, GL_RGB);
		tex.loadData(myFace);

		faces.push_back(new Face(tex, rect.x, rect.y));
		for (int i = 0; i < faces.size(); i++) {
			faces[i]->display();
		}
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
