#include "StrikeBallDecision.h"

const int32 NUMBER_BASEBALL_LENGTH = 3;

FString UStrikeBallDecision::PlayBaseballGame(FString Input, FString AnswerNumber)
{
	if (IsValidInput(Input))
	{
		return GameDecision(Input, AnswerNumber);
	}
	else
	{
		return FString("Out!");
	}
}

FString UStrikeBallDecision::GameDecision(FString& Numbers, FString AnswerNumber)
{
	FString Answer = " ";
	int32 StrikeCount = 0;
	int32 BallCount = 0;

	for (int32 i = 0; i < Numbers.Len(); i++)
	{
		int32 index = 0;
		if (AnswerNumber.FindChar(Numbers[i], index))
		{
			if (index == i)
			{
				StrikeCount++;
			}
			else
			{
				BallCount++;
			}
		}
	}

	if (StrikeCount > 0)
	{
		Answer += FString::Printf(TEXT("%d Strike"), StrikeCount);
		
		if (BallCount > 0)
		{
			Answer += FString::Printf(TEXT(" / %d Ball"), BallCount);
		}
	}
	else if (BallCount > 0)
	{
		Answer += FString::Printf(TEXT("%d Ball"), BallCount);

	}
	else
	{
		Answer += FString("Out!");
	}

	return Answer;
}

bool UStrikeBallDecision::IsValidInput(FString& Input)
{
	if (Input.Len() != NUMBER_BASEBALL_LENGTH)
	{
		return false;
	}

	if (Input.Contains(FString("0")))
	{
		return false;
	}

	if (TSet(Input).Num() != Input.Len())
	{
		return false;
	}
	
	if (!Input.IsNumeric())
	{
		return false;
	}

	return true;
}
