#include "stdafx.h"
#include <vector>
#include <iostream>
#include <fbxsdk.h>
#include <fbxsdk\fileio\fbxiosettings.h>
#include <string>

using namespace std;

int KFAnim(vector<char*> inputfiles, char* outputfile, int interval){
	// Create the FBX SDK manager
	int i = 0;
	FbxManager* manager = FbxManager::Create();								//the biggest container.
	FbxScene* scene = FbxScene::Create(manager, "scene");					// Create a new scene so it can be populated by the imported file.
	FbxAnimStack* animStack = FbxAnimStack::Create(scene, "animStack");
	FbxTime time;
	FbxAnimCurveKey animCurveKey;
	FbxAnimCurve* animCurve = NULL; //FbxAnimCurve::Create(scene, "animCurve");
	vector<FbxObject*> objList;												//this vector will be use to store the obj files the function takes as input
	vector<FbxMesh*> meshes;
	//vector<FbxAnimLayer*> animLayers;
	objList.resize(inputfiles.size());
	meshes.resize(inputfiles.size());
	FbxIOSettings * ios = FbxIOSettings::Create(manager, IOSROOT);			// Create an IOSettings object.
	manager->SetIOSettings(ios);
	FbxImporter* lImporter = FbxImporter::Create(manager, "");				// Create an importer.



	for (vector<char*>::iterator it = inputfiles.begin(); it != inputfiles.end(); ++it)   
	{
		// Initialize the importer.
		bool lImportStatus = lImporter->Initialize(*it, -1, manager->GetIOSettings());

		if (!lImportStatus) {
			printf("Call to FbxImporter::Initialize() failed.\n");
			printf("Error returned: %s\n\n", lImporter->GetStatus().GetErrorString());
			exit(-1);
		}

		//objList[i] = FbxScene::Create(manager, "obj" + i);     //TODO this is not correct, change.

		// Import the contents of the file into the scene./
		lImporter->Import(scene); //(FbxScene*)objList[i] was inside the things

		//animLayers[i] = FbxAnimLayer::Create(scene, "layer");
		//animStack->AddMember(animLayers[i]);
		meshes[i] = FbxMesh::Create(scene, "mesh" + i);
		i++;
	}	

	// The file has been imported; we can get rid of the importer.
	lImporter->Destroy();






	// Create an exporter.
	FbxExporter* lExporter = FbxExporter::Create(manager, "");

	// Initialize the exporter
	bool lExportStatus = lExporter->Initialize(outputfile, -1, manager->GetIOSettings());

	if (!lExportStatus) {
		printf("Call to FbxImporter::Initialize() failed.\n");
		printf("Error returned: %s\n\n", lImporter->GetStatus().GetErrorString());
		exit(-1);
	}

	// Export the content of scene to outputfile
	lExporter->Export(scene);
	system("pause");
	return 0;
}


/* int main(){
vector<char*> list;
list.push_back("C:\\Users\\zorik\\Documents\\alpha\\models\\cube.fbx");
KFAnim(list, "C:\\Users\\zorik\\Documents\\alpha\\models\\cube2.fbx", 5);
return 0;

} */