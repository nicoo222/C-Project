
//Constantes globales 

#define SCREEN_WIDTH 860
#define SCREEN_HEIGHT 640
#define SQUARE_WIDTH 48
#define SQUARE_HEIGHT 48
#define DEFAULT_MUSIC 1
#define MAX_ENEMIES 10

//Structures globales
typedef struct Input
{
	char key[SDLK_LAST];
	int mousex,mousey;
	int mousexrel,mouseyrel;
	char mousebuttons[6];
	int quit;
	int mouseMovement;
} Input;

typedef struct Collision
{
	int up;
	int down;
	int left;
	int right;
	int objectCollision;
}Collision;

typedef struct Objects
{
	SDL_Surface * square;
	SDL_Surface *enemies[MAX_ENEMIES];
}Objects;

/* Prototype des fonctions utiles au jeu. 
   Enregistrement de la structure Input utile à la gestion des évenements */
SDL_Surface* gameInitialization();
void updateEvents(Input* in);
void checkCollision(SDL_Rect squarePosition,SDL_Rect bobPosition,Collision *collision);
void loadMusic(int track);
void endGame();
