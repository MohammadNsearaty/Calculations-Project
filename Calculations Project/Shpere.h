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

public:
	Shpere();
	Shpere(GLUquadric *quadric, float r,float x,float y,float z,float c1,float c2,float c3);

	void Draw_Shpere();

	//TODO:The Virtual Function you must reDefine it in The subclass 

	float getRadius() {
		return Radius;
	}
	void setRadius(float R);

	void draw_2D(int x, int y);



	void draw_3D();

	void applyForce(Vector3f force);

	Collision_Data Collision(Shapes* other);
	void Collision2() {

	}
	



};
#endif // !SHPERE_H

