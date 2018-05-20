// Motus_1_Platform.h

#pragma once

#include <vector>

#include "SensorArray.h"

using namespace std;

class Motus_1_MovementVector;

class Motus_1_Platform
{
private:
	vector<SensorArray> _pads;
	int _numElementsPerPad;
	const float sin45 = 0.707f;

public:
	int GetNumElementsPerPad();
	void SetNumElementsPerPad(int val);

	Motus_1_Platform();

	Motus_1_Platform(int sensorsPerPad);

	Motus_1_Platform(SingularSensingElement defaultValues, int sensorsPerPad = 1);

	int GetNumPads();

	void SetAllSensorElementValues(vector<int> values);

	Motus_1_MovementVector GetDirectionalVector();
};

class Motus_1_MovementVector
{
public:
	float VerticalComponent;
	float GetVerticalComponent();
	void SetVerticalComponent(float val);
	float LateralComponent;
	float GetLateralComponent();
	void SetLateralComponent(float val);

	Motus_1_MovementVector();

	float GetMagnitude();

	void Normalize();
};

class ArgumentException
{
public:
	ArgumentException(string arg1, string arg2)
	{
		Message = arg1;
		StackTrace = arg2;
	};

	string Message;
	string StackTrace;
};

class Exception
{
public:
	Exception(string arg1, string arg2)
	{
		Message = arg1;
		StackTrace = arg2;
	};

	string Message;
	string StackTrace;
};
