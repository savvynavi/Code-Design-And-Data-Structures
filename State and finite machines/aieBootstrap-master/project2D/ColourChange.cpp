#include"ColourChange.h"
#include"GameObject.h"
#include"Input.h"

ColourChange::ColourChange(bool input){
	m_input = input;
}

ColourChange::~ColourChange(){

}

bool ColourChange::test(GameObject *object) const{
	if(m_input == true){
		return true;
	}
	return false;
}