#include <vector>
#include <iostream>

using namespace std;

class Point
{
public:
	Point(float x, float y, float z, float distance);
	~Point();
	float getX() { return this->_x; }
	float getY() { return this->_y; }
	float getZ() { return this->_z; }
	//float getDis(Point p) { return (); }
private:
	float _x, _y, _z;
};

class IndexedFace
{
public:
	IndexedFace(vector<size_t> points, float color);
	~IndexedFace();

private:
	vector<size_t> _points;
	float _color;
};

IndexedFace::IndexedFace(vector<size_t> points, float color) : _color(color)
{
	for (vector<size_t>::iterator it = points.begin(); it != points.end(); it++)
	{
		this->_points.push_back(*it);
	}
}

IndexedFace::~IndexedFace()
{
}

Point::Point(float x, float y, float z, float distance) : _x(x), _y(y), _z(z), _distance(distance)
{
}

Point::~Point()
{
}


class Mesh {

private:
	string label;
	vector<Point> points;
	vector<IndexedFace> faces;

public:
	Mesh(vector<Point> points, vector<IndexedFace> faces, string label);
	~Mesh();
	void simplify(size_t triangles, size_t vertices, float error);
	void operator<<(string output);
//protected:
//	vector<Face> vecFaces;
//	vector<Point> vecPoints;
//	string label;
//	float alpha;
//public:
//	Mesh();
//	Mesh(vector<Face> vecFaces, vector<Point> vecPoints, string label, float alpha);
//	void exportObj(string output);
//	Mesh reduce();
//	//Mesh merge(Mesh mesh); for now this function is cancelld
//	void removePoints(); //clears all the points who arent used from the vecPoints

};
