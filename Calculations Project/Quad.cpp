#include "Quad.h"

Quad::Quad() {
	this->Coordinates1 = 0;
	this->Coordinates2 = 0;
	this->Coordinates3 = 0;
	Color1 = 1.0f;
	Color2 = 1.0f;
	Color3 = 1.0f;
	NumRib = 0;
}

Quad::Quad(float H, float L, float W, float C1, float C2, float C3, int NumRib) {

	this->Coordinates1 = H;
	this->Coordinates2 = L;
	this->Coordinates3 = W;
	Color1 = C1;
	Color2 = C2;
	Color3 = C3;
	NumRib = NumRib;

}


void Quad::draw_2D(int x, int y) {
	glColor3d(Color1, Color2, Color3);
	glBegin(GL_QUADS);
	{
		glVertex2d(x, y);
		glVertex2d(-x, y);
		glVertex2d(-x, y + 2);
		glVertex2d(x, y + 2);
	}glEnd();

}

void Quad::draw_3D(int x, int y, int z) {


}

float Quad::Move_Shape(float S, float T, float M) {

	//A += S / T;

	return Accelerates;
}

void Quad::Collision2() {};