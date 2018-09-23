#include "stdafx.h"

//////////////////////////////////////////////////////////////////////////

using namespace GraphImplementations;

//////////////////////////////////////////////////////////////////////////


std::string VertexColor::toStr(EVertexColor clr)
{
	switch (clr)
	{
	case EVertexColor::White:
		return "White";
	case EVertexColor::Gray:
		return "Gray";
	case EVertexColor::Black:
		return "Black";
	default:
		assert(false); return "";
	}
}
