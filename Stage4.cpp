#include <bangtal.h>
#include <stdio.h>

//sceneID ObjectID 정리
extern SceneID scene, scene4, scene_1, scene_2, scene_3, scene_4, scene_stat;
ObjectID
start_stage4, quit, play,
category1, category2, category3, category4,
Mquiz1, Mquiz2, Mquiz3, Mquiz4,
Equiz1, Equiz2, Equiz3, Equiz4,
Nquiz1, Nquiz2, Nquiz3, Nquiz4,
Pquiz1, Pquiz2, Pquiz3, Pquiz4,
Ma_1_1, Ma_1_2, Ma_1_3, Ma_1_4,
Ma_2_1, Ma_2_2, Ma_2_3, Ma_2_4,
Ma_3_1, Ma_3_2, Ma_3_3, Ma_3_4,
Ma_4_1, Ma_4_2, Ma_4_3, Ma_4_4,
Ea_1_1, Ea_1_2, Ea_1_3, Ea_1_4,
Ea_2_1, Ea_2_2, Ea_2_3, Ea_2_4,
Ea_3_1, Ea_3_2, Ea_3_3, Ea_3_4,
Ea_4_1, Ea_4_2, Ea_4_3, Ea_4_4,
Na_1_1, Na_1_2, Na_1_3, Na_1_4,
Na_2_1, Na_2_2, Na_2_3, Na_2_4,
Na_3_1, Na_3_2, Na_3_3, Na_3_4,
Na_4_1, Na_4_2, Na_4_3, Na_4_4,
Pa_1_1, Pa_1_2, Pa_1_3, Pa_1_4,
Pa_2_1, Pa_2_2, Pa_2_3, Pa_2_4,
Pa_3_1, Pa_3_2, Pa_3_3, Pa_3_4,
Pa_4_1, Pa_4_2, Pa_4_3, Pa_4_4;

using namespace std;

//콜백함수 정의 
void mouseCallback_in_stage4(ObjectID object, int x, int y, MouseAction action)
{


    //종료 버튼이 눌려지면 게임 종료
    if (object == quit) {
        enterScene(scene);
    }


    //버튼 누르면 각각의 퀴즈 방으로 입장
    if (object == category1) {
        enterScene(scene_1);
        showMessage("여기는 수학 퀴즈 방입니다. 퀴즈를 풀어서 '지식' 능력치를 향상시키세요.");
        showObject(Mquiz1);
        showObject(Ma_1_1);
        showObject(Ma_1_2);
        showObject(Ma_1_3);
        showObject(Ma_1_4);
    }
    if (object == category2) {
        enterScene(scene_2);
        showMessage("여기는 영어 단어 퀴즈 방입니다. 퀴즈를 풀어서 '지식' 능력치를 향상시키세요.");
    }

    if (object == category3) {
        enterScene(scene_3);
        showMessage("여기는 넌센스 퀴즈 방입니다. 퀴즈를 풀어서 '지식' 능력치를 향상시키세요.");
    }

    if (object == category4) {
        enterScene(scene_4);
        showMessage("여기는 프로그래밍 퀴즈 방입니다. 퀴즈를 풀어서 '지식' 능력치를 향상시키세요.");
    }


    //수학 퀴즈 방 입장
    //정답 여부에 관계없이 답을 클릭하면 다음문제로 넘어감
    if (object == Ma_1_1 || object == Ma_1_2 || object == Ma_1_3 || object == Ma_1_4) {
        hideObject(Ma_1_1);
        hideObject(Ma_1_2);
        hideObject(Ma_1_3);
        hideObject(Ma_1_4);

        showObject(Mquiz2);
        showObject(Ma_2_1);
        showObject(Ma_2_2);
        showObject(Ma_2_3);
        showObject(Ma_2_4);
    }

    if (object == Ma_2_1 || object == Ma_2_2 || object == Ma_2_3 || object == Ma_2_4) {
        hideObject(Ma_2_2);
        hideObject(Ma_2_2);
        hideObject(Ma_2_3);
        hideObject(Ma_2_4);

        showObject(Mquiz3);
        showObject(Ma_3_1);
        showObject(Ma_3_2);
        showObject(Ma_3_3);
        showObject(Ma_3_4);
    }

    if (object == Ma_3_1 || object == Ma_3_2 || object == Ma_3_3 || object == Ma_3_4) {
        hideObject(Ma_3_3);
        hideObject(Ma_3_2);
        hideObject(Ma_3_3);
        hideObject(Ma_3_4);

        showObject(Mquiz4);
        showObject(Ma_4_1);
        showObject(Ma_4_2);
        showObject(Ma_4_3);
        showObject(Ma_4_4);
    }
    if (object == Ma_4_1 || object == Ma_4_2 || object == Ma_4_3 || object == Ma_4_4) {
        hideObject(Ma_4_4);
        hideObject(Ma_4_2);
        hideObject(Ma_4_3);
        hideObject(Ma_4_4);

        //퀴즈를 다 풀면 다시 돌아옴
        enterScene(scene4);
    }



    //start 버튼을 누르면 
    else if (object = start_stage4) {


        //start 버튼, end 버튼 사라지게 한다. 
        hideObject(start_stage4);
        hideObject(quit);
        showObject(category1);
        showObject(category2);
        showObject(category3);
        showObject(category4);
    }


}

void setting_4() {

    //퀴즈별 장면 생성
    scene_1 = createScene("math_QUIZ", "Images/mathdungeon.png");
    scene_2 = createScene("english_QUIZ", "Images/englishdungeon.png");
    scene_3 = createScene("nonsense_QUIZ", "Images/nonsensedungeon.png");
    scene_4 = createScene("programming_QUIZ", "Images/programmingdungeon.png");

    //start 버튼
    start_stage4 = createObject("Images/startbutton.png");
    locateObject(start_stage4, scene4, 800, 300);
    scaleObject(start_stage4, 0.3f);
    showObject(start_stage4);


    //end 버튼
    quit = createObject("Images/endbutton.png");
    locateObject(quit, scene4, 1000, 320);
    scaleObject(quit, 0.4f);
    showObject(quit);


    //게임 카테고리 생성   
    //카테고리1: 넌센스 퀴즈
    category1 = createObject("Images/redbutton.png");
    locateObject(category1, scene4, 400, 400);

    //카테고리2: 수학 퀴즈
    category2 = createObject("Images/greenbutton.png");
    locateObject(category2, scene4, 700, 400);

    //카테고리3: 영어단어 퀴즈
    category3 = createObject("Images/yellowbutton.png");
    locateObject(category3, scene4, 1000, 400);

    //카테고리4: 프로그래밍 퀴즈
    category4 = createObject("Images/pinkbutton.png");
    locateObject(category4, scene4, 1300, 400);



    //카테고리별 퀴즈 문제&답 생성하기
    //수학 문제 생성
    Mquiz1 = createObject("Images/Mquiz1.png");
    locateObject(Mquiz1, scene_1, 500, 250);
    Mquiz2 = createObject("Images/Mquiz2.png");
    locateObject(Mquiz2, scene_1, 500, 250);
    Mquiz3 = createObject("Images/Mquiz3.png");
    locateObject(Mquiz3, scene_1, 500, 250);
    Mquiz4 = createObject("Images/Mquiz4.png");
    locateObject(Mquiz4, scene_1, 500, 250);
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
    Ma_1_4 = createObject("Images/ma1-4.png");
    locateObject(Ma_1_4, scene_1, 1300, 200);
    scaleObject(Ma_1_4, 0.4f);

    Ma_2_1 = createObject("Images/ma2-1.png");
    locateObject(Ma_2_1, scene_1, 400, 200);
    scaleObject(Ma_2_1, 0.4f);
    Ma_2_2 = createObject("Images/ma2-2.png");
    locateObject(Ma_2_2, scene_1, 700, 200);
    scaleObject(Ma_2_2, 0.4f);
    Ma_2_3 = createObject("Images/ma2-3.png");
    locateObject(Ma_2_3, scene_1, 1000, 200);
    scaleObject(Ma_2_3, 0.4f);
    Ma_2_4 = createObject("Images/ma2-4.png");
    locateObject(Ma_2_4, scene_1, 1300, 200);
    scaleObject(Ma_2_4, 0.4f);

    Ma_3_1 = createObject("Images/ma3-1.png");
    locateObject(Ma_3_1, scene_1, 400, 200);
    scaleObject(Ma_3_1, 0.4f);
    Ma_3_2 = createObject("Images/ma3-2.png");
    locateObject(Ma_3_2, scene_1, 700, 200);
    scaleObject(Ma_3_2, 0.4f);
    Ma_3_3 = createObject("Images/ma3-3.png");
    locateObject(Ma_3_3, scene_1, 1000, 200);
    scaleObject(Ma_3_3, 0.4f);
    Ma_3_4 = createObject("Images/ma3-4.png");
    locateObject(Ma_3_4, scene_1, 1300, 200);
    scaleObject(Ma_3_4, 0.4f);

    Ma_4_1 = createObject("Images/ma4-1.png");
    locateObject(Ma_4_1, scene_1, 400, 200);
    scaleObject(Ma_4_1, 0.4f);
    Ma_4_2 = createObject("Images/ma4-2.png");
    locateObject(Ma_4_2, scene_1, 700, 200);
    scaleObject(Ma_4_2, 0.4f);
    Ma_4_3 = createObject("Images/ma4-3.png");
    locateObject(Ma_4_3, scene_1, 1000, 200);
    scaleObject(Ma_4_3, 0.4f);
    Ma_4_4 = createObject("Images/ma4-4.png");
    locateObject(Ma_4_4, scene_1, 1300, 200);
    scaleObject(Ma_4_4, 0.4f);

    //영어 단어 문제 생성
    Equiz1 = createObject("Equiz1.png");
    Equiz2 = createObject("Equiz2.png");
    Equiz3 = createObject("Equiz3.png");
    Equiz4 = createObject("Equiz4.png");
    //영어 답 생성
    Ea_1_1 = createObject("ea1-1.png");
    Ea_1_2 = createObject("ea1-2.png");
    Ea_1_3 = createObject("ea1-3.png");
    Ea_1_4 = createObject("ea1-4.png");

    Ea_2_1 = createObject("ea2-1.png");
    Ea_2_2 = createObject("ea2-2.png");
    Ea_2_3 = createObject("ea2-3.png");
    Ea_2_4 = createObject("ea2-4.png");

    Ea_3_1 = createObject("ea3-1.png");
    Ea_3_2 = createObject("ea3-2.png");
    Ea_3_3 = createObject("ea3-3.png");
    Ea_3_4 = createObject("ea3-4.png");

    Ea_4_1 = createObject("ea4-1.png");
    Ea_4_2 = createObject("ea4-2.png");
    Ea_4_3 = createObject("ea4-3.png");
    Ea_4_4 = createObject("ea4-4.png");

    //넌센스 문제 생성
    Nquiz1 = createObject("Nquiz1.png");
    Nquiz2 = createObject("Nquiz2.png");
    Nquiz3 = createObject("Nquiz3.png");
    Nquiz4 = createObject("Nquiz4.png");
    //넌센스 답 생성
    Na_1_1 = createObject("na1-1.png");
    Na_1_2 = createObject("na1-2.png");
    Na_1_3 = createObject("na1-3.png");
    Na_1_4 = createObject("na1-4.png");

    Na_2_1 = createObject("na2-1.png");
    Na_2_2 = createObject("na2-2.png");
    Na_2_3 = createObject("na2-3.png");
    Na_2_4 = createObject("na2-4.png");

    Na_3_1 = createObject("na3-1.png");
    Na_3_2 = createObject("na3-2.png");
    Na_3_3 = createObject("na3-3.png");
    Na_3_4 = createObject("na3-4.png");

    Na_4_1 = createObject("na4-1.png");
    Na_4_2 = createObject("na4-2.png");
    Na_4_3 = createObject("na4-3.png");
    Na_4_4 = createObject("na4-4.png");

    //프로그래밍 문제 생성
    Pquiz1 = createObject("Pquiz1.png");
    Pquiz2 = createObject("Pquiz2.png");
    Pquiz3 = createObject("Pquiz3.png");
    Pquiz4 = createObject("Pquiz4.png");
    //프로그래밍 답 생성
    Pa_1_1 = createObject("pa1-1.png");
    Pa_1_2 = createObject("pa1-2.png");
    Pa_1_3 = createObject("pa1-3.png");
    Pa_1_4 = createObject("pa1 - 4.png");

    Pa_2_1 = createObject("pa2-1.png");
    Pa_2_2 = createObject("pa2-2.png");
    Pa_2_3 = createObject("pa2-3.png");
    Pa_2_4 = createObject("pa2-4.png");

    Pa_3_1 = createObject("pa3-1.png");
    Pa_3_2 = createObject("pa3-2.png");
    Pa_3_3 = createObject("pa3-3.png");
    Pa_3_4 = createObject("pa3-4.png");

    Pa_4_1 = createObject("pa4-1.png");
    Pa_4_2 = createObject("pa4-2.png");
    Pa_4_3 = createObject("pa4-3.png");
    Pa_4_4 = createObject("pa4-4.png");
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
    scene_4 = createScene("programming_QUIZ", "Images/programmingdungeon.png");


    //start 버튼
    start_stage4 = createObject("Images/startbutton.png");
    locateObject(start_stage4, scene4, 800, 300);
    scaleObject(start_stage4, 0.3f);
    showObject(start_stage4);


    //end 버튼
    quit = createObject("Images/endbutton.png");
    locateObject(quit, scene4, 1000, 320);
    scaleObject(quit, 0.4f);
    showObject(quit);



    //게임 카테고리 생성   
    //카테고리1: 넌센스 퀴즈
    category1 = createObject("Images/redbutton.png");
    locateObject(category1, scene4, 400, 400);

    //카테고리2: 수학 퀴즈
    category2 = createObject("Images/greenbutton.png");
    locateObject(category2, scene4, 700, 400);

    //카테고리3: 영어단어 퀴즈
    category3 = createObject("Images/yellowbutton.png");
    locateObject(category3, scene4, 1000, 400);

    //카테고리4: 프로그래밍 퀴즈
    category4 = createObject("Images/pinkbutton.png");
    locateObject(category4, scene4, 1300, 400);



    //카테고리별 퀴즈 문제&답 생성하기
    //수학 문제 생성
    Mquiz1 = createObject("Images/Mquiz1.png");
    locateObject(Mquiz1, scene_1, 500, 250);
    Mquiz2 = createObject("Images/Mquiz2.png");
    locateObject(Mquiz2, scene_1, 500, 250);
    Mquiz3 = createObject("Images/Mquiz3.png");
    locateObject(Mquiz3, scene_1, 500, 250);
    Mquiz4 = createObject("Images/Mquiz4.png");
    locateObject(Mquiz4, scene_1, 500, 250);
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
    Ma_1_4 = createObject("Images/ma1-4.png");
    locateObject(Ma_1_4, scene_1, 1300, 200);
    scaleObject(Ma_1_4, 0.4f);

    Ma_2_1 = createObject("Images/ma2-1.png");
    locateObject(Ma_2_1, scene_1, 400, 200);
    scaleObject(Ma_2_1, 0.4f);
    Ma_2_2 = createObject("Images/ma2-2.png");
    locateObject(Ma_2_2, scene_1, 700, 200);
    scaleObject(Ma_2_2, 0.4f);
    Ma_2_3 = createObject("Images/ma2-3.png");
    locateObject(Ma_2_3, scene_1, 1000, 200);
    scaleObject(Ma_2_3, 0.4f);
    Ma_2_4 = createObject("Images/ma2-4.png");
    locateObject(Ma_2_4, scene_1, 1300, 200);
    scaleObject(Ma_2_4, 0.4f);

    Ma_3_1 = createObject("Images/ma3-1.png");
    locateObject(Ma_3_1, scene_1, 400, 200);
    scaleObject(Ma_3_1, 0.4f);
    Ma_3_2 = createObject("Images/ma3-2.png");
    locateObject(Ma_3_2, scene_1, 700, 200);
    scaleObject(Ma_3_2, 0.4f);
    Ma_3_3 = createObject("Images/ma3-3.png");
    locateObject(Ma_3_3, scene_1, 1000, 200);
    scaleObject(Ma_3_3, 0.4f);
    Ma_3_4 = createObject("Images/ma3-4.png");
    locateObject(Ma_3_4, scene_1, 1300, 200);
    scaleObject(Ma_3_4, 0.4f);

    Ma_4_1 = createObject("Images/ma4-1.png");
    locateObject(Ma_4_1, scene_1, 400, 200);
    scaleObject(Ma_4_1, 0.4f);
    Ma_4_2 = createObject("Images/ma4-2.png");
    locateObject(Ma_4_2, scene_1, 700, 200);
    scaleObject(Ma_4_2, 0.4f);
    Ma_4_3 = createObject("Images/ma4-3.png");
    locateObject(Ma_4_3, scene_1, 1000, 200);
    scaleObject(Ma_4_3, 0.4f);
    Ma_4_4 = createObject("Images/ma4-4.png");
    locateObject(Ma_4_4, scene_1, 1300, 200);
    scaleObject(Ma_4_4, 0.4f);

    //영어 단어 문제 생성
    Equiz1 = createObject("Images/Equiz1.png");
    Equiz2 = createObject("Images/Equiz2.png");
    Equiz3 = createObject("Images/Equiz3.png");
    Equiz4 = createObject("Images/Equiz4.png");
    //영어 답 생성
    Ea_1_1 = createObject("Images/ea1-1.png");
    Ea_1_2 = createObject("Images/ea1-2.png");
    Ea_1_3 = createObject("Images/ea1-3.png");
    Ea_1_4 = createObject("Images/ea1-4.png");

    Ea_2_1 = createObject("Images/ea2-1.png");
    Ea_2_2 = createObject("Images/ea2-2.png");
    Ea_2_3 = createObject("Images/ea2-3.png");
    Ea_2_4 = createObject("Images/ea2-4.png");

    Ea_3_1 = createObject("Images/ea3-1.png");
    Ea_3_2 = createObject("Images/ea3-2.png");
    Ea_3_3 = createObject("Images/ea3-3.png");
    Ea_3_4 = createObject("Images/ea3-4.png");

    Ea_4_1 = createObject("Images/ea4-1.png");
    Ea_4_2 = createObject("Images/ea4-2.png");
    Ea_4_3 = createObject("Images/ea4-3.png");
    Ea_4_4 = createObject("Images/ea4-4.png");

    //넌센스 문제 생성
    Nquiz1 = createObject("Images/Nquiz1.png");
    Nquiz2 = createObject("Images/Nquiz2.png");
    Nquiz3 = createObject("Images/Nquiz3.png");
    Nquiz4 = createObject("Images/Nquiz4.png");
    //넌센스 답 생성
    Na_1_1 = createObject("Images/na1-1.png");
    Na_1_2 = createObject("Images/na1-2.png");
    Na_1_3 = createObject("Images/na1-3.png");
    Na_1_4 = createObject("Images/na1-4.png");

    Na_2_1 = createObject("Images/na2-1.png");
    Na_2_2 = createObject("Images/na2-2.png");
    Na_2_3 = createObject("Images/na2-3.png");
    Na_2_4 = createObject("Images/na2-4.png");

    Na_3_1 = createObject("Images/na3-1.png");
    Na_3_2 = createObject("Images/na3-2.png");
    Na_3_3 = createObject("Images/na3-3.png");
    Na_3_4 = createObject("Images/na3-4.png");

    Na_4_1 = createObject("Images/na4-1.png");
    Na_4_2 = createObject("Images/na4-2.png");
    Na_4_3 = createObject("Images/na4-3.png");
    Na_4_4 = createObject("Images/na4-4.png");

    //프로그래밍 문제 생성
    Pquiz1 = createObject("Images/Pquiz1.png");
    Pquiz2 = createObject("Images/Pquiz2.png");
    Pquiz3 = createObject("Images/Pquiz3.png");
    Pquiz4 = createObject("Images/Pquiz4.png");
    //프로그래밍 답 생성
    Pa_1_1 = createObject("Images/pa1-1.png");
    Pa_1_2 = createObject("Images/pa1-2.png");
    Pa_1_3 = createObject("Images/pa1-3.png");
    Pa_1_4 = createObject("Images/pa1 - 4.png");

    Pa_2_1 = createObject("Images/pa2-1.png");
    Pa_2_2 = createObject("Images/pa2-2.png");
    Pa_2_3 = createObject("Images/pa2-3.png");
    Pa_2_4 = createObject("Images/pa2-4.png");

    Pa_3_1 = createObject("Images/pa3-1.png");
    Pa_3_2 = createObject("Images/pa3-2.png");
    Pa_3_3 = createObject("Images/pa3-3.png");
    Pa_3_4 = createObject("Images/pa3-4.png");

    Pa_4_1 = createObject("Images/pa4-1.png");
    Pa_4_2 = createObject("Images/pa4-2.png");
    Pa_4_3 = createObject("Images/pa4-3.png");
    Pa_4_4 = createObject("Images/pa4-4.png");


    //startGame(scene4);


    return 0;
}
