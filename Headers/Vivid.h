#pragma 
#include "Surf.h"

static Mesh importObj(string obj, string mtl);
static Mesh importObj(string obj);
static void vivify(float** points, bool mask[], float quan[], float Vmax, float Vmin, string label, int alpha);



