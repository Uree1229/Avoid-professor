#include <bangtal.h>
#include "Stage1.h"
#include "Stage2.h"
#include "Stage3.h"
#include "Stage4.h"
#include "Main.h"

extern int gametype = 0;          // gametype = 0 ∏ﬁ¿Œ, 1 = stage1, 2=stage2, 3=stage3, 4=stage4, 5=bossstage
SceneID scene,scene1,scene2,scene3,scene4;
ObjectID door[4];


void Mouse_callback(ObjectID object, int x, int y, MouseAction action) {

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
		}
		else if (object == door[3]) {
			gametype = 4;
			enterScene(scene4);
		}
	}

	
}



int main() {
	setMouseCallback(Mouse_callback);
	setKeyboardCallback(Keyboard_callback);
	scene = createScene("main", "Images/back.png");
	scene1 = createScene("main", "Images/scene1.png");
	scene2 = createScene("main", "Images/scene2.png");
	scene3 = createScene("main", "Images/scene3.png");
	scene4 = createScene("main", "Images/scene4.png");
	

	for (int i = 0; i < 4; i++) {
		door[i] = createObject("Images/door.png", scene, i * 300 + 100, i + 100, true);
	}


	startGame(scene);
}
