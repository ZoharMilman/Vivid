#include "stdafx.h"
#include <vector>
#include <iostream>
#include <fbxsdk.h>
#include <fbxsdk\fileio\fbxiosettings.h>

using namespace std;

int rotateAnim(FbxMesh* mesh, float length, float interval, int RotAxis, char* outputfile)
{
	FbxManager* manager = FbxManager::Create();
	FbxScene* scene = FbxScene::Create(manager, "");
	FbxAnimCurve* animCurve = NULL;
	FbxAnimStack* animStack = FbxAnimStack::Create(scene, "");
	FbxAnimLayer* layer0 = FbxAnimLayer::Create(scene, "");
	animStack->AddMember(layer0);
	FbxTime time;
	FbxNode* meshNode = FbxNode::Create(scene, "");
	meshNode->SetNodeAttribute(mesh);
	int keyIndex = 0;

	meshNode->LclRotation.GetCurveNode(layer0, true);
	if (RotAxis == 0) animCurve = meshNode->LclRotation.GetCurve(layer0, FBXSDK_CURVENODE_COMPONENT_X, true);
	else if (RotAxis == 1) animCurve = meshNode->LclRotation.GetCurve(layer0, FBXSDK_CURVENODE_COMPONENT_Y, true);
	else if (RotAxis == 2) animCurve = meshNode->LclRotation.GetCurve(layer0, FBXSDK_CURVENODE_COMPONENT_Z, true);

	if (animCurve)
	{
		animCurve->KeyModifyBegin();

		time.SetSecondDouble(0.0);
		keyIndex = animCurve->KeyAdd(time);
		animCurve->KeySet(keyIndex, time, 0.0, FbxAnimCurveDef::eInterpolationLinear);

		time.SetSecondDouble(interval);
		keyIndex = animCurve->KeyAdd(time);
		animCurve->KeySet(keyIndex, time, -length, FbxAnimCurveDef::eInterpolationLinear);
		animCurve->KeyModifyEnd();
	}
	// Create an exporter.
	FbxExporter* lExporter = FbxExporter::Create(manager, "");

	// Initialize the exporter
	bool lExportStatus = lExporter->Initialize(outputfile, -1, manager->GetIOSettings());

	// Export the content of lScene to outputfile
	lExporter->Export(scene);
	return 0;
}




/* int main(){
	rotateAnim();
	return 0;
} */