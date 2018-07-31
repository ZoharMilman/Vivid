
#include "Face.h"
#include <vector>

using namespace std;

class Surf {
private:
	vector<Face> vecFaces;
	vector<Point> vecPoints;
	string label;
	float Vmin; //Tomer: should be in the export, not here
	float Vmax; //Tomer: the same

public:
	Surf(vector<Face> vecFaces, vector<Point> vecPoints, string label);
	void exportObj(string output);
	Surf reduce();
};
