
#include "Plane.h"

//#include"Shpere.h"
Plane Plane::Normalized() {
	float magnitude = normal.Length();

	return Plane(normal / magnitude, length / magnitude);

}

Collision_Data Plane::Collision_Shpere_Plane(Shpere* s) {


	
	float distanceCentertoPlane = fabs(normal.Dot(s->getRadius()) + length);
//	float distanceCentertoPlane = fabs((normal.GetX()* s->getPostion().GetX() +  normal.GetY() * s->getPostion().GetY()  + normal.GetZ() * s->getPostion().GetZ() )+  length);
	float distanceShperetoplane = (distanceCentertoPlane - s->getRadius());
	if (distanceShperetoplane < 0) {
		Vector3f force2(0, 0.000001, 0);
		s->applyForce(force2);
		return Collision_Data(distanceShperetoplane, true);
	}
	else {
		Vector3f force2(0, -0.000001, 0);
		s->applyForce(force2);
		return Collision_Data(distanceShperetoplane, false);
	}

}
