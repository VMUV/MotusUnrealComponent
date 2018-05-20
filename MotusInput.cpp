// Fill out your copyright notice in the Description page of Project Settings.

#include "MotusInput.h"
#include "Motus1.h"


Motus_1_MovementVector MotusInput::_vector;
Motus_1_Platform MotusInput::_platform;
FQuat MotusInput::_steeringOffset    = FQuat(0, 0, 0, 1);
FQuat MotusInput::_inGameOffset      = FQuat(0, 0, 0, 1);
FQuat MotusInput::_trim              = FQuat(0, 0, 0, 1);
bool  MotusInput::_isMoving          = false;
bool  MotusInput::_movingStateChange = false;

MotusInput::MotusInput()
{
//	_platform = new Motus_1_Platform();
}


MotusInput::~MotusInput()
{
}

// Use this for initialization
void MotusInput::Start()
{
	Motus1::Initialize();
}
void MotusInput::Stop()
{
	Motus1::Terminate();
}

// Update is called once per frame
// returns error count
int MotusInput::Update()
{
	int errorcount = Motus1::Service();
	_vector = Motus1::GetMotionVector();
//	_platform = Motus1.GetRawPlatformData();
	return errorcount;
}

// returns a 3 dimensional vector representing the direction indicated
// by the players position on the motus. Z is always set to 0.
// if no clear direction can be determined - i.e the player is entirely
// on the center pad, the returned vector is set to all 0s.
FVector MotusInput::GetNormalizedMotionVector()
{
	// return normalized vector in direction player wants to move
	FVector Direction = FVector(0, 0, 0);	// 0 implies no motion

	Direction.X = _vector.GetVerticalComponent();
	Direction.Y = _vector.GetLateralComponent();
	float mag = _vector.GetMagnitude();
	if (mag != 0) {
		Direction.X /= mag;
		Direction.Y /= mag;
	}

	return Direction;
}

// returns a value reminescent of the amount of pressure on the pad in
// the direction indicated in _my_motusInput_GetNormalizedMotionVector(),
// the value is set to 0 when no clear direction can be determined.
float MotusInput::GetMotionMagnitude()
{
	return _vector.GetMagnitude();
}

//// Use this to get the _inGameOffset field applied to the motus
//FQuat MotusInput::GetInGameOffset()
//{
//	return _inGameOffset;
//}

// Use this to get a normalized translation vector in the x & z plane
FVector MotusInput::GetNormalizedTranslation()
{
	FVector rtn = FVector(0, 0, 0);		// temporary - remove when done
	//Motus_1_MovementVector local = _vector;
	//local.Normalize();
	//FVector rtn = FVector(local.LateralComponent, 0f, local.VerticalComponent);

	if (rtn.Size() != 0)
	{
		if (!_isMoving)
		{
			_movingStateChange = true;
			_isMoving = true;
		}
	}
	else
	{
		if (_isMoving)
		{
			_movingStateChange = true;
			_isMoving = false;
		}
	}

	return rtn;
}

// Use this to get a raw data object with all of the Motus-1 data fields
Motus_1_Platform MotusInput::GetRawDataObject()
{
	return _platform;
}

//// Use this to get the player rotation vector from your rotation tracker source
//FQuat MotusInput::GetPlayerRotation(FQuat rotationTracker)
//{
//	FQuat rtn = FQuat(0, 0, 0, 1);
//
//	//FVector rotationTrackerEuler = rotationTracker.eulerAngles;
//	FVector rotationTrackerEuler = rotationTracker.Euler();
//
//	rotationTrackerEuler.X = 0;
//	rotationTrackerEuler.Z = 0;
//
//	//rotationTracker = FQuat.Euler(rotationTrackerEuler);
////	rotationTracker = rotationTracker.MakeFromEuler(rotationTrackerEuler);
//	rotationTracker = FQuat::MakeFromEuler(rotationTrackerEuler);
//
//	FQuat steering = rotationTracker * _steeringOffset;
//	rtn = _inGameOffset * steering;
//	return rtn;
//}
//
//// Use this method to get the easy mode algorithm to trim your motion vector
//FQuat MotusInput::GetTrim()
//{
//	if (_movingStateChange)
//	{
//		_movingStateChange = false;
//
//		if (_isMoving)
//		{
////			Motus_1_MovementVector local = _vector;
////			local.Normalize();
////			FVector trans = new FVector(local.LateralComponent, 0f, local.VerticalComponent);
////			FQuat motusRot = _inGameOffset * FQuat.LookRotation(trans);
////			FQuat deltaQuat = motusRot * GetSteeringOffset();
////			float delta = deltaQuat.eulerAngles.y;
////			if (delta > 180f)
////				delta -= 360f;
////			if (Mathf.Abs(delta) <= 65f)
////				_trim = FQuat.Euler(0f, -delta, 0f);
////			else
////				_trim = FQuat.Euler(0f, 0f, 0f);
//		}
////		else
////			_trim = FQuat.Euler(0f, 0f, 0f);
//	}
//
//	return _trim;
//}
//
//// Use this to get the player rotation vector from your rotation tracker source
//FQuat MotusInput::GetPlayerRotation(FVector rotationTracker)
//{
//	//	return GetPlayerRotation(FQuat.Euler(rotationTracker));
//	return GetPlayerRotation(FQuat::MakeFromEuler(rotationTracker));
//}
//
//// Use this to track player rotation when they are not moving
//void MotusInput::SetNewSteeringOffset(FQuat rotationTracker)
//{
//	//FVector rotationTrackerEuler = rotationTracker.eulerAngles;
//	FVector rotationTrackerEuler = rotationTracker.Euler();
//	rotationTrackerEuler.X = 0;
//	rotationTrackerEuler.Z = 0;
//	//_steeringOffset = FQuat.Euler(rotationTrackerEuler);
//	_steeringOffset = FQuat::MakeFromEuler(rotationTrackerEuler);
//	//_steeringOffset = FQuat.Inverse(_steeringOffset);
//	_steeringOffset = _steeringOffset.Inverse();
//}
//
//// Use this to track player rotation when they are not moving
//void MotusInput::SetNewSteeringOffset(FVector rotationTracker)
//{
////	SetNewSteeringOffset(FQuat.Euler(rotationTracker));
//	SetNewSteeringOffset(FQuat::MakeFromEuler(rotationTracker));
//}
//
//// Use this to get the player's steering offset only -- do not use this
//// if you are using GetPlayerRotation() instead
//FQuat MotusInput::GetSteeringOffset()
//{
//	return _inGameOffset * _steeringOffset;
//}
//
//// Use this to calibrate the Motus to the game axes coordinate system
//void MotusInput::SnapMotusToGameAxes(FQuat rotationTracker)
//{
////	FVector rotationTrackerEuler = rotationTracker.eulerAngles;
//	FVector rotationTrackerEuler = rotationTracker.Euler();
//	rotationTrackerEuler.X = 0;
//	rotationTrackerEuler.Z = 0;
////	rotationTracker = FQuat.Euler(rotationTrackerEuler);
//	rotationTracker = FQuat::MakeFromEuler(rotationTrackerEuler);
//	FVector vect = GetNormalizedTranslation();
////	FQuat latchPadOffset = FQuat.LookRotation(vect);
////	_inGameOffset = rotationTracker * FQuat.Inverse(latchPadOffset);
//}
//
//// Use this to calibrate the Motus to the game axes coordinate system
//void MotusInput::SnapMotusToGameAxes(FVector rotationTracker)
//{
////	SnapMotusToGameAxes(FQuat.Euler(rotationTracker));
//	SnapMotusToGameAxes(FQuat::MakeFromEuler(rotationTracker));
//}
