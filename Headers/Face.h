#include "Point.h"
#include <iostream>
#include <vector>

using namespace std;

class Face
{
private:
	vector<Point> points; //holds this face points
	float quan; //holds the quen value of this face, this value will later be translated to the color of the face
	int Cpoints[2]; //holds the indexs for the two creating points of this face 

public:
	Face(vector<Point> points, float quan, int Cpoints[]);
	void removeFace(); //performs the facesub func for all is points, in order to delete himself from the record(mendatory if we want to delete him)
	float getQuan();
	void setQuan(float quen);
	Point getPoint(int index); // get the point in the given index(within this.points)
	vector<Point> getPoints(); //returns this->points
	int* getCpoints();//gets the creating points for this face
	~Face();
};