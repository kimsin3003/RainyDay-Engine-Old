#include "stdafx.h"
#include "Vertex.h"

namespace RainyDay {
	bool Vertex::operator==(const Vertex& rv)
	{
		return (pos.x == rv.pos.x && pos.y == rv.pos.y && pos.z == rv.pos.z)
			&& (color.x == rv.color.x && color.y == rv.color.y && color.z == rv.color.z && color.w == rv.color.w)
			&& (normal.x == rv.normal.x && normal.y == rv.normal.y && normal.z == rv.normal.z)
			&& (tex.x == rv.tex.x && tex.y == rv.tex.y);
	}


	void Vertex::operator=(const Vertex& rv)
	{

		pos = rv.pos;
		color = rv.color;
		normal = rv.normal;
		tex = rv.tex;
	}
}