// SensorArray.h

#pragma once

#include <vector>

#include "SingularSensingElement.h"

using namespace std;

class SensorArray
{
private:
	vector<SingularSensingElement> _sensors;

public:
	SensorArray();

	// we explicitly define a copy constructor
	SensorArray(const SensorArray &orig);

	SensorArray(int numElements);

	SensorArray(int numElements, SingularSensingElement defaultSettings);

	int GetNumberOfElements();

	void InitElementsWithDefaultValue(SingularSensingElement defaultSettings);
	void InitElementsWithDefaultValue(int numElements, SingularSensingElement defaultSettings);

	void InitElementWithDefaultValue(int elementNdx, SingularSensingElement defaultSettings);

	vector<SingularSensingElement> GetAll();

	SingularSensingElement GetAtIndex(int elementNdx);

	vector<int> GetAllElementCurrentValues();

	vector<bool> GetAllElementIsActiveValues();

	int GetSumOfAllElements();

	void SetElementValueAtIndex(int elementNdx, int val);
};

class IndexOutOfRangeException
{
public:
	IndexOutOfRangeException()
	{
	};
	IndexOutOfRangeException(string arg1, string arg2)
	{
		Message = arg1;
		StackTrace = arg2;
	};

	string Message;
	string StackTrace;
};
