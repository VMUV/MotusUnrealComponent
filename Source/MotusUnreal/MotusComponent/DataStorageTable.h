// DataStorageTable.h

#pragma once

#include <vector>

#include "Motus_1_Platform.h"

using namespace std;

class DataStorageTable
{
private:
	static Motus_1_Platform _platformPing;
	static Motus_1_Platform _platformPong;
	static bool _usePing;

	//static int movecount;
	//static int framecount;
public:
	static void SetMotus_1_Data(vector<int> data);

	static Motus_1_MovementVector GetMotionInput();

	static Motus_1_Platform GetPlatformObject();

};
