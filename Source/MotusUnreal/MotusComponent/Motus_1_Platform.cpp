// Motus_1_Platform.cpp

#include "Motus_1_Platform.h"
//#include "FPSCharacter.h"

Motus_1_Platform::Motus_1_Platform()
{
	SingularSensingElement defaultValues;
	defaultValues.SetUpperLimit(3300);
	defaultValues.SetLowerLimit(250);
	defaultValues.SetPctActiveThreshold(0.65f);
	defaultValues.SetActiveHigh(false);

	_numElementsPerPad = 1;
	_pads.resize(9);
	for (int i = 0; i < 8; i++)
		_pads[i].InitElementsWithDefaultValue(_numElementsPerPad, defaultValues);

	// special value for the center
	defaultValues.SetPctActiveThreshold(0.25f);
	_pads[8].InitElementsWithDefaultValue(_numElementsPerPad, defaultValues);
}

Motus_1_Platform::Motus_1_Platform(int sensorsPerPad)
{
	SingularSensingElement defaultValues;
	defaultValues.SetUpperLimit(3300);
	defaultValues.SetLowerLimit(250);
	defaultValues.SetPctActiveThreshold(0.65f);
	defaultValues.SetActiveHigh(false);

	_numElementsPerPad = sensorsPerPad;
	_pads.resize(9);
	for (int i = 0; i < 8; i++)
		_pads[i].InitElementsWithDefaultValue(_numElementsPerPad, defaultValues);

	// special value for the center
	defaultValues.SetPctActiveThreshold(0.25f);
	_pads[8].InitElementsWithDefaultValue(_numElementsPerPad, defaultValues);
}

Motus_1_Platform::Motus_1_Platform(SingularSensingElement defaultValues, int sensorsPerPad)
{
	_numElementsPerPad = sensorsPerPad;
	_pads.resize(9);
	for (int i = 0; i < 8; i++)
		_pads[i].InitElementsWithDefaultValue(_numElementsPerPad, defaultValues);

	// special value for the center
	defaultValues.SetPctActiveThreshold(0.25f);
	_pads[8].InitElementsWithDefaultValue(_numElementsPerPad, defaultValues);
}

int Motus_1_Platform::GetNumElementsPerPad()
{
	return _numElementsPerPad;
}
void Motus_1_Platform::SetNumElementsPerPad(int val)
{
	_numElementsPerPad = val;
}

int Motus_1_Platform::GetNumPads()
{
	return _pads.size();
}

void Motus_1_Platform::SetAllSensorElementValues(vector<int> values)
{
	int numValsNeeded = _pads.size() * _numElementsPerPad;
	if (values.size() != numValsNeeded)
		throw ArgumentException("Number of array elements not equal to number of elements present in internal structure SensorArray.", "values");
	else
	{
		int valNdx = 0;
		for (int i = 0; i < _pads.size(); i++)
		{
			for (int j = 0; j < _numElementsPerPad; j++)
				_pads[i].SetElementValueAtIndex(j, values[valNdx++]);
		}
	}
}

Motus_1_MovementVector Motus_1_Platform::GetDirectionalVector()
{
	// Assumes the center pad is the last pad (9)
	Motus_1_MovementVector rtn;

	// Check to see if any of the elements in the center pad are active
	if (_pads.size() != 9)
		throw new Exception("This algorithm assumes the number of SensoryArrays associated with the motus-1 device is 9.", "This exception should never be thrown, contact Arthur Woolsey at arthur.woolsey@vmuv.io");
	bool isCenterActive = (_pads[_pads.size() - 1].GetSumOfAllElements() > 0);

	if (isCenterActive)
	{
		// get each of the active values in each of the pads
		rtn.VerticalComponent = _pads[0].GetSumOfAllElements()
			+ (_pads[1].GetSumOfAllElements() * sin45)
			- (_pads[3].GetSumOfAllElements() * sin45)
			- _pads[4].GetSumOfAllElements()
			- (_pads[5].GetSumOfAllElements() * sin45)
			+ (_pads[7].GetSumOfAllElements() * sin45);

		rtn.LateralComponent = (_pads[1].GetSumOfAllElements() * sin45)
			+ _pads[2].GetSumOfAllElements()
			+ (_pads[3].GetSumOfAllElements() * sin45)
			- (_pads[5].GetSumOfAllElements() * sin45)
			- _pads[6].GetSumOfAllElements()
			- (_pads[7].GetSumOfAllElements() * sin45);
	}
	return rtn;
}


float Motus_1_MovementVector::GetVerticalComponent()
{
	return VerticalComponent;
}
void Motus_1_MovementVector::SetVerticalComponent(float val)
{
	VerticalComponent = val;
}
float Motus_1_MovementVector::GetLateralComponent()
{
	return LateralComponent;
}
void Motus_1_MovementVector::SetLateralComponent(float val)
{
	LateralComponent = val;
}

Motus_1_MovementVector::Motus_1_MovementVector()
{
	VerticalComponent = 0;
	LateralComponent = 0;
}

float Motus_1_MovementVector::GetMagnitude()
{
	return (float)sqrt(VerticalComponent * VerticalComponent +
		LateralComponent * LateralComponent);
}

void Motus_1_MovementVector::Normalize()
{
	float mag = GetMagnitude();
	if (mag != 0)
	{
		VerticalComponent = VerticalComponent / mag;
		LateralComponent = LateralComponent / mag;
	}
}

