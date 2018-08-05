#pragma once
#include "Mesh.h"
using namespace std;

class Surf: public Mesh {
private:

	vector<float[3]> inputPoints; // the original points that we got as an input
	vector<bool> mask;
	vector<float> quan;

	Surf(vector<float[3]> inputPoints, vector<Face> vecFaces, vector<Point> vecPoints, string label, float alpha);
	void runVorn(vector<float[3]> inputPoints, vector<float> quan);
	void cleanFaces(vector<bool> mask);
	void _setPinPout(vector<int> Pout, vector<int> Pin);
	void _updateInputPoints(vector<int> Pout, vector<int> Pin); // update Cpoints in order to run vornoi again(smooth)
	void _makeMask(int PoutS, int PinS);
public:
	Surf();
	Surf createSurf(vector<float[3]> inputPoints, vector<bool> mask, vector<float> quan, string label, float alpha);
	void smoothSurf(); //smooth the surf
	string getLabel();
	void setLabel(string label);
	float getAlpha();
	void setAlpha(float alpha);
};
	
