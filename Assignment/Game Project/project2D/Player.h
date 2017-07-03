#pragma once
#include"Resource.h"
#include"Texture.h"
#include<memory>

//add hitbox, or just start over with a game object like demo
typedef std::shared_ptr<Resource<aie::Texture>> TexturePtr;

class Player{
public:
	Player(TexturePtr texture) : m_chara(texture) {}
	~Player() {}
private:
	TexturePtr m_chara;
};