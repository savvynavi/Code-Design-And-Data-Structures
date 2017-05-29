#include"WithinRangeCondition.h"

WithinRangeCondition::WithinRangeCondition(GameObject *target, float range){
	m_target = target;
	m_range = range;
}

WithinRangeCondition::~WithinRangeCondition(){

}

bool WithinRangeCondition::test(GameObject * go) const{
	return (getDistanceBetween(go, m_target) <= m_range);
}