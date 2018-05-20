// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class AutoOrienter
{
public:
	AutoOrienter();
	~AutoOrienter();

private:
	bool _isOriented;

public:
	void Orient(FQuat rotation);

	void Orient(FVector rotation);

	bool IsOriented();
};
