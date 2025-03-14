#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "StrikeBallDecision.generated.h"

UCLASS()
class SAMPLECHAT_API UStrikeBallDecision : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "StrikeBall")
	static FString PlayBaseballGame(FString Input, FString AnswerNumber);

protected:
	static FString GameDecision(FString& Numbers, FString AnswerNumber);

	static bool IsValidInput(FString& Input);
};
