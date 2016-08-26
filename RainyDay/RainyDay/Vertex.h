#pragma once

namespace RainyDay {
	DLL_API class  Vertex
	{
	public:
		XMFLOAT3	pos;
		XMFLOAT4	color;

		XMFLOAT3	normal;
		XMFLOAT2	tex;

		bool operator==(const Vertex& rv);
		void operator=(const Vertex& rv);
	};
}