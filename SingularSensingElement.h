// SingularSensingElement.h

#pragma once

class SingularSensingElement
{
private:
	int _currentValue;
	int _upperLimit;
	int _lowerLimit;
	float _pctActiveThreshold;
	bool _isActive;
	bool _activeHigh;

public:
	int GetUpperLimit();
	void SetUpperLimit(int val);

	int GetLowerLimit();
	void SetLowerLimit(int val);

	float GetPctActiveThreshold();
	void SetPctActiveThreshold(float val);

	bool GetIsActive();

	bool GetActiveHigh();
	void SetActiveHigh(bool val);

	SingularSensingElement();	// default constructor

	// copy constructor is automatically created
	// SingularSensingElement(const SingularSensingElement &element);

	int GetCurrentValue();
	void SetCurrentValue(int val);

	void Copy(SingularSensingElement element);

	SingularSensingElement* Get();
};

