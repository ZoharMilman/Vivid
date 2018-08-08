#pragma once
#include "Mesh.h"

class Shape
{
public:
	Shape(Mesh mesh);
	~Shape();
	const Mesh createSphere();
	const Mesh elipsoid();
	const Mesh arrow();
	const Mesh 3DAxes();
private:
	Mesh mesh;
};