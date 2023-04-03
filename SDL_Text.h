#ifndef _SDLTEXT_H_INCLUDED
#define _SDLTEXT_H_INCLUDED

#include "SDL.h"
#include "SDL_ttf.h"
#include <string>

class SDL_Text final
{
public:
	SDL_Text(int x, int y);
	~SDL_Text();

	void loadFont(std::string path, int size);
	void loadText(SDL_Renderer* renderer, std::string text, SDL_Color color);

	void setPosition(int x, int y);
	int getX();
	int getY();

	SDL_Texture* getTexture();
	SDL_Rect getTextureRect();
	std::string getText();

private:
	void adaptTextureRect(SDL_Surface* surface);

	TTF_Font* font;
	SDL_Texture* texture;
	SDL_Rect rect;
	std::string text;
	SDL_Color color;
};

#endif // _SDLTEXT_H_INCLUDED