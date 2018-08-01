#include "fstream"
#include "Mesh.h"

Mesh::Mesh() {

}
Mesh::Mesh(vector<Face> vecFaces, vector<Point> vecPoints, string label, float alpha) {
	this->vecFaces = vecFaces;
	this->vecPoints = vecPoints;
	this->label = label;
	this->alpha = alpha;
}

void Mesh::removePoints() {
	vector<Point> newPoints;
	for (vector<Point>::iterator it = vecPoints.begin(); it != vecPoints.end(); it++){
		if (it->isPointDel() != true) {
			newPoints.push_back(*it);
		}
	}
	this->vecPoints = newPoints;
}

void Mesh::exportObj(string output) { //TODO get the color sorted(a way to convert quan to color)
	ofstream f;
	f.open(output);
	int countrer = 0;
}

Mesh Mesh::reduce() {
	//TODO sort out the reduse
}