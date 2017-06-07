#pragma once
#include<memory>
#include<vector>
#include<string>
#include"Resource.h"

template<class T>
class ResourceManager{
public:
	ResourceManager() {};
	~ResourceManager() {};

	//takes in filename to load, (places it in a shared poiner which is inserted into m_resources if unloaded), returns the shared pointer
	std::shared_ptr<Resource<T>> get(const std::string filename){
		std::vector<std::shared_ptr<Resource<T>>>::iterator it;
		for(it = m_resources.begin(); it != m_resources.end(); it++){
			if(filename.compare((*it)->getFilename()) == 0){
				return(*it);
			}
		}

		std::shared_ptr<Resource<T>> resource(new Resource<T>(filename));
		m_resources.push_back(resource);
		return resource;
	};

	//counts how many resources there currently are
	int getCount(){
		return(m_resources.size());
	};

	//deletes anything with a reference count = 1
	void collectGarbage(){
		std::vector<std::shared_ptr<Resource<T>>>::iterator it;
		for(it = m_resources.begin(); it != m_resources.end();){
			if((*it).use_count() == 1){
				it = m_resources.erase(it);
			} else{
				++it;
			}
		}
	};

private:
	std::vector<std::shared_ptr<Resource<T>>> m_resources;

	//keep the copy constructor and assignment allocator private
	ResourceManager(const ResourceManager&) {};
	ResourceManager& operator=(const ResourceManager&) {};
};