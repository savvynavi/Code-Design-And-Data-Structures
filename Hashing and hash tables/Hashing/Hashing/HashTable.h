#pragma once
#include"HashFunction.h"
#include<iostream>
using namespace HashFunction;

template<typename KeyType, typename T>
class HashTable{
public:
	HashTable(unsigned int size): m_size(size), m_data(new T[size]){ 
		this->clear(); 
	}

	~HashTable(){ delete[] m_data; }

	//overloaded [] ops
	T& operator[](const KeyType& key){
		auto hashedKey = hashFunction(key);
		return m_data[hashedKey];
	}

	const T& operator[](const KeyType& key)const{
		auto hashedKey = hashFunction(key);
		return m_data[];
	}

	//prints out value at hashed key
	void print(){
		for(int i = 0; i < m_size; i++){
			std::cout << m_data[i] << endl;
		}
	}

	//takes in key, hashes using hashFunction, places/removes it in m_data using it's returned index(only if current entry is empty)
	void addValue(const KeyType& key, T data){
		int hashKey = this->hashFunction(key);
		if(m_data[hashKey] == NULL){
			m_data[hashKey] = data;
		}else{
			std::cout << "COLLISION! : " << key << std::endl;
		}
	}

	//removes a value at the key by setting it to null
	void removeValue(const KeyType& key){
		int hashKey = this->hashFunction(key);
		m_data[hashKey] = NULL;

	}

	//clears the entire array by setting all used indexes to null
	void clear(){ 
		for(int i = 0; i < m_size; i++){
			m_data[i] = NULL;
			//std::cout <<"CLEAR: "<< m_data[i] << endl;
		}
	}

private:
	//takes in a key, hashes it/mods it by array size,returns the index
	unsigned int hashFunction(const KeyType& key){
		return(djb2Hash(key) % m_size);
	}

	T* m_data;
	unsigned int m_size;
};