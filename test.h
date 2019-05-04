#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED
enum walk { justice1 , justice2 , justice3 , justice4
	, justice5 , justice6 , justice_No  };

typedef struct
{
SDL_Surface *ecran;
int x,y;
}screen;

typedef struct
{
SDL_Surface *anim[justice_No] ;
int x,y,dir,initx;
}character;
enum walk2 { Ennemy1 , Ennemy2 , Ennemy3 , Ennemy4
	, Ennemy5 , Ennemy6 , Ennemy_No  };
typedef struct
{
SDL_Surface *enemi[Ennemy_No];
int x,y,dir,initx;
}oponent;

typedef struct
{
    char key[SDLK_LAST];
    int mousex,mousey;
    int mousexrel,mouseyrel;
    char mousebuttons[6];
        char quit;
} Input;
screen scr;
character chara;
oponent Ennemy;
Input in;
SDL_Surface *loadImage (char * file ,int R,int G, int B);
void init (void);
void UpdateEvents(Input* in);
void FPS_Initial(void);
void FPS_Fn(void);
void updateScreenPlayer(int num1,character chara1);
void updateScreenEnnemy(int num2,oponent chara1);
int animateplayer(int aTick,int num);
void animateEnnemy(void);
int animateEnnemys(int aTick,int num);
int ai (void);
#endif
