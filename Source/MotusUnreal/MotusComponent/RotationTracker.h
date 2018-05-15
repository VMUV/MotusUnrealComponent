// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class RotationTracker
{
public:
	RotationTracker();
	~RotationTracker();

private:
//	static Quaternion _quatRotation;
	FQuat _quatRotation;

public:
//	static void UpdateRotation(Quaternion rotation);
	void UpdateRotation(FQuat rotation);

//	static void UpdateRotation(Vector3 rotation);
	void UpdateRotation(FVector rotation);

//	static Quaternion GetRotation();
	FQuat GetRotation();
};
