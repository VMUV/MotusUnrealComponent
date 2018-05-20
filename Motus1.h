// Motus1.h

#pragma once

#include <string>

#include "Motus_1_Platform.h"

using namespace std;

class Motus1
{
private:
	static bool _isInitalized;
	static string _versionInfo;

public:
	static void Initialize(bool rawDataLog = false);
	static void Terminate(bool rawDataLog = false);

	static int Service();

	static Motus_1_MovementVector GetMotionVector();

//	static Motus_1_Platform GetRawPlatformData();
};

