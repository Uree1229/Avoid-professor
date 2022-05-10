#include <bangtal.h>

          // gametype = 0 ∏ﬁ¿Œ, 1 = stage1, 2=stage2, 3=stage3, 4=stage4, 5=bossstage
int gametype = 0;
TimerID timerA;
ObjectID keyblock[4];
SceneID scene, scene1, scene2, scene3, scene4;
ObjectID door[4];

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
		}
		else if (object == door[3]) {
			gametype = 4;
			enterScene(scene4);
		}
	}

	
}



