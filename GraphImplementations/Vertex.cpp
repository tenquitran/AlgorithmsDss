#include "stdafx.h"

//////////////////////////////////////////////////////////////////////////

using namespace GraphImplementations;

//////////////////////////////////////////////////////////////////////////


template <typename T>
Vertex<T>::Vertex(T data)
	: m_data(data)
{
}

template <typename T>
T Vertex<T>::getData() const
{
	return m_data;
}

template <typename T>
void Vertex<T>::display() const
{
	m_data.display();
}
