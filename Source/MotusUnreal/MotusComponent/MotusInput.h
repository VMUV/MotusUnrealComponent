// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Motus_1_Platform.h"

/**
 * 
 */
class MotusInput
{
public:
	MotusInput();
	~MotusInput();

private:
	static  Motus_1_MovementVector _vector;
	static  Motus_1_Platform _platform;
	static  FQuat _steeringOffset;
	static  FQuat _inGameOffset;
	static  FQuat _trim;
	static  bool _isMoving;
	static  bool _movingStateChange;


public:
	// Use this for initialization
	static void Start();
	static void Stop();

	// Update is called once per frame
	static int Update();

	static FVector GetNormalizedMotionVector();

	static float GetMotionMagnitude();


	//// Use this to get the _inGameOffset field applied to the motus
	//static FQuat GetInGameOffset();

	// Use this to get a normalized translation vector in the x & z plane
	static FVector GetNormalizedTranslation();

	// Use this to get a raw data object with all of the Motus-1 data fields
	static Motus_1_Platform GetRawDataObject();

	//// Use this to get the player rotation vector from your rotation tracker source
	//static FQuat GetPlayerRotation(FQuat rotationTracker);

	//// Use this method to get the easy mode algorithm to trim your motion vector
	//static FQuat GetTrim();

	//// Use this to get the player rotation vector from your rotation tracker source
	//static FQuat GetPlayerRotation(FVector rotationTracker);

	//// Use this to track player rotation when they are not moving
	//static void SetNewSteeringOffset(FQuat rotationTracker);

	//// Use this to track player rotation when they are not moving
	//static void SetNewSteeringOffset(FVector rotationTracker);

	//// if you are using GetPlayerRotation() instead
	//static FQuat GetSteeringOffset();

	//// Use this to calibrate the Motus to the game axes coordinate system
	//static void SnapMotusToGameAxes(FQuat rotationTracker);

	//// Use this to calibrate the Motus to the game axes coordinate system
	//static void SnapMotusToGameAxes(FVector rotationTracker);
};
