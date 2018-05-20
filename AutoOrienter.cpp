// Fill out your copyright notice in the Description page of Project Settings.

#include "AutoOrienter.h"
#include "MotusInput.h"

AutoOrienter::AutoOrienter()
{
	_isOriented = false;
}

AutoOrienter::~AutoOrienter()
{
}

void AutoOrienter::Orient(FQuat rotation)
{
	FVector vect = MotusInput::GetNormalizedTranslation();
	//if (vect.magnitude != 0)
	//{
	//	MotusInput.SnapMotusToGameAxes(rotation);
	//	_isOriented = true;
	//}
}

void AutoOrienter::Orient(FVector rotation)
{
	FVector vect = MotusInput::GetNormalizedTranslation();
	//if (vect.magnitude != 0)
	//{
	//	MotusInput.SnapMotusToGameAxes(rotation);
	//	_isOriented = true;
	//}
}

bool AutoOrienter::IsOriented()
{
	return _isOriented;
}
