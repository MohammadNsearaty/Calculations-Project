#include "Cube.h"
#include "Shape.h"
Cube::Cube() {
	Shapes();
	quadric1 = gluNewQuadric();
	length = 1;
}
Cube::Cube(GLUquadric *quadric, float l,float x,float y,float z,float c1,float c2,float c3) {
	Shapes(x,y,z,c1,c2,c3);
	quadric1 = quadric;
	length = l;
}



//TODO:The Virtual Function you must reDefine it in The subclass 
void Cube::draw_2D(int x, int y) { }

void Cube::draw_3D() { }


//TODO: To draw Cube
void Cube::Draw_Cube() {
	//glColor3d(color.GetX(), color.GetY(), color.GetZ());
//	gluCylinder(quadric1, RadiusBase, RadiusTop, Height, Longitudes, Latitudes);

}

void Cube::applyForce(Vector3f force) {
}

Collision_Data Cube::Collision(Shapes* other)
{
	return Collision_Data(1, true);
}

void Cube::Collision2() {

}