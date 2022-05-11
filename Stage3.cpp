#include <bangtal.h> //rhythm game

using namespace std;

TimerID timer_cr, timer_del;
extern ObjectID keyblock[4];
extern SceneID scene, scene1, scene2, scene3, scene4;
extern ObjectID door[4];
ObjectID createObject(const char* image, SceneID scene, int x, int y, bool shown);


extern int gametype;
int keytype = 0, keyblock_x = 590, keyblock_y = 360, key_state = 0;
Second time_DEL = 0.25f;

void setting4() {
	timer_del = createTimer(time_DEL);
	
	
}

void Timer_callback3(TimerID timer) {
	if (timer == timer_del) {

		if (keytype == 1) { //down
			hideObject(keyblock[0]);
		}
		else if (keytype == 2) { //up
			hideObject(keyblock[1]);
		}
		else if (keytype == 3) { //right
			hideObject(keyblock[2]);
		}
		else if (keytype == 4) { //left
			hideObject(keyblock[3]);
		}
		
		keytype = 0;
		
		setTimer(timer_del, time_DEL);
		
	}
}
void Keyboard_callback3(KeyCode key, KeyState state) {
	if (state == KeyState::KEY_PRESSED) { //key_state = block keyboard error
		
		if (gametype == 4 && keytype == 0) {
			switch (key) {

			case KeyCode::KEY_DOWN_ARROW:
				keytype = 1;
				
				keyblock[0] = createObject("Images/Down-arrow.png", scene4, keyblock_x, keyblock_y, true);
				startTimer(timer_del);
				break;

			case KeyCode::KEY_UP_ARROW:
				keytype = 2;
				
				keyblock[1] = createObject("Images/Up-arrow.png", scene4, keyblock_x, keyblock_y, true);
				startTimer(timer_del);
				break;

			case KeyCode::KEY_RIGHT_ARROW:
				keytype = 3;
				
				keyblock[2] = createObject("Images/Right-arrow.png", scene4, keyblock_x, keyblock_y, true);
				startTimer(timer_del);
				break;

			case KeyCode::KEY_LEFT_ARROW:
				keytype = 4;
				
				keyblock[3] = createObject("Images/Left-arrow.png", scene4, keyblock_x, keyblock_y, true);
				startTimer(timer_del);
				break;

			}

	}
	}
}
