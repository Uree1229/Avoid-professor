#include <bangtal.h>
#include <stdio.h>
#include <stdlib.h>

//sceneID ObjectID 정리
extern ObjectID door[5];
extern SceneID scene, scene4, scene_stat;
extern int gametype;
SceneID  scene_1, scene_2, scene_3;

ObjectID INT_6_1,INT_6_2,INT_6_3,INT_6_4,INT_6_5, INT_4_1,INT_4_2,INT_4_3,INT_4_4, INT_2_1,INT_2_2,INT_2_3, INT_0_1, INT_0_2, start_stage4, quit, play, fxxk_4, category1, category2, category3, INT[6], Mquiz1, Mquiz2, Mquiz3, Equiz1, Equiz2, Equiz3, Nquiz1, Nquiz2, Nquiz3, Ma_1_1, Ma_1_2, Ma_1_3, Ma_2_1, Ma_2_2, Ma_2_3, Ma_3_1, Ma_3_2, Ma_3_3, Ea_1_1, Ea_1_2, Ea_1_3, Ea_2_1, Ea_2_2, Ea_2_3, Ea_3_1, Ea_3_2, Ea_3_3, Na_1_1, Na_1_2, Na_1_3, Na_2_1, Na_2_2, Na_2_3, Na_3_1, Na_3_2, Na_3_3;

int life_4 = 3;        //처음 주어지는 life 는 3이다. 
                       //문제를 틀릴 때마다 life가 1씩 감소한다.
                       //남은 life에 따라 INT 스탯을 부여한다. 

extern ObjectID createObject(const char* image, SceneID scene, int x, int y, bool shown);



//점수에 따라 stat 부여
void stat_check_stage4() 
{
    if (life_4 == 3) {
        showObject(INT_6_1);
        showObject(INT_6_2);
        showObject(INT_6_3);
        showObject(INT_6_4);
        showObject(INT_6_5);
    }
    else if (life_4 == 2) {
        showObject(INT_4_1);
        showObject(INT_4_2);
        showObject(INT_4_3);
        showObject(INT_4_4);
    }
    else if (life_4 == 1) {
        showObject(INT_2_1);
        showObject(INT_2_2);
        showObject(INT_2_3);
    }
    else if (life_4 == 0) {
        showObject(INT_0_1);
        showObject(INT_0_2);
    }
}

//콜백함수 정의 
void mouseCallback_in_stage4(ObjectID object, int x, int y, MouseAction action)
{

    //종료 버튼이 눌려지면 stat 결과 나오면서 메인스테이지로 돌아가기
    if (object == quit)
    {
        //scene_stat = createScene("scene_stat", "Images/stat.png");
        fxxk_4 = createObject("Images/fXXk.png", scene_stat, 400, 460, false);
        enterScene(scene_stat);
        showObject(fxxk_4);       
        stat_check_stage4();
        gametype = -1;
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
        enterScene(scene_1);
        showMessage("여기는 영어 단어 퀴즈 방입니다. 퀴즈를 풀어서 '지식' 능력치를 향상시키세요.");
        showObject(Equiz1);
        showObject(Ea_1_1);
        showObject(Ea_1_2);
        showObject(Ea_1_3);
    }

    if (object == category3)
    {
        enterScene(scene_1);
        showMessage("여기는 넌센스 퀴즈 방입니다. 퀴즈를 풀어서 '지식' 능력치를 향상시키세요.");
        showObject(Nquiz1);
        showObject(Na_1_1);
        showObject(Na_1_2);
        showObject(Na_1_3);
    }


    //수학 퀴즈 방 입장    퀴즈는 정답 여부에 관계없이 답을 클릭하면 다음문제로 넘어감
    
    //1번 문제
    if (object == Ma_1_2 || object == Ma_1_3) 
    {
        life_4 -= 1; //정답이 아니면 INT를 -1 한다

        hideObject(Ma_1_1);
        hideObject(Ma_1_2);
        hideObject(Ma_1_3);
        hideObject(Mquiz1);
        showObject(Mquiz2);
        showObject(Ma_2_1);
        showObject(Ma_2_2);
        showObject(Ma_2_3);
    }
    else if (object == Ma_1_1)
    {
        hideObject(Ma_1_1);
        hideObject(Ma_1_2);
        hideObject(Ma_1_3);
        hideObject(Mquiz1);
        showObject(Mquiz2);
        showObject(Ma_2_1);
        showObject(Ma_2_2);
        showObject(Ma_2_3);
    }
    //2번 문제
    if (object == Ma_2_2 || object == Ma_2_3)
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
    else if (object == Ma_2_1)
    {
        hideObject(Ma_2_1);
        hideObject(Ma_2_2);
        hideObject(Ma_2_3);
        hideObject(Mquiz2);
        showObject(Mquiz2);
        showObject(Ma_3_1);
        showObject(Ma_3_2);
        showObject(Ma_3_3);
    }
    //3번 문제
    if (object == Ma_3_1 || object == Ma_3_2)
    {
        life_4 -= 1;

        hideObject(Ma_3_3);
        hideObject(Ma_3_2);
        hideObject(Ma_3_3);
        hideObject(Mquiz3);

        enterScene(scene4);   //퀴즈를 다 풀면 나가는 방으로 돌아옴
        hideObject(start_stage4);
        hideObject(category1);
        hideObject(category2);
        hideObject(category3);
    }
    else if (object == Ma_3_3)
    {
        hideObject(Ma_3_1);
        hideObject(Ma_3_2);
        hideObject(Ma_3_3);
        hideObject(Mquiz3);

        enterScene(scene4);   //퀴즈를 다 풀면 나가는 방으로 돌아옴

        hideObject(start_stage4);
        hideObject(category1);
        hideObject(category2);
        hideObject(category3);
    }


    //영어 퀴즈 방 입장
    
    //1번 문제
    if (object == Ea_1_2 || object == Ea_1_3)
    {
        life_4 -= 1;

        hideObject(Ea_1_1);
        hideObject(Ea_1_2);
        hideObject(Ea_1_3);

        showObject(Equiz2);
        showObject(Ea_2_1);
        showObject(Ea_2_2);
        showObject(Ea_2_3);
    }
    else if (object == Ea_1_1)
    {
        hideObject(Ea_1_1);
        hideObject(Ea_1_2);
        hideObject(Ea_1_3);

        showObject(Equiz2);
        showObject(Ea_2_1);
        showObject(Ea_2_2);
        showObject(Ea_2_3);
    }
    //2번 문제
    if (object == Ea_2_1 || object == Ea_2_2)
    {
        life_4 -= 1;

        hideObject(Ea_2_2);
        hideObject(Ea_2_2);
        hideObject(Ea_2_3);

        showObject(Equiz3);
        showObject(Ea_3_1);
        showObject(Ea_3_2);
        showObject(Ea_3_3);
    }
    else if (object == Ea_2_3)
    {
        hideObject(Ea_2_2);
        hideObject(Ea_2_2);
        hideObject(Ea_2_3);

        showObject(Equiz3);
        showObject(Ea_3_1);
        showObject(Ea_3_2);
        showObject(Ea_3_3);
    }
    //3번 문제
    if (object == Ea_3_1 || object == Ea_3_2)
    {
        life_4 -= 1;

        hideObject(Ea_3_3);
        hideObject(Ea_3_2);
        hideObject(Ea_3_3);

        enterScene(scene4);   //퀴즈를 다 풀면 나가는 방으로 돌아옴

        hideObject(start_stage4);
        hideObject(category1);
        hideObject(category2);
        hideObject(category3);
    }
    else if (object == Ea_3_3)
    {
        hideObject(Ea_3_3);
        hideObject(Ea_3_2);
        hideObject(Ea_3_3);

        enterScene(scene4);   //퀴즈를 다 풀면 나가는 방으로 돌아옴

        hideObject(start_stage4);
        hideObject(category1);
        hideObject(category2);
        hideObject(category3);
    }


    //넌센스 퀴즈 방 입장

    //1번 문제
    if (object == Na_1_2 || object == Na_1_3)
    {
        life_4 -= 1;

        hideObject(Na_1_1);
        hideObject(Na_1_2);
        hideObject(Na_1_3);

        showObject(Nquiz2);
        showObject(Na_2_1);
        showObject(Na_2_2);
        showObject(Na_2_3);
    }
    else if (object == Na_1_1)
    {
        hideObject(Na_1_1);
        hideObject(Na_1_2);
        hideObject(Na_1_3);

        showObject(Nquiz2);
        showObject(Na_2_1);
        showObject(Na_2_2);
        showObject(Na_2_3);
    }
    //2번 문제
    if (object == Na_2_2 || object == Na_2_3)
    {
        life_4 -= 1;

        hideObject(Na_2_2);
        hideObject(Na_2_2);
        hideObject(Na_2_3);

        showObject(Nquiz3);
        showObject(Na_3_1);
        showObject(Na_3_2);
        showObject(Na_3_3);
    }
    else if (object == Na_2_1)
    {
        hideObject(Na_2_2);
        hideObject(Na_2_2);
        hideObject(Na_2_3);

        showObject(Nquiz3);
        showObject(Na_3_1);
        showObject(Na_3_2);
        showObject(Na_3_3);
    }
    //3번 문제
    if (object == Na_3_2 || object == Na_3_3)
    {
        life_4 -= 1;

        hideObject(Na_3_3);
        hideObject(Na_3_2);
        hideObject(Na_3_3);

        enterScene(scene4);   //퀴즈를 다 풀면 나가는 방으로 돌아옴

        hideObject(start_stage4);
        hideObject(category1);
        hideObject(category2);
        hideObject(category3);
    }
    else if (object == Na_3_1)
    {
        hideObject(Na_3_3);
        hideObject(Na_3_2);
        hideObject(Na_3_3);

        enterScene(scene4);   //퀴즈를 다 풀면 나가는 방으로 돌아옴

        hideObject(start_stage4);
        hideObject(category1);
        hideObject(category2);
        hideObject(category3);
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


    //퀴즈 방 생성
    scene_1 = createScene("math_QUIZ", "Images/mathdungeon.png");
    //scene_2 = createScene("english_QUIZ", "Images/englishdungeon.png");
    //scene_3 = createScene("nonsense_QUIZ", "Images/nonsensedungeon.png");
   

    //start 버튼
    start_stage4 = createObject("Images/startbutton.png", scene4, 750, 300, false);
    scaleObject(start_stage4, 0.5f);
    showObject(start_stage4);


    //나가는 문(버튼)
    quit = createObject("Images/door.png", scene4, 480, 200, false);
    showObject(quit);


    //stat 생성
    
    INT_6_4 = createObject("Images/INT.png", scene_stat, 204 + 548, 237, false);
    INT_6_3 = createObject("Images/INT.png", scene_stat, 204 + 411, 237, false);
    INT_6_2 = createObject("Images/INT.png", scene_stat, 204 + 274, 237, false);
    INT_6_1 = createObject("Images/INT.png", scene_stat, 204 + 137, 237, false);
    INT_6_5 = createObject("Images/INT.png", scene_stat, 204, 237, false);        //다 맞았을 때  
    INT_4_1 = createObject("Images/INT.png", scene_stat, 204 + 411, 237, false);
    INT_4_2 = createObject("Images/INT.png", scene_stat, 204 + 274, 237, false);
    INT_4_3 = createObject("Images/INT.png", scene_stat, 204 + 137, 237, false); 
    INT_4_4 = createObject("Images/INT.png", scene_stat, 204, 237, false);        //하나 틀렸을 때
    INT_2_1 = createObject("Images/INT.png", scene_stat, 204 + 274, 237, false);
    INT_2_2 = createObject("Images/INT.png", scene_stat, 204 + 137, 237, false);  
    INT_2_3 = createObject("Images/INT.png", scene_stat, 204, 237, false);        //두 문제 틀렸을 때
    INT_0_1 = createObject("Images/INT.png", scene_stat, 204 + 137, 237, false);    
    INT_0_2 = createObject("Images/INT.png", scene_stat, 204, 237, false);        //세 문제 다 틀렸을 때
    


    //게임 카테고리 생성   
    //카테고리1: 넌센스 퀴즈
    category1 = createObject("Images/redbutton.png", scene4, 600, 550, false);    
    //카테고리2: 수학 퀴즈
    category2 = createObject("Images/greenbutton.png", scene4, 900, 550, false);    
    //카테고리3: 영어단어 퀴즈
    category3 = createObject("Images/yellowbutton.png", scene4, 1200, 550, false);   
   


    //카테고리별 퀴즈 문제&답 생성하기
    //수학 문제 생성
    Mquiz1 = createObject("Images/Mquiz1.png", scene_1, 500, 250, false);
    scaleObject(Mquiz1, 2.3f);
    Mquiz2 = createObject("Images/Mquiz2.png", scene_1, 500, 250, false);
    scaleObject(Mquiz2, 2.3f);    
    Mquiz3 = createObject("Images/Mquiz3.png", scene_1, 500, 250, false);
    scaleObject(Mquiz3, 2.3f);   
    //영어 단어 문제 생성
    Equiz1 = createObject("Images/Equiz1.png", scene_1, 500, 250, false);
    scaleObject(Equiz1, 2.3f);
    Equiz2 = createObject("Images/Equiz2.png", scene_1, 500, 250, false);
    scaleObject(Equiz2, 2.3f);
    Equiz3 = createObject("Images/Equiz3.png", scene_1, 500, 250, false);
    scaleObject(Equiz3, 2.3f);
    //넌센스 문제 생성
    Nquiz1 = createObject("Images/Nquiz1.png", scene_1, 500, 250, false);
    scaleObject(Nquiz1, 2.3f);
    Nquiz2 = createObject("Images/Nquiz2.png", scene_1, 500, 250, false);
    scaleObject(Nquiz2, 2.3f);
    Nquiz3 = createObject("Images/Nquiz3.png", scene_1, 500, 250, false);
    scaleObject(Nquiz3, 2.3f);
    

    //수학 답 생성
    Ma_1_1 = createObject("Images/ma1-1.png", scene_1, 550, 200, false);
    scaleObject(Ma_1_1, 0.5f);
    Ma_1_2 = createObject("Images/ma1-2.png", scene_1, 850, 200, false);
    scaleObject(Ma_1_2, 0.5f);
    Ma_1_3 = createObject("Images/ma1-3.png", scene_1, 1150, 200, false);
    scaleObject(Ma_1_3, 0.5f);   

    Ma_2_1 = createObject("Images/ma2-1.png", scene_1, 550, 200, false);
    scaleObject(Ma_2_1, 0.5f);
    Ma_2_2 = createObject("Images/ma2-2.png", scene_1, 850, 200, false);
    scaleObject(Ma_2_2, 0.5f);
    Ma_2_3 = createObject("Images/ma2-3.png", scene_1, 1150, 200, false);
    scaleObject(Ma_2_3, 0.5f);

    Ma_3_1 = createObject("Images/ma3-1.png", scene_1, 550, 200, false);
    scaleObject(Ma_3_1, 0.5f);
    Ma_3_2 = createObject("Images/ma3-2.png", scene_1, 850, 200, false);
    scaleObject(Ma_3_2, 0.5f);
    Ma_3_3 = createObject("Images/ma3-3.png", scene_1, 1150, 200, false);
    scaleObject(Ma_3_3, 0.5f);
        
  
    //영어 답 생성
    Ea_1_1 = createObject("Images/ea1-1.png", scene_1, 550, 200, false);
    scaleObject(Ea_1_1, 0.5f);
    Ea_1_2 = createObject("Images/ea1-2.png", scene_1, 850, 200, false);
    scaleObject(Ea_1_2, 0.5f);
    Ea_1_3 = createObject("Images/ea1-3.png", scene_1, 1150, 200, false);
    scaleObject(Ea_1_3, 0.5f);

    Ea_2_1 = createObject("Images/ea2-1.png", scene_1, 550, 200, false);
    scaleObject(Ea_2_1, 0.5f);
    Ea_2_2 = createObject("Images/ea2-2.png", scene_1, 850, 200, false);
    scaleObject(Ea_2_2, 0.5f);
    Ea_2_3 = createObject("Images/ea2-3.png", scene_1, 1150, 200, false);
    scaleObject(Ea_2_3, 0.5f);
 
    Ea_3_1 = createObject("Images/ea3-1.png", scene_1, 550, 200, false);
    scaleObject(Ea_3_1, 0.5f);
    Ea_3_2 = createObject("Images/ea3-2.png", scene_1, 850, 200, false);
    scaleObject(Ea_3_2, 0.5f);
    Ea_3_3 = createObject("Images/ea3-3.png", scene_1, 1150, 200, false);
    scaleObject(Ea_3_3, 0.5f);

    
    //넌센스 답 생성
    Na_1_1 = createObject("Images/na1-1.png", scene_1, 550, 200, false);
    scaleObject(Na_1_1, 0.5f);
    Na_1_2 = createObject("Images/na1-2.png", scene_1, 850, 200, false);
    scaleObject(Na_1_2, 0.5f);
    Na_1_3 = createObject("Images/na1-3.png", scene_1, 1150, 200, false);
    scaleObject(Na_1_3, 0.5f);
    
    Na_2_1 = createObject("Images/na2-1.png", scene_1, 550, 200, false);
    scaleObject(Na_2_1, 0.5f);
    Na_2_2 = createObject("Images/na2-2.png", scene_1, 850, 200, false);
    scaleObject(Na_2_2, 0.5f);
    Na_2_3 = createObject("Images/na2-3.png", scene_1, 1150, 200, false);
    scaleObject(Na_2_3, 0.5f);
   
    Na_3_1 = createObject("Images/na3-1.png", scene_1, 550, 200, false);
    scaleObject(Na_3_1, 0.5f);
    Na_3_2 = createObject("Images/na3-2.png", scene_1, 850, 200, false);
    scaleObject(Na_3_2, 0.5f);
    Na_3_3 = createObject("Images/na3-3.png", scene_1, 1150, 200, false);
    scaleObject(Na_3_3, 0.5f);


    //startGame(scene4);

    return 0;
}