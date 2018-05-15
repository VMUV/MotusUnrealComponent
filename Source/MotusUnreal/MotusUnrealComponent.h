// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//#include "CoreMinimal.h"
//#include "Core.h"
#include "Engine.h"
#include "Components/ActorComponent.h"
#include "MotusComponent/MotusInput.h"
#include "MotusComponent/RotationTracker.h"
#include "MotusComponent/AutoOrienter.h"
#include "MotusUnrealComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MOTUSUNREAL_API UMotusUnrealComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMotusUnrealComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	MotusInput _motusInput;

	
};
