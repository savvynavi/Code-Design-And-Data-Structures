#pragma once
#include"HashFunction.h"
#include<iostream>
using namespace HashFunction;

template<typename KeyType, typename T>
class HashTable{
public:
	HashTable(unsigned int size) : m_size(size), m_data(new T[size]){}
	~HashTable(){ delete[] m_data; }

	T& operator[](const KeyType& key){
		auto hashedKey = hash(key) % m_size;
		return m_data[hashedKey];
	}

	const T& operator[](const KeyType& key)const{
		auto hashedKey = hash(key) % m_size;
		return m_data[];
	}

	void print(const KeyType& key){
		//std::cout << m_data[key];
	}

	//takes in key, hashes using hashFunction, places/removes it in m_data using it's returned index
	void addValue(const KeyType& key){
		this->hashFunction(key);
	}
	//void removeValue(const KeyType& key);

	////clears the entire array
	//void clear();

	////returns item at given key
	//unsigned int getValue(const KeyType& key);

private:
	unsigned int hashFunction(const KeyType& key){	//takes in a key, hashes it and returns index?
		return(djb2Hash(key) % m_size);
	}

	T* m_data;
	unsigned int m_size;
};