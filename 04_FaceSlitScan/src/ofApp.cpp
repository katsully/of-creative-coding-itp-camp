#include "ofApp.h"



//--------------------------------------------------------------
void ofApp::setup(){
	camera.setup(camWidth, camHeight);

	// make empty canvas for us to draw beautiful slit scans
	videoTexture.allocate(window_width, window_height, GL_RGB);
	texpixels = new unsigned char[window_width * window_height * 3];
}

//--------------------------------------------------------------
void ofApp::update(){
	// get new frame
	camera.update();
	if (camera.isFrameNew()) {
		vidpixels = camera.getPixels();
		for (int y = 0; y < camHeight; y++) {
			unsigned char r, g, b;
			getPixel(video_slice_x, y, &r, &g, &b, camWidth, vidpixels);
			setPixel(draw_position_x, y, r, g, b, window_width, texpixels);
		}
		videoTexture.loadData(texpixels, window_width, window_height, GL_RGB);

		++draw_position_x;
		if (draw_position_x >= window_width) {
			// OF_EXIT_APP(0);
			draw_position_x = 0;
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0, 0, 0);
	videoTexture.draw(0, 0);
}

void ofApp::setPixel(int horizontal, int vertical, unsigned char R,
	unsigned char G, unsigned char B, int w, unsigned char pixels[]) {

	// the single pixel where i'm extracting the r, g, and b values
	int thisPixel;
	thisPixel = 3 * (w * vertical + horizontal);
	pixels[thisPixel] = R;
	pixels[thisPixel + 1] = G;
	pixels[thisPixel + 2] = B;
}

//--------------------------------------------------------------
void ofApp::getPixel(int horizontal, int vertical, unsigned char* R, unsigned char* G, unsigned char* B, int w,
	ofPixels pixels) {

	// the single pixel from the texture that i'm currently drawing to 
	int thisPixel;
	thisPixel = 3 * (w * vertical + horizontal);
	*R = pixels[thisPixel];
	*G = pixels[thisPixel + 1];
	*B = pixels[thisPixel + 2];

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
