/*
	sudo apt install libsdl2-2.0-0 libsdl2-gfx-1.0-0 libsdl2-image-2.0-0 libsdl2-mixer-2.0-0 libsdl2-net-2.0-0 libsdl2-ttf-2.0-0
	sudo apt-get install libsdl2-ttf-dev
	gcc -Wall droites.c -o droites $(sdl2-config --cflags --libs) -lSDL2 -lSDL2_gfx -lm
	
	gcc -Wall droites.c -lm -o exe $(sdl2-config --cflags --libs) -lSDL2_image -lSDL2_ttf
	*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL.h>
#include <time.h>
#include <math.h>

#define tailleFenetreH		400
#define tailleFenetreW	640
#define centreX				(tailleFenetreW / 2)
#define centreY				(tailleFenetreH / 2) 

// Creation de la fenetre et du canvas de la fenetre
int init(SDL_Window ** mafenetre, SDL_Renderer * canvas, SDL_Renderer ** renderer)
{
	int res=0;
	if (SDL_VideoInit(NULL) < 0)  res = 1;  // SDL_VideoInit renvoie 0 en cas de succes
	SDL_CreateWindowAndRenderer(tailleFenetreW,tailleFenetreH, SDL_WINDOW_SHOWN,mafenetre,renderer);
	SDL_SetRenderDrawColor(canvas, 0, 0, 0, 255);
	SDL_RenderClear(canvas);
	return res;
}



void SDL_MyRenderDrawLine(SDL_Renderer * renderer ,int x1,int y1,int x2,int y2){
	SDL_RenderDrawPoint(renderer,x1,y1);
	SDL_RenderDrawPoint(renderer,x2,y2);


	int deltay = y2 -y1;

	int deltax = x2 -x1;


	// double pente = deltay/deltax;
	int erreur =0;
	SDL_SetRenderDrawColor(renderer,0,255,255,255);


	
	
	if (abs(deltax)>abs(deltay)){
		int y = (double) y1;
	
		if (x1>x2)
		{
			int xtemp,ytemp ;
			xtemp = x1 ;
			ytemp = y1 ;
			y =y2;
			x1 = x2;
			y1 = y2;
			SDL_SetRenderDrawColor(renderer,0,0,255,255);
			x2 = xtemp;
			y2 = ytemp;

			deltax = -deltax;
			deltay = -deltay;
		}

		for (int x = x1; x < x2; x++)
		{
			erreur -= deltay;
			if (2 * erreur < -1 *deltax)
			{
				y+=1;
				erreur +=deltax;
			}

			else if (2 * erreur > deltax)
			{
				y -=1;
				erreur -= deltax;
			}
			
			SDL_RenderDrawPoint(renderer,x,y);
			
			
		}

	}else if (abs(deltax) < abs(deltay)){
		int x = (double) x1;
		if (y1>y2)
		{
			int xtemp,ytemp ;
			x =  x2;
			xtemp = x1 ;
			ytemp = y1 ;
			x1 = x2;
			y1 = y2;

			x2 = xtemp;
			y2 = ytemp;

			deltax = -deltax;
			deltay = -deltay;
			SDL_SetRenderDrawColor(renderer,0,255,0,255);
		}
		
		for (int y = y1; y < y2 ; y++){
			erreur -= deltax;
			if (2 * erreur < -1 *deltay)
			{
				x+=1;
				erreur +=deltay;
			}

			else if (2 * erreur > deltay)
			{
				x -=1;
				erreur -= deltay;
			}
			SDL_RenderDrawPoint(renderer,x,y);
		}
	}
	
	
	
}


int main() 
{
	SDL_Window * mafenetre; 		// Fenetre du programme
	SDL_Event event; 					// Structure pour gerer les evenements clavier, souris, joystick
	SDL_Renderer * renderer;		// Canvas
		
	init(&mafenetre,renderer,&renderer);

	int fin = 0;
	float inca = (3.14 * 2) / 360;
	float a = 0;
	while (!fin) 
	{
		Uint64 start = SDL_GetPerformanceCounter();
		
		SDL_SetRenderDrawColor(renderer,0,0,0,255);
		SDL_RenderClear(renderer);

		// Boucle principale
		if (SDL_PollEvent(&event)) 
		{ 												// Scrute sans cesse les evenements et renvoie 1
			switch (event.type) 
			{
				case SDL_QUIT: 			// Evenement fermeture de la fenetre
				fin=1;
				break;
				
				case SDL_KEYDOWN:
                if(event.key.keysym.sym == SDLK_ESCAPE) fin = 1;					
				break;
			}
		}
		
		SDL_SetRenderDrawColor(renderer,255,255,255,255);
		
		for (int i = 0; i < 4; i++)
		{
			float x1 = centreX + 150 * sin(a + (inca * 90 * i));
			float  y1 = centreY + 150 * cos(a + (inca * 90 * i));
			float x2 = centreX + 150 * sin(a + (inca * 90 * (i+1)));
			float y2 = centreY + 150 * cos(a + (inca * 90 * (i+1)));
			SDL_MyRenderDrawLine(renderer,x1,y1,x2,y2);	
			//SDL_RenderDrawLine(renderer,x1,y1,x2,y2);					// A remplacer par votre algorithme		
		}
		
		a += inca;
		if (a > 3.14 * 2) a = 0;

		SDL_RenderPresent(renderer);
		
		// Vertical sync => Attente 60 fps
		Uint64 end= SDL_GetPerformanceCounter() ;
		float elapseTime = (end - start) / 1000000000.f;		
		while(1.0f / elapseTime > 60)
		{
			end= SDL_GetPerformanceCounter() ;
			elapseTime = (end - start) / 1000000000.f;				
		}
	}
	
	SDL_DestroyWindow(mafenetre);
	SDL_Quit();
	exit(0);
}

