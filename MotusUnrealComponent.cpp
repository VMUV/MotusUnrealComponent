// Fill out your copyright notice in the Description page of Project Settings.

#include "MotusUnrealComponent.h"


// Sets default values for this component's properties
UMotusUnrealComponent::UMotusUnrealComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMotusUnrealComponent::BeginPlay()
{
	Super::BeginPlay();

	//Call to initialize the Motus controller
	_motusInput.Start();

	// ...
	
}

void UMotusUnrealComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	//Call to cleanup the Motus controller
	_motusInput.Stop();

}


// Called every frame
void UMotusUnrealComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	AActor* owner = GetOwner();
	ACharacter* character = Cast<ACharacter>(owner);
	if (character) {

		float Value = 10.0;
		FRotator newRotation = FRotator(0, 0, 0);
		bool bsweep = true;

//		Super::Tick(DeltaTime);

		UCharacterMovementComponent* characterMovementComponent = character->GetCharacterMovement();
		if (characterMovementComponent) {

			int errorcount = _motusInput.Update();
			if (errorcount > 0) {
				if (GEngine)
				{
					// Put up a debug message for five seconds. The -1 "Key" value (first argument) indicates that we will never need to update or refresh this message.
					GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, TEXT("  _motusInput.Update() returned errors"));
				}
			}

			////		FVector trans = _motusInput.GetNormalizedTranslation();
			FVector trans = _motusInput.GetNormalizedMotionVector();
			float _value = _motusInput.GetMotionMagnitude();

			// for the test, we would be getting a magnitude of 0 to 4096
			// so we need to normalize that to be from 0 to 10
			//		Value = (_value*10.0) / 4096.0;
			Value = (_value*20.0) / 4000.0;

			////		FQuat tracker = _rotationTracker.GetRotation();

			////		if (!_autoOrienter.IsOriented())
			////			_autoOrienter.Orient(tracker);

			//		//if (trans.magnitude == 0.0f)
			//		if (trans.Size() == 0.0f)
			////			_motusInput.SetNewSteeringOffset(tracker);

			////		FQuat rot = _motusInput.GetPlayerRotation(tracker);

			FRotator frot = character->Controller->GetControlRotation();
			FQuat rot = FQuat(frot);
			//		FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);


			////		trans = _motusInput.GetTrim() * trans;
			trans = rot * trans;
			//		//trans *= speedMultiplier;
			//		//trans += FVector(0, -1 * playerGravity, 0);
			//
			//		// only do something if player is moving
			//		if (trans.Size() != 0) {
			if (Value > 0) {
				//	if (playerController.isGrounded)
				if (characterMovementComponent->IsMovingOnGround())
				{
					//playerController.Move(trans * Time.deltaTime);
					//player.transform.localRotation = new Quaternion(0, 0, 0, 1);
					character->AddMovementInput(trans, Value);
					FVector delta = character->ConsumeMovementInputVector();
					characterMovementComponent->MoveUpdatedComponent(delta, newRotation, bsweep);
					if (GEngine)
					{
						// Put up a debug message for five seconds. The -1 "Key" value (first argument) indicates that we will never need to update or refresh this message.
						GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, TEXT("FPSCharacter Tick: move trans"));
					}
				}
				else
				{
					// I think this is done automagically
					//makePlayerFall();
				}
			}

		}
	}
	// ...
}

