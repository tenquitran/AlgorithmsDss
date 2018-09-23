#pragma once


namespace GraphImplementations
{
	// The underlying data type is char to save some space.
	enum class EEdgeDirection : char {
		Unknown = ' ',
		Directed = 'd',
		Undirected = 'u',
	};


	class EdgeDirection
	{
	public:
		static std::string toStr(EEdgeDirection dir);
	};
}
