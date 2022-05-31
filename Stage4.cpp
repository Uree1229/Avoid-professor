#include <bangtal.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <string.h>

//sceneID ObjectID 정리
TimerID timer_cr_4;
ObjectID INT[6];
extern ObjectID door[4];
extern SceneID scene, scene4, scene_stat;
extern int gametype;
SceneID scene_1, scene_2, scene_3;
ObjectID start_stage4, quit, play, fxxk_4,
category1, category2, category3,
Mquiz1, Mquiz2, Mquiz3,
Equiz1, Equiz2, Equiz3,
Nquiz1, Nquiz2, Nquiz3,
Pquiz1, Pquiz2, Pquiz3,
Ma_1_1, Ma_1_2, Ma_1_3,
Ma_2_1, Ma_2_2, Ma_2_3,
Ma_3_1, Ma_3_2, Ma_3_3,
Ma_4_1, Ma_4_2, Ma_4_3,
Ea_1_1, Ea_1_2, Ea_1_3,
Ea_2_1, Ea_2_2, Ea_2_3,
Ea_3_1, Ea_3_2, Ea_3_3,
Ea_4_1, Ea_4_2, Ea_4_3,
Na_1_1, Na_1_2, Na_1_3,
Na_2_1, Na_2_2, Na_2_3,
Na_3_1, Na_3_2, Na_3_3,
Na_4_1, Na_4_2, Na_4_3,
Pa_1_1, Pa_1_2, Pa_1_3,
Pa_2_1, Pa_2_2, Pa_2_3,
Pa_3_1, Pa_3_2, Pa_3_3,
Pa_4_1, Pa_4_2, Pa_4_3;
int life_4 = 3;

//stat 함수
void stat_check_INT()
{
    if (life_4 == 3) {
        showObject(INT[5]);
        showObject(INT[4]);
        showObject(INT[3]);
        showObject(INT[2]);
        showObject(INT[1]);
        showObject(INT[0]);
    }
    else if (life_4 == 2) {
        showObject(INT[3]);
        showObject(INT[2]);
        showObject(INT[1]);
        showObject(INT[0]);
    }
    else if (life_4 == 1) {
        showObject(INT[1]);
        showObject(INT[0]);
    }
    else if (life_4 == 0) {
        showObject(INT[0]);
    }
}


//게임 끝내기
void endgame_4() 
{
    fxxk_4 = createObject("Images/fXXk.png");
    locateObject(fxxk_4, scene_stat, 400, 460);
    showObject(fxxk_4);
    enterScene(scene_stat);    
  
    
    stat_check_INT();
    gametype = -1;
    startTimer(timer_cr_4);

}


//타이머 콜백 함수
void Timer_callback_4(TimerID timer)
{
    if (timer == timer_cr_4)
    {
        enterScene(scene);
        hideObject(fxxk_4);
        gametype = 0;
        setTimer(timer_cr_4, 5.0f);
    }
}


//콜백함수 정의 
void mouseCallback_in_stage4(ObjectID object, int x, int y, MouseAction action)
{


    //종료 버튼이 눌려지면 stat 결과 나오면서 메인스테이지로 돌아가기
    if (object == quit) 
    {
        enterScene(scene);
        scene_stat = createScene("scene_stat", "Images/stat.png");
        enterScene(scene_stat);
        hideObject(fxxk_4);
        gametype = 0;
        hideObject(door[3]);
    }


    //버튼 누르면 각각의 퀴즈 방으로 입장
    if (object == category1)
    {
        enterScene(scene_1);
        showMessage("여기는 수학 퀴즈 방입니다. 퀴즈를 풀어서 '지식' 능력치를 향상시키세요.");
        showObject(Mquiz1);
        showObject(Ma_1_1);
        showObject(Ma_1_2);
        showObject(Ma_1_3);
    }

    if (object == category2)
    {
        enterScene(scene_2);
        showMessage("여기는 영어 단어 퀴즈 방입니다. 퀴즈를 풀어서 '지식' 능력치를 향상시키세요.");
        showObject(Equiz1);
        showObject(Ea_1_1);
        showObject(Ea_1_2);
        showObject(Ea_1_3);
    }

    if (object == category3)
    {
        enterScene(scene_3);
        showMessage("여기는 넌센스 퀴즈 방입니다. 퀴즈를 풀어서 '지식' 능력치를 향상시키세요.");
        showObject(Nquiz1);
        showObject(Na_1_1);
        showObject(Na_1_2);
        showObject(Na_1_3);
    }


    //수학 퀴즈 방 입장    //퀴즈는 정답 여부에 관계없이 답을 클릭하면 다음문제로 넘어감
    if (object == Ma_1_1 || object == Ma_1_2 || object == Ma_1_3)
    {
        life_4 -= 1;

        hideObject(Ma_1_1);
        hideObject(Ma_1_2);
        hideObject(Ma_1_3);

        showObject(Mquiz2);
        showObject(Ma_2_1);
        showObject(Ma_2_2);
        showObject(Ma_2_3);
    }
    if (object == Ma_2_1 || object == Ma_2_2 || object == Ma_2_3)
    {
        life_4 -= 1;

        hideObject(Ma_2_1);
        hideObject(Ma_2_2);
        hideObject(Ma_2_3);

        showObject(Mquiz3);
        showObject(Ma_3_1);
        showObject(Ma_3_2);
        showObject(Ma_3_3);
    }
    if (object == Ma_3_1 || object == Ma_3_2 || object == Ma_3_3)
    {
        life_4 -= 1;
        hideObject(Ma_3_3);
        hideObject(Ma_3_2);
        hideObject(Ma_3_3);

        enterScene(scene4);   //퀴즈를 다 풀면 나가는 방으로 돌아옴

        hideObject(start_stage4);
        hideObject(category1);
        hideObject(category2);
        hideObject(category3);

        //퀴즈를 다 풀면 나가는 방으로 돌아옴
        enterScene(scene4);
        hideObject(category1);
        hideObject(category2);
        hideObject(category3);
        hideObject(start_stage4);
    }


    //영어 퀴즈 방 입장
    if (object == Ea_1_1 || object == Ea_1_2 || object == Ea_1_3)
    {
        hideObject(Ea_1_1);
        hideObject(Ea_1_2);
        hideObject(Ea_1_3);

        showObject(Equiz2);
        showObject(Ea_2_1);
        showObject(Ea_2_2);
        showObject(Ea_2_3);
    }
    if (object == Ea_2_1 || object == Ea_2_2 || object == Ea_2_3)
    {
        hideObject(Ea_2_2);
        hideObject(Ea_2_2);
        hideObject(Ea_2_3);

        showObject(Equiz3);
        showObject(Ea_3_1);
        showObject(Ea_3_2);
        showObject(Ea_3_3);
    }
    if (object == Ea_3_1 || object == Ea_3_2 || object == Ea_3_3)
    {
        hideObject(Ea_3_3);
        hideObject(Ea_3_2);
        hideObject(Ea_3_3);

        enterScene(scene4);   //퀴즈를 다 풀면 나가는 방으로 돌아옴

        hideObject(start_stage4);
        hideObject(category1);
        hideObject(category2);
        hideObject(category3);

        //퀴즈를 다 풀면 나가는 방으로 돌아옴
        enterScene(scene4);
        hideObject(category1);
        hideObject(category2);
        hideObject(category3);

        hideObject(start_stage4);
    }


    //넌센스 퀴즈 방 입장
    if (object == Na_1_1 || object == Na_1_2 || object == Na_1_3)
    {
        hideObject(Na_1_1);
        hideObject(Na_1_2);
        hideObject(Na_1_3);

        showObject(Nquiz2);
        showObject(Na_2_1);
        showObject(Na_2_2);
        showObject(Na_2_3);
    }
    if (object == Na_2_1 || object == Na_2_2 || object == Na_2_3)
    {
        hideObject(Na_2_2);
        hideObject(Na_2_2);
        hideObject(Na_2_3);

        showObject(Nquiz3);
        showObject(Na_3_1);
        showObject(Na_3_2);
        showObject(Na_3_3);
    }
    if (object == Na_3_1 || object == Na_3_2 || object == Na_3_3)
    {
        hideObject(Na_3_3);
        hideObject(Na_3_2);
        hideObject(Na_3_3);

        enterScene(scene4);   //퀴즈를 다 풀면 나가는 방으로 돌아옴

        hideObject(start_stage4);
        hideObject(category1);
        hideObject(category2);
        hideObject(category3);

        //퀴즈를 다 풀면 나가는 방으로 돌아옴
        enterScene(scene4);
        hideObject(category1);
        hideObject(category2);
        hideObject(category3);
        hideObject(start_stage4);
    }



    //start 버튼을 누르면 
    if (object = start_stage4) 
    {
        showObject(category1);
        showObject(category2);
        showObject(category3);
    }
}


//메인 함수
int Quiz_stage4() {

    //콜백 함수 등록
    setMouseCallback(mouseCallback_in_stage4);


    //퀴즈 메인 방 장면 생성
    //scene4 = createScene("dungeonbackground", "scene4.png");
    showMessage("퀴즈 방에 오신 것을 환영합니다. 주어지는 퀴즈를 풀어 '지식' 능력치를 향상시키세요.");


    //각 퀴즈 방 생성
    scene_1 = createScene("math_QUIZ", "Images/mathdungeon.png");
    scene_2 = createScene("english_QUIZ", "Images/englishdungeon.png");
    scene_3 = createScene("nonsense_QUIZ", "Images/nonsensedungeon.png");
   

    //start 버튼
    start_stage4 = createObject("Images/startbutton.png");
    locateObject(start_stage4, scene4, 750, 300);
    scaleObject(start_stage4, 0.5f);
    showObject(start_stage4);


    //나가는 문(버튼)
    quit = createObject("Images/door.png");
    locateObject(quit, scene4, 480, 200);
    showObject(quit);



    //게임 카테고리 생성   
    //카테고리1: 넌센스 퀴즈
    category1 = createObject("Images/redbutton.png");
    locateObject(category1, scene4, 400, 550);
    //카테고리2: 수학 퀴즈
    category2 = createObject("Images/greenbutton.png");
    locateObject(category2, scene4, 700, 550);
    //카테고리3: 영어단어 퀴즈
    category3 = createObject("Images/yellowbutton.png");
    locateObject(category3, scene4, 1000, 550);
   


    //카테고리별 퀴즈 문제&답 생성하기
    //수학 문제 생성
    Mquiz1 = createObject("Images/Mquiz1.png");
    locateObject(Mquiz1, scene_1, 500, 250);
    Mquiz2 = createObject("Images/Mquiz2.png");
    locateObject(Mquiz2, scene_1, 500, 250);
    Mquiz3 = createObject("Images/Mquiz3.png");
    locateObject(Mquiz3, scene_1, 500, 250);
    
    //수학 답 생성
    Ma_1_1 = createObject("Images/ma1-1.png");
    locateObject(Ma_1_1, scene_1, 400, 200);
    scaleObject(Ma_1_1, 0.4f);
    Ma_1_2 = createObject("Images/ma1-2.png");
    locateObject(Ma_1_2, scene_1, 700, 200);
    scaleObject(Ma_1_2, 0.4f);
    Ma_1_3 = createObject("Images/ma1-3.png");
    locateObject(Ma_1_3, scene_1, 1000, 200);
    scaleObject(Ma_1_3, 0.4f);   

    Ma_2_1 = createObject("Images/ma2-1.png");
    locateObject(Ma_2_1, scene_1, 400, 200);
    scaleObject(Ma_2_1, 0.4f);
    Ma_2_2 = createObject("Images/ma2-2.png");
    locateObject(Ma_2_2, scene_1, 700, 200);
    scaleObject(Ma_2_2, 0.4f);
    Ma_2_3 = createObject("Images/ma2-3.png");
    locateObject(Ma_2_3, scene_1, 1000, 200);
    scaleObject(Ma_2_3, 0.4f);

    Ma_3_1 = createObject("Images/ma3-1.png");
    locateObject(Ma_3_1, scene_1, 400, 200);
    scaleObject(Ma_3_1, 0.4f);
    Ma_3_2 = createObject("Images/ma3-2.png");
    locateObject(Ma_3_2, scene_1, 700, 200);
    scaleObject(Ma_3_2, 0.4f);
    Ma_3_3 = createObject("Images/ma3-3.png");
    locateObject(Ma_3_3, scene_1, 1000, 200);
    scaleObject(Ma_3_3, 0.4f);
   
    Ma_4_1 = createObject("Images/ma4-1.png");
    locateObject(Ma_4_1, scene_1, 400, 200);
    scaleObject(Ma_4_1, 0.4f);
    Ma_4_2 = createObject("Images/ma4-2.png");
    locateObject(Ma_4_2, scene_1, 700, 200);
    scaleObject(Ma_4_2, 0.4f);
    Ma_4_3 = createObject("Images/ma4-3.png");
    locateObject(Ma_4_3, scene_1, 1000, 200);
    scaleObject(Ma_4_3, 0.4f);

    //영어 단어 문제 생성
    Equiz1 = createObject("Images/Equiz1.png");
    locateObject(Equiz1, scene_2, 500, 250);
    Equiz2 = createObject("Images/Equiz2.png");
    locateObject(Equiz1, scene_2, 500, 250);
    Equiz3 = createObject("Images/Equiz3.png");
    locateObject(Equiz1, scene_2, 500, 250);
  
    //영어 답 생성
    Ea_1_1 = createObject("Images/ea1-1.png");
    locateObject(Ea_1_1, scene_2, 400, 200);
    Ea_1_2 = createObject("Images/ea1-2.png");
    locateObject(Ea_1_1, scene_2, 400, 200);
    Ea_1_3 = createObject("Images/ea1-3.png");
    locateObject(Ea_1_1, scene_2, 400, 200);

    Ea_2_1 = createObject("Images/ea2-1.png");
    locateObject(Ea_1_1, scene_2, 400, 200);
    Ea_2_2 = createObject("Images/ea2-2.png");
    locateObject(Ea_1_1, scene_2, 400, 200);
    Ea_2_3 = createObject("Images/ea2-3.png");
    locateObject(Ea_1_1, scene_2, 400, 200);
 
    Ea_3_1 = createObject("Images/ea3-1.png");
    locateObject(Ea_1_1, scene_2, 400, 200);
    Ea_3_2 = createObject("Images/ea3-2.png");
    locateObject(Ea_1_1, scene_2, 400, 200);
    Ea_3_3 = createObject("Images/ea3-3.png");
    locateObject(Ea_1_1, scene_2, 400, 200);   

    Ea_4_1 = createObject("Images/ea4-1.png");
    locateObject(Ea_1_1, scene_2, 400, 200);
    Ea_4_2 = createObject("Images/ea4-2.png");
    locateObject(Ea_1_1, scene_2, 400, 200);
    Ea_4_3 = createObject("Images/ea4-3.png");
    locateObject(Ea_1_1, scene_2, 400, 200);
   

    //넌센스 문제 생성
    Nquiz1 = createObject("Images/Nquiz1.png");
    locateObject(Nquiz1, scene_3, 500, 250);
    Nquiz2 = createObject("Images/Nquiz2.png");
    locateObject(Nquiz1, scene_3, 500, 250);
    Nquiz3 = createObject("Images/Nquiz3.png");
    locateObject(Nquiz1, scene_3, 500, 250);
   
    //넌센스 답 생성
    Na_1_1 = createObject("Images/na1-1.png");
    locateObject(Na_1_1, scene_3, 400, 200);
    Na_1_2 = createObject("Images/na1-2.png");
    locateObject(Na_1_1, scene_3, 400, 200);
    Na_1_3 = createObject("Images/na1-3.png");
    locateObject(Na_1_1, scene_3, 400, 200);
    
    Na_2_1 = createObject("Images/na2-1.png");
    locateObject(Na_1_1, scene_3, 400, 200);
    Na_2_2 = createObject("Images/na2-2.png");
    locateObject(Na_1_1, scene_3, 400, 200);
    Na_2_3 = createObject("Images/na2-3.png");
    locateObject(Na_1_1, scene_3, 400, 200);
   
    Na_3_1 = createObject("Images/na3-1.png");
    locateObject(Na_1_1, scene_3, 400, 200);
    Na_3_2 = createObject("Images/na3-2.png");
    locateObject(Na_1_1, scene_3, 400, 200);
    Na_3_3 = createObject("Images/na3-3.png");
    locateObject(Na_1_1, scene_3, 400, 200);
   
    Na_4_1 = createObject("Images/na4-1.png");
    locateObject(Na_1_1, scene_3, 400, 200);
    Na_4_2 = createObject("Images/na4-2.png");
    locateObject(Na_1_1, scene_3, 400, 200);
    Na_4_3 = createObject("Images/na4-3.png");
    locateObject(Na_1_1, scene_3, 400, 200);

    //startGame(scene4);


    return 0;
}