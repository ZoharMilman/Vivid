#include "Surf.h"


Surf::Surf() {};

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

string Surf::getLabel() {
	return this->label;
}

void Surf::setLabel(string label) {
	this->label = label;
}

float Surf::getAlpha() {
	return this->alpha;
}

void Surf::setAlpha(float alpha) {
	this->alpha = alpha;
}

void Surf::runVorn(float ** inputPoints, vector<int> quan) {
	//defines vecFaces and vecPoints
}

Surf Surf::createSurf(float ** inputPoints, vector<bool> mask, vector<int> quan, string label, float alpha) {
	Surf surf;
	surf.runVorn(inputPoints, quan);
	surf.cleanFaces(mask);
	surf.removePoints();
	surf.setLabel(label);
	surf.setAlpha(alpha);
	return surf;
}

void Surf::smoothSurf() {
	//need run vorn
}