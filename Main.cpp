#include <bangtal.h>
#include <random>

extern TimerID timerA;
extern ObjectID keyblock[4];
extern SceneID scene, scene1, scene2, scene3, scene4;
extern ObjectID door[4];
extern void Mouse_callback_m(ObjectID object, int x, int y, MouseAction action);
extern void Keyboard_callback3(KeyCode key, KeyState state);


using namespace std;

ObjectID createObject(const char* image, SceneID scene, int x, int y, bool shown) {

	ObjectID object = createObject(image);
	locateObject(object, scene, x, y);

	if (shown) {
		showObject(object);
	}
	return object;
}

int random_number(int start, int end) {
	random_device rd;
	mt19937_64 rdn(rd());
	uniform_int_distribution<int> dis(start, end);

	return dis(rdn);
}

int main() {
	setMouseCallback(Mouse_callback_m);
	setKeyboardCallback(Keyboard_callback3);
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
