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
    int circleX = 0;
    float circleY = 0;
    //ゲームループ
    while (ProcessMessage()== 0 &&  CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {
        //画面の初期化
        ClearDrawScreen();
        //円の描画
        DrawCircle(circleX, circleY,30, GetColor(0, 0, 225), TRUE);
        //x座標に動き
        circleX += 2;
        circleY += 1.5f;
        //裏画面の内容を表画面に反映
        ScreenFlip();
    }

    //画面に描写　カラー
    DrawCircle(320, 240, 30,  GetColor(0, 0, 255), TRUE );

    DrawPixel(320, 240, GetColor(255, 100, 0));
    //キー入力待ち
    WaitKey();
    //Dxlib終了
    DxLib_End();
    //ソース終了
    return 0;
}