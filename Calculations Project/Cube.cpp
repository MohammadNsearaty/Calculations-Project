#include "Cube.h"

Cube::Cube() {
	quadric1 = gluNewQuadric();
	RadiusBase = 2;
	RadiusTop = 2;
	Height = 2;
	Longitudes = 32;
	Latitudes = 32;
	Color1 = 1;
	Color2 = 1;
	Color3 = 1;
}
Cube::Cube(GLUquadric *quadric, float r1, float r2, float h, int L1, int L2, float C1, float C2, float C3) {
	quadric1 = quadric;
	RadiusBase = r1;
	RadiusTop = r2;
	Height = h;
	Longitudes = L1;
	Latitudes = L2;
	Color1 = C1;
	Color2 = C2;
	Color3 = C3;
}



//TODO:The Virtual Function you must reDefine it in The subclass 
void Cube::draw_2D(int x, int y) { }

void Cube::draw_3D(int x, int y, int z) { }


//TODO: To draw Cube
void Cube::Draw_Cube() {
	glColor3d(Color1, Color2, Color3);
	gluCylinder(quadric1, RadiusBase, RadiusTop, Height, Longitudes, Latitudes);

}

float Cube::Move_Shape(float S, float T, float M) {

	Speed = S;
	Time = T;
	Mass = M;
	Accelerates += Speed / Time;
	return Accelerates;



}


void Cube::Collision2() {

}