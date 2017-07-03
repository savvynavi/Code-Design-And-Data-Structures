#pragma once

#include<vector>
#include<memory>

class IPrototype;

class Factory{
public:
	Factory();
	~Factory();

	void addPrototype(std::shared_ptr<IPrototype> prototype);

	std::shared_ptr<IPrototype> create(const char* name);
private:
	std::vector<std::shared_ptr<IPrototype>> m_prototypes;
};