#include "Vivid.h"
#include "fstream"

static const string MADEBY = "This 3D code was produced by Vivid";
static Mesh importObj(string obj) {
	ofstream f;
	f.open(obj, ios::in);

}