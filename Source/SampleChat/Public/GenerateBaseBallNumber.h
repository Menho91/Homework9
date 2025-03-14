#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GenerateBaseBallNumber.generated.h"

UCLASS()
class SAMPLECHAT_API UGenerateBaseBallNumber : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "BaseballGame")
	static FString GenerateBaseBall();
};
