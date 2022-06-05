#include <bangtal.h>

TimerID  timer_hp, Timer_sk1, Timer_sk2, Timer_sk3, Timer_range, timer_band, timer_stop, Timer_sk4;
TimerID j_Timer_b, hitbox_Timer_b, h_Timer, timer_move_b, boss_Jump_Timer, boss_Walk_Timer, Timer_time;
ObjectID hp_p[4], Player, range1, range2, range3, hp_b[100], hit_range_b[5], hit_box_b, rage, rage1,A,B,C,F,Ap;
Second time_first=1410.f;
extern SoundID boss_bgm;

extern SceneID sceneB, scene_stat;
extern TimerID first_Timer;
extern int gametype, dex, luk, str, Int;
extern int random_number(int start, int end);
extern ObjectID createObject(const char* image, SceneID scene, int x, int y, bool shown);
using namespace std;

int HP_p = 3, HP_b = 1, type = 0, Player_x = 0, Player_y = 0, ply = 120, sk1_x, sk1_y, sk2_x, sk2_y, num_1 = 0, num_2 = 0, num_3 = 0;

int vel_ch_b, hit_xb, hit_yb, x2_b, dx_b, walkidx, walkL, walkR, jumpL, jumpR, jumpidx, time_stack=30;
bool c_jump_b = false;
bool Rage = false, check1, check2, check3, check4, check0, walkLb, walkRb, dont_move = false;

char boss_JumpR[20][100]{
      "images/R_J1.png",
      "images/R_J2.png",
      "images/R_J3.png",
      "images/R_J4.png",
      "images/R_J5.png",
      "images/R_J6.png",
      "images/R_J7.png"

};

char boss_JumpL[20][100]{
      "images/L_J1.png",
      "images/L_J2.png",
      "images/L_J3.png",
      "images/L_J4.png",
      "images/L_J5.png",
      "images/L_J6.png",
      "images/L_J7.png"

};

char boss_WalkR[6][20]{
      "images/W_R1.png",
      "images/W_R2.png",
      "images/W_R3.png",
      "images/W_R4.png",
      "images/W_R5.png",
      "images/W_R6.png"
};

char boss_WalkL[6][20]{
      "images/W_L1.png",
      "images/W_L2.png",
      "images/W_L3.png",
      "images/W_L4.png",
      "images/W_L5.png",
      "images/W_L6.png"

};



void boss_skill_1();
void boss_skill_2();
void boss_skill_3();
void boss_skill_4();

void set_time() {
    
    timer_hp = createTimer(0.01f);
    Timer_sk1 = createTimer(1.0f);
    Timer_sk2 = createTimer(1.0f);
    Timer_sk3 = createTimer(1.0f);
    Timer_sk4 = createTimer(1.0f);
    Timer_time = createTimer(60.0f);
    j_Timer_b = createTimer(0.06f);
    Timer_range = createTimer(0.5f);
    timer_band = createTimer(1.0f);
    timer_stop = createTimer(1.0f); // 수정
    hitbox_Timer_b = createTimer(0.06f);
    boss_Walk_Timer = createTimer(0.06f);
    boss_Jump_Timer = createTimer(0.06f);


    showTimer(first_Timer);
    startTimer(timer_hp);
    startTimer(Timer_time);
    
}

void boss_attack() {
    if (type == 0) {
        if (HP_b <= 100 && HP_b > 30) {
            type = random_number(1, 2);
        }
        else if (HP_b >= 0 && HP_b <= 30) {
            type = 3;
            if (Rage == false) {
                Rage = true;
                rage = createObject("Images/rage.png", sceneB, 645, 321, true);
                rage1 = createObject("Images/rage.png", sceneB, 740, 321, true);

            }
        }
        else if (HP_b == 0) {

        }

    }
    switch (type) {
    case 1:
        boss_skill_1();
        break;
    case 2:
        boss_skill_2();
        break;
    case 3:
        boss_skill_3();

        break;
    case 4:
        boss_skill_4();
        break;
    }
}

void setting_B() {
    if (gametype == 5) {
        showMessage("aaa"); //보스의 입장대사
        set_time();
        for (int i = 0; i < 3; i++) {
            hp_p[i] = createObject("Images/Heart.png", sceneB, 30 + 70 * i, 50, true);
        }
        Player = createObject("Images/ch1.png", sceneB, Player_x, Player_y, true);
        for (int i = 0; i < 100; i++) {
            hp_b[i] = createObject("Images/HP_boss.png", sceneB, 1110 - 9 * i, 640, true);
        }
        hit_range_b[0] = createObject("images/hit_range.png", sceneB, 650, 230, false);
        hit_range_b[1] = createObject("images/hit_range.png", sceneB, 670, 300, false);
        hit_range_b[2] = createObject("images/hit_range.png", sceneB, 550, 300, false);
        hit_range_b[3] = createObject("images/hit_range.png", sceneB, 780, 310, false);
        hit_range_b[4] = createObject("images/hit_range.png", sceneB, 670, 370, false);
        hit_box_b = createObject("images/hitbox.png", sceneB, 100, 100, false);
        scaleObject(hit_box_b, 2.f);

        startTimer(timer_stop);

        // 지워야함
    }

}

void show_boss_hitbox() {
    int x = random_number(0, 4);
    x2_b = x;
    switch (x) {
    case 0:
        showObject(hit_range_b[0]);
        check0 = true;
        break;
    case 1:
        showObject(hit_range_b[1]);
        check1 = true;
        break;
    case 2:
        showObject(hit_range_b[2]);
        check2 = true;
        break;
    case 3:
        showObject(hit_range_b[3]);
        check3 = true;
        break;
    case 4:
        showObject(hit_range_b[4]);
        check4 = true;
        break;
    }
}

bool check_crush_b(int x, int y, int rx, int ry, int size) {
    return (y >= ry - size) && (y <= ry + size) && (x >= rx - size) && (x <= rx + size);
}

void check_hit_b() {
    if (check0 == true) {
        if (check_crush_b(hit_xb, hit_yb, 650, 230, 120)) {
            int LUk = random_number(1, 1 + luk);
            if (LUk > 3) {
                showMessage("critical!");
            }
            HP_b -= luk + 1 * str;
            check0 = false;
            hideObject(hit_range_b[0]);
            startTimer(Timer_sk4);


        }
    }
    if (check1 == true) {
        if (check_crush_b(hit_xb, hit_yb, 670, 300, 120)) {
            int LUk = random_number(1, 1 + luk);
            if (LUk > 3) {
                showMessage("critical!");
            }
            HP_b -= luk + 1 * str;
            check1 = false;
            hideObject(hit_range_b[1]);
            startTimer(Timer_sk4);


        }
    }
    if (check2 == true) {
        if (check_crush_b(hit_xb, hit_yb, 550, 300, 120)) {
            int LUk = random_number(1, 1 + luk);
            if (LUk > 3) {
                showMessage("critical!");
            }
            HP_b -= luk + 1 * str;
            check2 = false;
            hideObject(hit_range_b[2]);
            startTimer(Timer_sk4);

        }
    }
    if (check3 == true) {
        if (check_crush_b(hit_xb, hit_yb, 780, 310, 120)) {
            int LUk = random_number(1, 1 + luk);
            if (LUk > 3) {
                showMessage("critical!");
            }
            HP_b -= luk + 1 * str;
            check3 = false;
            hideObject(hit_range_b[3]);
            startTimer(Timer_sk4);

        }
    }
    if (check4 == true) {
        if (check_crush_b(hit_xb, hit_yb, 670, 400, 120)) {
            int LUk = random_number(1, 1 + luk);
            if (LUk > 3) {
                showMessage("critical!");
            }
            HP_b -= luk + 1 * str;
            check4 = false;
            hideObject(hit_range_b[4]);
            startTimer(Timer_sk4);

        }
    }
}
void hp_player() {

    if (HP_p >= 2 && HP_p < 3) { // hp=2
        hideObject(hp_p[2]);
    }
    else if (HP_p >= 1 && HP_p < 2) { //hp=1
        hideObject(hp_p[1]);
        hideObject(hp_p[2]);
    }
    else if (HP_p >= 0 && HP_p < 1) { //hp=0
        hideObject(hp_p[0]);
        hideObject(hp_p[2]);
        hideObject(hp_p[1]);
    }
}
//없에야됨
void hp_boss() {

    int i = 100 - HP_b;
    for (int j = 0; j < i; j++) {
        hideObject(hp_b[j]);
    }

}

void boss_skill_1() { //F 범위 공격 100,100
    if (type == 1) {
        Int = 50;
        sk1_x = random_number(0, 1280), sk1_y = random_number(60, 80);
        range1 = createObject("Images/Range.png", sceneB, sk1_x, sk1_y, false);
        locateObject(range1, sceneB, sk1_x, sk1_y);
        showObject(range1);
        startTimer(Timer_sk1);
        num_1++;

    }
}
void boss_skill_2() { // 점프로 피하는 거
    if (type == 2) {
        sk2_x = random_number(0, 1250), sk2_y = random_number(0, 29);
        range2 = createObject("Images/range1.png", sceneB, 0, sk2_y, false);
        range3 = createObject("Images/range2.png", sceneB, sk2_x, 0, false);
        locateObject(range2, sceneB, 0, sk2_y);
        locateObject(range3, sceneB, sk2_x, 0);
        showObject(range2);
        showObject(range3);
        startTimer(Timer_sk2);
        num_2++;
    }
}
void boss_skill_3() {
    if (type == 3) {
        sk1_x = random_number(0, 1280), sk1_y = random_number(60, 80);
        sk2_x = random_number(0, 1250), sk2_y = random_number(0, 29);
        range1 = createObject("Images/Range.png", sceneB, sk1_x, sk1_y, false);
        range2 = createObject("Images/range1.png", sceneB, 0, sk2_y, false);
        range3 = createObject("Images/range2.png", sceneB, sk2_x, 0, false);
        locateObject(range1, sceneB, sk1_x, sk1_y);
        locateObject(range2, sceneB, 0, sk2_y);
        locateObject(range3, sceneB, sk2_x, 0);
        showObject(range1);
        showObject(range2);
        showObject(range3);
        startTimer(Timer_sk3);
        num_3++;
    }
}
void boss_skill_4() {// 허깅상태
    show_boss_hitbox();
    type = 0;
}
void ending() {
    if (HP_b < 0) {
        if (time_stack <30 && time_stack >=25 ) {
            Ap = createObject("Images/A+.png", scene_stat, 400, 360, true);
        }
        else if (time_stack < 25 && time_stack >= 20) {
            A = createObject("Images/A.png", scene_stat, 400, 360, true);
        }
        else if (time_stack < 20 && time_stack >= 15) {
            B = createObject("Images/B.png", scene_stat, 400, 360, true);
        }
        else if (time_stack < 15 && time_stack > 0) {
            C = createObject("Images/C.png", scene_stat, 400, 360, true);
        }
        enterScene(scene_stat);
        showMessage("Clear");
        gametype = 10;
    }
    else if (HP_p == 0 || time_stack == 0) {
        F = createObject("Images/F_1.png", scene_stat,400,360, true );
        enterScene(scene_stat);
        showMessage("Bug CUT~~~");
        
        stopSound(boss_bgm);
        gametype = 10;
    }
    
}

bool range_damage() {
    switch (type) {
    case 1:
        if (Player_x < sk1_x + 100 && Player_x > sk1_x - 70 && ply == 120) {
            return true;
        }
        else return false;
        break;

    case 2:
        if (Player_y < sk2_y + 20 || (sk2_x > Player_x - 30 && sk2_x < Player_x + 70)) {
            return true;
        }
        else return false;
        break;
    case 3:
        if ((Player_y < sk2_y + 20 || (sk2_x > Player_x - 30 && sk2_x < Player_x + 70)) ||
            (Player_x < sk1_x + 100 && Player_x > sk1_x - 70 && ply == 120)) {
            return true;
        }
        else return false;
        break;
    case 4:
        break;
    }
}

void move_player() {
    locateObject(Player, sceneB, Player_x, Player_y);
}

void Mouse_callback_B(ObjectID object, int x, int y, MouseAction action) {
    if (gametype == 5) {
    }
}

void Keyboard_callback_B(KeyCode code, KeyState state) { // default = 0,0 -> 크기 70, 120
    if (gametype == 5) {
        if (code == KeyCode::KEY_DOWN_ARROW && ply == 120 && c_jump_b == false) { //숙이기  -  숙이면 높이 반으로 ㄱㄱ
            ply = 60;
            setObjectImage(Player, "Images/S2.png");      // 숙이는 이미지 넣어야함
            setTimer(boss_Walk_Timer, 0.06f);
            stopTimer(boss_Walk_Timer);
            Player_y = 0;
            dont_move = true;
        }
        else if (code == KeyCode::KEY_UP_ARROW && ply == 60) {
            ply = 120;
            //setObjectImage(Player, "Images/ch1.png");
            startTimer(boss_Walk_Timer);
            Player_y = 0;
            dont_move = false;
        }
        else if (code == KeyCode::KEY_LEFT_ARROW && dont_move == false && ply == 120) {// 좌 이동 dex로 스피드 조정
            if (walkRb == false && walkLb == false && c_jump_b == false) {
                walkLb = true;
                walkidx = 1;
                setTimer(boss_Walk_Timer, 0.06f);
                startTimer(boss_Walk_Timer);
            }
            dx_b -= (state == KeyState::KEY_PRESSED ? (10 + 1 * dex) : -(10 + 1 * dex));//수정 

        }

        else if (code == KeyCode::KEY_RIGHT_ARROW && dont_move == false&&ply == 120) { //우 이동
            if (walkRb == false && walkLb == false && c_jump_b == false) {
                walkRb = true;
                walkidx = 0;
                setTimer(boss_Walk_Timer, 0.06f);
                startTimer(boss_Walk_Timer);
            }
            dx_b += (state == KeyState::KEY_PRESSED ? (10 + 1 * dex) : -(10 + 1 * dex));

        }
        else if (code == KeyCode::KEY_SPACE && c_jump_b == false) {// 점프 고정 y +50
            vel_ch_b = 60;
            c_jump_b = true;
            startTimer(j_Timer_b);
            startTimer(boss_Jump_Timer);
        }
        else  if (code == KeyCode::KEY_R or code == KeyCode::KEY_CAPITAL_R) {
            hit_yb = 100;
            hit_xb = 0;
            locateObject(hit_box_b, sceneB, hit_xb = hit_xb + Player_x + 30, hit_yb = hit_yb + Player_y);
            showObject(hit_box_b);
            startTimer(hitbox_Timer_b);

        }
    }
}

void Timer_callback_B(TimerID timer) {
    if (gametype == 5) {
        if (timer == timer_hp) {
            Player_x += dx_b;

            hp_player();
            hp_boss();
            move_player();
            setTimer(timer_hp, 0.1f);
            ending();
            startTimer(timer_hp);
        }

        else if (timer == Timer_sk1 && type == 1) {
            setObjectImage(range1, "Images/F.png");
            setTimer(Timer_sk1, 1.0f);
            startTimer(Timer_range);
            if (range_damage() == true) {
                HP_p--;
            }
        }
        else if (timer == Timer_sk2 && type == 2) {
            setObjectImage(range2, "Images/E.png");
            setObjectImage(range3, "Images/E-1.png");
            setTimer(Timer_sk2, 1.0f);
            startTimer(Timer_range);
            if (range_damage() == true) {
                HP_p--;
            }
        }
        else if (timer == Timer_sk3 && type == 3) {
            setObjectImage(range1, "Images/F.png");
            setObjectImage(range2, "Images/E.png");
            setObjectImage(range3, "Images/E-1.png");
            setTimer(Timer_sk3, 1.0f);
            startTimer(Timer_range);
            if (range_damage() == true) {
                HP_p--;
            }
        }
        else if (timer == Timer_sk4) {
            type = 0;
            boss_attack();
            setTimer(Timer_sk4, 1.0f);
        }
        else if (timer == j_Timer_b) {
            vel_ch_b -= 8;
            Player_y += vel_ch_b;
            move_player();
            setTimer(j_Timer_b, 0.06f);
            startTimer(j_Timer_b);
            if (Player_y <= 0) {
                Player_y = 0;
                move_player();
                stopTimer(j_Timer_b);
                c_jump_b = false;
            }
        }
        else if (timer == hitbox_Timer_b) {
            check_hit_b();
            hideObject(hit_box_b);
            setTimer(hitbox_Timer_b, 0.06f);
        }
        else if (timer == Timer_time) {
            time_stack--;
            time_first++;
            setTimer(first_Timer, time_first);
            if (time_stack == 0) {
                ending();
            }
            setTimer(Timer_time, 60.0f);
            startTimer(Timer_time);
            
        }

        else if (timer == boss_Walk_Timer) {
            if (walkidx == 1) {
                setObjectImage(Player, boss_WalkL[walkL]);
                walkL++;
                setTimer(boss_Walk_Timer, 0.06f);
                startTimer(boss_Walk_Timer);
                if (walkL == 5) {
                    walkL = 0;
                    setTimer(boss_Walk_Timer, 0.06f);
                    startTimer(boss_Walk_Timer);
                    walkRb = false;
                    walkLb = false;
                }

            }
            else {
                setObjectImage(Player, boss_WalkR[walkR]);
                walkR++;
                setTimer(boss_Walk_Timer, 0.06f);
                startTimer(boss_Walk_Timer);
                if (walkR == 5) {
                    walkR = 0;
                    setTimer(boss_Walk_Timer, 0.06f);
                    startTimer(boss_Walk_Timer);
                    walkRb = false;
                    walkLb = false;

                }
            }
        }

        else if (timer == boss_Jump_Timer) {
            setTimer(boss_Walk_Timer, 0.06f);
            stopTimer(boss_Walk_Timer);
            if (walkidx == 1) {
                if (jumpidx < 1) {
                    setObjectImage(Player, boss_JumpL[0]);

                }
                if (jumpidx >= 1 && jumpidx < 2) {
                    setObjectImage(Player, boss_JumpL[3]);

                }
                if (jumpidx >= 2) {
                    setObjectImage(Player, boss_JumpL[5]);

                }
                jumpidx++;
                setTimer(boss_Jump_Timer, 0.06f);
                startTimer(boss_Jump_Timer);
                if (Player_y < 10) {
                    jumpidx = 0;
                    setTimer(boss_Jump_Timer, 0.06f);
                    stopTimer(boss_Jump_Timer);
                    setTimer(boss_Walk_Timer, 0.06f);
                    startTimer(boss_Walk_Timer);

                }
            }
            else {
                if (jumpidx < 1) {
                    setObjectImage(Player, boss_JumpR[0]);

                }
                if (jumpidx >= 1 && jumpidx < 2) {
                    setObjectImage(Player, boss_JumpR[3]);

                }
                if (jumpidx >= 2) {
                    setObjectImage(Player, boss_JumpR[5]);

                }
                jumpidx++;
                setTimer(boss_Jump_Timer, 0.06f);
                startTimer(boss_Jump_Timer);
                if (Player_y < 10) {
                    jumpidx = 0;
                    setTimer(boss_Jump_Timer, 0.06f);
                    stopTimer(boss_Jump_Timer);
                    setTimer(boss_Walk_Timer, 0.06f);
                    startTimer(boss_Walk_Timer);

                }
            }
        }

        else if (timer == Timer_range) {

            setTimer(Timer_range, 0.5f);
            if (type == 1) {
                hideObject(range1);
                if (num_1 == (20 - Int * 2)) {  //20 - Int * 2
                    type = 4;
                    num_1 = 0;
                    boss_attack();
                }
                else boss_skill_1();

            }
            else if (type == 2) {
                hideObject(range2);
                hideObject(range3);
                if (num_2 == (20 - Int * 2)) { //20 - Int * 2
                    type = 4;
                    num_2 = 0;
                    boss_attack();
                }
                else boss_skill_2();
            }
            else if (type == 3) {
                hideObject(range1);
                hideObject(range2);
                hideObject(range3);
                if (num_3 == (20 - Int * 2)) { //20 - Int * 2
                    type = 4;
                    num_3 = 0;
                    boss_attack();
                }
                else {
                    boss_skill_3();

                }
            }


        }
        else if (timer_stop) {
            boss_attack();
            setTimer(timer_stop, 5.0f);
            //startTimer(timer_stop);
        }

    }
}