#pragma once
#include "Mesh.h"
using namespace std;

class Surf: public Mesh {
private:

	float ** inputPoints; // the original points that we got as an input


	Surf(float ** inputPoints, vector<Face> vecFaces, vector<Point> vecPoints, string label, float alpha);
	void runVorn(float ** inputPoints, vector<int> quan);
	void cleanFaces(vector<bool> mask);
public:
	Surf();
	Surf createSurf(float ** inputPoints, vector<bool> mask, vector<int> quan, string label, float alpha);
	void smoothSurf(); //smooth the surf
	string getLabel();
	void setLabel(string label);
	float getAlpha();
	void setAlpha(float alpha);
};
	
