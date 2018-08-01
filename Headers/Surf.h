#pragma once
#include "Mesh.h"
using namespace std;

class Surf: public Mesh {
private:

	float ** inputPoints; // the original points that we got as an input


	Surf(float ** inputPoints, vector<Face> vecFaces, vector<Point> vecPoints, string label, float alpha);
	void runVorn(float ** inputPoints);
	void cleanFaces(vector<bool> mask);
public:
	Surf * create(float ** inputPoints, bool mask[], float quan[], string label, float alpha);
	void smoothSurf(); //smooth the surf
};
	
