#include "SDL_Text.h"

SDL_Text::SDL_Text(int x, int y) {
	setPosition(x, y);
}

SDL_Text::~SDL_Text() {
	TTF_CloseFont(font);
	SDL_DestroyTexture(texture);
}

void SDL_Text::loadFont(std::string path, int size) {
	font = TTF_OpenFont(path.c_str(), size);
}

void SDL_Text::loadText(SDL_Renderer* renderer, std::string text, SDL_Color color) {
	this->text = text;
	this->color = color;
	SDL_Surface* surface = TTF_RenderText_Solid(font, this->text.c_str(), this->color);
	adaptTextureRect(surface);
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
}

void SDL_Text::adaptTextureRect(SDL_Surface* surface) {
	rect.w = surface->w;
	rect.h = surface->h;
}

void SDL_Text::setPosition(int x, int y) {
	rect.x = x;
	rect.y = y;
}

int SDL_Text::getX() {
	return rect.x;
}

int SDL_Text::getY() {
	return rect.y;
}

SDL_Texture* SDL_Text::getTexture() {
	return texture;
}

SDL_Rect SDL_Text::getTextureRect() {
	return rect;
}

std::string SDL_Text::getText() {
	return text;
}