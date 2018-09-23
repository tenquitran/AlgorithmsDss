#pragma once


namespace GraphImplementations
{
	// Vertex data.
	// NOTE: suitable to store statically but NOT dynamically allocated data.
	template <typename Label, typename Data>
	struct VertexDataStatic
	{
	public:
		VertexDataStatic(Label label, Data data);

		void display() const;

	private:
		// Vertex label (to simplify debugging and logging).
		// Can be an integer, a char, etc.
		Label m_label;

		// Vertex data.
		Data m_data;
	};
}

#include "VertexDataStatic.cpp"
