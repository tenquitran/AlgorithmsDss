#include "stdafx.h"

//////////////////////////////////////////////////////////////////////////

using namespace GraphImplementations;

//////////////////////////////////////////////////////////////////////////


std::string EdgeDirection::toStr(EEdgeDirection dir)
{
	switch (dir)
	{
	case EEdgeDirection::Unknown:
		return "Unknown";
	case EEdgeDirection::Directed:
		return "Directed";
	case EEdgeDirection::Undirected:
		return "Undirected";
	default:
		assert(false); return "";
	}
}
