// SingularSensingElement.cpp

#include "SingularSensingElement.h"


SingularSensingElement::SingularSensingElement()
{
	_upperLimit = 4096;
	_lowerLimit = 0;
	_pctActiveThreshold = 0.5f;
	_currentValue = _lowerLimit;
	_isActive = false;
	_activeHigh = true;
}
// copy constructor is automatically created
// SingularSensingElement::SingularSensingElement(const SingularSensingElement &element);

int SingularSensingElement::GetUpperLimit()
{
	return _upperLimit;
}
void SingularSensingElement::SetUpperLimit(int val)
{
	_upperLimit = val;
}

int SingularSensingElement::GetLowerLimit()
{
	return _lowerLimit;
}
void SingularSensingElement::SetLowerLimit(int val)
{
	_lowerLimit = val;
}

float SingularSensingElement::GetPctActiveThreshold()
{
	return _pctActiveThreshold;
}
void SingularSensingElement::SetPctActiveThreshold(float val)
{
	_pctActiveThreshold = val;
}

bool SingularSensingElement::GetIsActive()
{
	return _isActive;
}

bool SingularSensingElement::GetActiveHigh()
{
	return _activeHigh;
}
void SingularSensingElement::SetActiveHigh(bool val)
{
	_activeHigh = val;
}

int SingularSensingElement::GetCurrentValue()
{
	return _currentValue;
}
void SingularSensingElement::SetCurrentValue(int value)
{
	_currentValue = value;
	if (_currentValue < _lowerLimit)
		_currentValue = _lowerLimit;
	else if (_currentValue > _upperLimit)
		_currentValue = _upperLimit;

	int normalizedVal = _currentValue - _lowerLimit;
	float normalizedPct = (float)(normalizedVal) / ((float)(_upperLimit - _lowerLimit));

	if (_activeHigh)
	{
		if (normalizedPct >= _pctActiveThreshold)
			_isActive = true;
		else
			_isActive = false;
	}
	else
	{
		// invert everything for active low
		float invertedPct = 1.0f - normalizedPct;
		_currentValue = _upperLimit - _currentValue;
		if (invertedPct >= _pctActiveThreshold)
			_isActive = true;
		else
			_isActive = false;
	}

	if (!_isActive)
		_currentValue = 0;
}

void SingularSensingElement::Copy(SingularSensingElement element)
{
	_currentValue = element.GetCurrentValue();
	_upperLimit = element.GetUpperLimit();
	_lowerLimit = element.GetLowerLimit();
	_pctActiveThreshold = element.GetPctActiveThreshold();
	_isActive = element.GetIsActive();
	_activeHigh = element.GetActiveHigh();
}

SingularSensingElement* SingularSensingElement::Get()
{
	return this;
}

