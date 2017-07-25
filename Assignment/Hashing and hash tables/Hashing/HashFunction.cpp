#include"HashFunction.h"

namespace HashFunction{
	//implementation of basic add hash
	unsigned int badHash(const char* data, unsigned int length){
		unsigned int hash = 0;

		for(unsigned int i = 0; i < length; ++i){
			hash += data[i];
		}
		return hash;
	}

	//djb2 hashing
	unsigned long djb2Hash(unsigned char* string){
		unsigned long hash = 5381;
		int c;
		while(c = *string++){
			hash = ((hash << 5) + hash) + c;
		}
		return hash;
	}
	
	//complex ones
	unsigned int BKDRHash(unsigned char* data, unsigned int size){
		unsigned int hash = 0;

		for(unsigned int i = 0; i < size; ++i){
			hash = (hash * 1313) + data[i];
		}
		return(hash & 0x7FFFFFFF);
	}

	unsigned int ELFHash(unsigned char* data, unsigned int size){
		unsigned int hash = 0, x = 0;

		for(unsigned int i = 0; i < size; ++i){
			hash = (hash << 4) + data[i];
			if((x = hash & 0xF0000000L) != 0){
				hash ^= (x >> 24);
				hash &= ~x;
			}
		}
		return(hash & 0x7FFFFFFF);
	}
}