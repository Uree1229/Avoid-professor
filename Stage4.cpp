#include <bangtal.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <string.h>

//sceneID ObjectID ����
TimerID timer_cr_4;
ObjectID INT[6];
extern ObjectID door[4];
extern SceneID scene, scene4, scene_stat;
extern int gametype;
int correct = 0, wrong = 0, plusINT = 0;
SceneID scene_1, scene_2, scene_3;
ObjectID start_stage4, quit, play, fxxk_4,
category1, category2, category3,
Mquiz1, Mquiz2, Mquiz3,
Equiz1, Equiz2, Equiz3,
Nquiz1, Nquiz2, Nquiz3,
Ma_1_1, Ma_1_2, Ma_1_3,
Ma_2_1, Ma_2_2, Ma_2_3,
Ma_3_1, Ma_3_2, Ma_3_3,
Ea_1_1, Ea_1_2, Ea_1_3,
Ea_2_1, Ea_2_2, Ea_2_3,
Ea_3_1, Ea_3_2, Ea_3_3,
Na_1_1, Na_1_2, Na_1_3,
Na_2_1, Na_2_2, Na_2_3,
Na_3_1, Na_3_2, Na_3_3;

int life_4 = 3;

//stat �Լ�
void stat_check_INT()
{
    if (plusINT == 3) {
        showObject(INT[5]);
        showObject(INT[4]);
        showObject(INT[3]);
        showObject(INT[2]);
        showObject(INT[1]);
        showObject(INT[0]);
    }
    else if (plusINT == 2) {
        showObject(INT[3]);
        showObject(INT[2]);
        showObject(INT[1]);
        showObject(INT[0]);
    }
    else if (plusINT == 1) {
        showObject(INT[1]);
        showObject(INT[0]);
    }
    else if (plusINT == 0) {
        showObject(INT[0]);
    }
}


//���� ������
void endgame_4() 
{
    fxxk_4 = createObject("Images/fXXk.png");
    locateObject(fxxk_4, scene_stat, 400, 460);
    showObject(fxxk_4);
    enterScene(scene_stat);    
    stat_check_INT();
    gametype = -1;
}



//�ݹ��Լ� ���� 
void mouseCallback_in_stage4(ObjectID object, int x, int y, MouseAction action)
{

    //���� ��ư�� �������� stat ��� �����鼭 ���ν��������� ���ư���
    if (object == quit) 
    {
        scene_stat = createScene("scene_stat", "Images/stat.png");
        enterScene(scene_stat);
        stat_check_INT();
        gametype = -1;
        hideObject(door[3]);
    }


    //��ư ������ ������ ���� ������ ����
    if (object == category1)
    {
        enterScene(scene_1);
        showMessage("����� ���� ���� ���Դϴ�. ��� Ǯ� '����' �ɷ�ġ�� ����Ű����.");
        showObject(Mquiz1);
        showObject(Ma_1_1);
        showObject(Ma_1_2);
        showObject(Ma_1_3);
    }

    if (object == category2)
    {
        enterScene(scene_1);
        showMessage("����� ���� �ܾ� ���� ���Դϴ�. ��� Ǯ� '����' �ɷ�ġ�� ����Ű����.");
        showObject(Equiz1);
        showObject(Ea_1_1);
        showObject(Ea_1_2);
        showObject(Ea_1_3);
    }

    if (object == category3)
    {
        enterScene(scene_1);
        showMessage("����� �ͼ��� ���� ���Դϴ�. ��� Ǯ� '����' �ɷ�ġ�� ����Ű����.");
        showObject(Nquiz1);
        showObject(Na_1_1);
        showObject(Na_1_2);
        showObject(Na_1_3);
    }


    //���� ���� �� ����    
    if (object == Ma_1_1 || object == Ma_1_2) //����� ���� ���ο� ������� ���� Ŭ���ϸ� ���������� �Ѿ
    {
        plusINT -= 1; //������ �ƴϸ� INT�� -1 �Ѵ�

        hideObject(Ma_1_1);
        hideObject(Ma_1_2);
        hideObject(Ma_1_3);
        hideObject(Mquiz1);
        showObject(Mquiz2);
        showObject(Ma_2_1);
        showObject(Ma_2_2);
        showObject(Ma_2_3);
    }
    else if (object == Ma_1_3)
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

    if (object == Ma_2_1 || object == Ma_2_2)
    {
        plusINT -= 1;

        hideObject(Ma_2_1);
        hideObject(Ma_2_2);
        hideObject(Ma_2_3);

        showObject(Mquiz3);
        showObject(Ma_3_1);
        showObject(Ma_3_2);
        showObject(Ma_3_3);
    }
    else if (object == Ma_2_3)
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
    if (object == Ma_3_1 || object == Ma_3_2)
    {
        plusINT -= 1;
        hideObject(Ma_3_3);
        hideObject(Ma_3_2);
        hideObject(Ma_3_3);
        hideObject(Mquiz3);

        enterScene(scene4);   //��� �� Ǯ�� ������ ������ ���ƿ�

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

        enterScene(scene4);   //��� �� Ǯ�� ������ ������ ���ƿ�

        hideObject(start_stage4);
        hideObject(category1);
        hideObject(category2);
        hideObject(category3);
    }


    //���� ���� �� ����
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

        enterScene(scene4);   //��� �� Ǯ�� ������ ������ ���ƿ�

        hideObject(start_stage4);
        hideObject(category1);
        hideObject(category2);
        hideObject(category3);

        //��� �� Ǯ�� ������ ������ ���ƿ�
        enterScene(scene4);
        hideObject(category1);
        hideObject(category2);
        hideObject(category3);

        hideObject(start_stage4);
    }


    //�ͼ��� ���� �� ����
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

        enterScene(scene4);   //��� �� Ǯ�� ������ ������ ���ƿ�

        hideObject(start_stage4);
        hideObject(category1);
        hideObject(category2);
        hideObject(category3);

        //��� �� Ǯ�� ������ ������ ���ƿ�
        enterScene(scene4);
        hideObject(category1);
        hideObject(category2);
        hideObject(category3);
        hideObject(start_stage4);
    }

    //start ��ư�� ������ 
    if (object = start_stage4) 
    {
        showObject(category1);
        showObject(category2);
        showObject(category3);
    }
}


//���� �Լ�
int Quiz_stage4() {

    //�ݹ� �Լ� ���
    setMouseCallback(mouseCallback_in_stage4);


    //���� ���� �� ��� ����
    //scene4 = createScene("dungeonbackground", "scene4.png");
    showMessage("���� �濡 ���� ���� ȯ���մϴ�. �־����� ��� Ǯ�� '����' �ɷ�ġ�� ����Ű����.");


    //���� �� ����
    scene_1 = createScene("math_QUIZ", "Images/mathdungeon.png");
    //scene_2 = createScene("english_QUIZ", "Images/englishdungeon.png");
    //scene_3 = createScene("nonsense_QUIZ", "Images/nonsensedungeon.png");
   

    //start ��ư
    start_stage4 = createObject("Images/startbutton.png");
    locateObject(start_stage4, scene4, 750, 300);
    scaleObject(start_stage4, 0.5f);
    showObject(start_stage4);


    //������ ��(��ư)
    quit = createObject("Images/door.png");
    locateObject(quit, scene4, 480, 200);
    showObject(quit);



    //���� ī�װ� ����   
    //ī�װ�1: �ͼ��� ����
    category1 = createObject("Images/redbutton.png");
    locateObject(category1, scene4, 400, 550);
    //ī�װ�2: ���� ����
    category2 = createObject("Images/greenbutton.png");
    locateObject(category2, scene4, 700, 550);
    //ī�װ�3: ����ܾ� ����
    category3 = createObject("Images/yellowbutton.png");
    locateObject(category3, scene4, 1000, 550);
   


    //ī�װ��� ���� ����&�� �����ϱ�
    //���� ���� ����
    Mquiz1 = createObject("Images/Mquiz1.png");
    scaleObject(Mquiz1, 2.3f);
    locateObject(Mquiz1, scene_1, 500, 250);
    Mquiz2 = createObject("Images/Mquiz2.png");
    scaleObject(Mquiz2, 2.3f);
    locateObject(Mquiz2, scene_1, 500, 250);
    Mquiz3 = createObject("Images/Mquiz3.png");
    scaleObject(Mquiz3, 2.3f);
    locateObject(Mquiz3, scene_1, 500, 250);
    //���� �ܾ� ���� ����
    Equiz1 = createObject("Images/Equiz1.png");
    scaleObject(Equiz1, 2.3f);
    locateObject(Equiz1, scene_1, 500, 250);
    Equiz2 = createObject("Images/Equiz2.png");
    scaleObject(Equiz2, 2.3f);
    locateObject(Equiz2, scene_1, 500, 250);
    Equiz3 = createObject("Images/Equiz3.png");
    scaleObject(Equiz3, 2.3f);
    locateObject(Equiz3, scene_1, 500, 250);
    //�ͼ��� ���� ����
    Nquiz1 = createObject("Images/Nquiz1.png");
    scaleObject(Nquiz1, 2.3f);
    locateObject(Nquiz1, scene_1, 500, 250);
    Nquiz2 = createObject("Images/Nquiz2.png");
    scaleObject(Nquiz2, 2.3f);
    locateObject(Nquiz2, scene_1, 500, 250);
    Nquiz3 = createObject("Images/Nquiz3.png");
    scaleObject(Nquiz3, 2.3f);
    locateObject(Nquiz3, scene_1, 500, 250);
    
    //���� �� ����
    Ma_1_1 = createObject("Images/ma1-1.png");
    locateObject(Ma_1_1, scene_1, 550, 200);
    scaleObject(Ma_1_1, 0.5f);
    Ma_1_2 = createObject("Images/ma1-2.png");
    locateObject(Ma_1_2, scene_1, 850, 200);
    scaleObject(Ma_1_2, 0.5f);
    Ma_1_3 = createObject("Images/ma1-3.png");
    locateObject(Ma_1_3, scene_1, 1150, 200);
    scaleObject(Ma_1_3, 0.5f);   

    Ma_2_1 = createObject("Images/ma2-1.png");
    locateObject(Ma_2_1, scene_1, 550, 200);
    scaleObject(Ma_2_1, 0.5f);
    Ma_2_2 = createObject("Images/ma2-2.png");
    locateObject(Ma_2_2, scene_1, 850, 200);
    scaleObject(Ma_2_2, 0.5f);
    Ma_2_3 = createObject("Images/ma2-3.png");
    locateObject(Ma_2_3, scene_1, 1150, 200);
    scaleObject(Ma_2_3, 0.5f);

    Ma_3_1 = createObject("Images/ma3-1.png");
    locateObject(Ma_3_1, scene_1, 550, 200);
    scaleObject(Ma_3_1, 0.5f);
    Ma_3_2 = createObject("Images/ma3-2.png");
    locateObject(Ma_3_2, scene_1, 850, 200);
    scaleObject(Ma_3_2, 0.5f);
    Ma_3_3 = createObject("Images/ma3-3.png");
    locateObject(Ma_3_3, scene_1, 1150, 200);
    scaleObject(Ma_3_3, 0.5f);
        
  
    //���� �� ����
    Ea_1_1 = createObject("Images/ea1-1.png");
    locateObject(Ea_1_1, scene_1, 550, 200);
    Ea_1_2 = createObject("Images/ea1-2.png");
    locateObject(Ea_1_1, scene_1, 850, 200);
    Ea_1_3 = createObject("Images/ea1-3.png");
    locateObject(Ea_1_1, scene_1, 1150, 200);

    Ea_2_1 = createObject("Images/ea2-1.png");
    locateObject(Ea_1_1, scene_1, 550, 200);
    Ea_2_2 = createObject("Images/ea2-2.png");
    locateObject(Ea_1_1, scene_1, 850, 200);
    Ea_2_3 = createObject("Images/ea2-3.png");
    locateObject(Ea_1_1, scene_1, 1150, 200);
 
    Ea_3_1 = createObject("Images/ea3-1.png");
    locateObject(Ea_1_1, scene_1, 550, 200);
    Ea_3_2 = createObject("Images/ea3-2.png");
    locateObject(Ea_1_1, scene_1, 850, 200);
    Ea_3_3 = createObject("Images/ea3-3.png");
    locateObject(Ea_1_1, scene_1, 1150, 200);   

    
    //�ͼ��� �� ����
    Na_1_1 = createObject("Images/na1-1.png");
    locateObject(Na_1_1, scene_1, 550, 200);
    Na_1_2 = createObject("Images/na1-2.png");
    locateObject(Na_1_1, scene_1, 850, 200);
    Na_1_3 = createObject("Images/na1-3.png");
    locateObject(Na_1_1, scene_1, 1150, 200);
    
    Na_2_1 = createObject("Images/na2-1.png");
    locateObject(Na_1_1, scene_1, 550, 200);
    Na_2_2 = createObject("Images/na2-2.png");
    locateObject(Na_1_1, scene_1, 850, 200);
    Na_2_3 = createObject("Images/na2-3.png");
    locateObject(Na_1_1, scene_1, 1150, 200);
   
    Na_3_1 = createObject("Images/na3-1.png");
    locateObject(Na_1_1, scene_1, 550, 200);
    Na_3_2 = createObject("Images/na3-2.png");
    locateObject(Na_1_1, scene_1, 850, 200);
    Na_3_3 = createObject("Images/na3-3.png");
    locateObject(Na_1_1, scene_1, 1150, 200);



    for (int i = 0; i < 5; i++)
    {
        INT[i] = createObject("Images/INT.png");
        locateObject(INT[i], scene_stat, 204 + i * 137, 137);
    }

    //startGame(scene4);

    return 0;
}