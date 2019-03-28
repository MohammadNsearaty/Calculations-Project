
#include "Plane.h"
//#include"Shpere.h"
Plane Plane::Normalized() {
	float magnitude = normal.Length();

	return Plane(normal / magnitude, length / magnitude);

}

Collision_Data Plane::Collision_Shpere_Plane(Shpere s) {

	float distanceCentertoPlane = fabs(normal.Dot(s.getRadius()) + length);
	float distanceShperetoplane = distanceCentertoPlane - s.getRadius();

		return Collision_Data(distanceShperetoplane, distanceShperetoplane < 0);

}
