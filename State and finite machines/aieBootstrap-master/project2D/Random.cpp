#include"Random.h"
#include"GameObject.h"
#include<stdlib.h>
#include<time.h>

Random::Random(GameObject *object){
	m_target = object;
}

Random::~Random(){

}

bool Random::test(GameObject *object) const{
	srand(time(NULL));
	if((rand() % 100) <= 70){
		return true;
	}
	return false;
}