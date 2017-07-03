#include"Bubble.h"
#include"ResourceManager.h"
#include<Texture.h>
#include<Renderer2D.h>
#include<iostream>

Bubble::Bubble(const std::string name, std::shared_ptr<ResourceBase> texture): m_name(name), m_texture(texture), m_position(glm::vec2(0, 0)), m_velocity(glm::vec2(0, 0)){
}

Bubble::Bubble(const std::string name, const char* filename) : m_name(name), m_position(glm::vec2(0, 0)), m_velocity(glm::vec2(0, 0)){
	m_texture = ResourceManager::getInstance().get(filename, ResourceManager::TEXTURE);
}

Bubble::Bubble(const Bubble& other){
	m_texture = other.m_texture;
	m_position = other.m_position;
	m_velocity = other.m_velocity;
	m_name = other.m_name;
}

Bubble::~Bubble(){
	std::cout << m_name << " deallocated" << std::endl;
}

Bubble& Bubble::operator=(const Bubble& other){
	m_texture = other.m_texture;
	m_position = other.m_position;
	m_velocity = other.m_velocity;
	m_name = other.m_name;
	return(*this);
}

std::shared_ptr<IPrototype> Bubble::clone(){
	return std::shared_ptr<IPrototype>(new Bubble(*this));
}

void Bubble::setPosition(float x, float y){
	m_position.x = x;
	m_position.y = y;
}

void Bubble::setVelocity(float x, float y){
	m_velocity.x = x;
	m_velocity.y = y;
}

void Bubble::update(float dt){
	m_position.x += m_velocity.x * dt;
	m_position.y += m_velocity.y * dt;
}

void Bubble::draw(aie::Renderer2D* renderer){
	renderer->drawSprite(m_texture->as<aie::Texture>(), m_position.x, m_position.y);
}