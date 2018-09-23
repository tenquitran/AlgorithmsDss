#include "stdafx.h"

//////////////////////////////////////////////////////////////////////////

using namespace GraphImplementations;

//////////////////////////////////////////////////////////////////////////


template <typename Label, typename Data>
VertexDataStatic<Label, Data>::VertexDataStatic(Label label, Data data)
	: m_label(label), m_data(data)
{
}

template <typename Label, typename Data>
void VertexDataStatic<Label, Data>::display() const
{
	std::cout << "\tLabel: " << m_label << ", data: " << m_data << std::endl;
}
