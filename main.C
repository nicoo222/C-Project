#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include "myGame.h"


int main(int argc, char *argv[])
{
	
	Input in;
	Collision collision;
	Objects objects;
	SDL_Rect squarePosition,mapPosition,bobPosition;
	
	
	
	//Appel de la fonction initialisant la partie 
	SDL_Surface* ecran=gameInitialization();
	
	//Initialisation des surfaces 
	SDL_Surface* map=NULL,*bob=NULL; 
	SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
	objects.square = SDL_LoadBMP("Pictures/Square.bmp");
	map= SDL_LoadBMP("Pictures/map.bmp");
	bob=SDL_LoadBMP("Pictures/Bob.bmp");

	squarePosition.x = ecran->w / 2 - objects.square->w / 2;
	squarePosition.y = ecran->h / 2 - objects.square->h / 2;
	
	mapPosition.x=0;
	mapPosition.y=0;

	bobPosition.x=ecran->w / 2 - objects.square->w / 2;
	bobPosition.y=ecran->w / 2 - objects.square->w / 2;

	SDL_BlitSurface(map, NULL, ecran, &mapPosition);
	SDL_BlitSurface(objects.square, NULL, ecran, &squarePosition);
	SDL_BlitSurface(bob, NULL, ecran, &bobPosition);

	SDL_Flip(ecran);
	
	//On initialise à 0 les élements des structures (l'ensemble des "booléens")
	memset(&in,0,sizeof(in));
	memset(&collision,0,sizeof(collision));
	
	
	//Tant que l'utilisateur ne décide pas de quitter le jeu : on analyse les différents évenement possibles
	while(!in.key[SDLK_ESCAPE] && !in.quit)
	{
		updateEvents(&in);//On met à jour les booléens de la structure "input"
		checkCollision(squarePosition,bobPosition,&collision);//On met à jour la structure relative aux collisions
		
		if (in.key[SDLK_UP]){
	 	  	if(collision.up==0){
	  			squarePosition.y--;
		 	}

		}

		if (in.key[SDLK_LEFT]){
			if(collision.left==0){
		  		squarePosition.x--;
	  		}
		  		
		}

		if (in.key[SDLK_DOWN]){
		  if(collision.down==0){
		  		squarePosition.y++;
	  		}
		}

		if(in.key[SDLK_RIGHT]){
		  if(collision.right==0){
		  		squarePosition.x++;
	  		}
		}
		
		if(in.key[SDLK_KP1]){
		 	loadMusic(1);
		}
		
		if(in.key[SDLK_KP2]){
		 	loadMusic(2);
		}
		

		if(in.mouseMovement==1){
			squarePosition.x=in.mousex;
			squarePosition.y=in.mousey;
			in.mouseMovement=0;
		}

		SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
		//SDL_BlitSurface(map, NULL, ecran, &mapPosition);
		SDL_BlitSurface(objects.square, NULL, ecran, &squarePosition);
		SDL_BlitSurface(bob, NULL, ecran, &bobPosition);
    
		/* On met à jour l'affichage */
		SDL_Flip(ecran);
	}

	endGame();

	return EXIT_SUCCESS; // Fermeture du programme

}


