#define _CRT_SECURE_CPP_OVERLOAD_STANDARD_NAMES   1
using namespace std;

#include <windows.h> 
#include <stdio.h>
#include <bangtal.h>
#include <time.h>

ObjectID STR[6];
ObjectID  ch1, hit_box, fxxk_1;
extern SceneID scene1, scene_stat, scene;
<<<<<<< Updated upstream
TimerID enemyTimer, playerJumpTimer, check_l, hitbox_Timer, jumpR_Timer, hitM_Timer, back_Timer,first_Timer;
=======
TimerID enemyTimer, playerJumpTimer, check_l, hitbox_Timer, jumpR_Timer, hitM_Timer, back_Timer, first_Timer;
>>>>>>> Stashed changes
extern int gametype;
extern ObjectID door[4];

clock_t start;
float time_d;

ObjectID floor_ob[100], c_life[3];
int check_hit[100];
int f_x = 250, str = 0;
int f_y[100];
int ch_y = 20;
int ch_x = 620;
int vel;
float gravity = -12;
int check = 0;
int hit_x = 580;
int hit_y = 120;
bool c_timer = false;
bool c_jump = false;
bool hit_check = false;
float speed = 1.;
int life = 3;
int jridx, jdidx, hitidx = 0;

#define ANIMATION_TIME      0.01f
#define ANIMATION_STEP      5

extern ObjectID createObject(const char* image, SceneID scene, int x, int y, bool shown);

char Jump_Ready[3][14] = {
   "images/N2.png",
   "images/N3.png",
   "images/N4.png",
};
char Jump[3][14] = {
   "images/N5.png",
   "images/N6.png",
   "images/N7.png"
};
char Hit_M[2][14] = {
   "images/N8.png",
   "images/N9.png"
};

void setting_1() {
    f_y[0] = 600;
    ch1 = createObject("images/ch1.png", scene1, ch_x, ch_y, true);
    srand((unsigned int)time(NULL));
    char image[100];
    for (int i = 0; i < 100; i++) {
        f_x = f_x;
        f_y[i] = 600 + 150 * i;
        int x = rand() % 3;
        sprintf(image, "Images/%d.png", x + 1);

        floor_ob[i] = createObject(image, scene1, f_x, f_y[i], true);
        check_hit[i] = x + 1;
    }
    for (int i = 0; i < 3; i++) {
        c_life[i] = createObject("images/Heart.png", scene1, 50 + 60 * i, 100, true);
    }
    hit_box = createObject("Images/hitbox.png", scene1, hit_x, hit_y, false);

    for (int i = 0; i < 5; i++) {
        STR[i] = createObject("Images/STR.png", scene_stat, 204 + i * 137, 337, false);
    }

    enemyTimer = createTimer(ANIMATION_TIME);
    playerJumpTimer = createTimer(0.06f);
    hitbox_Timer = createTimer(0.06f);
    jumpR_Timer = createTimer(0.03f);
    hitM_Timer = createTimer(0.029f);
    back_Timer = createTimer(1.0f);
    first_Timer = createTimer(720.00f);
    showTimer(first_Timer);

    startTimer(enemyTimer);
}

bool check_crush_apt(int x, int y, int rx, int ry, int size) {
    return (y >= ry) && (y <= ry + size);
}

bool collided_apt(int i) {
    return check_crush_apt(ch_x, ch_y + 100, f_x, f_y[i], 150);
}

bool collided_hit_apt(int i) {
    return check_crush_apt(hit_x, hit_y + 50, f_x, f_y[i], 150);
}

void stat_check_STR() {
    if (life == 3) {
        str = 5;
        showObject(STR[4]);
        showObject(STR[3]);
        showObject(STR[2]);
        showObject(STR[1]);
        showObject(STR[0]);
    }
    else if (life == 2) {
        str = 4;
        showObject(STR[3]);
        showObject(STR[2]);
        showObject(STR[1]);
        showObject(STR[0]);
    }
    else if (life == 1) {
        str = 3;
        showObject(STR[1]);
        showObject(STR[0]);
    }
    else if (life == 0) {
        str = 2;
        showObject(STR[0]);
    }
    else {
        str = 1;
    }
}

void endgame_1() {
    fxxk_1 = createObject("Images/fXXk.png", scene_stat, 400, 460, true);
    enterScene(scene_stat);
    stat_check_STR();
    gametype = -1;
    startTimer(back_Timer);
}

void Timer_callback_1(TimerID timer)
{
    if (gametype == 1) {
        if (timer == enemyTimer) {
            bool c_apt_ch = false;
            int c_i;
            for (int i = 0; i < 100; i++) {
                gravity -= 0.000003;
                speed += 0.000002;
                f_y[i] -= speed;
                if (collided_apt(i)) {
                    c_i = i;
                    c_apt_ch = true;
                }
                locateObject(floor_ob[i], scene1, f_x, f_y[i]);
            }
            if (c_apt_ch) {
                ch_y = f_y[c_i] - 100;
                vel = -4;
                locateObject(ch1, scene1, ch_x, ch_y += vel);
                if (f_y[c_i] < 120) {
                    life -= 1;
                    hideObject(floor_ob[c_i]);
                    locateObject(floor_ob[c_i], scene1, f_x, f_y[c_i] += f_y[99]);
                    hideObject(c_life[life]);
                    if (life == 0) {
                        endgame_1();
                        stopTimer(enemyTimer);
                    }
                }
            }
            setTimer(enemyTimer, ANIMATION_TIME);
            startTimer(enemyTimer);
        }
        if (timer == jumpR_Timer) {
            setObjectImage(ch1, Jump_Ready[jridx]);
            jridx++;
            setTimer(jumpR_Timer, 0.3f);
            startTimer(jumpR_Timer);


            if (jridx > 2) {
                stopTimer(jumpR_Timer);
            }

        }
        if (timer == playerJumpTimer) {
            locateObject(ch1, scene1, ch_x, ch_y += vel);
            setTimer(playerJumpTimer, 0.06f);
            startTimer(playerJumpTimer);
            vel += gravity;
            jdidx++;
            if (jdidx < 1) {
                setObjectImage(ch1, Jump[0]);

            }
            if (jdidx >= 1 && jdidx < 2) {
                setObjectImage(ch1, Jump[1]);

            }
            if (jdidx >= 2) {
                setObjectImage(ch1, Jump[2]);

            }
            if (ch_y < 20) {
                locateObject(ch1, scene1, ch_x, ch_y = 20);
                stopTimer(playerJumpTimer);
                setTimer(playerJumpTimer, 0.06f);
                setObjectImage(ch1, "images/ch1.png");

                c_timer = false;
                c_jump = false;

            }
        }

        if (timer == hitM_Timer) {
            setObjectImage(ch1, Hit_M[hitidx % 2]);
            hitidx++;
            setTimer(hitM_Timer, 0.05f);
            startTimer(hitM_Timer);
            if (hitidx > 5)
            {
                setObjectImage(ch1, "images/N7.png");
                if (ch_y < 21)setObjectImage(ch1, "images/ch1.png");
                stopTimer(hitM_Timer);
            }
        }

        if (timer == hitbox_Timer) {
            bool c_apt_hit = false;
            int h_i;
            int h_c_i;
            for (int i = 0; i < 100; i++) {
                if (collided_hit_apt(i)) {
                    h_c_i = check_hit[i];
                    printf("%d", h_c_i);
                    h_i = i;
                    printf("%d", h_i);
                    c_apt_hit = true;
                }
            }
            if (c_apt_hit && hit_check == true) {
                check_hit[h_i] -= 1;
                printf("%d", check_hit[h_i]);
                if (check_hit[h_i] == 0) {
                    hideObject(floor_ob[h_i]);
                    locateObject(floor_ob[h_i], scene1, f_x, f_y[h_i] += f_y[99]);
                    if ((h_i + 1) % 10 == 0) {
                        gravity -= 0.055;
                        speed += 0.055;
                        showMessage("빨라진다");
                    }
                    if (h_i == 99) {
                        endgame_1();
                        stopTimer(enemyTimer);
                    }
                }
            }

            hideObject(hit_box);
            hit_check = false;
            setTimer(hitbox_Timer, 0.06f);
        }
        if (timer == back_Timer) {
            hideObject(fxxk_1);

        }
    }

}

void Keyboard_callback_1(KeyCode code, KeyState state) {
    if (gametype == 1) {
        if (state == KeyState::KEY_PRESSED) {
            if (code == KeyCode::KEY_SPACE && c_timer == false) {
                jridx = 0;
                start = clock();
                setTimer(jumpR_Timer, 0.1f);
                startTimer(jumpR_Timer);
                c_timer = true;
            }
            if (code == KeyCode::KEY_R or code == KeyCode::KEY_CAPITAL_R) {
                hit_y = 120;
                locateObject(hit_box, scene1, hit_x, hit_y = hit_y + ch_y);
                hit_check = true;
                startTimer(hitbox_Timer);
                setTimer(playerJumpTimer, 0.06f);
                hitidx = 0;
                startTimer(hitM_Timer);
            }
        }
        if (state == KeyState::KEY_RELEASED) {
            if (code == KeyCode::KEY_SPACE && c_timer == true && c_jump == false) {
                clock_t end = clock();
                jdidx = 0;
                double time = double(end - start) / CLOCKS_PER_SEC; //초단위 변환
                startTimer(playerJumpTimer);
                stopTimer(jumpR_Timer);
                setTimer(jumpR_Timer, 0.3f);
                if (time < 0.3) vel = 66;
                if (time < 0.60 && time >= 0.3) vel = 78;
                if (time >= 0.60) vel = 90;
                c_jump = true;

            }
        }
    }
<<<<<<< Updated upstream
    
}
=======

}
>>>>>>> Stashed changes
