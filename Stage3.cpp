#include <bangtal.h> //rhythm game

using namespace std;

TimerID timerA;

int gametype;

void setting4() {
	gametype = 4;
	timerA = createTimer(1.0);
}

void Timer_callback(TimerID timer) {
	if (timer == timerA) {

	}
}
void Keyboard_callback(KeyCode key, KeyState state) {
	if (gametype == 4) {
		switch (key) {
		
		case KeyCode::KEY_DOWN_ARROW:
			startTimer(timerA);
			break;
		case KeyCode::KEY_UP_ARROW:

			break;
		case KeyCode::KEY_RIGHT_ARROW:

			break;
		case KeyCode::KEY_LEFT_ARROW:

			break;

		}
	}
}
