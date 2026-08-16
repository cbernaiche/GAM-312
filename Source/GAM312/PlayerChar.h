// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "Resource_M.h"
#include "Kismet/GameplayStatics.h"
#include "BuildingPart.h"
#include "PlayerWidget.h"
#include "ObjectiveWidget.h"
#include "PlayerChar.generated.h"

UCLASS()
class GAM312_API APlayerChar : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerChar();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
	void MoveForward(float axisValue);

	UFUNCTION()
	void MoveRight(float axisValue);

	UFUNCTION()
	void StartJump();

	UFUNCTION()
	void StopJump();

	UFUNCTION()
	void FindObject();

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* PlayerCamComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Stats") //player stats bp
	float Health = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Stats") //player stats bp
	float Hunger = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Stats") //player stats bp
	float Stamina = 100.0f;

	UPROPERTY(EditAnywhere, Category = "Resources") //get wood
	int Wood;

	UPROPERTY(EditAnywhere, Category = "Resources") //get stone
	int Stone;

	UPROPERTY(EditAnywhere, Category = "Resources") //get berry
	int Berry;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Resources")
	TArray<int> ResourcesArray;

	UPROPERTY(EditAnywhere, Category = "Resources")
	TArray<FString> ResourcesNameArray;

	UPROPERTY(EditAnywhere, Category = "HitMarker")
	UMaterialInterface* hitDecal;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Building Supplies")
	TArray<int> BuildingArray;

	UPROPERTY()
	bool isBuilding;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TSubclassOf<AbuildingPart> BuildPartClass;

	UPROPERTY()
	AbuildingPart* spawnedPart;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UPlayerWidget* playerUI;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UObjectiveWidget* objWidget;

	UPROPERTY()
	float objectsBuilt;

	UPROPERTY()
	float matsCollected;

	UFUNCTION(BlueprintCallable) //callable bp function
	void SetHealth(float amount);

	UFUNCTION(BlueprintCallable) //callable bp function
	void SetHunger(float amount);

	UFUNCTION() //stats decrease
	void DecreaseStats();

	UFUNCTION(BlueprintCallable) //callable bp function
	void SetStamina(float amount);

	UFUNCTION()
	void GiveResource(float amount, FString resourceType);

	UFUNCTION(BlueprintCallable)
	void UpdateResources(float woodAmount, float stoneAmount, FString buildingObject);

	UFUNCTION(BlueprintCallable)
	void SpawnBuilding(int buildingID, bool& isSuccess);

	UFUNCTION()
	void RotateBuilding();

};
