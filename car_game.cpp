#include<graphics.h>
#include<process.h>
#include<dos.h>
#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{

    int hscore=0;
    int death=0;
    start:
    int i=1;
    int gdriver = DETECT, gmode ,errorcode;
    initgraph (&gdriver, &gmode, "");
    int down=50;

    int x1=200,y1=280,x2=230,y2=320;//car parameters

    int score=1;
    int level=1;

    char msg[128];
    char msg2[128];
    int cx= (rand() % (290 - 160 + 1)) + 160;
    int cy= 60;
    int del=250;//for delay
    while(1)
    {
        rectangle(50,50,400,400);
        line(150,50,150,400);
        line(300,50,300,400);

        sprintf(msg, "Score= %d  Level= %d", score,level);
        outtextxy(430, 55, msg);

        sprintf(msg2, "highScore= %d  Death= %d", hscore,death);
        outtextxy(430, 75, msg2);
        char key;



        //moving car
        if(kbhit()){
            key=getch();
            if(key==77){//right
                x1=x1+20;
                x2=x2+20;
                if(x1>=270){
                    x1=270;
                    x2=300;
                }
            }
            if(key==75){//left
                x1=x1-20;
                x2=x2-20;
                if(x1<=150){
                    x1=150;
                    x2=180;
                }
            }
            if (key==72){//up
                y1=y1-20;
                y2=y2-20;
                if(y1<=50){
                    y1=50;
                    y2=90;
                }
            }
            if(key==80){//down
                y1=y1+20;
                y2=y2+20;
                if(y1>=360){
                    y1=360;
                    y2=400;
                }

            }
            if(key==27){
                break;
            }


        }
        rectangle(x1,y1,x2,y2);
        //side lines
        int b=2;
        int x=50,y=400;
        int k=25;
        //big lines
        line(x+k,down,150,down);
        line(300,down,y-k,down);
        down=down+20;
        //small lines
        line(x+k+50,down,150,down);
        line(300,down,y-k-50,down);


        k=k+25;
        if(k>=100){
            k=25;
        }
        down=down+20+b;

        if(down+20>400){
            b=b++;
            down=50+b;

            //color change
            i=i+1;
        }
        if(cy<380){
            circle(cx,cy,10);
            cy=cy+15;
        }
        if(cy>380){
            cy=60;
             cx= (rand() % (290 - 160 + 1)) + 160;
        }
        //collision mechanic
        if((cx+10>=x1)&&(cy+10>=y1)&&(cx-10<=x2)&&(cy-10<=y2)){
            death++;
            if(score>hscore){
                hscore=score;
            }
            outtextxy(cx, cy, "YOU DIED");
            goto start;
        }
        delay(del);
        cleardevice();

        score++;
        if(score%20==1){
            level++;
            del=del-30;
            if(del<40)del=40;

            //for color changing
            if(i>14)i=1;
            i++;
            setcolor(i);
        }
    }

    printf("High score is = %d\n",hscore);
    return 0;

}
