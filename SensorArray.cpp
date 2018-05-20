// SensorArray.cpp

#include "SensorArray.h"


SensorArray::SensorArray()
{
//	_sensors = new SingularSensingElement[1];
	_sensors.resize(1);

//	_sensors[0] = new SingularSensingElement();
}

SensorArray::SensorArray(int numElements)
{
//	_sensors = new SingularSensingElement[numElements];
//	for (int i = 0; i < numElements; i++)
//		_sensors[i] = new SingularSensingElement();
	_sensors.resize(numElements);
}

SensorArray::SensorArray(int numElements, SingularSensingElement defaultSettings)
{
//	_sensors = new SingularSensingElement[numElements];
//	for (int i = 0; i < numElements; i++)
//		_sensors[i] = new SingularSensingElement();
	_sensors.resize(numElements);
//	this.InitElementsWithDefaultValue(defaultSettings);
	InitElementsWithDefaultValue(defaultSettings);
}

// we explicitly define a copy constructor
SensorArray::SensorArray(const SensorArray &orig)
{
	_sensors = orig._sensors;
}

int SensorArray::GetNumberOfElements()
{
	return _sensors.size();
}

void SensorArray::InitElementsWithDefaultValue(SingularSensingElement defaultSettings)
{
//	foreach(SingularSensingElement sensor in _sensors)
//		sensor.Copy(defaultSettings);

	vector<SingularSensingElement>::iterator itr;
	for (itr = _sensors.begin(); itr != _sensors.end(); ++itr)
	{
		SingularSensingElement item = *itr;
		item.Copy(defaultSettings);
	}
}
void SensorArray::InitElementsWithDefaultValue(int numElements, SingularSensingElement defaultSettings)
{
	_sensors.resize(numElements);
	InitElementsWithDefaultValue(defaultSettings);
}

void SensorArray::InitElementWithDefaultValue(int elementNdx,
	SingularSensingElement defaultSettings)
{
	if (elementNdx > _sensors.size())
		throw IndexOutOfRangeException();
	else
		_sensors[elementNdx].Copy(defaultSettings);
}

vector<SingularSensingElement> SensorArray::GetAll()
{
	return _sensors;
}

SingularSensingElement SensorArray::GetAtIndex(int elementNdx)
{
	if (elementNdx > _sensors.size())
		throw IndexOutOfRangeException();
	else
		return _sensors[elementNdx];
}

vector<int> SensorArray::GetAllElementCurrentValues()
{
//	vector<int> rtn = new int[_sensors.size()];
	vector<int> rtn(_sensors.size());
	for (int i = 0; i < rtn.size(); i++)
		rtn[i] = _sensors[i].GetCurrentValue();
	return rtn;
}

vector<bool> SensorArray::GetAllElementIsActiveValues()
{
//	vector<bool> rtn = new bool[_sensors.size()];
	vector<bool> rtn(_sensors.size());
	for (int i = 0; i < rtn.size(); i++)
		rtn[i] = _sensors[i].GetIsActive();
	return rtn;
}

int SensorArray::GetSumOfAllElements()
{
	int rtn = 0;
//	foreach(SingularSensingElement element in _sensors)
//		rtn += element.CurrentValue;

	vector<SingularSensingElement>::iterator itr;
	for (itr = _sensors.begin(); itr != _sensors.end(); ++itr)
	{
		SingularSensingElement element = *itr;
		rtn += element.GetCurrentValue();
	}
	return rtn;
}

void SensorArray::SetElementValueAtIndex(int elementNdx, int val)
{
	if (elementNdx > _sensors.size())
		throw IndexOutOfRangeException();
	else
		_sensors[elementNdx].SetCurrentValue(val);
}

