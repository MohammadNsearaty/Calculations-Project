#pragma once
#ifndef CUBE_H
#define CUBE_H

#include"Shape.h"

class Cube : public Shapes {

private:
	GLUquadric *quadric1 = gluNewQuadric();
	float length;
	Vector3f edges[8];
public:
	Cube();
	Cube(GLUquadric *quadric, float l, float x, float y, float z, float c1, float c2, float c3);

	//TODO:The Virtual Function you must reDefine it in The subclass 
	void draw_2D(int x, int y);

	void draw_3D();
	void calcEdges();
	void applyForce(Vector3f force);
	Collision_Data Collision(Shapes* other);

	void Collision2();



};
#endif // !CUBE_H

