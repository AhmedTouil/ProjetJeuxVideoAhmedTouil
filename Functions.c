#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "test.h"
int sigh=0;
int dist=0;
int state=0;
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

void updateScreenPlayer(int num,character chara1)
{
SDL_Rect animRect ;
animRect.x=chara1.x; 
animRect.y=chara1.y;
SDL_FillRect(scr.ecran,NULL,0x221122);
SDL_BlitSurface(chara1.anim[num], NULL , scr.ecran , &animRect );	
}
void updateScreenEnnemy(int num,oponent chara1)
{
SDL_Rect enemiRect;
enemiRect.x=chara1.x; 
enemiRect.y=chara1.y;
SDL_BlitSurface(chara1.enemi[num], NULL , scr.ecran , &enemiRect );
SDL_Flip(scr.ecran);	
}
int animateplayer(int aTick,int num)
{
if( aTick%5 == 0 ) num++;
if(num >= justice_No) num = 0;
return num;
}
int animateEnnemys(int aTick,int num)
{
if( aTick%5 == 0 ) num++;
if(num >= Ennemy_No) num = 0;
return num;
}
void animateEnnemy(void)
{
if(Ennemy.x==250)
{
Ennemy.dir=-1;
}
if (Ennemy.x==180)
{
Ennemy.dir=1;
}
Ennemy.x=Ennemy.x+2*Ennemy.dir;
}

int ai(void)
{

if(chara.dir!=Ennemy.dir) 
{
if(chara.x<Ennemy.x)
{
sigh=-1;
chara.dir=-1;
}
if(chara.x>Ennemy.x)
{
sigh=1;
chara.dir=1;
}
}

if(chara.dir==Ennemy.dir)
{
if(chara.x>Ennemy.x)
{
sigh=1;
chara.dir=1;
}
if(chara.x<Ennemy.x)
{
sigh=-1;
chara.dir=-1;
}
}

dist=sigh*(chara.x-Ennemy.x);
if ((dist>=20)&&(dist<=60))
{
state=1;
}
else if (dist>50) 
{
state=2;
}
else if(dist<20)
{
state=3;
}
switch (state)
{
case 1 :
Ennemy.x+=2*Ennemy.dir;
break;
case 2 :
if ((Ennemy.initx<Ennemy.x) && (Ennemy.x>Ennemy.initx+90))   
{
Ennemy.dir=-1;
}
if ((Ennemy.initx>Ennemy.x) && (Ennemy.x<Ennemy.initx-20))
{
Ennemy.dir=1;
}
Ennemy.x=Ennemy.x+2*Ennemy.dir;

break;

case 3 :
Ennemy.dir=chara.dir;
break;
}
return(state);
}




