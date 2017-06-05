#include"Patrol.h"
#include<stdlib.h>
#include<time.h> 

Patrol::Patrol(){

}

Patrol::~Patrol(){

}

//randomly makes new coordinates
void Patrol::onEnter(GameObject *object){
	srand(time(NULL));
	m_newPos.x = ((rand() % 1080) + 200);
	m_newPos.y = ((rand() % 520) + 200);
}

//stops moving the object
void Patrol::onExit(GameObject *object){

}

//when it updates it will want to move to a new random location on the screen
void Patrol::onUpdate(GameObject *object, float deltaTime){
	object->m_position.interpolation(object->m_position, m_newPos, deltaTime);
}