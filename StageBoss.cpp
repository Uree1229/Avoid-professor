#include <bangtal.h>

TimerID timer_b, timer_hp, Timer_sk1,Timer_sk2,Timer_range, timer_band, timer_stop;
ObjectID hp_p[4], Player, range1,range2,range3;
extern SceneID sceneB;
extern int gametype;
extern int random_number(int start, int end);
extern ObjectID createObject(const char* image, SceneID scene, int x, int y, bool shown);
using namespace std;
int HP_p = 3, HP_b = 100, type=0, Player_x=0, Player_y=0,ply=120,sk1_x, sk1_y,sk2_x,sk2_y,
num_1=0,num_2=0;
void boss_skill_1();
void boss_skill_2();
void boss_skill_3();
void boss_skill_4();

void set_time() {
	timer_b = createTimer(1800.f);
	timer_hp = createTimer(1.0f);
	Timer_sk1 = createTimer(3.0f);
	Timer_sk2 = createTimer(3.0f);
	Timer_range = createTimer(0.5f);
	timer_band = createTimer(1.0f);
	timer_stop = createTimer(5.0f);
	startTimer(timer_b);
	startTimer(timer_hp);
	showTimer(timer_b);

}

void boss_attack() {
	if (type == 0) {
		type = random_number(1, 2);
	}
	switch (type) {
	case 1:
		boss_skill_1();
		break;
	case 2:
		boss_skill_2();
		break;
	case 3:
		boss_skill_3();
		break;
	case 4:
		boss_skill_4();
		break;
		}
	}
	
void setting_B() {
	showMessage("aaa"); //보스의 입장대사
	set_time();
	for (int i = 0; i < 3; i++) {
		hp_p[i] = createObject("Images/Heart.png", sceneB, 30 + 70 * i, 50, true);
	}
	Player = createObject("Images/ch1.png", sceneB, Player_x,Player_y, true);
	startTimer(timer_stop);
	
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
		range1 = createObject("Images/Range.png", sceneB, sk1_x, sk1_y, false);
		locateObject(range1, sceneB, sk1_x, sk1_y);
		showObject(range1);
		startTimer(Timer_sk1);
		num_1++;
		
	}	
}
void boss_skill_2() { // 점프로 피하는 거
	if (type == 2) {
		sk2_x = random_number(0,1250), sk2_y = random_number(0, 29);
		range2 = createObject("Images/range1.png", sceneB, 0, sk2_y, false);
		range3 = createObject("Images/range2.png", sceneB, sk2_x, 0, false);
		locateObject(range2, sceneB, 0, sk2_y);
		locateObject(range3, sceneB, sk2_x, 0);
		showObject(range2);
		showObject(range3);
		startTimer(Timer_sk2);
		num_2++;
	}
}
void boss_skill_3() { // 

}
void boss_skill_4() {// 허깅상태

}
bool range_damage() {
	switch (type) {
	case 1:
		if (Player_x < sk1_x + 100 && Player_x > sk1_x-70 && ply == 120) {
			return true;
		}
		else return false;
		break;

	case 2:
		if (Player_y < sk2_y+20 || (sk2_x > Player_x-30 && sk2_x < Player_x+70)) {
			return true;
		}
		else return false;
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
		else if (code == KeyCode::KEY_LEFT_ARROW) {// 좌 이동 dex로 스피드 조정

		}
		else if (code == KeyCode::KEY_RIGHT_ARROW) { //우 이동

		}
		else if (code == KeyCode::KEY_SPACE) {// 점프 고정 y +50

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
		setObjectImage(range1, "Images/F.png");
		setTimer(Timer_sk1, 3.0f);
		startTimer(Timer_range);
		if (range_damage() == true) {
			HP_p--;
		}
	}
	else if (timer == Timer_sk2) {
		setObjectImage(range2, "Images/E.png");
		setObjectImage(range3, "Images/E-1.png");
		setTimer(Timer_sk2, 3.0f);
		startTimer(Timer_range);
		if (range_damage() == true) {
			HP_p--;
		}
	}
	else if (timer == Timer_range) {
	
		setTimer(Timer_range, 0.5f);
		if (type == 1) {
			hideObject(range1);
			if (num_1 == 5) {
				type = 4;
				num_1 = 0;
				boss_attack();
			}else boss_skill_1(); 
			
		}
		else if (type == 2) {
			hideObject(range2);
			hideObject(range3);
			if (num_2 ==5) {
				type = 4;
				num_2 = 0;
				boss_attack();
			}
			else boss_skill_2();
		}
		
	}
	else if (timer_stop) {
		boss_attack();
		setTimer(timer_stop, 5.0f);
		//startTimer(timer_stop);
	}
	else if (timer == timer_band) {
		ply = 120;
		setObjectImage(Player, "Images/ch1.png");
		setTimer(timer_band, 1.0f);
	}
}