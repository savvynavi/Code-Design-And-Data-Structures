#pragma once
#include<string>

class ResourceBase{
public:
	~ResourceBase() {}
	std::string getFilename() { return m_filename; }
	virtual void* getData() = 0;

	template<typename T>
	T* as() {
		return(T*)getData();
	}

protected:
	ResourceBase(const std::string& filename) : m_filename(filename){}
	std::string m_filename;
}; 