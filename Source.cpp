#include <bangtal.h>
#include "Stage1.h"
#include "Stage2.h"
#include "Stage3.h"
#include "Stage4.h"
#include "Main.h"

SceneID scene,scene1,scene2,scene3,scene4;
ObjectID door[3];


void Mouse_callback(ObjectID object, int x, int y, MouseAction action) {

	if(object == door[0]) enterScene(scene1);
	else if (object == door[1]) enterScene(scene2);
	else if (object == door[2]) enterScene(scene3);
	else if (object == door[3]) enterScene(scene4);
}

int main() {
	setMouseCallback(Mouse_callback);
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
