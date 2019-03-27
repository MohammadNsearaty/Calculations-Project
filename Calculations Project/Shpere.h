#pragma once
#ifndef SHPERE_H
#define SHPERE_H

#include"Shape.h"


class Shpere : public Shapes {

private:
	GLUquadric *quadric1;
	float Radius;
	int Longitudes;
	int Latitudes;
	Vector3f Center;

public:
	Shpere();
	Shpere(GLUquadric *quadric, int x, int y, int z, float C1, float C2, float C3, float S, float T, float A, float M, Vector3f c);

	void Draw_Shpere();

	//TODO:The Virtual Function you must reDefine it in The subclass 
	void draw_2D(int x, int y);

	void draw_3D(int x, int y, int z);

	float Move_Shape(float S, float T, float M);
	Vector3f getVec() {



		return Center;

	}

	float getRadius() {

		return Radius;
	}


	Collision_Data Collision(Shpere other);
	void Collision2() {

	}
	



};
#endif // !SHPERE_H

