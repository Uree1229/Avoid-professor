#include <bangtal.h>

TimerID timer_b, timer_hp;
ObjectID hp_p[4];
extern SceneID sceneB;
extern int gametype;
extern ObjectID createObject(const char* image, SceneID scene, int x, int y, bool shown);
using namespace std;
int HP_p = 3, HP_b = 100;

void set_time() {
	timer_b = createTimer(1800.f);
	timer_hp = createTimer(1.0f);
	startTimer(timer_b);
	startTimer(timer_hp);
	showTimer(timer_b);

}
void setting_B() {
	showMessage("aaa"); //보스의 입장대사
	set_time();
	for (int i = 0; i < 3; i++) {
		hp_p[i] = createObject("Images/Heart.png", sceneB, 30 + 70 * i, 50, true);
	}
}
void hp_player() {

	if (HP_p >= 2 && HP_p < 3) { // hp=2
		hideObject(hp_p[2]);
	}
	else if (HP_p >= 1 && HP_p < 2) { //hp=1
		hideObject(hp_p[1]);
	}
	else if (HP_p >= 0 && HP_p < 1) { //hp=0
		hideObject(hp_p[0]);
	}
}
void hp_boss() {

}


void Mouse_callback_B(ObjectID object, int x, int y, MouseAction action) {
	if (gametype == 5) {
	}
}

void Keyboard_callback_B(KeyCode code, KeyState state) {
	if (gametype == 5) {
		if (code == KeyCode::KEY_DOWN_ARROW) { //숙이기

		}
		else if (code == KeyCode::KEY_LEFT_ARROW) {// 좌 이동

		}
		else if (code == KeyCode::KEY_RIGHT_ARROW) { //우 이동

		}
		else if (code == KeyCode::KEY_SPACE) {// 점프

		}

	}

}
void Timer_callback_B(TimerID timer) {
	if (timer == timer_hp) {

		hp_player();
		hp_boss();
		setTimer(timer_hp, 1.0f);
		startTimer(timer_hp);
	}
}