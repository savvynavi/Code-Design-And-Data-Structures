#include"ResourceManager.h"

ResourceManager& ResourceManager::getInstance(){
	static ResourceManager instance;
	return instance;
}

ResourceManager::~ResourceManager(){

}

std::shared_ptr<ResourceBase> ResourceManager::get(const std::string filename, ResourceType type){
	unsigned int index = 0;
	std::vector<std::shared_ptr<ResourceBase>>::iterator it;

	for(it = m_resources.begin(); it != m_resources.end(); it++){
		if(filename.compare((*it)->getFilename()) == 0){
			return(*it);
		}
	}

	switch(type){
	case ResourceType::TEXTURE:{
		std::shared_ptr<ResourceBase> resource(new Resource<aie::Texture>(filename));
		m_resources.push_back(resource);
		return resource;
	}
	case ResourceType::FONT:{
		std::shared_ptr<ResourceBase> resource(new Resource<aie::Font>(filename, 32));
		m_resources.push_back(resource);
		return resource;
	}
	case ResourceType::AUDIO:{
		std::shared_ptr<ResourceBase> resource(new Resource<aie::Audio>(filename));
		m_resources.push_back(resource);
		return resource;
	}
	default:
		return nullptr;
	}

}
