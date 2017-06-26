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

	static ResourceManager& getInstance();
	~ResourceManager();
	std::shared_ptr<ResourceBase> get(const std::string filename, ResourceType type);

	//counts how many resources there currently are
	int getCount(){
		return(m_resources.size());
	}

	//deletes anything with a reference count = 1
	void collectGarbage(){
		std::vector< std::shared_ptr<ResourceBase>>::iterator it;
		for(it = m_resources.begin(); it != m_resources.end();){
			if((*it).use_count() == 1){
				it = m_resources.erase(it);
			} else{
				++it;
			}
		}
	}

private:
	std::vector<std::shared_ptr<ResourceBase>> m_resources;

	ResourceManager(){}
	ResourceManager(const ResourceManager&){}
	ResourceManager& operator=(const ResourceManager&){}
};