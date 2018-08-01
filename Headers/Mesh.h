
#include "Face.h"

using namespace std;

class Mesh {
protected:
	vector<Face> vecFaces;
	vector<Point> vecPoints;
	string label;
	float alpha;
public:
	Mesh();
	Mesh(vector<Face> vecFaces, vector<Point> vecPoints, string label, float alpha);
	void exportObj(string output);
	Mesh reduce();
	//Mesh merge(Mesh mesh); for now this function is cancelld
	void removePoints(); //clears all the points who arent used from the vecPoints

};
