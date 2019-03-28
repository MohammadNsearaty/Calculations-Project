#include"Shpere.h"

Shpere::Shpere() {
	position.Set(0, 0, 0);
	Radius = 4;
	Longitudes = 32;
	Latitudes = 32;
	color.Set(0.0f, 0.0f, 0.0f);
	quadric1 = gluNewQuadric();
}
Shpere::Shpere(GLUquadric *quadric, float r,float x,float y,float z,float c1,float c2,float c3) {
	//Shapes(x, y, z, c1, c2, c3);
	Longitudes = 32;
	Latitudes = 32;
	position.Set(x, y, z);
	color.Set(c1, c2, c3);
	Radius = r;
	quadric1 = quadric;
}
void Shpere::Draw_Shpere() {

}
void Shpere::setRadius(float R)
{
	Radius = R;
}

void Shpere::draw_2D(int x, int y) { }

void Shpere::draw_3D() {
	glPushMatrix();
	{
		glColor3d(color.GetX(), color.GetY(), color.GetZ());
		glTranslatef(position.GetX(), position.GetY(), position.GetZ());
		gluSphere(quadric1, Radius, Longitudes, Latitudes);
	}
	glPopMatrix();
}

void Shpere::applyForce(Vector3f force) {
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
