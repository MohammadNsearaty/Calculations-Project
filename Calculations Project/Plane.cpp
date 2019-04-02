
#include "Plane.h"

//#include"Shpere.h"
Plane Plane::Normalized() {
	float magnitude = normal.Length();

	return Plane(normal / magnitude, length / magnitude);

}

Collision_Data Plane::Collision_Shpere_Plane(Shapes* s) {

	float dist = fabs(normal.Dot(s->getPostion())-length);
	
	float *len = s->getlength();
	float dist2 = dist - len[0];

	if (dist2 < 1e-6)
		return Collision_Data(dist2, true);
	return Collision_Data(dist2, false);
}

