#include "GenerateBaseBallNumber.h"

const int32 NUMBER_BASEBALL_LENGTH = 3;

FString UGenerateBaseBallNumber::GenerateBaseBall()
{
	FString BaseballNumber = "";

	while (BaseballNumber.Len() < NUMBER_BASEBALL_LENGTH)
	{
		FString NewNum = FString::FromInt(FMath::RandRange(1, 9));
		if (BaseballNumber.Contains(NewNum))
		{
			continue;
		}
		else
		{
			BaseballNumber += NewNum;
		}
	}

	return BaseballNumber;
}
