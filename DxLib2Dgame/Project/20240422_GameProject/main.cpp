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
    int circleX = 400;
    int circleY = 300;
    //�����̏����ʒu
    int stringX = 10;
    int stringY = 15;
    //Hit�\���ʒu
    int stringX1 = 10;
    int stringY1 = 45;
    //�}�E�X�̍��W
    int mouseX = 0;
    int mouseY = 0;
    int Dach;           //�_�b�V��

    int circleColor = GetColor(0, 0, 225);

    int StringColor = GetColor(225, 225, 225);
    int StringColor2 = GetColor(225, 0, 0);

    //�Q�[�����[�v
    while (ProcessMessage()== 0 &&  CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {
        //��ʂ̏�����
        ClearDrawScreen();
        //�����̑傫���̎w��
        SetFontSize(32);
        //��ʂɕ����\��
        //DrawString(10,15,"HelloWould",StringColor);
        DrawFormatString(stringX, stringY, StringColor, "Mouse X:%d Y:%d", mouseX, mouseY);
        //�~�̕`��
        DrawCircle(circleX, circleY,30, GetColor(0, 0, 225), TRUE);
        //�}�E�X�̍��W���擾
        GetMousePoint(&mouseX, &mouseY);
        //�}�E�X���N���b�N���ꂽ��
        if (GetMouseInput() & MOUSE_INPUT_LEFT)
        {
            DrawString(stringX1, stringY1, "Hit!", StringColor2);
        }

        if (CheckHitKey(KEY_INPUT_LSHIFT))  // �V�t�g�L�[����
        {
            Dach = 1;       //�����Ɓ~�P�{�@����
        }
        else
        {
            Dach = 2;       //�����Ƒ��x�~�Q�{
        }
        
        if (CheckHitKey(KEY_INPUT_W))
        {
            if (circleY >= 40)
            {
                circleY -= 5 * Dach;
            }
            else
            {
                circleY += 10;
            }
        }
        if (CheckHitKey(KEY_INPUT_S))
        {
            if (circleY <= 560)
            {
                circleY += 5 * Dach;
            }
            else
            {
                circleY -= 10;
            }
            
        }
        if (CheckHitKey(KEY_INPUT_A))
        {
            if (circleX >= 40)
            {
                circleX -= 5 * Dach;
            }
            else
            {
                circleX += 10;
            }
        }
        if (CheckHitKey(KEY_INPUT_D))
        {
            if (circleX <= 740)
            {
                circleX += 5 * Dach;
            }
            else
            {
                circleX -= 10;
            }
        }

        //x���W�ɓ���
        // circleX += 36;
        //circleY += 27;

        //�G���A�O�ɏo���Ƃ����Α��Ƀ��[�v
        /*if (circleX >= 800)
        {
            circleX = 0;
        }
        else if (circleX <= 0)
        {
            circleX = 800;
        }

        if (circleY <= 0)
        {
            circleY = 600;
        }
        else if (circleY >= 600)
        {
            circleY = 0;
        }
        */

        //����ʂ̓��e��\��ʂɔ��f
        ScreenFlip();
    }

    //��ʂɕ`�ʁ@�J���[
    //DrawCircle(320, 240, 30,  GetColor(0, 0, 255), TRUE );

    DrawPixel(320, 240, GetColor(255, 100, 0));
    //�L�[���͑҂�
    //WaitKey();
    //Dxlib�I��
    DxLib_End();
    //�\�[�X�I��
    return 0;
}