// Fill out your copyright notice in the Description page of Project Settings.

#include "RotationTracker.h"

RotationTracker::RotationTracker()
{
//	_quatRotation = new Quaternion(0, 0, 0, 1);
	_quatRotation = FQuat(0, 0, 0, 1);
}

RotationTracker::~RotationTracker()
{
}

void RotationTracker::UpdateRotation(FQuat rotation)
{
	_quatRotation = rotation;
}

void RotationTracker::UpdateRotation(FVector rotation)
{
//	_quatRotation = FQuat.Euler(rotation);
	_quatRotation = FQuat::MakeFromEuler(rotation);
}

FQuat RotationTracker::GetRotation()
{
	return _quatRotation;
}
