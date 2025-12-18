#pragma once

#include "CoreMinimal.h"

#include "NvCTypes.h"

DECLARE_LOG_CATEGORY_EXTERN(LogBlast, Log, All);

FORCEINLINE NvcQuat ToNvQuat(const FQuat& Quat)
{
	return { static_cast<float>(Quat.X), static_cast<float>(Quat.Y), static_cast<float>(Quat.Z), static_cast<float>(Quat.W) };
}

FORCEINLINE NvcQuat ToNvQuat(const FQuat4f& Quat)
{
	return { Quat.X, Quat.Y, Quat.Z, Quat.W };
}

FORCEINLINE NvcVec3 ToNvVector(const FVector& Vec)
{
	return { static_cast<float>(Vec.X), static_cast<float>(Vec.Y), static_cast<float>(Vec.Z) };
}

FORCEINLINE NvcVec3 ToNvVector(const FVector3f& Vec)
{
	return { Vec.X, Vec.Y, Vec.Z };
}

FORCEINLINE NvcVec2 ToNvVector(const FVector2f& Vec)
{
	return { Vec.X, Vec.Y };
}

FORCEINLINE void ToNvPlane4(const FPlane& Plane, float OutPlane[4])
{
	OutPlane[0] =  static_cast<float>(Plane.X);
	OutPlane[1] =  static_cast<float>(Plane.Y);
	OutPlane[2] =  static_cast<float>(Plane.Z);
	OutPlane[3] =  -static_cast<float>(Plane.W);
}

FORCEINLINE void ToNvPlane4(const FPlane4f& Plane, float OutPlane[4])
{
	OutPlane[0] =  Plane.X;
	OutPlane[1] =  Plane.Y;
	OutPlane[2] =  Plane.Z;
	OutPlane[3] =  -Plane.W;
}

FORCEINLINE FVector FromNvVector(const NvcVec3& Vec)
{
	return { static_cast<double>(Vec.x), static_cast<double>(Vec.y), static_cast<double>(Vec.z) };
}

FORCEINLINE FVector FromNvVector(const float Vec[3])
{
	return { static_cast<double>(Vec[0]), static_cast<double>(Vec[1]), static_cast<double>(Vec[2]) };
}

FORCEINLINE FPlane FromNvPlane4(float Plane[4])
{
	return { static_cast<double>(Plane[0]), static_cast<double>(Plane[1]), static_cast<double>(Plane[2]), -static_cast<double>(Plane[3]) };
}

FORCEINLINE FPlane4f FromNvPlane4f(float Plane[4])
{
	return { Plane[0], Plane[1], Plane[2], -Plane[3] };
}
