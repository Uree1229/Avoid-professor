#include <bangtal.h> //rhythm game
#include <string.h>
#include <string>

using namespace std;

TimerID timer_cr, timer_del, timer_cre, timer_drop;

extern SceneID scene, scene3, scene_stat;
extern ObjectID createObject(const char* image, SceneID scene, int x, int y, bool shown);
extern int random_number(int start, int end);
ObjectID start, keyblock[4], note[100], heart1, heart2, heart3, DEX[6], fxxk;
extern ObjectID door[4];
extern int gametype;
int keytype = 100, heart = 3, score_stack = 0, score = 0, notetype = 0, keyblock_x = 590, keyblock_y = 310, key_state = 0, speed = 100, note_stack = 0, note_x[200], note_y[200], note_s[200];
Second time_DEL = 0.25f;

void note_add() {

	for (int i = 0; i < 100; i++) {
		int num = random_number(1, 4);
		switch (num)
		{
		case 1: //down

			note_x[i] = 590;
			note_y[i] = 670;
			note[i] = createObject("Images/note.png", scene3, note_x[i], note_y[i], false);
			note_s[i] = 1;
			break;

		case 2: //up

			note_x[i] = 590;
			note_y[i] = 0;
			note[i] = createObject("Images/note.png", scene3, note_x[i], note_y[i], false);
			note_s[i] = 2;
			break;

		case 3: // right

			note_x[i] = 0;
			note_y[i] = 310;
			note[i] = createObject("Images/note_turn.png", scene3, note_x[i], note_y[i], false);
			note_s[i] = 3;
			break;

		case 4: //left

			note_x[i] = 1280;
			note_y[i] = 310;
			note[i] = createObject("Images/note_turn.png", scene3, note_x[i], note_y[i], false);
			note_s[i] = 4;
			break;
		}
	}

}
void setting_3() {
	timer_del = createTimer(time_DEL);
	start = createObject("Images/start.png", scene3, 200, 200, true);
	heart1 = createObject("Images/Heart.png", scene3, 30, 40, true);
	heart2 = createObject("Images/Heart.png", scene3, 100, 40, true);
	heart3 = createObject("Images/Heart.png", scene3, 170, 40, true);
	for (int i = 0; i < 5; i++) {
		DEX[i] = createObject("Images/DEX.png", scene_stat, 204 + i * 137, 47, false);
	}
	note_add();
	timer_drop = createTimer(0.01f);
	timer_cr = createTimer(5.0f);
}
void stat_check_DEX() {
	if (score_stack > 55) {
		showObject(DEX[4]);
		showObject(DEX[3]);
		showObject(DEX[2]);
		showObject(DEX[1]);
		showObject(DEX[0]);
	}
	else if (score_stack <= 55 && score_stack > 45) {
		showObject(DEX[3]);
		showObject(DEX[2]);
		showObject(DEX[1]);
		showObject(DEX[0]);
	}
	else if (score_stack <= 45 && score_stack > 35) {
		showObject(DEX[2]);
		showObject(DEX[1]);
		showObject(DEX[0]);
	}
	else if (score_stack <= 35 && score_stack > 25) {
		showObject(DEX[1]);
		showObject(DEX[0]);
	}
	else if (score_stack <= 25 && score_stack > 15) {
		showObject(DEX[0]);
	}

}

void endgame_3() {
	fxxk = createObject("Images/fXXk.png", scene_stat, 400, 460, true);
	enterScene(scene_stat);
	const char* sc_f;
	score_stack = score;
	string sc = to_string(score_stack);
	sc_f = sc.c_str();
	showMessage(sc_f);



	stat_check_DEX();
	gametype = -1;
	startTimer(timer_cr);


}                      //130*56

void Timer_callback_3(TimerID timer) {
	if (timer == timer_del && heart > 0) {

		if (keytype == 1) { //down
			hideObject(keyblock[0]);
		}
		else if (keytype == 2) { //up
			hideObject(keyblock[1]);
		}
		else if (keytype == 3) { //right
			hideObject(keyblock[2]);
		}
		else if (keytype == 4) { //left
			hideObject(keyblock[3]);
		}

		keytype = 0;

		setTimer(timer_del, time_DEL);

	}
	else if (timer == timer_drop) {

		if (note_s[note_stack] == 1) { //down
			showObject(note[note_stack]);
			note_y[note_stack] = note_y[note_stack] - speed * (0.1) * (0.5 * score + 1);
			locateObject(note[note_stack], scene3, note_x[note_stack], note_y[note_stack]);

			if (note_y[note_stack] < 310) {
				hideObject(note[note_stack]);
				note_stack++;
				heart--;


			}
		}
		else if (note_s[note_stack] == 2) { //up
			showObject(note[note_stack]);
			note_y[note_stack] = note_y[note_stack] + speed * (0.1) * (0.5 * score + 1);
			locateObject(note[note_stack], scene3, note_x[note_stack], note_y[note_stack]);

			if (note_y[note_stack] > 360) {
				hideObject(note[note_stack]);
				note_stack++;
				heart--;

			}
		}
		else if (note_s[note_stack] == 3) { //right
			showObject(note[note_stack]);
			note_x[note_stack] = note_x[note_stack] + speed * (0.1) * (0.5 * score + 1);
			locateObject(note[note_stack], scene3, note_x[note_stack], note_y[note_stack]);

			if (note_x[note_stack] > 640) {
				hideObject(note[note_stack]);
				note_stack++;
				heart--;

			}
		}
		else if (note_s[note_stack] == 4) { //left
			showObject(note[note_stack]);
			note_x[note_stack] = note_x[note_stack] - speed * (0.1) * (0.5 * score + 1);
			locateObject(note[note_stack], scene3, note_x[note_stack], note_y[note_stack]);

			if (note_x[note_stack] < 590) {
				hideObject(note[note_stack]);
				note_stack++;
				heart--;

			}
		}
		setTimer(timer_drop, 0.01f);
		if (heart == 3) {
			startTimer(timer_drop);
		}
		else if (heart >= 2 && heart < 3) { // hp=2

			hideObject(heart3);
			startTimer(timer_drop);
		}
		else if (heart >= 1 && heart < 2) { //hp=1
			hideObject(heart2);
			startTimer(timer_drop);
		}
		else if (heart >= 0 && heart < 1) { //hp=0
			hideObject(heart1);
			stopTimer(timer_drop);
			endgame_3();

		}



	}
	else if (timer == timer_cr) {
		hideObject(fxxk);
		gametype = 0;
		setTimer(timer_cr, 5.0f);
		
	}

}

void Mouse_callback_3(ObjectID object, int x, int y, MouseAction action) {
	if (object == start) {
		keytype = 0;
		hideObject(start);
		startTimer(timer_drop);
	}
}


void Keyboard_callback_3(KeyCode key, KeyState state) {
	if (state == KeyState::KEY_PRESSED) { //key_state = block keyboard error

		if (gametype == 3 && keytype == 0) {
			switch (key) {

			case KeyCode::KEY_DOWN_ARROW:
				keytype = 1;

				keyblock[0] = createObject("Images/Down-arrow.png", scene3, keyblock_x, keyblock_y, true);

				if (note_y[note_stack] < 360 && note_y[note_stack] > 260 && note_s[note_stack] == 2) {
					hideObject(note[note_stack]);
					note_stack++;
					score++;
				}
				startTimer(timer_del);
				break;

			case KeyCode::KEY_UP_ARROW:
				keytype = 2;

				keyblock[1] = createObject("Images/Up-arrow.png", scene3, keyblock_x, keyblock_y, true);
				if (note_y[note_stack] < 410 && note_y[note_stack] > 310 && note_s[note_stack] == 1) {
					hideObject(note[note_stack]);
					note_stack++;
					score++;
				}

				startTimer(timer_del);
				break;

			case KeyCode::KEY_RIGHT_ARROW:
				keytype = 3;

				keyblock[2] = createObject("Images/Right-arrow.png", scene3, keyblock_x, keyblock_y, true);
				if (note_x[note_stack] < 690 && note_x[note_stack] > 590 && note_s[note_stack] == 4) {
					hideObject(note[note_stack]);
					note_stack++;
					score++;
				}
				startTimer(timer_del);
				break;

			case KeyCode::KEY_LEFT_ARROW:
				keytype = 4;

				keyblock[3] = createObject("Images/Left-arrow.png", scene3, keyblock_x, keyblock_y, true);

				if (note_x[note_stack] < 640 && note_x[note_stack] > 540 && note_s[note_stack] == 3) {
					hideObject(note[note_stack]);
					note_stack++;
					score++;
				}
				startTimer(timer_del);
				break;

			}


		}

	}
}