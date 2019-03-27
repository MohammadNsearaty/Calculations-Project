#pragma once
#ifndef CUBE_H
#define CUBE_H

#include"Shape.h"

class Cube : public Shapes {

private:
	GLUquadric *quadric1 = gluNewQuadric();
	float RadiusBase;
	float RadiusTop;
	float Height;
	int Longitudes;
	int Latitudes;

public:
	Cube();
	Cube(GLUquadric *quadric, float r1, float r2, float h, int L1, int L2, float C1, float C2, float C3);



	//TODO:The Virtual Function you must reDefine it in The subclass 
	void draw_2D(int x, int y);

	void draw_3D(int x, int y, int z);


	//TODO: To draw Cube
	void Draw_Cube();

	float Move_Shape(float S, float T, float M);


	void Collision2();



};
#endif // !CUBE_H

