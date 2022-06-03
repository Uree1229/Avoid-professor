#include <bangtal.h>
#include <stdio.h>
#include <stdlib.h>

//sceneID ObjectID ����
extern ObjectID door[5];
extern SceneID scene, scene4, scene_stat;
extern int gametype;
SceneID  scene_1, scene_2, scene_3;

ObjectID INT_6_1,INT_6_2,INT_6_3,INT_6_4,INT_6_5, INT_4_1,INT_4_2,INT_4_3,INT_4_4, INT_2_1,INT_2_2,INT_2_3, INT_0_1, INT_0_2, start_stage4, quit, play, fxxk_4, category1, category2, category3, INT[6], Mquiz1, Mquiz2, Mquiz3, Equiz1, Equiz2, Equiz3, Nquiz1, Nquiz2, Nquiz3, Ma_1_1, Ma_1_2, Ma_1_3, Ma_2_1, Ma_2_2, Ma_2_3, Ma_3_1, Ma_3_2, Ma_3_3, Ea_1_1, Ea_1_2, Ea_1_3, Ea_2_1, Ea_2_2, Ea_2_3, Ea_3_1, Ea_3_2, Ea_3_3, Na_1_1, Na_1_2, Na_1_3, Na_2_1, Na_2_2, Na_2_3, Na_3_1, Na_3_2, Na_3_3;

int life_4 = 3;        //ó�� �־����� life �� 3�̴�. 
                       //������ Ʋ�� ������ life�� 1�� �����Ѵ�.
                       //���� life�� ���� INT ������ �ο��Ѵ�. 

extern ObjectID createObject(const char* image, SceneID scene, int x, int y, bool shown);



//������ ���� stat �ο�
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

//�ݹ��Լ� ���� 
void mouseCallback_in_stage4(ObjectID object, int x, int y, MouseAction action)
{

    //���� ��ư�� �������� stat ��� �����鼭 ���ν��������� ���ư���
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


    //���� ���� �� ����    ����� ���� ���ο� ������� ���� Ŭ���ϸ� ���������� �Ѿ
    
    //1�� ����
    if (object == Ma_1_2 || object == Ma_1_3) 
    {
        life_4 -= 1; //������ �ƴϸ� INT�� -1 �Ѵ�

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
    //2�� ����
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
    //3�� ����
    if (object == Ma_3_1 || object == Ma_3_2)
    {
        life_4 -= 1;

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
    
    //1�� ����
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
    //2�� ����
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
    //3�� ����
    if (object == Ea_3_1 || object == Ea_3_2)
    {
        life_4 -= 1;

        hideObject(Ea_3_3);
        hideObject(Ea_3_2);
        hideObject(Ea_3_3);

        enterScene(scene4);   //��� �� Ǯ�� ������ ������ ���ƿ�

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

        enterScene(scene4);   //��� �� Ǯ�� ������ ������ ���ƿ�

        hideObject(start_stage4);
        hideObject(category1);
        hideObject(category2);
        hideObject(category3);
    }


    //�ͼ��� ���� �� ����

    //1�� ����
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
    //2�� ����
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
    //3�� ����
    if (object == Na_3_2 || object == Na_3_3)
    {
        life_4 -= 1;

        hideObject(Na_3_3);
        hideObject(Na_3_2);
        hideObject(Na_3_3);

        enterScene(scene4);   //��� �� Ǯ�� ������ ������ ���ƿ�

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

        enterScene(scene4);   //��� �� Ǯ�� ������ ������ ���ƿ�

        hideObject(start_stage4);
        hideObject(category1);
        hideObject(category2);
        hideObject(category3);
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
    start_stage4 = createObject("Images/startbutton.png", scene4, 750, 300, false);
    scaleObject(start_stage4, 0.5f);
    showObject(start_stage4);


    //������ ��(��ư)
    quit = createObject("Images/door.png", scene4, 480, 200, false);
    showObject(quit);


    //stat ����
    
    INT_6_4 = createObject("Images/INT.png", scene_stat, 204 + 548, 237, false);
    INT_6_3 = createObject("Images/INT.png", scene_stat, 204 + 411, 237, false);
    INT_6_2 = createObject("Images/INT.png", scene_stat, 204 + 274, 237, false);
    INT_6_1 = createObject("Images/INT.png", scene_stat, 204 + 137, 237, false);
    INT_6_5 = createObject("Images/INT.png", scene_stat, 204, 237, false);        //�� �¾��� ��  
    INT_4_1 = createObject("Images/INT.png", scene_stat, 204 + 411, 237, false);
    INT_4_2 = createObject("Images/INT.png", scene_stat, 204 + 274, 237, false);
    INT_4_3 = createObject("Images/INT.png", scene_stat, 204 + 137, 237, false); 
    INT_4_4 = createObject("Images/INT.png", scene_stat, 204, 237, false);        //�ϳ� Ʋ���� ��
    INT_2_1 = createObject("Images/INT.png", scene_stat, 204 + 274, 237, false);
    INT_2_2 = createObject("Images/INT.png", scene_stat, 204 + 137, 237, false);  
    INT_2_3 = createObject("Images/INT.png", scene_stat, 204, 237, false);        //�� ���� Ʋ���� ��
    INT_0_1 = createObject("Images/INT.png", scene_stat, 204 + 137, 237, false);    
    INT_0_2 = createObject("Images/INT.png", scene_stat, 204, 237, false);        //�� ���� �� Ʋ���� ��
    


    //���� ī�װ� ����   
    //ī�װ�1: �ͼ��� ����
    category1 = createObject("Images/redbutton.png", scene4, 600, 550, false);    
    //ī�װ�2: ���� ����
    category2 = createObject("Images/greenbutton.png", scene4, 900, 550, false);    
    //ī�װ�3: ����ܾ� ����
    category3 = createObject("Images/yellowbutton.png", scene4, 1200, 550, false);   
   


    //ī�װ��� ���� ����&�� �����ϱ�
    //���� ���� ����
    Mquiz1 = createObject("Images/Mquiz1.png", scene_1, 500, 250, false);
    scaleObject(Mquiz1, 2.3f);
    Mquiz2 = createObject("Images/Mquiz2.png", scene_1, 500, 250, false);
    scaleObject(Mquiz2, 2.3f);    
    Mquiz3 = createObject("Images/Mquiz3.png", scene_1, 500, 250, false);
    scaleObject(Mquiz3, 2.3f);   
    //���� �ܾ� ���� ����
    Equiz1 = createObject("Images/Equiz1.png", scene_1, 500, 250, false);
    scaleObject(Equiz1, 2.3f);
    Equiz2 = createObject("Images/Equiz2.png", scene_1, 500, 250, false);
    scaleObject(Equiz2, 2.3f);
    Equiz3 = createObject("Images/Equiz3.png", scene_1, 500, 250, false);
    scaleObject(Equiz3, 2.3f);
    //�ͼ��� ���� ����
    Nquiz1 = createObject("Images/Nquiz1.png", scene_1, 500, 250, false);
    scaleObject(Nquiz1, 2.3f);
    Nquiz2 = createObject("Images/Nquiz2.png", scene_1, 500, 250, false);
    scaleObject(Nquiz2, 2.3f);
    Nquiz3 = createObject("Images/Nquiz3.png", scene_1, 500, 250, false);
    scaleObject(Nquiz3, 2.3f);
    

    //���� �� ����
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
        
  
    //���� �� ����
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

    
    //�ͼ��� �� ����
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