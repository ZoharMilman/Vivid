#include "Surf.h"

Surf::Surf(float ** inputPoints, vector<Face> vecFaces, vector<Point> vecPoints, string label, float alpha) {
	this->inputPoints = inputPoints;
	this->vecFaces = vecFaces;
	this->vecPoints = vecPoints;
	this->label = label;
	this->alpha = alpha;
}

void Surf::cleanFaces(vector<bool> mask) {
	vector<Face> newFaces;
	int maskLen = mask.size();
	int cPoint1;
	int cPoint2;
	for (vector<Face>::iterator it = vecFaces.begin(); it != vecFaces.end(); it++) {
		cPoint1 = it->getCpoints[0];
		cPoint2 = it->getCpoints[1];
		if (maskLen > cPoint1 && maskLen > cPoint2) { //the indexs are both in range and not a part of the box
			if (mask[cPoint1] != mask[cPoint2]) { //the face is a part of the surf
				newFaces.push_back(*it);
			}
		}
	}
	this->vecFaces = newFaces;
}

Surf * Surf::create(float ** inputPoints, bool mask[], float quan[], string label, float alpha) {
	//need to know the runVorn output first
}

void Surf::smoothSurf() {
	//need run vorn
}