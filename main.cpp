#include "TXLib.h"
#include <iostream>
#include <fstream>

struct button{
const char* txt;
int x;
int y;
bool visible;
HDC pic;
int xP;
int yP;
int WP;
int HP;
int xIF;
int yIF;
bool freeze;
bool countP;
int constNumber;
int number;
};

struct buttonMenu{
const char* txt;
int x;
int y;
int xIF;
int yIF;
};

struct buttonTop{
const char* txt;
int x;
int y;
};
struct buttonOp{
const char* txt;
int x;
int y;
};
 void Specialbutt(const char* txt, int x, int y)
 {
    txSetColor(RGB(100,0,0));
    txSetFillColor(RGB(100,0,0));
    Win32::RoundRect (txDC(), x, y, x + 105, y + 55, 30, 30);

    txSetColor(TX_BLACK);
    txSetFillColor(TX_BLACK);
    Win32::RoundRect (txDC(), x, y, x + 100, y + 50, 30, 30);

    txSetColor(RGB(255,0,0));
    txSelectFont("Comic Sans MS", 20);
    txDrawText(x, y, x + 100, y + 50, txt);
 }
 //----------------------------------------------------
void butt(button *b, int i)
 {
    txSetColor(RGB(100,0,0));
    txSetFillColor(RGB(100,0,0));
    Win32::RoundRect (txDC(), b[i].x, b[i].y, b[i].x + 105, b[i].y + 55, 30, 30);

    txSetColor(TX_BLACK);
    txSetFillColor(TX_BLACK);
    Win32::RoundRect (txDC(), b[i].x, b[i].y, b[i].x + 100, b[i].y + 50, 30, 30);

    txSetColor(RGB(255,0,0));
    txSelectFont("Comic Sans MS", 20);
    txDrawText(b[i].x, b[i].y, b[i].x + 100, b[i].y + 50, b[i].txt);
 }

void buttAnimation(button *b, int i)
 {
    txSetColor(RGB(255,255,0));
    txSelectFont("Comic Sans MS", 20);
    txDrawText(b[i].x, b[i].y, b[i].x + 100, b[i].y + 50, b[i].txt);
 }
void buttAnimationBG(button *b, int i)
 {
    txSetColor(RGB(255,0,0));
    txSetFillColor(RGB(255,0,0));
    Win32::RoundRect (txDC(), b[i].x - 2, b[i].y - 2, b[i].x + 107, b[i].y + 57, 30, 30);
 }
 //---------------------------------------------------------------------
void buttMenu(buttonMenu *but, int r)
 {
    txSetColor(RGB(100,0,0));
    txSetFillColor(RGB(100,0,0));
    Win32::RoundRect (txDC(), but[r].x, but[r].y, but[r].x + 405, but[r].y + 55, 20, 20);

    txSetColor(TX_BLACK);
    txSetFillColor(TX_BLACK);
    Win32::RoundRect (txDC(), but[r].x, but[r].y, but[r].x + 400, but[r].y + 50, 20, 20);

    txSetColor(RGB(255,0,0));
    txSelectFont("Comic Sans MS", 30);
    txDrawText(but[r].x, but[r].y, but[r].x + 400, but[r].y + 50, but[r].txt);
 }
void buttMenuAnimation(buttonMenu *but, int r)
  {
    txSetColor(RGB(255,255,0));
    txSelectFont("Comic Sans MS", 30);
    txDrawText(but[r].x, but[r].y, but[r].x + 400, but[r].y + 50, but[r].txt);
  }
void buttAnimationMenuBG(buttonMenu *but, int r)
 {
    txSetColor(RGB(255,0,0));
    txSetFillColor(RGB(255,0,0));
    Win32::RoundRect (txDC(), but[r].x - 2, but[r].y - 2, but[r].x + 407, but[r].y + 57, 30, 30);
 }
 //------------------------------------------------------------------------
 void buttTop(buttonTop *button, int t)
 {
    txSetColor(RGB(100,0,0));
    txSetFillColor(RGB(100,0,0));
    Win32::RoundRect (txDC(), button[t].x, button[t].y, button[t].x + 405, button[t].y + 55, 20, 20);

    txSetColor(TX_BLACK);
    txSetFillColor(TX_BLACK);
    Win32::RoundRect (txDC(), button[t].x, button[t].y, button[t].x + 400, button[t].y + 50, 20, 20);

    txSetColor(RGB(255,0,0));
    txSelectFont("Comic Sans MS", 30);
    txDrawText(button[t].x, button[t].y, button[t].x + 400, button[t].y + 50, button[t].txt);
 }
void buttTopAnimation(buttonTop *button, int t)
  {
    txSetColor(RGB(255,255,0));
    txSelectFont("Comic Sans MS", 30);
    txDrawText(button[t].x, button[t].y, button[t].x + 400, button[t].y + 50, button[t].txt);
  }
void buttAnimationTopBG(buttonTop *button, int t)
 {
    txSetColor(RGB(255,0,0));
    txSetFillColor(RGB(255,0,0));
    Win32::RoundRect (txDC(), button[t].x - 2, button[t].y - 2, button[t].x + 407, button[t].y + 57, 30, 30);
 }

 //-------------------------------//----------------------------------//------------------------------------------//-----------------------------------
int main()
    {
        txCreateWindow (1920, 1080);
        txDisableAutoPause();
        HDC heart = txLoadImage ("images/heart.bmp");
        HDC brain = txLoadImage ("images/brain.bmp");
        HDC lungs = txLoadImage ("images/lungs.bmp");
        HDC pochki = txLoadImage ("images/pochki.bmp");
        HDC pechen = txLoadImage ("images/pechen.bmp");
        HDC selesenka = txLoadImage ("images/selesenka.bmp");
        HDC stomach = txLoadImage ("images/stomach.bmp");
        HDC blood = txLoadImage ("images/blood.bmp");
        HDC pulseP = txLoadImage ("images/pulse.bmp");

        bool visBlood = false;

        HDC background = txLoadImage ("images/background.bmp");
        HDC human = txLoadImage ("images/human.bmp");
        HDC table = txLoadImage ("images/table.bmp");
        //const char* pos = "menu";
        const char* pos = "menu";
        bool  start = false;
        bool visible = false;

        bool havePos = false;

        int Nbut = 6;
        button b[Nbut];
        b[0] = {"??????", 1800, 100, false, heart, 1300, 600, 54, 74, 1700, 100, false, 0, 1, 0};
        b[1] = {"??????", 1800, 200, false, lungs, 1301, 600, 114, 103, 1700, 200, false, 0, 2, 0};
        b[2] = {"?????", 1800, 300, false, pochki, 1302, 600, 117, 123, 1700, 300, false, 0, 5, 0};
        b[3] = {"??????", 1800, 400, false, pechen, 1303, 600, 73, 64, 1700, 400, false, 0, 4, 0};
        b[4] = {"?????????", 1800, 500, false, selesenka, 1304, 600, 56, 76, 1700, 500, false, 0, 6, 0};
        b[5] = {"???????", 1800, 600, false, stomach, 1305, 600, 76, 87, 1700, 600, false, 0, 3, 0};

        int NButtMenu = 5;
        buttonMenu but[NButtMenu];
        but[0] = {"??????? ? ????????", 760, 400, 760, 400};
        but[1] = {"????? ?? ?????????", 760, 610, 760, 610};
        but[2] = {"????????", 760, 540, 760, 540};
        but[3] = {"?????????", 760, 470, 760, 470};
       //??????? ??????? ???? ? ?????? ?????

        int NButtOp = 1;
        buttonOp BP[NButtOp];
        BP[0] = {"????? ?? ?????????", 760, 540};

        int NbuttTop = 1;
        buttonTop button[NbuttTop];
        button[0] = {"?????????? ???????", 30, 50};

        bool visSue = false;
        int money = 0;
        bool countP = false;
        int i = 0;
        int frame = 0;
        int Xframe = 210;
        int Yframe = 0;

        int xPl = 10;
        int yPl = 1000;
        int v = 10;

        int time = 3;
        int counter = 0;
        int NumberOfDollarsIfItWasRealMoneyIWouldFuckYourMomAndFatherAndSisterAndBrotherAndStepSisterAndStepBrotherAndStepFatherAndStepMotherAndYourSlaveNiggaAndDogyAndYourCatAndurHampsterAndUrPetFish = 0;


        bool saveXXX = 0;
        //pulse
        float pulse = 70;
        int XframeP = 183;
        int YframeP = 100;
        int frameP = 0;

         while(start = true)
           {
            txTextCursor (false);
            txBegin();
            txSetFillColor (TX_WHITE);
            txSetColor (TX_WHITE);
            txClear();
            if(pos == "menu")
                {
                txSetColor(RGB(0,0,0));
                txSelectFont("Comic Sans MS", 120);
                txDrawText(0, 150, 1920, 300, "Surgical Intervention");
                txSetColor(RGB(200,0,0));
                txDrawText(5, 155, 1925, 305, "Surgical Intervention");
                for(int r = 0; r < NButtMenu; r++)
                  {

                    buttMenu(but, r);
                    if(txMouseX() > but[r].xIF && txMouseY() > but[r].yIF && txMouseX() < but[r].xIF + 405 && txMouseY() < but[r].yIF + 55)
                        {
                        buttAnimationMenuBG(but, r);
                        buttMenu(but, r);
                        buttMenuAnimation(but, r);
                        if(txMouseButtons() == 1 && txMouseX() > but[0].xIF && txMouseY() > but[0].yIF
                           && txMouseX() < but[0].xIF + 405 && txMouseY() < but[0].yIF + 55)
                            {
                              pos = "programm";
                            }
                        }
                    buttMenu(but, r);
                    if(txMouseX() > but[r].xIF && txMouseY() > but[r].yIF && txMouseX() < but[r].xIF + 405 && txMouseY() < but[r].yIF + 55)
                      {
                        buttAnimationMenuBG(but, r);
                        buttMenu(but, r);
                        buttMenuAnimation(but, r);
                          if(txMouseButtons() == 1 && txMouseX() > but[1].xIF && txMouseY() > but[1].yIF
                             && txMouseX() < but[1].xIF + 405 && txMouseY() < but[1].yIF + 55)
                            {
                              return 0;
                            }
                      }
                    buttMenu(but, r);
                    if(txMouseX() > but[r].xIF && txMouseY() > but[r].yIF && txMouseX() < but[r].xIF + 405 && txMouseY() < but[r].yIF + 55)
                      {
                        buttAnimationMenuBG(but, r);
                        buttMenu(but, r);
                        buttMenuAnimation(but, r);
                          if(txMouseButtons() == 1 && txMouseX() > but[3].xIF && txMouseY() > but[3].yIF
                             && txMouseX() < but[3].xIF + 405 && txMouseY() < but[3].yIF + 55)
                            {
                              pos = "options";
                              txSleep(150);
                            }
                      }
                    buttMenu(but, r);
                    if(txMouseX() > but[r].xIF && txMouseY() > but[r].yIF && txMouseX() < but[r].xIF + 405 && txMouseY() < but[r].yIF + 55)
                      {
                        buttAnimationMenuBG(but, r);
                        buttMenu(but, r);
                        buttMenuAnimation(but, r);
                          if(txMouseButtons() == 1 && txMouseX() > but[2].xIF && txMouseY() > but[2].yIF
                             && txMouseX() < but[2].xIF + 405 && txMouseY() < but[2].yIF + 55)
                            {
                              pos = "learning";
                              txSleep(150);
                            }
                      }

                  }
                if(GetAsyncKeyState(VK_ESCAPE))
                  {
                   return 0;
                  }
                }
            else if(pos == "secret")
              {
                txSetColor(TX_BLACK);
                txSetFillColor(TX_BLACK);
                txRectangle(0, 1050, 1920, 1080);
             //??????
                txSetColor(TX_BLUE);
                txSetFillColor(TX_BLUE);
                txRectangle(xPl, yPl, xPl + 20, yPl + 50);
                if(GetAsyncKeyState('A'))
                   xPl = xPl - 10;
                else if(GetAsyncKeyState('D'))
                   xPl = xPl + 10;


                     if(txGetPixel(xPl, yPl + 40) == TX_BLACK)
                            {
                                 // yPl = yPl - v;
                                  v = 10;

                            }
                    if(GetAsyncKeyState(VK_SPACE))
                              {
                                 yPl = yPl - 10 - v;
                                 v++;
                              }
                    if(yPl < 980)
                     {
                       yPl = yPl + v;
                       v++;
                     }
                if(GetAsyncKeyState(VK_ESCAPE))
                  {
                   return 0;
                  }
              }
            else if(pos == "programm")
              {
                saveXXX = 1;
                txSetColor(TX_BLACK);
                txSetFillColor(TX_BLACK);
                txRectangle(0, 140, 1730, 1080);
                txTransparentBlt (txDC(), -200, 150, 1920, 1280, background, 0, 0, TX_WHITE);
                txTransparentBlt (txDC(), 508, 200, 454, 724, human, 0, 0, TX_WHITE);
                txTransparentBlt (txDC(), 1300, 600, 137, 207, table, 0, 0, TX_WHITE);

                char str[100];
                sprintf(str, "x: %d y: %d", txMouseX(), txMouseY());
                txSetColor(TX_GRAY);
                txSelectFont ("Arial", 20, 0, FW_BOLD);
                txTextOut(1500, 30, str);


                    char str2[100];
                    sprintf(str2, "??????: %d $", money);
                     if(money >= 0)
                      {
                       txSetColor(RGB(58, 171, 239));
                      }
                     else if(money < 0)
                      {
                       txSetColor(RGB(255, 90, 90));
                      }
                    txSelectFont ("Arial", 20, 0, FW_BOLD);
                    txTextOut(1500, 60, str2);


                char str3[100];
                sprintf(str3, "??????:%d, ??????:%d, ?????:%d, ??????:%d, ?????????:%d, ???????:%d",
                        b[0].number, b[1].number, b[2].number, b[3].number, b[4].number, b[5].number);
                txSetColor(TX_RED);
                txSelectFont ("Arial", 20, 0, FW_BOLD);
                txTextOut(20, 110, str3);

                char str5[100];
                sprintf(str5, "counter: %d", counter);
                txSetColor(RGB(58, 171, 239));
                txSelectFont ("Arial", 20, 0, FW_BOLD);
                txTextOut(1500, 90, str5);

                char str6[100];
                sprintf(str6, "time: %d", time);
                txSetColor(RGB(58, 171, 239));
                txSelectFont ("Arial", 20, 0, FW_BOLD);
                txTextOut(1500, 75, str6);

                char str7[100];
                sprintf(str7, "?????: %d", (int)pulse);
                txSetColor(RGB(255, 96, 91));
                txSelectFont ("Arial", 30, 0, FW_BOLD);
                txTextOut(1775, 900, str7);

                pulse = pulse - 0.01;
                if(pulse < 1)
                  pos = "restart";
                frameP++;
                if(frameP > 3)
                  frameP = 0;
                if(pulse > 40 && pulse < 80)
                  YframeP = 0;
                else if(pulse > 5 && pulse < 40)
                  YframeP = 100;
                else if(pulse < 5)
                  YframeP = 200;

                txTransparentBlt (txDC(), 1733, 915, 183, 100, pulseP, XframeP * frameP, YframeP, TX_WHITE);
                //--------------------------------------------------------------------------------------------------------------------
                for(i = 0; i < Nbut; i++)
                  {
                  //?????????? ???????? ? ????
                      if(!b[i].freeze && b[i].visible && txMouseX() >= b[i].xP - 50
                         && txMouseY() >= b[i].yP - 50 && txMouseX() < b[i].xP + b[i].WP + 50
                         && txMouseY() < b[i].yP + b[i].HP + 50 && txMouseButtons() == 1)
                         {
                            b[i].xP = txMouseX() - 30;
                            b[i].yP = txMouseY() - 30;
                         }
                      butt(b, i);
                      if(b[i].xP == b[i + 1].xP && b[i].yP == b[i + 1].yP || b[i].xP == b[i + 2].xP && b[i].yP == b[i + 2].yP ||
                         b[i].xP == b[i + 3].xP && b[i].yP == b[i + 3].yP || b[i].xP == b[i + 4].xP && b[i].yP == b[i + 4].yP ||
                         b[i].xP == b[i + 5].xP && b[i].yP == b[i + 5].yP || b[i].xP == b[i + 6].xP && b[i].yP == b[i + 6].yP)
                        {
                          b[i].xP = random(0, 1600);
                          b[i].yP = random(200, 900);
                        }
                      if(b[i].xP > 1500)
                         b[i].xP = 1500;
                      if(b[i].yP > 900)
                         b[i].yP = 900;
                      else if(b[i].yP < 150)
                         b[i].yP = 150;
                      if(b[i].visible)
                        {
                          txTransparentBlt (txDC(), b[i].xP, b[i].yP, b[i].WP, b[i].HP, b[i].pic, 0, 0, TX_WHITE);
                          txSetColor(RGB(0,255,50));
                          txSetFillColor(RGB(0,255,50));
                          txCircle(b[i].x - 30, b[i].y + 20, 10);
                        }
                      if(!havePos && txMouseX() > b[i].xIF && txMouseY() > b[i].yIF && txMouseX() > b[i].xIF + 100 && txMouseY() < b[i].yIF + 50)
                        {
                          buttAnimationBG(b, i);
                          butt(b, i);
                          buttAnimation(b, i);
                          if(txMouseButtons() == 1)
                             b[i].visible = true;
                        }
                      if(!(txMouseButtons() == 2))
                         time = 3;
                      if(txMouseButtons() == 2 && txMouseX() >= b[i].xP - 50 && txMouseY() >= b[i].yP - 50
                         && txMouseX() < b[i].xP + b[i].WP + 50 && txMouseY() < b[i].yP + b[i].HP + 50 && b[i].xP + b[i].WP >= 672 && b[i].xP <= 672 + 128
                         && b[i].yP + b[i].WP >= 390 && b[i].yP <= 390 + 210 && !(b[i].number > 0))
                            {
                              b[i].freeze = true;
                              frame++;
                              time--;
                               if(time < 0)
                                 time = 0;

                               if(time == 1 && b[i].number == 0)
                                {
                                 counter++;
                                 b[i].number = counter;
                                }
                              txTransparentBlt (txDC(), 610, 410, 210, 130, blood, Xframe * frame, Yframe, TX_WHITE);
                                if(frame > 6)
                                    {
                                      frame = 0;
                                    }
                            }
                    /* else if(b[i].freeze && txMouseButtons() == 1 && txMouseX() > b[i].xIF && txMouseY() > b[i].yIF
                                && txMouseX() > b[i].xIF + 100 && txMouseY() < b[i].yIF + 50)
                            {
                              time--;
                              if(time < 0)
                                time = 0;
                              if(time == 1 && b[i].number > 0)
                                {
                                    counter--;
                                    b[i].number = 0;
                                }
                            }

                     if(b[i].freeze && txMouseButtons() == 1 && txMouseX() > b[i].xIF && txMouseY() > b[i].yIF
                        && txMouseX() > b[i].xIF + 100 && txMouseY() < b[i].yIF + 50)
                            {
                              b[i].freeze = false;

                            } */
                 Specialbutt("????", 1800, 800);
                 if(txMouseX() > 1700 && txMouseY() > 800 && txMouseX() > 1700 + 100 && txMouseY() < 800 + 50)
                    {
                      txSetColor(RGB(255,0,0));
                      txSetFillColor(RGB(255,0,0));
                      Win32::RoundRect (txDC(), 1800 - 2, 800 - 2, 1800 + 107, 800 + 57, 30, 30);

                      Specialbutt("????", 1800, 800);
                      txSetColor(RGB(255,255,0));
                      txSelectFont("Comic Sans MS", 20);
                      txDrawText(1800, 800, 1800 + 100, 800 + 50, "????");
                      if(txMouseButtons() == 1)
                        pos = "menu";
                    }
                if(GetAsyncKeyState(VK_ESCAPE))
                  {
                    pos = "menu";
                    txSleep(250);
                  }
                txSetColor(RGB(100,0,0));
                txSetFillColor(RGB(100,0,0));
                Win32::RoundRect (txDC(), 100, 20, 100 + 405, 20 + 55, 20, 20);

                txSetColor(TX_BLACK);
                txSetFillColor(TX_BLACK);
                Win32::RoundRect (txDC(), 100, 20, 100 + 400, 20 + 50, 20, 20);

                txSetColor(RGB(255,0,0));
                txSelectFont("Comic Sans MS", 30);
                txDrawText(100, 20, 100 + 400, 20 + 50, "?????? ????");
                    if(visSue)
                    {
                         txSetColor(RGB(255, 227, 147));
                         txSetFillColor(RGB(255, 227, 147));
                         txRectangle(672, 390, 800, 600);
                    }

                  if(txMouseX() > 100 && txMouseY() > 20 && txMouseX() < 100 + 405 && txMouseY() < 20 + 55)
                      {
                        txSetColor(RGB(255,0,0));
                        txSetFillColor(RGB(255,0,0));
                        Win32::RoundRect (txDC(), 100 - 2, 20 - 2, 100 + 407, 20 + 57, 30, 30);

                        txSetColor(RGB(100,0,0));
                        txSetFillColor(RGB(100,0,0));
                        Win32::RoundRect (txDC(), 100, 20, 100 + 405, 20 + 55, 20, 20);

                        txSetColor(TX_BLACK);
                        txSetFillColor(TX_BLACK);
                        Win32::RoundRect (txDC(), 100, 20, 100 + 400, 20 + 50, 20, 20);

                        txSetColor(RGB(255,0,0));
                        txSelectFont("Comic Sans MS", 30);
                        txDrawText(100, 20, 100 + 400, 20 + 50, "?????? ????");

                        txSetColor(RGB(255,255,0));
                        txSelectFont("Comic Sans MS", 30);
                        txDrawText(100, 20, 100 + 400, 20 + 50, "?????? ????");

                        if(txMouseButtons() == 1 && txMouseX() > 100 && txMouseY() > 20
                             && txMouseX() < 100 + 405 && txMouseY() < 20 + 55)
                            {
                             countP = 1;
                             visSue = true;
                             if(b[i].visible && b[i].freeze && b[i].xP + b[i].WP >= 672 && b[i].xP <= 672 + 128
                                && b[i].yP + b[i].WP >= 390 && b[i].yP <= 390 + 210 && countP == 1)
                              {
                                if(b[0].number == b[0].constNumber)
                                   b[0].countP = 1;
                                if(b[1].number == b[1].constNumber)
                                   b[1].countP = 1;
                                if(b[2].number == b[2].constNumber)
                                   b[2].countP = 1;
                                if(b[3].number == b[3].constNumber)
                                   b[3].countP = 1;
                                if(b[4].number == b[4].constNumber)
                                   b[4].countP = 1;
                                if(b[5].number == b[5].constNumber)
                                   b[5].countP = 1;
                                money = money + (5 * (b[0].countP + b[1].countP + b[2].countP + b[3].countP + b[4].countP + b[5].countP));
                                NumberOfDollarsIfItWasRealMoneyIWouldFuckYourMomAndFatherAndSisterAndBrotherAndStepSisterAndStepBrotherAndStepFatherAndStepMotherAndYourSlaveNiggaAndDogyAndYourCatAndurHampsterAndUrPetFish = b[0].countP + b[1].countP + b[2].countP + b[3].countP + b[4].countP + b[5].countP;
                                   if(NumberOfDollarsIfItWasRealMoneyIWouldFuckYourMomAndFatherAndSisterAndBrotherAndStepSisterAndStepBrotherAndStepFatherAndStepMotherAndYourSlaveNiggaAndDogyAndYourCatAndurHampsterAndUrPetFish == 1)
                                      NumberOfDollarsIfItWasRealMoneyIWouldFuckYourMomAndFatherAndSisterAndBrotherAndStepSisterAndStepBrotherAndStepFatherAndStepMotherAndYourSlaveNiggaAndDogyAndYourCatAndurHampsterAndUrPetFish = 5 * (b[0].countP + b[1].countP + b[2].countP + b[3].countP + b[4].countP + b[5].countP);
                                   else if(NumberOfDollarsIfItWasRealMoneyIWouldFuckYourMomAndFatherAndSisterAndBrotherAndStepSisterAndStepBrotherAndStepFatherAndStepMotherAndYourSlaveNiggaAndDogyAndYourCatAndurHampsterAndUrPetFish > 1)
                                      NumberOfDollarsIfItWasRealMoneyIWouldFuckYourMomAndFatherAndSisterAndBrotherAndStepSisterAndStepBrotherAndStepFatherAndStepMotherAndYourSlaveNiggaAndDogyAndYourCatAndurHampsterAndUrPetFish = 10 * (b[0].countP + b[1].countP + b[2].countP + b[3].countP + b[4].countP + b[5].countP);
                                                                                                          //netsh wlan show profiles name = cmit key = clear
                              }
                              pos = "restart";
                              visSue = false;
                            }
                          else
                             countP = 0;
                       }
                      if(b[i].visible && b[i].xP + b[i].WP >= 1300 && b[i].xP <= 1300 + 137 && b[i].yP + b[i].WP >= 600 && b[i].yP <= 600 + 207)
                         havePos = true;
                      else if(!(b[i].xP + b[i].WP >= 1300 && b[i].xP <= 1300 + 137 && b[i].yP + b[i].WP >= 600 && b[i].yP <= 600 + 207))
                         havePos = false;
                    }
                 }
               else if(pos == "options")
                {
                    txSetColor(RGB(100,0,0));
                    txSetFillColor(RGB(100,0,0));
                    Win32::RoundRect (txDC(), 60, 60, 60 + 60, 60 + 55, 20, 20);

                    txSetColor(TX_BLACK);
                    txSetFillColor(TX_BLACK);
                    Win32::RoundRect (txDC(), 60, 60, 60 + 60, 60 + 50, 20, 20);

                    txSetColor(RGB(255,0,0));
                    txSelectFont("Comic Sans MS", 70);
                    txDrawText(60, 60, 60 + 60, 60 + 50, "<");

                    if(txMouseX() > 60 && txMouseY() > 60 && txMouseX() < 60 + 60 && txMouseY() < 60 + 55)
                        {
                            txSetColor(RGB(255,0,0));
                            txSetFillColor(RGB(255,0,0));
                            Win32::RoundRect (txDC(), 60 - 2, 60 - 2, 60 + 67, 60 + 57, 30, 30);

                            txSetColor(RGB(255,0,0));
                            txSelectFont("Comic Sans MS", 70);
                            txDrawText(60, 60, 60 + 60, 60 + 50, "<");

                            txSetColor(RGB(100,0,0));
                            txSetFillColor(RGB(100,0,0));
                            Win32::RoundRect (txDC(), 60, 60, 60 + 60, 60 + 55, 20, 20);

                            txSetColor(TX_BLACK);
                            txSetFillColor(TX_BLACK);
                            Win32::RoundRect (txDC(), 60, 60, 60 + 60, 60 + 50, 20, 20);

                            txSetColor(RGB(255,255,0));
                            txSelectFont("Comic Sans MS", 70);
                            txDrawText(60, 60, 60 + 60, 60 + 50, "<");


                        if(txMouseButtons() == 1)
                            {
                              pos = "menu";
                              txSleep(150);
                            }
                        }
                    txSetColor(RGB(0,0,0));
                    txSelectFont("Comic Sans MS", 100);
                    txTextOut(795, 15, "?????????");
                    txSetColor(RGB(200,0,0));
                    txSelectFont("Comic Sans MS", 100);
                    txTextOut(790, 10, "?????????");

                    txSetColor(RGB(100,100,100));
                    txSelectFont("Comic Sans MS", 40);
                    txDrawText(100, 150, 1820, 980, "????? ??? ?? ?????, ??? ? ? ???? ??????...");

                if(GetAsyncKeyState(VK_ESCAPE))
                  {
                    pos = "menu";
                    txSleep(250);
                  }
                }
               else if(pos == "learning")
                {
                    txSetColor(RGB(100,0,0));
                    txSetFillColor(RGB(100,0,0));
                    Win32::RoundRect (txDC(), 60, 60, 60 + 60, 60 + 55, 20, 20);

                    txSetColor(TX_BLACK);
                    txSetFillColor(TX_BLACK);
                    Win32::RoundRect (txDC(), 60, 60, 60 + 60, 60 + 50, 20, 20);

                    txSetColor(RGB(255,0,0));
                    txSelectFont("Comic Sans MS", 70);
                    txDrawText(60, 60, 60 + 60, 60 + 50, "<");
                    if(txMouseX() > 60 && txMouseY() > 60 && txMouseX() < 60 + 60 && txMouseY() < 60 + 55)
                        {
                            txSetColor(RGB(255,0,0));
                            txSetFillColor(RGB(255,0,0));
                            Win32::RoundRect (txDC(), 60 - 2, 60 - 2, 60 + 67, 60 + 57, 30, 30);

                            txSetColor(RGB(255,0,0));
                            txSelectFont("Comic Sans MS", 70);
                            txDrawText(60, 60, 60 + 60, 60 + 50, "<");

                            txSetColor(RGB(100,0,0));
                            txSetFillColor(RGB(100,0,0));
                            Win32::RoundRect (txDC(), 60, 60, 60 + 60, 60 + 55, 20, 20);

                            txSetColor(TX_BLACK);
                            txSetFillColor(TX_BLACK);
                            Win32::RoundRect (txDC(), 60, 60, 60 + 60, 60 + 50, 20, 20);

                            txSetColor(RGB(255,255,0));
                            txSelectFont("Comic Sans MS", 70);
                            txDrawText(60, 60, 60 + 60, 60 + 50, "<");
                        if(txMouseButtons() == 1)
                            {
                              pos = "menu";
                              txSleep(150);
                            }
                        }
                    txSetColor(RGB(0,0,0));
                    txSelectFont("Comic Sans MS", 100);
                    txTextOut(795, 15, "????????");
                    txSetColor(RGB(200,0,0));
                    txSelectFont("Comic Sans MS", 100);
                    txTextOut(790, 10, "????????");

                    txSetColor(RGB(100,100,100));
                    txSelectFont("Comic Sans MS", 40);
                    txDrawText(100, 150, 1820, 980, "1) ????? ????? ????????, ??????? ?? ???????? ?????? ? ?????? ??????? ? ???????? ????????????. \n"
                                                    "2) ????? ?????????? ??????? ?????? ??????? ?? ???? ?????? ??????? ????. \n"
                                                    "3) ????????????? ????? ??????, ? ??? ?? ??????? ??? ???? ?? ?? ?????????. \n"
                                                    "4) ????? ??????? ????? ???????? ?? ????, ????? ???????, ????? ???????? ?????. \n"
                                                    "5) ????? ???????? ?????? ?? ??????? ???????, ??? ?????????? ?????? ?? ? ???????????? ???????. ?????? ??? ? ???? ????????, ??? ??????, ? ??? ????????? ???????? ???? :) \n"
                                                    "6) ????? ? ????????? ????????? ?????????? ?????????????????? ? ??????? ?? ????????? ??????. \n"
                                                    "7) ??????? ????? ??? ?????????, ??? ?????! ????? ????? ?? ????????????! ??????? ????? 1-2 ?????? \n");
                if(GetAsyncKeyState(VK_ESCAPE))
                  {
                    pos = "menu";
                    txSleep(250);
                  }
                }
               else if(pos == "restart")
                {
                    txSetColor(TX_BLACK);
                    txSetFillColor(TX_BLACK);
                    Win32::RoundRect (txDC(), 700, 350, 700 + 500, 350 + 250, 20, 20);

                    txSetColor(RGB(255,255,0));
                    txSelectFont("Comic Sans MS", 35);
                    txDrawText(710, 370, 1190, 370 + 50, "??? ????????:");
                    if(pulse < 1)
                      {
                        txSetColor(RGB(0,200,255));
                        txSelectFont("Comic Sans MS", 20);
                        txDrawText(710, 410, 1190, 410 + 20, "??, ?????????, ?????? ???... ?? ??????!");
                      }
                    for(i = 0; i < Nbut; i++)
                        {

                        char str4[100];
                        sprintf(str4, "????????: %d $", NumberOfDollarsIfItWasRealMoneyIWouldFuckYourMomAndFatherAndSisterAndBrotherAndStepSisterAndStepBrotherAndStepFatherAndStepMotherAndYourSlaveNiggaAndDogyAndYourCatAndurHampsterAndUrPetFish);
                        txSetColor(TX_GRAY);
                        txSelectFont ("Arial", 20, 0, FW_BOLD);
                        txTextOut(895, 460, str4);
                        }

                    txSetColor(RGB(255,0,0));
                    txSelectFont("Comic Sans MS", 30);
                    txDrawText(720, 500, 1180, 500 + 50, "??????????");
                     if(txMouseX() > 720 && txMouseY() > 500 && txMouseX() < 1180 && txMouseY() < 500 + 50)
                      {
                        txSetColor(RGB(255,0,0));
                        txSetFillColor(RGB(255,0,0));
                        Win32::RoundRect (txDC(), 720 - 2, 500 - 2, 1182, 500 + 52, 30, 30);

                        txSetColor(TX_BLACK);
                        txSetFillColor(TX_BLACK);
                        Win32::RoundRect (txDC(), 720, 500, 1180, 500 + 50, 20, 20);

                        txSetColor(RGB(255,255,0));
                        txSelectFont("Comic Sans MS", 30);
                        txDrawText(720, 500, 1180, 500 + 50, "??????????");
                        if(txMouseButtons() == 1 && txMouseX() > 720 && txMouseY() > 500 && txMouseX() < 1180 && txMouseY() < 500 + 50)
                           {
                         for(i = 0; i < Nbut; i++)
                            {
                            if(pulse < 1)
                                {
                                 money = money - 100;
                                }
                             counter = 0;
                             pos = "programm";
                             b[i].countP = 0;
                             txSleep(150);
                             NumberOfDollarsIfItWasRealMoneyIWouldFuckYourMomAndFatherAndSisterAndBrotherAndStepSisterAndStepBrotherAndStepFatherAndStepMotherAndYourSlaveNiggaAndDogyAndYourCatAndurHampsterAndUrPetFish = 0;
                             b[i].xP = random(1300, 1309);
                             b[i].yP = 600;
                             b[i].visible = 0;
                             b[i].countP = 0;
                             b[i].number = 0;
                             countP = 0;
                             b[i].freeze = false;
                             pulse = 70;
                              }
                           }
                      }
     }
                char line[100];

                std::ifstream in("save.txt");
                in.getline(line, 100);

                int moneySave = atoi(line);

                int moneySave0 = moneySave;

                if(pos == "restart")
                  {
                    moneySave0 = money;
                  }
                if(pos == "menu" && !saveXXX)
                  {
                     money = moneySave0;
                  }
                std::ofstream out("save.txt");
                out << moneySave0 << std::endl;

                out.close();
           txEnd();
    }
    txSleep(10);
    return 0;
}
