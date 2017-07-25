#pragma once
#include<functional>

namespace HashFunction{
	typedef std::function<unsigned int(const char*, unsigned int)> HashFunc;

	//implementation of basic addition hash
	unsigned int badHash(const char* data, unsigned int length);

	//ADD MORE FNS HERE

	//djb2 - uses hash(i) = hash(i - 1) * 33 ^ str[i]
	unsigned long djb2Hash(unsigned char* string);

	unsigned int BKDRHash(unsigned char* data, unsigned int size);
	unsigned int ELFHash(unsigned char* data, unsigned int size);
	//a helper to access a default hash function
	static HashFunc default = badHash;
}