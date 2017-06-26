#pragma once
#include"Resource.h"
#include"Texture.h"

typedef std::shared_ptr<Resource<aie::Texture>> TexturePtr;

class Player{
public:
	Player(TexturePtr texture) : m_ship(texture) {};
	~Player() {};
private:
	TexturePtr m_ship;
};