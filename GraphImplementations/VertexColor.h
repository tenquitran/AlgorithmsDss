#pragma once


namespace GraphImplementations
{
	// Vertex colors for the graph algorithms.
	enum class EVertexColor
	{
		White,
		Gray,
		Black
	};


	// Helper functions for the vertex colors enumeration.
	class VertexColor
	{
	public:
		static std::string toStr(EVertexColor clr);
	};
}
