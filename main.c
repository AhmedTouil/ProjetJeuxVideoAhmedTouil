#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "test.h"
int main(int argc, char *argv[])
{
int a;
Ennemy.x=160;
Ennemy.y=160;
Ennemy.initx=160;
Ennemy.dir=1;
chara.x=0;
chara.y=160;
chara.dir=0;
int bRun = 1;
int num1 = 0 ,num2 =0, aTick = 0,R=255,G=255,B=255;
init();
Ennemy.enemi[5] = loadImage ("./anim/justice1.gif",R,G,B);
Ennemy.enemi[4] = loadImage ("./anim/justice2.gif",R,G,B);
Ennemy.enemi[3] = loadImage ("./anim/justice3.gif",R,G,B);
Ennemy.enemi[2] = loadImage ("./anim/justice4.gif",R,G,B);
Ennemy.enemi[1] = loadImage("./anim/justice5.gif",R,G,B);
Ennemy.enemi[0] = loadImage("./anim/justice6.gif",R,G,B);

chara.anim[0] = loadImage("./anim/justice1.gif",R,G,B);
chara.anim[1] = loadImage("./anim/justice2.gif",R,G,B);
chara.anim[2] = loadImage("./anim/justice3.gif",R,G,B);
chara.anim[3] = loadImage("./anim/justice4.gif",R,G,B);
chara.anim[4] = loadImage("./anim/justice5.gif",R,G,B);
chara.anim[5] = loadImage("./anim/justice6.gif",R,G,B);
FPS_Initial( );
while(bRun) {
        aTick++;
	updateScreenPlayer(num1,chara);
        FPS_Fn();
        UpdateEvents(&in);
        updateScreenEnnemy(num2,Ennemy);
        a=ai();
        if (a==3)
        {
        num2=5;
        }
        if(a!=3)
        {
        num2=animateEnnemys(aTick, num2);
        }
        
        
        if(in.key[SDLK_ESCAPE])
        {
        bRun=0;
        }
        if(in.key[SDLK_UP])
        {
        chara.y-=2;
        }
        if(in.key[SDLK_DOWN])
        {
        chara.y+=2;
        }
        if(in.key[SDLK_RIGHT])
        {
        aTick++;
        num1=animateplayer(aTick,num1);
        chara.x+=2;
        chara.dir=1;
        }
        if(in.key[SDLK_LEFT])
        {
        aTick++;
        num1=animateplayer(aTick,num1);
        chara.x-=2;
        chara.dir=-1;
        }
	}; 


        
        
return 0;
}
