#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include "myGame.h"


SDL_Surface* gameInitialization()
{
	int init=SDL_Init(SDL_INIT_VIDEO); // Initialisation de la SDL

	if(init == -1)
	{
		fprintf(stderr, "SDL can't be loaded: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	SDL_Surface* ecran = SDL_SetVideoMode(860, 640, 32, SDL_HWSURFACE | SDL_DOUBLEBUF); // Ouverture de la fenêtre

	if (ecran == NULL) // Fin du programme avec message d'erreur si problème d'initiatlisation
	{
		fprintf(stderr, "Video mode can't be loaded : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	SDL_WM_SetCaption("Mr Blue" , NULL);

	if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) //Initialisation de l'API Mixer
	{
		fprintf(stderr,"Audio mode can't be loaded:%s", Mix_GetError());
		exit(EXIT_FAILURE);
	}

	return ecran;

}

void loadMusic(int track)
{
	Mix_Music* musique; //Création du pointeur de type Mix_Music
	switch(track){
		case 1 :
			
			musique = Mix_LoadMUS("Music/Steve Miller Band.mp3"); //Chargement de la musique
			Mix_PlayMusic(musique, -1); //Jouer infiniment la musique
			break;
		case 2:
			musique = Mix_LoadMUS("Music/Box Tops.mp3"); //Chargement de la musique
			Mix_PlayMusic(musique, -1); //Jouer infiniment la musique
			break;

		default:break;
	}
	
}

void updateEvents(Input* in)
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
			in->mousebuttons[event.button.button-1]=1;
			break;
		case SDL_MOUSEBUTTONUP:
			in->mousebuttons[event.button.button-1]=0;
			break;
		case SDL_QUIT:
			in->quit = 1;
			break;
		default:
			break;
		}
	}
}

//End of the game session
void endGame(){
    Mix_CloseAudio();
    Mix_Quit();
    SDL_Quit(); 

}