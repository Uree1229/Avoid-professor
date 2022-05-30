#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <bangtal.h>

extern int gametype;
extern SceneID scene, scene2;
ObjectID box[10], door1, restart;
int boxX[10] = { 200, 400, 600, 800, 1000, 300, 500, 700, 900, 1100 };
int boxY[10] = { 300, 300, 300, 300, 300, 500, 500, 500, 500, 500 };
int realBox = 0, boxOpen = 0, plusLuc = 0;
bool re = false;


//상자 5개 열었을때 
void gameEnd_2()
{
    //당첨된 상자 개수만큼 능력치 상승
    if (plusLuc == 0) {
        showMessage("Among the boxes you opened, there is no treasure box in total. The lucky ability value goes up by 0.");
    }
    else if (plusLuc == 1) {
        showMessage("Among the boxes you opened, there is one treasure box in total. The lucky ability value goes up by 1. ");
    }
    else if (plusLuc == 2) {
        showMessage("Among the boxes you opened, there are two treasure boxes in total. The lucky ability value goes up by 2.");
    }
    else if (plusLuc == 3) {
        showMessage("Among the boxes you opened, there are three treasure boxes in total. The lucky ability value goes up by 3.");
    }
    else if (plusLuc == 4) {
        showMessage("Among the boxes you opened, there are four treasure boxes in total. The lucky ability value goes up by 4. ");
    }
    else if (plusLuc == 5) {
        showMessage("Among the boxes you opened, there are five treasure boxes in total. The lucky ability value goes up by 5.");
    }

    //restart 버튼
    restart = createObject("Images/restart.png");
    locateObject(restart, scene2, 20, 600);
    if (re == false)
        showObject(restart);

    //다음 씬으로 넘어감
    door1 = createObject("Images/door.png");
    locateObject(door1, scene2, 20, 0);
    showObject(door1);

}


// 박스 순서 바꾸고 배치
int boxmix_2()
{
    int a[10];
    int i, j;
    int bFound;

    // 0~ 9까지 숫자 섞기
    srand((unsigned int)time(NULL));

    for (i = 0; i < 10; ++i)
    {
        while (1)
        {
            // 난수를하나생성
            a[i] = rand() % 10;

            // 이미있는값인지확인하기위해플래그설정
            bFound = 0;

            // 같은값이있는지확인한다
            for (j = 0; j < i; ++j)
            {
                // 같은값이있으면
                if (a[j] == a[i])
                {
                    // 같은값이이미있음
                    bFound = 1;

                    break;
                }
            }

            // 같은값이없으면while문탈출
            if (!bFound)
                break;
        }
    }

    // 박스생성, 위치배정
    for (i = 0; i < 10; ++i)
    {
        box[i] = createObject("Images/box.png");
        int b = a[i];
        locateObject(box[i], scene2, boxX[b], boxY[b]);
        showObject(box[i]);
    }

    return 0;
}

void openBox_2(int x)
{
    // 당첨상자
    if (x < 5) {
        if (x < 3)setObjectImage(box[x], "Images/goldbox.png");
        else setObjectImage(box[x], "Images/diabox.png");
        boxOpen += 1;
        realBox += 1;
    }
    // 꽝 상자
    else {
        setObjectImage(box[x], "Images/emptybox.png"); // 열린 꽝 박스 이미지 넣기
        boxOpen += 1;
    }

    // 상자 5개 다 열면 종료됨
    if (boxOpen == 5) {
        plusLuc = realBox;
        gameEnd_2();
    }
}

void mouseCallback_2(ObjectID object, int x, int y, MouseAction action)
{
    //상자 열때
    if (object == box[0]) openBox_2(0);
    else if (object == box[1]) openBox_2(1);
    else if (object == box[2]) openBox_2(2);
    else if (object == box[3]) openBox_2(3);
    else if (object == box[4]) openBox_2(4);
    else if (object == box[5]) openBox_2(5);
    else if (object == box[6]) openBox_2(6);
    else if (object == box[7]) openBox_2(7);
    else if (object == box[8]) openBox_2(8);
    else if (object == box[9]) openBox_2(9);

    //나가는 문 클릭하면
    if (object == door1)
    {
        enterScene(scene);
        gametype = 0;
    }

    //restart 클릭하면
    if (object == restart) {
        re = true;
        hideObject(restart);
        for (int z = 0; z < 10; z++) hideObject(box[z]);
        boxOpen = 0;
        realBox = 0;
        boxmix_2();
        //startGame(scene2);

    }

}

// 인트로
void intro_2()
{
    showMessage("You can try your luck in this room. Only five out of ten boxes raise your luck level. A total of 5 boxes can be opened. I'll give you another chance to try after one try.");
}

void main_2()
{
    setMouseCallback(mouseCallback_2);

    //scene2 = createScene("상자 찾기", "Images/stage2.png");


    boxmix_2();
    intro_2();

    //startGame(scene2);
}
