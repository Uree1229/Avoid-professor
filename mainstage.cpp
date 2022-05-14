#include <bangtal.h>

// gametype = 0 ∏ﬁ¿Œ, 1 = stage1, 2=stage2, 3=stage3, 4=stage4, 5=bossstage

extern void setting_3();
extern ObjectID createObject(const char* image, SceneID scene, int x, int y, bool shown);
int gametype = 0;


SceneID scene, scene1, scene2, scene3, scene4;
ObjectID door[4];

void setting_m() {
	scene = createScene("main", "Images/back.png");
	scene1 = createScene("main", "Images/scene1.png");
	scene2 = createScene("main", "Images/scene2.png");
	scene3 = createScene("main", "Images/scene3.png");
	scene4 = createScene("main", "Images/scene4.png");

	for (int i = 0; i < 4; i++) {
		door[i] = createObject("Images/door.png", scene, i * 300 + 100, i + 100, true);
	}
}

void Mouse_callback_m(ObjectID object, int x, int y, MouseAction action) {

	if (gametype == 0) {
		if (object == door[0]) {
			gametype = 1;
			enterScene(scene1);
		}
		else if (object == door[1]) {
			gametype = 2;
			enterScene(scene2);
		}
		else if (object == door[2]) {
			gametype = 3;
			enterScene(scene3);
			setting_3();
		}
		else if (object == door[3]) {
			gametype = 4;
			enterScene(scene4);
			
		}
	}

	
}



