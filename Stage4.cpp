#include <bangtal.h>
#include <stdio.h>

//sceneID ObjectID ����
extern SceneID scene, scene4, scene_stat;
SceneID scene_1, scene_2, scene_3, scene_4;
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

//�ݹ��Լ� ���� 
void mouseCallback_in_stage4(ObjectID object, int x, int y, MouseAction action)
{


    //���� ��ư�� �������� ���� ����
    if (object == quit) {
        enterScene(scene);
    }


    //��ư ������ ������ ���� ������ ����
    if (object == category1) {
        enterScene(scene_1);
        showMessage("����� ���� ���� ���Դϴ�. ��� Ǯ� '����' �ɷ�ġ�� ����Ű����.");
        showObject(Mquiz1);
        showObject(Ma_1_1);
        showObject(Ma_1_2);
        showObject(Ma_1_3);
        showObject(Ma_1_4);
    }
    if (object == category2) {
        enterScene(scene_2);
        showMessage("����� ���� �ܾ� ���� ���Դϴ�. ��� Ǯ� '����' �ɷ�ġ�� ����Ű����.");
    }

    if (object == category3) {
        enterScene(scene_3);
        showMessage("����� �ͼ��� ���� ���Դϴ�. ��� Ǯ� '����' �ɷ�ġ�� ����Ű����.");
    }

    if (object == category4) {
        enterScene(scene_4);
        showMessage("����� ���α׷��� ���� ���Դϴ�. ��� Ǯ� '����' �ɷ�ġ�� ����Ű����.");
    }


    //���� ���� �� ����
    //���� ���ο� ������� ���� Ŭ���ϸ� ���������� �Ѿ
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

        //��� �� Ǯ�� �ٽ� ���ƿ�
        enterScene(scene4);
    }



    //start ��ư�� ������ 
    else if (object = start_stage4) {


        //start ��ư, end ��ư ������� �Ѵ�. 
        hideObject(start_stage4);
        hideObject(quit);
        showObject(category1);
        showObject(category2);
        showObject(category3);
        showObject(category4);
    }


}

void setting_4() {

    //��� ��� ����
    scene_1 = createScene("math_QUIZ", "Images/mathdungeon.png");
    scene_2 = createScene("english_QUIZ", "Images/englishdungeon.png");
    scene_3 = createScene("nonsense_QUIZ", "Images/nonsensedungeon.png");
    scene_4 = createScene("programming_QUIZ", "Images/programmingdungeon.png");

    //start ��ư
    start_stage4 = createObject("Images/startbutton.png");
    locateObject(start_stage4, scene4, 800, 300);
    scaleObject(start_stage4, 0.3f);
    showObject(start_stage4);


    //end ��ư
    quit = createObject("Images/endbutton.png");
    locateObject(quit, scene4, 1000, 320);
    scaleObject(quit, 0.4f);
    showObject(quit);


    //���� ī�װ� ����   
    //ī�װ�1: �ͼ��� ����
    category1 = createObject("Images/redbutton.png");
    locateObject(category1, scene4, 400, 400);

    //ī�װ�2: ���� ����
    category2 = createObject("Images/greenbutton.png");
    locateObject(category2, scene4, 700, 400);

    //ī�װ�3: ����ܾ� ����
    category3 = createObject("Images/yellowbutton.png");
    locateObject(category3, scene4, 1000, 400);

    //ī�װ�4: ���α׷��� ����
    category4 = createObject("Images/pinkbutton.png");
    locateObject(category4, scene4, 1300, 400);



    //ī�װ��� ���� ����&�� �����ϱ�
    //���� ���� ����
    Mquiz1 = createObject("Images/Mquiz1.png");
    locateObject(Mquiz1, scene_1, 500, 250);
    Mquiz2 = createObject("Images/Mquiz2.png");
    locateObject(Mquiz2, scene_1, 500, 250);
    Mquiz3 = createObject("Images/Mquiz3.png");
    locateObject(Mquiz3, scene_1, 500, 250);
    Mquiz4 = createObject("Images/Mquiz4.png");
    locateObject(Mquiz4, scene_1, 500, 250);
    //���� �� ����
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

    //���� �ܾ� ���� ����
    Equiz1 = createObject("Equiz1.png");
    Equiz2 = createObject("Equiz2.png");
    Equiz3 = createObject("Equiz3.png");
    Equiz4 = createObject("Equiz4.png");
    //���� �� ����
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

    //�ͼ��� ���� ����
    Nquiz1 = createObject("Nquiz1.png");
    Nquiz2 = createObject("Nquiz2.png");
    Nquiz3 = createObject("Nquiz3.png");
    Nquiz4 = createObject("Nquiz4.png");
    //�ͼ��� �� ����
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

    //���α׷��� ���� ����
    Pquiz1 = createObject("Pquiz1.png");
    Pquiz2 = createObject("Pquiz2.png");
    Pquiz3 = createObject("Pquiz3.png");
    Pquiz4 = createObject("Pquiz4.png");
    //���α׷��� �� ����
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



//���� �Լ�
int Quiz_stage4() {

    //�ݹ� �Լ� ���
    setMouseCallback(mouseCallback_in_stage4);



    //���� ���� �� ��� ����
    //scene4 = createScene("dungeonbackground", "scene4.png");
    showMessage("���� �濡 ���� ���� ȯ���մϴ�. �־����� ��� Ǯ�� '����' �ɷ�ġ�� ����Ű����.");


    //�� ���� �� ����
    scene_1 = createScene("math_QUIZ", "Images/mathdungeon.png");
    scene_2 = createScene("english_QUIZ", "Images/englishdungeon.png");
    scene_3 = createScene("nonsense_QUIZ", "Images/nonsensedungeon.png");
    scene_4 = createScene("programming_QUIZ", "Images/programmingdungeon.png");


    //start ��ư
    start_stage4 = createObject("Images/startbutton.png");
    locateObject(start_stage4, scene4, 800, 300);
    scaleObject(start_stage4, 0.3f);
    showObject(start_stage4);


    //end ��ư
    quit = createObject("Images/endbutton.png");
    locateObject(quit, scene4, 1000, 320);
    scaleObject(quit, 0.4f);
    showObject(quit);



    //���� ī�װ� ����   
    //ī�װ�1: �ͼ��� ����
    category1 = createObject("Images/redbutton.png");
    locateObject(category1, scene4, 400, 400);

    //ī�װ�2: ���� ����
    category2 = createObject("Images/greenbutton.png");
    locateObject(category2, scene4, 700, 400);

    //ī�װ�3: ����ܾ� ����
    category3 = createObject("Images/yellowbutton.png");
    locateObject(category3, scene4, 1000, 400);

    //ī�װ�4: ���α׷��� ����
    category4 = createObject("Images/pinkbutton.png");
    locateObject(category4, scene4, 1300, 400);



    //ī�װ��� ���� ����&�� �����ϱ�
    //���� ���� ����
    Mquiz1 = createObject("Images/Mquiz1.png");
    locateObject(Mquiz1, scene_1, 500, 250);
    Mquiz2 = createObject("Images/Mquiz2.png");
    locateObject(Mquiz2, scene_1, 500, 250);
    Mquiz3 = createObject("Images/Mquiz3.png");
    locateObject(Mquiz3, scene_1, 500, 250);
    Mquiz4 = createObject("Images/Mquiz4.png");
    locateObject(Mquiz4, scene_1, 500, 250);
    //���� �� ����
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

    //���� �ܾ� ���� ����
    Equiz1 = createObject("Images/Equiz1.png");
    Equiz2 = createObject("Images/Equiz2.png");
    Equiz3 = createObject("Images/Equiz3.png");
    Equiz4 = createObject("Images/Equiz4.png");
    //���� �� ����
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

    //�ͼ��� ���� ����
    Nquiz1 = createObject("Images/Nquiz1.png");
    Nquiz2 = createObject("Images/Nquiz2.png");
    Nquiz3 = createObject("Images/Nquiz3.png");
    Nquiz4 = createObject("Images/Nquiz4.png");
    //�ͼ��� �� ����
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

    //���α׷��� ���� ����
    Pquiz1 = createObject("Images/Pquiz1.png");
    Pquiz2 = createObject("Images/Pquiz2.png");
    Pquiz3 = createObject("Images/Pquiz3.png");
    Pquiz4 = createObject("Images/Pquiz4.png");
    //���α׷��� �� ����
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