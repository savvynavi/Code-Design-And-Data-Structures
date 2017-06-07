#pragma once
#include<string>

class ResourceBase{
public:
	~ResourceBase() {};
	std::string getFilename() { return m_filename; };
	virtual void* getData() = 0;
protected:
	ResourceBase(const std::string& filename) : m_filename(filename){};
	std::string m_filename;
}; 