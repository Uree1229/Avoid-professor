#include <bangtal.h> //rhythm game

using namespace std;

TimerID timer_cr, timer_del, timer_cre, timer_drop;

extern SceneID scene, scene1, scene2, scene3, scene4;
extern ObjectID createObject(const char* image, SceneID scene, int x, int y, bool shown);

ObjectID start, keyblock[4], note[100];

extern int gametype;
int keytype = 100, notetype = 0, keyblock_x = 590, keyblock_y = 360, key_state = 0, speed = 10, note_stack=0, note_x=0 ,note_y=0;
Second time_DEL = 0.25f;

void setting_3() {
	timer_del = createTimer(time_DEL);
	start = createObject("Images/start.png", scene3, 200, 200, true);
	timer_cre = createTimer(10.f);
	timer_drop = createTimer(0.1f);
}
void note_drop() {
	if (notetype == 0) {
		
	}
	else if (note) {

	}
}

void Timer_callback_3(TimerID timer) {
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
	else if (timer == timer_cre) {
		note[note_stack] = createObject("Images/note.png", scene3, note_x, note_y, false);
		note_stack++;
		speed += 10;
	}
	else if (timer == timer_drop) {
		note_x = note_x + speed;
		note_y = note_y + speed;
		setTimer(timer_drop, 0.1f);
	}
}

void Mouse_callback_3(ObjectID object, int x, int y, MouseAction action) {
	if (object == start) {
		keytype = 0;
		hideObject(start);
	}
}

void Keyboard_callback_3(KeyCode key, KeyState state) {
	if (state == KeyState::KEY_PRESSED) { //key_state = block keyboard error
		
		if (gametype == 3 && keytype == 0) {
			switch (key) {

			case KeyCode::KEY_DOWN_ARROW:
				keytype = 1;
				
				keyblock[0] = createObject("Images/Down-arrow.png", scene3, keyblock_x, keyblock_y, true);
				startTimer(timer_del);
				break;

			case KeyCode::KEY_UP_ARROW:
				keytype = 2;
				
				keyblock[1] = createObject("Images/Up-arrow.png", scene3, keyblock_x, keyblock_y, true);
				startTimer(timer_del);
				break;

			case KeyCode::KEY_RIGHT_ARROW:
				keytype = 3;
				
				keyblock[2] = createObject("Images/Right-arrow.png", scene3, keyblock_x, keyblock_y, true);
				startTimer(timer_del);
				break;

			case KeyCode::KEY_LEFT_ARROW:
				keytype = 4;
				
				keyblock[3] = createObject("Images/Left-arrow.png", scene3, keyblock_x, keyblock_y, true);
				startTimer(timer_del);
				break;

			}

	}
	}
}
