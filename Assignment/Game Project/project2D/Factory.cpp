#include"Factory.h"
#include"IPrototype.h"
#include<memory>


Factory::Factory(){

}
Factory::~Factory(){

}

void Factory::addPrototype(std::shared_ptr<IPrototype> prototype){
	m_prototypes.push_back(prototype);
}

std::shared_ptr<IPrototype> Factory::create(const char* name){
	for(std::shared_ptr<IPrototype> proto : m_prototypes){
		if(proto->getName().compare(name) == 0){
			return(proto->clone());
		}
	}
	return nullptr;
}