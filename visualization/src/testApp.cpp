#include "testApp.h"
#include "Poco/DateTimeFormatter.h"
#include "Poco/DateTimeFormat.h"
#include "Poco/DateTime.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofEnableAlphaBlending();
	ofBackground(0);
	ofSetVerticalSync(true);
	wall.setup();

	twitterListener.setup();

	LEDStrip::initClassParameters();
	EnergyBurst::initClassParameters();

	gui.setup("parameters");
	gui.add(currentTag.setup("",twitterListener.hashtag));
	gui.add(changeTag.setup("changeHashtag"));
	gui.add(startTest.setup("startTest"));
	gui.add(LEDStrip::parameters);
	gui.add(EnergyBurst::parameters);
	gui.add(twitterListener.parameters);
	gui.add(wall.parameters);
	gui.loadFromFile("settings.xml");

	//twitterListener.hashtag = "#RedLeaf";
	changeTag.addListener(this,&testApp::changeHashTag);
	startTest.addListener(this,&testApp::startTestPressed);

	ofAddListener(twitterListener.newTweetE,this,&testApp::newTweet);
	twitterListener.start();
}

void testApp::changeHashTag(bool & pressed){
	if(!pressed) twitterListener.hashtag = ofSystemTextBoxDialog("new hashtag",twitterListener.hashtag);
}

void testApp::startTestPressed(bool & pressed){
	if(!pressed) wall.startTest();
}

//--------------------------------------------------------------
void testApp::update(){
	wall.update();
}

//--------------------------------------------------------------
void testApp::draw(){
	wall.draw();
	gui.draw();
	Poco::LocalDateTime date;
	ofDrawBitmapString(Poco::DateTimeFormatter::format(date,Poco::DateTimeFormat::ASCTIME_FORMAT ),ofGetWidth()-210,20);
}

void testApp::newTweet(const Tweet & tweet){
	wall.energyBurst(ofRandom(1),.5,wall.useColors ? wall.niceRandomColor() : ofColor::white);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
