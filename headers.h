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
SDL_Surface *anim[justice_No];
int x,y,dir;
}character;

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
Input in;
SDL_Surface *loadImage (char * file ,int R,int G, int B);
void init (void);
void UpdateEvents(Input* in);
void FPS_Initial(void);
void FPS_Fn(void);
void updateScreenPlayer(int num);
int animateplayer(int aTick,int num);
void animateEnnemy();

#endif
