#include "DxLib.h"   //Dx���C�u�����[���C���N���[�h

int WinMain(HINSTANCE, HINSTANCE, LPSTR, int) //windows�̃��C���œ�����
{
    //��{�݌v
    ChangeWindowMode(TRUE);
    DxLib_Init;
    SetDrawScreen(DX_SCREEN_BACK);
    SetGraphMode(800, 600, 32);
    
    //����������
    if (DxLib_Init() == -1)
    {
        //�G���[��������I��
        return -1;
    }
    //�~�̏����ʒu
    int circleX = 0;
    float circleY = 0;
    //�Q�[�����[�v
    while (ProcessMessage()== 0 &&  CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {
        //��ʂ̏�����
        ClearDrawScreen();
        //�~�̕`��
        DrawCircle(circleX, circleY,30, GetColor(0, 0, 225), TRUE);
        //x���W�ɓ���
        circleX += 2;
        circleY += 1.5f;
        //����ʂ̓��e��\��ʂɔ��f
        ScreenFlip();
    }

    //��ʂɕ`�ʁ@�J���[
    DrawCircle(320, 240, 30,  GetColor(0, 0, 255), TRUE );

    DrawPixel(320, 240, GetColor(255, 100, 0));
    //�L�[���͑҂�
    WaitKey();
    //Dxlib�I��
    DxLib_End();
    //�\�[�X�I��
    return 0;
}