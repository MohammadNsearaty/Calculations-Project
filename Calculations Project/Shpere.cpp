#include"Shpere.h"

Shpere::Shpere() {
	this->Coordinates1 = 0;
	this->Coordinates2 = 0;
	this->Coordinates3 = 0;
	Radius = 4;
	Longitudes = 32;
	Latitudes = 32;
	Color1 = 1;
	Color2 = 1;
	Color3 = 1;
	quadric1 = gluNewQuadric();
	Center = 0;
}
Shpere::Shpere(GLUquadric *quadric, int x, int y, int z, float C1, float C2, float C3, float S, float T, float A, float M, Vector3f c) {
	Coordinates1 = 0;
	Coordinates2 = 0;
	Coordinates3 = 0;
	Color1 = C1;
	Color2 = C2;
	Color3 = C3;
	Radius = x;
	Longitudes = y;
	Latitudes = z;
	quadric1 = quadric;
	Accelerates = A;
	Speed = S;
	Mass = M;
	Time = T;
	//Center[0] = c[0];
	//Center[1] = c[1];
	//Center[2] = c[2];
	Center = c;
}
void Shpere::Draw_Shpere() {

	glPushMatrix();
	{
		glColor3d(Color1, Color2, Color3);
		glTranslatef(Center[0], Center[1], Center[2]);
		gluSphere(quadric1, Radius, Longitudes, Latitudes);

	}
	glPopMatrix();
}

void Shpere::draw_2D(int x, int y) { }

void Shpere::draw_3D(int x, int y, int z) { }

float Shpere::Move_Shape(float S, float T, float M) {


	Speed = S;
	Time = T;
	Mass = M;
	Accelerates += Speed / Time;

	return Accelerates;

}

Collision_Data Shpere::Collision(Shpere other) {


	float RaduisDistance = Radius + other.Radius;
	float CenterDistance = (other.getVec().Length() - Center.Length());
	float distance = CenterDistance - RaduisDistance;

	if (CenterDistance < RaduisDistance) {

		return(Collision_Data(distance, true));
	}
	else if (CenterDistance == RaduisDistance) {

		return(Collision_Data(distance, true));

	}
	else {
		return(Collision_Data(distance, false));
	}

	
}
