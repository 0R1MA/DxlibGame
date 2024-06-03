#include "DxLib.h"   //Dxライブラリーをインクルード

int WinMain(HINSTANCE, HINSTANCE, LPSTR, int) //windowsのメインで動かす
{
    //基本設計
    ChangeWindowMode(TRUE);
    DxLib_Init;
    SetDrawScreen(DX_SCREEN_BACK);
    SetGraphMode(800, 600, 32);
    
    //初期化処理
    if (DxLib_Init() == -1)
    {
        //エラー発見次第終了
        return -1;
    }
    //円の初期位置
    int circleX = 400;
    int circleY = 300;
    //文字の初期位置
    int stringX = 10;
    int stringY = 15;
    //Hit表示位置
    int stringX1 = 10;
    int stringY1 = 45;
    //マウスの座標
    int mouseX = 0;
    int mouseY = 0;
    int Dach;           //ダッシュ

    int circleColor = GetColor(0, 0, 225);

    int StringColor = GetColor(225, 225, 225);
    int StringColor2 = GetColor(225, 0, 0);

    //ゲームループ
    while (ProcessMessage()== 0 &&  CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {
        //画面の初期化
        ClearDrawScreen();
        //文字の大きさの指定
        SetFontSize(32);
        //画面に文字表示
        //DrawString(10,15,"HelloWould",StringColor);
        DrawFormatString(stringX, stringY, StringColor, "Mouse X:%d Y:%d", mouseX, mouseY);
        //円の描画
        DrawCircle(circleX, circleY,30, GetColor(0, 0, 225), TRUE);
        //マウスの座標を取得
        GetMousePoint(&mouseX, &mouseY);
        //マウスがクリックされたら
        if (GetMouseInput() & MOUSE_INPUT_LEFT)
        {
            DrawString(stringX1, stringY1, "Hit!", StringColor2);
        }

        if (CheckHitKey(KEY_INPUT_LSHIFT))  // シフトキー入力
        {
            Dach = 1;       //押すと×１倍　減速
        }
        else
        {
            Dach = 2;       //離すと速度×２倍
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

        //x座標に動き
        // circleX += 36;
        //circleY += 27;

        //エリア外に出たとき反対側にワープ
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

        //裏画面の内容を表画面に反映
        ScreenFlip();
    }

    //画面に描写　カラー
    //DrawCircle(320, 240, 30,  GetColor(0, 0, 255), TRUE );

    DrawPixel(320, 240, GetColor(255, 100, 0));
    //キー入力待ち
    //WaitKey();
    //Dxlib終了
    DxLib_End();
    //ソース終了
    return 0;
}