#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "test.h"
int main(int argc, char *argv[])
{
chara.x=160;
chara.y=160;
int bRun = 1;
int num = 0 , aTick = 0,R=255,G=255,B=255;
init();
chara.anim[0] = loadImage ("./anim/justice1.gif",R,G,B);
chara.anim[1] = loadImage ("./anim/justice2.gif",R,G,B);
chara.anim[2] = loadImage ("./anim/justice3.gif",R,G,B);
chara.anim[3] = loadImage ("./anim/justice4.gif",R,G,B);
chara.anim[4] = loadImage("./anim/justice5.gif",R,G,B);
chara.anim[5] = loadImage("./anim/justice6.gif",R,G,B);
FPS_Initial( );
while(bRun) {
	updateScreenPlayer(num);
        FPS_Fn();
        UpdateEvents (&in);
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
        num=animateplayer(aTick,num);
        chara.x+=2;
        }
        if(in.key[SDLK_LEFT])
        {
        aTick++;
        num=animateplayer(aTick,num);
        chara.x-=2;
        }
	}; 

return 0;
}
