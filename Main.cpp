#include <bangtal.h>
#include <random>

extern SceneID scene;
extern void Mouse_callback_m(ObjectID object, int x, int y, MouseAction action);
extern void Mouse_callback_3(ObjectID object, int x, int y, MouseAction action);
extern void Keyboard_callback_3(KeyCode key, KeyState state);
extern void Timer_callback_3(TimerID timer);
extern void setting_m();

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
void mouseCallback(ObjectID object, int x, int y, MouseAction action) {
	Mouse_callback_m(object, x, y, action);
	Mouse_callback_3(object, x, y, action);
}

void keyboardCallback(KeyCode code, KeyState state) {
	Keyboard_callback_3(code, state);
}

void soundCallback(SoundID sound) {
}

void timerCallback(TimerID timer) {
	Timer_callback_3(timer);
}

int main() {
	setMouseCallback(mouseCallback);
	setKeyboardCallback(keyboardCallback);
	setSoundCallback(soundCallback);
	setTimerCallback(timerCallback);
	setting_m();

	startGame(scene);
}