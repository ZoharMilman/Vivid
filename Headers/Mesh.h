#include <vector>
#include <iostream>
#include "Face.h"

using namespace std;

class Mesh {
	class Point
	{
	public:
		Point(float x, float y, float z, float distance);
		~Point();

	private:
		float _x, _y, _z, _distance;
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

private:
	const vector<const Point> points;
	const vector<IndexedFace> faces;

public:
	Mesh(const vector<const Point> points, const vector<IndexedFace> faces);
	void simplify(size_t triangles, size_t vertices, float error);
	operator<<();
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
