#include <bangtal.h>

// gametype = 0 ¸ÞÀÎ, 1 = stage1, 2=stage2, 3=stage3, 4=stage4, 5=bossstage
SoundID start_bgm, boss_bgm;


extern void setting_1();  // stage1
extern void main_2();     // stage2
extern void setting_3();
extern void setting_B();  //stage boss
extern int Quiz_stage4(); //stage4
extern TimerID first_Timer;
extern void setting_B();
extern ObjectID createObject(const char* image, SceneID scene, int x, int y, bool shown);
int gametype = -2, type_type=0;
using namespace std;

SceneID scene_back,scene, scene1, scene2, scene3, scene4, scene_stat, sceneB;
ObjectID door[5], start_game;

void setting_m() {

	scene_back = createScene("background", "Images/back.png");
	scene = createScene("main", "Images/main.png");
	scene1 = createScene("1", "Images/ap_scene.png");
	scene2 = createScene("2", "Images/scene2.png");
	scene3 = createScene("3", "Images/scene3.png");
	scene4 = createScene("4", "Images/scene4.png");
	sceneB = createScene("Boss","Images/scene_B.png"); 
	scene_stat = createScene("stat", "Images/stat.png");
	for (int i = 0; i < 5; i++) {
		door[i] = createObject("Images/door.png", scene, 55, 370-68*i , true);
		scaleObject(door[i], 1.5f);
	}
	start_bgm = createSound("Sounds/start_bgm.mp3");
	boss_bgm = createSound("Sounds/boss_bgm.mp3");

	start_game = createObject("Images/startbutton.png", scene_back, 640, 220, true);
}

void Mouse_callback_m(ObjectID object, int x, int y, MouseAction action) {
	if (gametype == -2&& object == start_game) {
		enterScene(scene);
		gametype = 0;
	}
	if (gametype == 0) {
		if (object == door[0] && type_type ==0) {
			gametype = 1;
			enterScene(scene1);
			setObjectImage(door[0], "Images/check.png");
			setting_1();
			type_type = 1;
			
		}
		else if (object == door[1] && type_type == 1) {
			gametype = 2;
			enterScene(scene2);
			setObjectImage(door[1], "Images/check.png");
			main_2();
			type_type = 2;
			setTimer(first_Timer, 900.f);
		}
		else if (object == door[2] && type_type == 2) {
			gametype = 3;
			enterScene(scene3);
			setObjectImage(door[2], "Images/check.png");
			setting_3();
			type_type = 3;
			setTimer(first_Timer, 1080.f);
		}
		else if (object == door[3] && type_type == 3) {
			gametype = 4;
			enterScene(scene4);
			setObjectImage(door[3], "Images/check.png");
			Quiz_stage4();
			type_type = 4;
			setTimer(first_Timer, 1260.f);

		}
		else if (object == door[4] && type_type == 4) {
			gametype = 5;
			enterScene(sceneB);
			setObjectImage(door[4], "Images/check.png");
			setting_B();
			type_type = 5;
			setTimer(first_Timer, 1410.f);
			playSound(boss_bgm);
			stopSound(start_bgm);
		}
	}
}
void Keyboard_callback_m(KeyCode key, KeyState state) {
		if (gametype == 0 && key == KeyCode::KEY_E) {
			enterScene(scene_stat);
			gametype = -1;
		}
		else if (gametype == -1 && key == KeyCode::KEY_ESCAPE) {
			enterScene(scene);
			gametype = 0;
		}	
}


