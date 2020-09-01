#include "chance.h"

#include <random>
#include <ctime>

//set the seed to std::time
static std::mt19937 mersenne{static_cast<std::mt19937::result_type>(std::time(nullptr))};

//Standalone Rand # Generator template
template <class T>
template <class V, class W>
V Chance<T>::GetRandSingle(const V &min, const W &max)
{
	std::uniform_real_distribution<> die{static_cast<double>(min), static_cast<double>(max)};
	return die(mersenne);
}

//Rand # Generator using the saved m_min, m_max values in template class
template <class T>
T Chance<T>::GetRandSave()
{
	std::uniform_real_distribution<> die{static_cast<double>(m_min), static_cast<double>(m_max)};
	return die(mersenne);
}

//Change the m_min, m_max values in template class
template <class T>
template <class V, class W>
void Chance<T>::SaveMinMax(const V &min, const W &max)
{
	m_min = min;
	m_max = max;
}