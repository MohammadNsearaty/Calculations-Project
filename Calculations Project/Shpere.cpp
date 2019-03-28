#include"Shpere.h"

Shpere::Shpere() {
	position.Set(0, 0, 0);
	length[0] = 4;
	Longitudes = 20;
	Latitudes = 20;
	color.Set(0.0f, 0.0f, 0.0f);
	quadric1 = gluNewQuadric();
}
Shpere::Shpere(GLUquadric *quadric, float r,float m,float x,float y,float z,float c1,float c2,float c3) {
	Longitudes = 20;
	Latitudes = 20;
	mass = m;
	position.Set(x, y, z);
	color.Set(c1, c2, c3);
	length[0] = r;
	quadric1 = quadric;
}
void Shpere::Draw_Shpere() {

}
void Shpere::setRadius(float R)
{
	length[0] = R;
}

void Shpere::draw_2D(int x, int y) { }

void Shpere::draw_3D() {
	glPushMatrix();
	{
		glColor3d(color.GetX(), color.GetY(), color.GetZ());
		glTranslatef(position.GetX(), position.GetY(), position.GetZ());
		gluSphere(quadric1, length[0], Longitudes, Latitudes);
		glColor3d(1, 1, 1);

	}
	glPopMatrix();
}



Collision_Data Shpere::Collision(Shapes* other) {


	//float RaduisDistance = Radius + other.Radius;
	//float CenterDistance = (other.getVec().Length() - Center.Length());
	//float distance = CenterDistance - RaduisDistance;

	//if (CenterDistance < RaduisDistance) {

	//	return(Collision_Data(distance, true));
	//}
	//else if (CenterDistance == RaduisDistance) {

	//	return(Collision_Data(distance, true));

	//}
	//else {
	//	return(Collision_Data(distance, false));
	//}

	//
	return Collision_Data(1,true);
}
