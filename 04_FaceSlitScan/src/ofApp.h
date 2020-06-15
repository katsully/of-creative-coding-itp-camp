#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		// signed char, which gives you at least the -127 to 127 range. (-128 to 127 is common)
		// unsigned char, which gives you at least the 0 to 255 range.
		void setPixel(int horizontal, int vertical, unsigned char R,
			unsigned char G, unsigned char B, int w, unsigned char pixels[]);
		void getPixel(int horizontal, int vertical, unsigned char* R, unsigned char* G, unsigned char* B, int w,
			ofPixels pixels);

		ofVideoGrabber camera;

		int window_width = 1000;
		int draw_position_x = 0;
		int camWidth = 320;
		int camHeight = 240;
		int video_slice_x = camWidth / 2;
		int window_height = camHeight;

		ofTexture videoTexture;
		ofPixels vidpixels;
		unsigned char* texpixels;

		
};
