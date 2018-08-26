#include "stdafx.h"
#include <vector>
#include <iostream>
#include <fbxsdk.h>
#include <fbxsdk\fileio\fbxiosettings.h>
#include <string>

using namespace std;

int FbfAnim(vector<FbxMesh*> fbxMesh, char* outputfile, float interval)
{
	FbxManager* manager = FbxManager::Create();
	FbxScene* scene = FbxScene::Create(manager, "manager");
	FbxAnimStack* animStack = FbxAnimStack::Create(scene, "animStack");
	FbxAnimLayer* layer0 = FbxAnimLayer::Create(scene, "layer0");
	animStack->AddMember(layer0);
	FbxTime time;
	FbxNode *sceneRootNode = scene->GetRootNode();
	vector<FbxNode*> meshNodes;				//Tomer says to initialize this vector.
	meshNodes.resize(fbxMesh.size());
	int a = 0;
	for (vector<FbxMesh*>::iterator it = fbxMesh.begin(); it != fbxMesh.end(); ++it)
	{
		meshNodes[a] = FbxNode::Create(scene, "meshNode" + a);
		meshNodes[a]->SetNodeAttribute(fbxMesh[a]);
		scene->AddMember(fbxMesh[a]);
		sceneRootNode->AddChild(meshNodes[a]);
		//meshNodes[a]->SetVisibility(false);
		a++;
	}

	/*int i = 0;
	vector<int> keyIndexes;
	vector<FbxAnimCurve*> animCurves;
	animCurves.resize(fbxMesh.size());
	keyIndexes.resize(fbxMesh.size());
	for (vector<FbxMesh*>::iterator it = fbxMesh.begin(); it != fbxMesh.end(); ++it)
	{
		animCurves[i] = NULL;
		keyIndexes[i] = 0;
		animCurves.push_back(meshNodes[i]->Visibility.GetCurve(layer0, true));
		if (animCurves[i])
		{
			animCurves[i]->KeyModifyBegin();
			time.SetSecondDouble(interval * i);
			keyIndexes.push_back(animCurves[i]->KeyAdd(time));
			animCurves[i]->KeySet(keyIndexes[i], time, 0.0, FbxAnimCurveDef::eInterpolationConstant);

			time.SetSecondDouble((interval * i) + interval);
			keyIndexes.push_back(animCurves[i]->KeyAdd(time));
			animCurves[i]->KeySet(keyIndexes[i], time, 1.0, FbxAnimCurveDef::eInterpolationConstant);
		} 
		i++;
	}  */
	
	// Create an exporter.
	FbxExporter* lExporter = FbxExporter::Create(manager, "");

	// Initialize the exporter
	bool lExportStatus = lExporter->Initialize(outputfile, -1, manager->GetIOSettings());

	// Export the content of lScene to outputfile
	lExporter->Export(scene);
	return 0;
}


FbxMesh* createCube(int sizeX, int sizeY, int sizeZ)
{

	FbxManager* manager = FbxManager::Create();	//the biggest container
	FbxScene* scene = FbxScene::Create(manager, "");
	FbxMesh* mesh0 = FbxMesh::Create(scene, "mesh0");			//creates the mesh
	//creating vertices for the mesh
	FbxVector4 vertex0(-sizeX, -sizeY, sizeZ);
	FbxVector4 vertex1(sizeX, -sizeY, sizeZ);
	FbxVector4 vertex2(sizeX, sizeY, sizeZ);
	FbxVector4 vertex3(-sizeX, sizeY, sizeZ);
	FbxVector4 vertex4(-sizeX, -sizeY, -sizeZ);
	FbxVector4 vertex5(sizeX, -sizeY, -sizeZ);
	FbxVector4 vertex6(sizeX, sizeY, -sizeZ);
	FbxVector4 vertex7(-sizeX, sizeY, -sizeZ);

	//meshNode0->ConnectSrcObject(mesh0);
	mesh0->InitControlPoints(24);								//Initialize the control point array of the mesh.
	FbxVector4* mesh0ControlPoints = mesh0->GetControlPoints();		// 

	// Define each face of the cube.
	// Face 1
	mesh0ControlPoints[0] = vertex0;
	mesh0ControlPoints[1] = vertex1;
	mesh0ControlPoints[2] = vertex2;
	mesh0ControlPoints[3] = vertex3;
	// Face 2
	mesh0ControlPoints[4] = vertex1;
	mesh0ControlPoints[5] = vertex5;
	mesh0ControlPoints[6] = vertex6;
	mesh0ControlPoints[7] = vertex2;
	// Face 3
	mesh0ControlPoints[8] = vertex5;
	mesh0ControlPoints[9] = vertex4;
	mesh0ControlPoints[10] = vertex7;
	mesh0ControlPoints[11] = vertex6;
	// Face 4
	mesh0ControlPoints[12] = vertex4;
	mesh0ControlPoints[13] = vertex0;
	mesh0ControlPoints[14] = vertex3;
	mesh0ControlPoints[15] = vertex7;
	// Face 5
	mesh0ControlPoints[16] = vertex3;
	mesh0ControlPoints[17] = vertex2;
	mesh0ControlPoints[18] = vertex6;
	mesh0ControlPoints[19] = vertex7;
	// Face 6
	mesh0ControlPoints[20] = vertex1;
	mesh0ControlPoints[21] = vertex0;
	mesh0ControlPoints[22] = vertex4;
	mesh0ControlPoints[23] = vertex5;

	int i, j;
	int polygonVertices0[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
		14, 15, 16, 17, 18, 19, 20, 21, 22, 23 };
	for (i = 0; i < 6; i++)
	{
		// all faces of the cube have the same texture
		mesh0->BeginPolygon(-1, -1, -1, false);																				/*this is a bit tricky. when creating a polygon for the mesh you want to use BeginPolygon so the program																				will understand that when you started creating the polygon. afterwards you should create a loop to add
																															the desired vertices into the polygon you begun creating. after you have add all vertices, you should use
																															EndPolygon so the program knows you have finished creating your polygon.*/

		for (j = 0; j < 4; j++)
		{
			// Control point index
			mesh0->AddPolygon(polygonVertices0[i * 4 + j]);

		}

		mesh0->EndPolygon();
	}

	return mesh0;
}




/* int main()
{
	vector<FbxMesh*> list;
	list.push_back(createCube(50, 50, 50));
	list.push_back(createCube(150, 150, 150));
	FbfAnim(list, "C:\\Users\\zorik\\Documents\\alpha\\models\\cube2.fbx", 10.0);
	// rotateAnim(list[0], 6500, 30.0, 0, "C:\\Users\\zorik\\Documents\\alpha\\models\\cube2.fbx");
	system("pause");


	return 0;
} */