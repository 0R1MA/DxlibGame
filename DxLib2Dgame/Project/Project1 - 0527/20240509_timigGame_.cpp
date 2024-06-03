#include "DxLib.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>


//定数
#define SCREEN_X 800
#define SCREEN_Y 600
#define CIRCEL_POS_X 400
#define CIRCEL_POS_Y 300
#define CIRCEL_RADIUS_START 10
#define CIRCEL_RADIUS_MAX 200
#define RESULT_STRING_X 15
#define RESULT_STRING_Y 15

//変数
typedef struct circle
{
    int posX;       //x座標
    int posY;       //y座標
    int radius;     //半径
    double area;
}circle;

//ゲームフラグ
bool enterPressedLastFrame = false;     //エンターキーが押されたかのフラグ
bool gameStartFlag = false;             //ゲームスタートのフラグ
bool circleGenerationFlag = false;       //円の生成フラグ
bool gameEndFlag = false;                //ゲーム終了フラグ
bool enterPressAllowed = true;          //エンターキーの入力許可

//ゲームカウント
int enterPressCount;

//構造体
circle Circle;

//円の最大面積
double circleAreaMax = M_PI * CIRCEL_RADIUS_MAX * CIRCEL_RADIUS_MAX;

//円の面積割合
double circlePorpotoin = 0.0f;

//フレームカウント
double frameCount = 0;
//デルタ時間
int prevCount, nowCount;

//メイン関数
int WinMain(HINSTANCE, HINSTANCE, LPSTR, int)   //windowsのメインで動かす
{
    //----------------------//
    //基本操作
    //----------------------//
    ChangeWindowMode(TRUE);
    DxLib_Init;
    SetMainWindowText("タイミングゲーム");
    SetDrawScreen(DX_SCREEN_BACK);
    SetGraphMode(SCREEN_X, SCREEN_Y, 32);

    //初期化処理
    if (DxLib_Init() == -1)
    {
        //エラー発見次第終了
        return -1;
    }

    //画面に描写　カラー
    int CirclrColor = GetColor(128, 128, 128);
    int resultColor = GetColor(255, 255, 255);

    //円の座標指定
    Circle.posX = CIRCEL_POS_X;
    Circle.posY = CIRCEL_POS_Y;
    Circle.radius = CIRCEL_RADIUS_START;
    //フレームカウント初期化
    nowCount = prevCount = GetNowCount();

    //----------------------//
    //ゲームループ
    //----------------------//
    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0 && ClearDrawScreen() == 0)
    {
        //時間を獲得
        nowCount = GetNowCount();

        //デルタタイム
        double deltaTime = (nowCount - prevCount) / 1000.0f;

        //フレームカウントに追加
        frameCount += deltaTime;

        //画面の初期化
        ClearDrawScreen();

        //エンターキーが押されたらゲームスタート
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

        //エンターキーが押されたかを記憶させる
        enterPressedLastFrame = CheckHitKey(KEY_INPUT_RETURN);

        //終了フラグがfalse
        if (!gameEndFlag)
        {
            if (gameStartFlag)
            {
                if (frameCount >= 1.0f / 60.0f)
                {
                    frameCount = 0;

                    //円の動き
                    if (circleGenerationFlag)
                    {
                        //半径を5ずつ増やす
                        Circle.radius += 5;
                        //半径が最大値になったときフラグを変換
                        if (Circle.radius >= CIRCEL_RADIUS_MAX)
                        {
                            circleGenerationFlag = false;
                        }
                        //半径を5ずつ減らす
                    }
                    else
                    {
                        Circle.radius -= 5;
                        //半径が最小値になったらフラグを変換
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
            //リザルトを出力
            Circle.area = M_PI * (double)Circle.radius * (double)Circle.radius;
            //面積の割合計算
            circlePorpotoin = Circle.area / circleAreaMax * 100;
            //画面に描画
            SetFontSize(30);
            DrawFormatString(RESULT_STRING_X, RESULT_STRING_Y, resultColor, "円の割合は%.1f%%です", circlePorpotoin);
        }

        //円の描画
        DrawCircle(Circle.posX, Circle.posY, Circle.radius, CirclrColor);

        //裏画面の内容を表画面に反映
        ScreenFlip();
        //60FPSに調整
        prevCount = nowCount;
    }

    //Dxlib終了処理
    DxLib_End();

    return 0;
}
