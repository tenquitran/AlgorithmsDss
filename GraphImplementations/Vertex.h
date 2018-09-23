#pragma once


namespace GraphImplementations
{
	// Graph vertex.
	// NOTE: memory allocation/deallocation is the responsibility of the graph class.
	template <typename T>
	class Vertex
	{
	public:
		explicit Vertex(T data);

		T getData() const;

		void display() const;

	private:
		T m_data;
	};
};

#include "Vertex.cpp"
