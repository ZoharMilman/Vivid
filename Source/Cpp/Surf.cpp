#include "Surf.h"


Surf::Surf() {};

Surf::Surf(vector<float[3]> inputPoints, vector<Face> vecFaces, vector<Point> vecPoints, string label, float alpha) {
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
		cPoint1 = it->getCpoints()[0];
		cPoint2 = it->getCpoints()[1];
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

void Surf::runVorn(vector<float[3]> inputPoints, vector<float> quan) {
	//defines vecFaces and vecPoints
}

Surf Surf::createSurf(vector<float[3]> inputPoints, vector<bool> mask, vector<float> quan, string label, float alpha) {
	Surf surf;
	surf.runVorn(inputPoints, quan);
	surf.cleanFaces(mask);
	surf.removePoints();
	this->inputPoints = inputPoints;
	this->mask = mask;
	this->quan = quan;
	surf.setLabel(label);
	surf.setAlpha(alpha);
	return surf;
}

void Surf::smoothSurf() {
	vector<int> Pout;
	vector<int> Pin;
	_setPinPout(Pout, Pin);
	_updateInputPoints(Pout, Pin);
	_makeMask(Pout.size(), Pin.size());
	runVorn(this->inputPoints, this->quan);
	cleanFaces(mask);
}

void Surf::_setPinPout(vector<int> Pout, vector<int> Pin) { //define Pin and Pout
	int cPoint1;
	int cPoint2;
	for (vector<Face>::iterator it = this->vecFaces.begin(); it != this->vecFaces.end(); it++) {
		cPoint1 = it->getCpoints()[0];
		cPoint2 = it->getCpoints()[1];
		if (this->mask[cPoint1]) {
			Pin.push_back(cPoint1);
			Pout.push_back(cPoint2);
		}
		else 
		{
			Pin.push_back(cPoint2);
			Pout.push_back(cPoint1);
		}

	}
}

void Surf::_updateInputPoints(vector<int> Pout, vector<int> Pin) {
	vector<float[3]> newPoints;
	vector<float> quan;
	newPoints.resize(Pout.size() + Pin.size());
	quan.resize(Pout.size() + Pin.size());
	for (vector<int>::iterator it = Pout.begin(); it != Pout.end(); it++) {
		newPoints.push_back(this->inputPoints[*it]);
		quan.push_back(this->quan[*it]);
	}
	for (vector<int>::iterator it = Pin.begin(); it != Pin.end(); it++) {
		newPoints.push_back(this->inputPoints[*it]);
		quan.push_back(this->quan[*it]);
	}
	this->inputPoints = newPoints;
	this->quan = quan;
}

void Surf::_makeMask(int PoutS, int PinS) {
	vector<bool> newMask;
	newMask.resize(PoutS + PinS);
	for (int i; i < PoutS; i++) {
		newMask.push_back(false);
	}
	for (int i; i < PinS; i++) {
		newMask.push_back(true);
	}
	this->mask = mask;
}