#pragma once
#include"IPrototype.h"
#include"ResourceManager.h"
#include<glm\vec2.hpp>

namespace aie{
	class Texture;
	class Renderer2D;
}

class Bubble: public IPrototype{
public:
	Bubble(const std::string name, std::shared_ptr<ResourceBase> texture);
	Bubble(const std::string name, const char* filename);
	Bubble(const Bubble& other);
	~Bubble();

	Bubble& operator=(const Bubble& other);

	virtual std::shared_ptr<IPrototype> clone();
	virtual std::string getName() { return m_name; }

	bool isAlive(){ return m_bAlive; }
	glm::vec2 getPosition() { return m_position; }
	void setAlive(bool state) { m_bAlive = state; }
	void setVelocity(float x, float y);
	void setPosition(float x, float y);

	void update(float dt);
	void draw(aie::Renderer2D* renderer);
private:
	std::shared_ptr<ResourceBase> m_texture;
	glm::vec2 m_position;
	glm::vec2 m_velocity;
	bool m_bAlive;
	std::string m_name;
};