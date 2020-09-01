#ifndef CHANCE_H
#define CHANCE_H

template <class T>
class Chance
{
  private:
	//Encapsulation woooooo
	T m_min;
	T m_max;

  public:
	//default constructor, duh
	Chance(const T &min = 0, const T &max = 0) : m_min(min),m_max(max){}
	
	//Standalone Rand # Generator template
	template <class V, class W>
	V GetRandSingle(const V &min, const W &max);
	
	//Rand # Generator using the saved m_min, m_max values in template class
	T GetRandSave();
	
	//Change the m_min, m_max values in template class
	template <class V, class W>
	void SaveMinMax(const V &min, const W &max);
};

#include "chance.cpp"

#endif