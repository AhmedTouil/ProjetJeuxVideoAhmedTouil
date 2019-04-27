#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "test.h"

int FPS = 50;    
int NextTick , interval ;
void FPS_Initial(void) {
NextTick = 0 ;
interval = 1 * 1000 / FPS ;
return;
}
void FPS_Fn(void) {
if ( NextTick > SDL_GetTicks( ) ) SDL_Delay( NextTick - SDL_GetTicks( ) );
NextTick = SDL_GetTicks( ) + interval ;
return;
}
void UpdateEvents(Input* in)
{
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_KEYDOWN:
            in->key[event.key.keysym.sym]=1;
            break;
        case SDL_KEYUP:
            in->key[event.key.keysym.sym]=0;
            break;
        case SDL_MOUSEMOTION:
            in->mousex=event.motion.x;
            in->mousey=event.motion.y;
            in->mousexrel=event.motion.xrel;
            in->mouseyrel=event.motion.yrel;
            break;
        case SDL_MOUSEBUTTONDOWN:
            in->mousebuttons[event.button.button]=1;
            break;
        case SDL_MOUSEBUTTONUP:
            in->mousebuttons[event.button.button]=0;
            break;
        case SDL_QUIT:
            in->quit = 1;
            break;
        default:
            break;
        }
    }
}
void init (void)
{
scr.ecran = SDL_SetVideoMode( 400 , 300 , 32 , SDL_DOUBLEBUF|SDL_HWSURFACE|SDL_ANYFORMAT);
}

SDL_Surface *loadImage (char * file ,int R,int G, int B)
{
SDL_Surface *pic= NULL;
pic=IMG_Load(file);
SDL_SetColorKey(pic,SDL_SRCCOLORKEY|SDL_RLEACCEL,SDL_MapRGB(pic->format,R,G,B));
return (pic);
}

void updateScreenPlayer(int num)
{
SDL_Rect animRect ;
animRect.x=chara.x; 
animRect.y=chara.y;
SDL_FillRect(scr.ecran,NULL,0x221122);
SDL_BlitSurface(chara.anim[num], NULL , scr.ecran , &animRect );
	SDL_Flip(scr.ecran);
}

int animateplayer(int aTick,int num)
{
if( aTick%5 == 0 ) num++;
if(num >= justice_No) num = 0;
return num;
}

void animateEnnemy(void)
{
if(chara.x==250)
{
chara.dir=-1;
}
if (chara.x==0)
{
chara.dir=1;
}
chara.x=chara.x+2*chara.dir;
}

