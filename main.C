#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include "myGame.h"


int main(int argc, char *argv[])
{
	SDL_Surface* man=NULL; 
	Input in;
	SDL_Rect manPosition;
	
	//Appel de la fonction initialisant la partie 
	SDL_Surface* ecran=gameInitialization();
	
	//Gestion musique 
	loadMusic(1);


	SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
	man = SDL_LoadBMP("Pictures/man.bmp");

	int color=SDL_SetColorKey(man, SDL_SRCCOLORKEY, SDL_MapRGB(man->format, 0, 0, 255));

	if (color !=0) // Fin du programme avec message d'erreur si problème de modification de couleur
	{
		fprintf(stderr, "Impossible de charger le mode vidéo : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	manPosition.x = ecran->w / 2 - man->w / 2;
	manPosition.y = ecran->h / 2 - man->h / 2;

	SDL_BlitSurface(man, NULL, ecran, &manPosition);
	SDL_Flip(ecran);

	memset(&in,0,sizeof(in));

	while(!in.key[SDLK_ESCAPE] && !in.quit)
	{
		updateEvents(&in);
		if (in.mousebuttons[0])
		{
			in.mousebuttons[0] = 0;
			// fait une seule fois.
		}      

		if (in.key[SDLK_UP]){
		  manPosition.y--;
		}

	        if (in.key[SDLK_LEFT]){
		  manPosition.x--;
		}

	        if (in.key[SDLK_DOWN]){
		  manPosition.y++;
		}

		if(in.key[SDLK_RIGHT]){
		  manPosition.x++;
		}
		if(in.key[SDLK_KP2]){
		 	loadMusic(2);
		}
		SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));

		SDL_BlitSurface(man, NULL, ecran, &manPosition);
    
		/* On met à jour l'affichage */
		SDL_Flip(ecran);
	}

	endGame();

	return EXIT_SUCCESS; // Fermeture du programme

}

