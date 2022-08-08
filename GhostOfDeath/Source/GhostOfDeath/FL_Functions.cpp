// Fill out your copyright notice in the Description page of Project Settings.


#include "FL_Functions.h"

/*
* Returns a relative Location vector that bobs up and down on the Z axis over time.
*/
FVector UFL_Functions::GetBobbingLocation(float timeSinceStart, float bobbingSpeed, float bobbingHeight)
{
	FVector bobbingLocation = FVector(0.0f, 0.0f, 0.0f);
	bobbingLocation.Z = FMath::Cos(timeSinceStart * bobbingSpeed) * bobbingHeight;
	return bobbingLocation;
}

/*
* Returns a relative Scale vector that flips the X axis depending on the velocity's X direction.
*/
FVector UFL_Functions::FlipScaleWithMovement(FVector velocity, FVector originalScale)
{
	FVector scale = originalScale;
	if (velocity.X > 0) {
		scale.X = FMath::Abs(scale.X);
	}
	else if (velocity.X < 0) {
		scale.X = -FMath::Abs(scale.X);
	}
	return scale;
}

/*
* Returns a Unit Vector pointing from "from" to "to" that ignores difference in Y values.
*/
FVector UFL_Functions::GetUnitDirectionXZ(FVector from, FVector to)
{
	from.Y = 0.0f;
	to.Y = 0.0f;
	FVector direction = to - from;
	direction.Normalize();
	return direction;
}
