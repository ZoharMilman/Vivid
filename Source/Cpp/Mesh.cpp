#include "fstream"
#include "Mesh.h"
#include "string"
#include "boost/algorithm/string/predicate.hpp"
#include "../../misc/int2str.hpp"
using namespace boost::algorithm;
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
	if (ends_with(output, ".obj")) { //check if hte output file ends with .obj, and delete it if it does
		output.erase(output.length - 4, 4);
	}
	ofstream o; // the obj file
	o.open(output + ".obj");
	ofstream m; //the mtl file
	m.open(output + ".mtl");
	string mtl = output;
	while (mtl.find('/') != string::npos) {
		mtl = mtl.substr(mtl.find('/'), string::npos);
	}
	//write obj file starter
	o << "# This 3D code was produced by Vivid /n/n/n";
	o << "mtllib" + mtl + "/n";
	o << "o" + label + "/n";
	//write points to obj file
	int counter = 0;
	for (vector<Point>::iterator it = vecPoints.begin(); it != vecPoints.end(); it++) {
		o << int2str(it->getX) + int2str(it->getY) + int2str(it->getZ);
		it->setIndex(counter);
		counter += 1;
	}
	//

}

Mesh Mesh::reduce() {
	//TODO sort out the reduse
}