#include <bangtal.h> //rhythm game

using namespace std;

extern TimerID timerA;
extern ObjectID keyblock[4];
extern SceneID scene, scene1, scene2, scene3, scene4;
extern ObjectID door[4];
ObjectID createObject(const char* image, SceneID scene, int x, int y, bool shown);

extern int keytype;
extern int gametype;
int keytype = 1;

extern void setting4() {
	
	timerA = createTimer(1.0);
}

extern void Timer_callback3(TimerID timer) {
	if (timer == timerA) {

		if (keytype == 1) { //down
			keyblock[0] = createObject("Images/Down-arrow.png", scene, 100, 200, true);
		}
		else if (keytype == 2) { //up
			keyblock[1] = createObject("Images/Down-arrow.png", scene, 100, 200, true);
		}
		else if (keytype == 3) { //right
			keyblock[2] = createObject("Images/Down-arrow.png", scene, 100, 200, true);
		}
		else if (keytype == 4) { //left
			keyblock[3] = createObject("Images/Down-arrow.png", scene, 100, 200, true);
		}
	}
}
extern void Keyboard_callback3(KeyCode key, KeyState state) {
	if (gametype == 4) {
		switch (key) {
		
		case KeyCode::KEY_DOWN_ARROW:
			keytype = 1;
			startTimer(timerA);
			break;

		case KeyCode::KEY_UP_ARROW:
			keytype = 1;
			startTimer(timerA);
			break;

		case KeyCode::KEY_RIGHT_ARROW:
			keytype = 1;
			startTimer(timerA);
			break;

		case KeyCode::KEY_LEFT_ARROW:
			keytype = 1;
			startTimer(timerA);
			break;

		}
	}
}
