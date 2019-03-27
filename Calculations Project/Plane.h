#ifndef PLANE_H
#define PLANE_H
#pragma once
#include "math3d.h"
#include "Shape.h"
#include"Shpere.h"


class Plane {

private:
	Vector3f Normal;
	float Distance;

public:
	Plane() {
		Normal = 0.0f;
		Distance = 0.0f;
	}
	Plane(Vector3f normal, float distance)
	{
		Normal = normal;
		Distance = distance;
	}

	Vector3f GetNormal(){return Normal;}

	float GetDistance(){
		return Distance;
	}

	Plane Normalized();
    Collision_Data Collision_Shpere_Plane(Shpere s); 


};



#endif 
