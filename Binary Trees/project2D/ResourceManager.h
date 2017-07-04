#pragma once
#include<memory>
#include<vector>
#include<string>
#include"Resource.h"
#include"ResourceBase.h"
#include"Texture.h"
#include"Font.h"
#include"Audio.h"

class ResourceManager{
public:
	enum ResourceType{
		TEXTURE = 0,
		FONT,
		AUDIO
	};

	static ResourceManager& getInstance(){
		static ResourceManager instance;
		return instance;
	};

	~ResourceManager() {};

	std::shared_ptr<ResourceBase> get(const std::string filename, ResourceType type){
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

	};

	//counts how many resources there currently are
	int getCount(){
		return(m_resources.size());
	};

	//deletes anything with a reference count = 1 FIX THIS, PROBLEM WITH VECTOR THING
	void collectGarbage(){
		std::vector< std::shared_ptr<ResourceBase>>::iterator it;
		for(it = m_resources.begin(); it != m_resources.end();){
			if((*it).use_count() == 1){
				it = m_resources.erase(it);
			} else{
				++it;
			}
		}
	};

private:
	std::vector<std::shared_ptr<ResourceBase>> m_resources;

	ResourceManager() {};
	ResourceManager(const ResourceManager&) {};
	ResourceManager& operator=(const ResourceManager&) {};
};