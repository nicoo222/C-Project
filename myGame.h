
/* Prototype des fonctions utiles au jeu. 
   Enregistrement de la structure Input utile à la gestion des évenements */

typedef struct
{
	char key[SDLK_LAST];
	int mousex,mousey;
	int mousexrel,mouseyrel;
	char mousebuttons[6];
	char quit;
} Input;


SDL_Surface* gameInitialization();
void updateEvents(Input* in);
void loadMusic(int track);
void endGame();
