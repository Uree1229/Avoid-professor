#include <bangtal.h>

TimerID timer_b, timer_hp, Timer_sk1,Timer_range, timer_band;
ObjectID hp_p[4], Player, range;
extern SceneID sceneB;
extern int gametype;
extern int random_number(int start, int end);
extern ObjectID createObject(const char* image, SceneID scene, int x, int y, bool shown);
using namespace std;
int HP_p = 3, HP_b = 100, type, Player_x=0, Player_y=0,ply=120,sk1_x, sk1_y;
void boss_skill_1();

void set_time() {
	timer_b = createTimer(1800.f);
	timer_hp = createTimer(1.0f);
	Timer_sk1 = createTimer(3.0f);
	Timer_range = createTimer(0.5f);
	timer_band = createTimer(0.1f);
	startTimer(timer_b);
	startTimer(timer_hp);
	showTimer(timer_b);

}
void boss_attack() {
	type = random_number(1, 1);
	switch (type) {
	case 1:
		boss_skill_1();
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	}
}
void setting_B() {
	showMessage("aaa"); //보스의 입장대사
	set_time();
	for (int i = 0; i < 3; i++) {
		hp_p[i] = createObject("Images/Heart.png", sceneB, 30 + 70 * i, 50, true);
	}
	Player = createObject("Images/ch1.png", sceneB, Player_x,Player_y,true);
	boss_attack();
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

void boss_skill_1() { //F 범위 공격 100,100
	if (type == 1) {
		sk1_x = random_number(0, 1280), sk1_y = random_number(60, 80);
		range = createObject("Images/Range.png", sceneB, sk1_x, sk1_y, false);
		locateObject(range, sceneB, sk1_x, sk1_y);
		showObject(range);
		startTimer(Timer_sk1);
	}	
}
void boss_skill_2() { // 점프로 피하는 거

}
void boss_skill_3() { // 

}
void boss_skill_4() {

}
bool range_damage() {
	switch (type) {
	case 1:
		if (Player_x <= sk1_x + 100 && Player_x >= sk1_x && ply == 120) {
			return true;
		}
		else return false;
		break;

	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	}
}


void Mouse_callback_B(ObjectID object, int x, int y, MouseAction action) {
	if (gametype == 5) {
	}
}

void Keyboard_callback_B(KeyCode code, KeyState state) { // default = 0,0 -> 크기 70, 120
	if (gametype == 5) {
		if (code == KeyCode::KEY_DOWN_ARROW) { //숙이기  -  숙이면 높이 반으로 ㄱㄱ
			ply = 60;
			setObjectImage(Player, "Images/Heart.png");      // 숙이는 이미지 넣어야함
			startTimer(timer_band);
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
	else if (timer == Timer_sk1) {
		setObjectImage(range, "Images/F.png");
		setTimer(Timer_sk1, 3.0f);
		startTimer(Timer_range);
		if (range_damage() == true) {
			HP_p--;
		}
	}
	else if (timer == Timer_range) {
		hideObject(range);
		setTimer(Timer_range, 0.5f);
		if (type == 1) {
			boss_skill_1();
		}
		
	}
	else if (timer == timer_band) {
		ply = 120;
		setObjectImage(Player, "Images/ch1.png");
		setTimer(timer_band, 0.1f);
	}
}