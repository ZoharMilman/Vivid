#include "stdafx.h"
#include <vector>
#include <iostream>
#include <fbxsdk.h>
#include <fbxsdk\fileio\fbxiosettings.h>

using namespace std;



int fbxtry(){


	// HOW TO create a working mesh.
	FbxManager* manager = FbxManager::Create();					//the biggest container.
	FbxScene* scene = FbxScene::Create(manager, "scene");		//creates the scene.
	//int i;
	FbxAnimStack* animStack = FbxAnimStack::Create(scene, "animStack");
	FbxAnimLayer* layer0 = FbxAnimLayer::Create(scene, "layer0");  //later the layers should be created automaticly according to the amount of input files. 
	animStack->AddMember(layer0);
	FbxTime time;
	FbxAnimCurveKey animCurveKey;
	FbxNode* meshNode0 = FbxNode::Create(scene, "node0");		//creates a node to connect to the mesh (for later use).
	FbxMesh* mesh0 = FbxMesh::Create(scene, "mesh0");			//creates the mesh
	meshNode0->SetNodeAttribute(mesh0);							//set the node atrribute to mesh. this lets the node know that he is connected to a mesh. 
	FbxNode *lRootNode = scene->GetRootNode();					//contains the root node of the scene in a normal node.	
	lRootNode->AddChild(meshNode0);								//creats a parent-child relationship between the mesh node and the root node.
	//creating vertices for the mesh
	FbxVector4 vertex0(-50, 0, 50);
	FbxVector4 vertex1(50, 0, 50);
	FbxVector4 vertex2(50, 100, 50);
	FbxVector4 vertex3(-50, 100, 50);						
	FbxVector4 vertex4(-50, 0, -50);
	FbxVector4 vertex5(50, 0, -50);
	FbxVector4 vertex6(50, 100, -50);
	FbxVector4 vertex7(-50, 100, -50);

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

	FbxNode* meshNode1 = FbxNode::Create(scene, "node1");		
	FbxMesh* mesh1 = FbxMesh::Create(scene, "mesh1");			
	meshNode1->SetNodeAttribute(mesh1);
	lRootNode->AddChild(meshNode1);


	FbxVector4 vertex8(-150, 0, 50);
	FbxVector4 vertex9(50, 0, 50);
	FbxVector4 vertex10(50, 100, 50);
	FbxVector4 vertex11(-150, 100, 50);
	FbxVector4 vertex12(-150, 0, -50);
	FbxVector4 vertex13(50, 0, -50);
	FbxVector4 vertex14(50, 100, -50);
	FbxVector4 vertex15(-150, 100, -50);

	mesh1->InitControlPoints(24);
	FbxVector4* mesh1ControlPoints = mesh1->GetControlPoints();

	// Define each face of the cube.
	// Face 1
	mesh1ControlPoints[0] = vertex8;
	mesh1ControlPoints[1] = vertex9;
	mesh1ControlPoints[2] = vertex10;
	mesh1ControlPoints[3] = vertex11;
	// Face 2
	mesh1ControlPoints[4] = vertex9;
	mesh1ControlPoints[5] = vertex12;
	mesh1ControlPoints[6] = vertex13;
	mesh1ControlPoints[7] = vertex10;
	// Face 3
	mesh1ControlPoints[8] = vertex12;
	mesh1ControlPoints[9] = vertex11;
	mesh1ControlPoints[10] = vertex14;
	mesh1ControlPoints[11] = vertex13;
	// Face 4
	mesh1ControlPoints[12] = vertex11;
	mesh1ControlPoints[13] = vertex8;
	mesh1ControlPoints[14] = vertex10;
	mesh1ControlPoints[15] = vertex14;
	// Face 5
	mesh1ControlPoints[16] = vertex11;
	mesh1ControlPoints[17] = vertex10;
	mesh1ControlPoints[18] = vertex12;
	mesh1ControlPoints[19] = vertex13;
	// Face 6
	mesh1ControlPoints[20] = vertex9;
	mesh1ControlPoints[21] = vertex8;
	mesh1ControlPoints[22] = vertex11;
	mesh1ControlPoints[23] = vertex12;

	int b, g;
	int polygonVertices1[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
		14, 15, 16, 17, 18, 19, 20, 21, 22, 23 };
	for (b = 0; b < 6; b++)
	{
		// all faces of the cube have the same texture
		mesh1->BeginPolygon(-1, -1, -1, false);																				/*this is a bit tricky. when creating a polygon for the mesh you want to use BeginPolygon so the program																				will understand that when you started creating the polygon. afterwards you should create a loop to add
																															the desired vertices into the polygon you begun creating. after you have add all vertices, you should use
																															EndPolygon so the program knows you have finished creating your polygon.*/

		for (g = 0; g < 4; g++)
		{
			// Control point index
			mesh1->AddPolygon(polygonVertices1[b * 4 + g]);

		}

		mesh1->EndPolygon();
	}


	FbxAnimCurve* animCurve = NULL;
	int keyIndex = 0;
	animCurve = meshNode0->LclRotation.GetCurve(layer0, FBXSDK_CURVENODE_COMPONENT_Y, true);
	FbxAnimCurve* animCurve1 = NULL;
	int keyIndex1 = 0;
	animCurve1 = meshNode1->LclRotation.GetCurve(layer0, FBXSDK_CURVENODE_COMPONENT_Y, true);
	FbxAnimCurve* animCurve0 = NULL;
	int keyIndex0 = 0;
	animCurve0 = meshNode1->Visibility.GetCurve(layer0, true);
	FbxAnimCurve* animCurve2 = NULL;
	int keyIndex2 = 0;
	animCurve2 = meshNode0->Visibility.GetCurve(layer0, true);
	
	meshNode0->SetVisibility(false);

	if (animCurve0)
	{
		animCurve0->KeyModifyBegin();

		time.SetSecondDouble(5.0);																//"be invisible until 4.99"
		keyIndex0 = animCurve0->KeyAdd(time);
		animCurve0->KeySet(keyIndex0, time, 0.0, FbxAnimCurveDef::eInterpolationConstant);

		time.SetSecondDouble(10.0);																//be visible after the last key is over and until 10.0
		keyIndex0 = animCurve0->KeyAdd(time);
		animCurve0->KeySet(keyIndex0, time, 1.0, FbxAnimCurveDef::eInterpolationConstant);
	}

	if (animCurve2)
	{
		animCurve2->KeyModifyBegin();

		time.SetSecondDouble(5.0);
		keyIndex2 = animCurve2->KeyAdd(time);
		animCurve2->KeySet(keyIndex2, time, 1.0, FbxAnimCurveDef::eInterpolationConstant);

		time.SetSecondDouble(10.0);
		keyIndex2 = animCurve2->KeyAdd(time);
		animCurve2->KeySet(keyIndex2, time, 0.0, FbxAnimCurveDef::eInterpolationConstant);
	}

	if (animCurve)
	{
		animCurve->KeyModifyBegin();

		time.SetSecondDouble(0.0);
		keyIndex = animCurve->KeyAdd(time);
		animCurve->KeySet(keyIndex, time, 0.0, FbxAnimCurveDef::eInterpolationLinear);

		time.SetSecondDouble(5.0);
		keyIndex = animCurve->KeyAdd(time);
		animCurve->KeySet(keyIndex, time, -3500, FbxAnimCurveDef::eInterpolationLinear);	//the number after time determines the amount of distance the cube will rotate.

		animCurve->KeyModifyEnd();
	}


	if (animCurve1)
	{

		animCurve1->KeyModifyBegin();

		time.SetSecondDouble(5.0);
		keyIndex1 = animCurve1->KeyAdd(time);
		animCurve1->KeySet(keyIndex1, time, 0.0, FbxAnimCurveDef::eInterpolationLinear);


		time.SetSecondDouble(10.0);
		keyIndex1 = animCurve1->KeyAdd(time);
		animCurve1->KeySet(keyIndex1, time, -3500, FbxAnimCurveDef::eInterpolationLinear);				//the number after time determines the amount of distance the cube will rotate.
		animCurve1->KeyModifyEnd();
	} 



	FbxExporter* lExporter = FbxExporter::Create(manager, "");

	// Initialize the exporter
	bool lExportStatus = lExporter->Initialize("C:\\Users\\zorik\\Documents\\alpha\\models\\cube3.fbx", -1, manager->GetIOSettings());

	// Export the content of lScene to outputfile
	lExporter->Export(scene);
	system("pause");

	

	return 0;
}


/*int main(){
	 fbxtry();
	 return 0;
}  */
 