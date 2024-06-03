#include "DxLib.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>


//�萔
#define SCREEN_X 800
#define SCREEN_Y 600
#define CIRCEL_POS_X 400
#define CIRCEL_POS_Y 300
#define CIRCEL_RADIUS_START 10
#define CIRCEL_RADIUS_MAX 200
#define RESULT_STRING_X 15
#define RESULT_STRING_Y 15

//�ϐ�
typedef struct circle
{
    int posX;       //x���W
    int posY;       //y���W
    int radius;     //���a
    double area;
}circle;

//�Q�[���t���O
bool enterPressedLastFrame = false;     //�G���^�[�L�[�������ꂽ���̃t���O
bool gameStartFlag = false;             //�Q�[���X�^�[�g�̃t���O
bool circleGenerationFlag = false;       //�~�̐����t���O
bool gameEndFlag = false;                //�Q�[���I���t���O
bool enterPressAllowed = true;          //�G���^�[�L�[�̓��͋���

//�Q�[���J�E���g
int enterPressCount;

//�\����
circle Circle;

//�~�̍ő�ʐ�
double circleAreaMax = M_PI * CIRCEL_RADIUS_MAX * CIRCEL_RADIUS_MAX;

//�~�̖ʐϊ���
double circlePorpotoin = 0.0f;

//�t���[���J�E���g
double frameCount = 0;
//�f���^����
int prevCount, nowCount;

//���C���֐�
int WinMain(HINSTANCE, HINSTANCE, LPSTR, int)   //windows�̃��C���œ�����
{
    //----------------------//
    //��{����
    //----------------------//
    ChangeWindowMode(TRUE);
    DxLib_Init;
    SetMainWindowText("�^�C�~���O�Q�[��");
    SetDrawScreen(DX_SCREEN_BACK);
    SetGraphMode(SCREEN_X, SCREEN_Y, 32);

    //����������
    if (DxLib_Init() == -1)
    {
        //�G���[��������I��
        return -1;
    }

    //��ʂɕ`�ʁ@�J���[
    int CirclrColor = GetColor(128, 128, 128);
    int resultColor = GetColor(255, 255, 255);

    //�~�̍��W�w��
    Circle.posX = CIRCEL_POS_X;
    Circle.posY = CIRCEL_POS_Y;
    Circle.radius = CIRCEL_RADIUS_START;
    //�t���[���J�E���g������
    nowCount = prevCount = GetNowCount();

    //----------------------//
    //�Q�[�����[�v
    //----------------------//
    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0 && ClearDrawScreen() == 0)
    {
        //���Ԃ��l��
        nowCount = GetNowCount();

        //�f���^�^�C��
        double deltaTime = (nowCount - prevCount) / 1000.0f;

        //�t���[���J�E���g�ɒǉ�
        frameCount += deltaTime;

        //��ʂ̏�����
        ClearDrawScreen();

        //�G���^�[�L�[�������ꂽ��Q�[���X�^�[�g
        if (enterPressAllowed && CheckHitKey(KEY_INPUT_RETURN) && !enterPressedLastFrame)
        {
            enterPressCount++;
            if (enterPressCount % 2 == 1)
            {
                gameStartFlag = true;
                gameEndFlag = false;
            }
            else
            {
                gameEndFlag = true;
                gameStartFlag = false;
                enterPressAllowed = false;
            }
        }

        //�G���^�[�L�[�������ꂽ�����L��������
        enterPressedLastFrame = CheckHitKey(KEY_INPUT_RETURN);

        //�I���t���O��false
        if (!gameEndFlag)
        {
            if (gameStartFlag)
            {
                if (frameCount >= 1.0f / 60.0f)
                {
                    frameCount = 0;

                    //�~�̓���
                    if (circleGenerationFlag)
                    {
                        //���a��5�����₷
                        Circle.radius += 5;
                        //���a���ő�l�ɂȂ����Ƃ��t���O��ϊ�
                        if (Circle.radius >= CIRCEL_RADIUS_MAX)
                        {
                            circleGenerationFlag = false;
                        }
                        //���a��5�����炷
                    }
                    else
                    {
                        Circle.radius -= 5;
                        //���a���ŏ��l�ɂȂ�����t���O��ϊ�
                        if (Circle.radius <= CIRCEL_RADIUS_START)
                        {
                            circleGenerationFlag = true;
                        }
                    }
                }
            }
        }
        else
        {
            //���U���g���o��
            Circle.area = M_PI * (double)Circle.radius * (double)Circle.radius;
            //�ʐς̊����v�Z
            circlePorpotoin = Circle.area / circleAreaMax * 100;
            //��ʂɕ`��
            SetFontSize(30);
            DrawFormatString(RESULT_STRING_X, RESULT_STRING_Y, resultColor, "�~�̊�����%.1f%%�ł�", circlePorpotoin);
        }

        //�~�̕`��
        DrawCircle(Circle.posX, Circle.posY, Circle.radius, CirclrColor);

        //����ʂ̓��e��\��ʂɔ��f
        ScreenFlip();
        //60FPS�ɒ���
        prevCount = nowCount;
    }

    //Dxlib�I������
    DxLib_End();

    return 0;
}
