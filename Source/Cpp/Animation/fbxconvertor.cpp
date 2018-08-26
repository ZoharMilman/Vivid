#include "stdafx.h"
#include <vector>
#include <iostream>
#include <fbxsdk.h>
#include <fbxsdk\fileio\fbxiosettings.h>

using namespace std;

int fbxconvert(vector<char*> inputfiles, char* outputfile){

	// Create the FBX SDK manager
	FbxManager* lSdkManager = FbxManager::Create();

	// Create an IOSettings object.
	FbxIOSettings * ios = FbxIOSettings::Create(lSdkManager, IOSROOT);
	lSdkManager->SetIOSettings(ios);

	// ... Configure the FbxIOSettings object ...

	// Create an importer.
	FbxImporter* lImporter = FbxImporter::Create(lSdkManager, "");

	// Create a new scene so it can be populated by the imported file.
	FbxScene* lScene = FbxScene::Create(lSdkManager, "myScene");

	// Declare the path and filename of the file containing the scene.
	// In this case, we are assuming the file is in the same directory as the executable.s
	for (vector<char*>::iterator it = inputfiles.begin(); it != inputfiles.end(); ++it)
	{
		// Initialize the importer.
		bool lImportStatus = lImporter->Initialize(*it, -1, lSdkManager->GetIOSettings());

		if (!lImportStatus) {
			printf("Call to FbxImporter::Initialize() failed.\n");
			printf("Error returned: %s\n\n", lImporter->GetStatus().GetErrorString());
			exit(-1);
		}



		// Import the contents of the file into the scene.
		lImporter->Import(lScene);

	}

	// The file has been imported; we can get rid of the importer.
	lImporter->Destroy();

	// Create an exporter.
	FbxExporter* lExporter = FbxExporter::Create(lSdkManager, "");

	// Initialize the exporter
	bool lExportStatus = lExporter->Initialize(outputfile, -1, lSdkManager->GetIOSettings());

	if (!lExportStatus) {
		printf("Call to FbxImporter::Initialize() failed.\n");
		printf("Error returned: %s\n\n", lImporter->GetStatus().GetErrorString());
		exit(-1);
	}

	// Export the content of lScene to outputfile
	lExporter->Export(lScene);

	system("pause");
	return 0;
}

/* int main(){
	vector<char*> list;
	list.push_back("C:\\Users\\zorik\\Documents\\alpha\\models\\cube.obj");
	fbxconvert(list, "C:\\Users\\zorik\\Documents\\alpha\\models\\cube.fbx");
	return 0;

} */

