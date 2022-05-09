#include <bangtal.h>
#include <random>

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