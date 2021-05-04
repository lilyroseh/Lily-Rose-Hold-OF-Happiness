#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetCircleResolution(100);
    
    shader.load("", "shader.frag");
    
    img.load("flower1.png");

}

//--------------------------------------------------------------
void ofApp::update(){
     if (ofGetFrameNum() % 60 == 0){
            shader.load("", "shader.frag");
        }
    

}

//--------------------------------------------------------------
void ofApp::draw(){
    
       ofBackground(0);
       
       //img.draw(0,0);
       ofSetColor(0);

       shader.begin();
       shader.setUniform1f("time", ofGetElapsedTimef());
       shader.setUniform2f("mousePos", mouseX, mouseY);
       shader.setUniformTexture("img", img.getTexture(), 0);
       //ofDrawRectangle(0,0, 800,800);
       //ofDrawCircle(400,400,250);
    //ofPolyline line;
       for (int j = 0; j < 10; j++){
       float amt = ofMap(j, 0, 10, 0, 1);
       for (int i = 0; i < 10; i++){
           float angle = ofMap(i, 0, 10, 0, TWO_PI);
           float radius = 250;
           //radius += ofRandom(-mouseX, mouseX);
           float x = 400 + cos(angle) * radius;
           float y = 400 + sin(angle) * radius;
           ofPoint circlePt(x,y);
           ofPoint mouse(mouseX, mouseY);
           float distance = (circlePt - mouse).length();
           float strength = ofMap(distance, 0, 1000, 1, 0, true);
           strength = powf(strength, 2.4);
           ofPoint dir = (circlePt - mouse).getNormalized();
           circlePt += dir * strength * 300 * amt;
           //line.addVertex(circlePt.x,circlePt.y);
           ofDrawCircle(circlePt.x,circlePt.y,powf(amt, 2.0) * 10 + 30);
       }
//       line.setClosed(true);
//
//       for (int i = 0; i < line.size(); i++){
//           line[i].x += ofSignedNoise( line[i].x*0.1, line[i].y*0.1, mouseX*0.03)*mouseY;
//
//       }
       
       
       
       
       ofSetLineWidth(200);
       
       //line.draw();
       
//       ofBeginShape();
//       for (int i = 0; i < line.size(); i++){
//           ofVertex(line[i]);
//       }
//       ofEndShape();
       
       shader.end();
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
