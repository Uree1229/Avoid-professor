#include <bangtal.h>

TimerID timer_b;
extern int gametype;
void setting_B() {
	showMessage(""); //보스의 입장대사
	set_time();
}


void set_time() {
	timer_b = createTimer(1800.f);
	startTimer(timer_b);
	showTimer(timer_b);
}
void mouseCallback_B(ObjectID object, int x, int y, MouseAction action) {
	if (gametype == 5) {

	}
}

void keyboardCallback_B(KeyCode code, KeyState state) {
	if (gametype == 5) {

	}

}