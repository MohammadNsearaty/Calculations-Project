#ifndef SHAPE_INCLUDE_H
#define SHAPE_INCLUDE_H

#pragma once
#include <windows.h>		// Header File For Windows
#include <gl.h>			// Header File For The OpenGL32 Library
#include <glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <cmath>

#include "math3d.h"

#include "Collision_Data.h"


//Abstruct Class for shapes
class Shapes {
protected:

	
	//TODO:the main paramitives
	float Coordinates1;
	float Coordinates2;
	float Coordinates3;

	//TODO:the color paramitives (RGB)
	float Color1;
	float Color2;
	float Color3;

	//TODO:the paramivites for move
	float Accelerates;  // the value of increased of speed
	float Speed;
	float Time;
	float Mass;


public:
	Shapes(){
		this->Coordinates1 = 0;
		this->Coordinates2 = 0;
		this->Coordinates3 = 0;
		this->Color1 = 0.0f;
		this->Color2 = 0.0f;
		this->Color3 = 0.0f;
		this->Accelerates = 0.0f;
		this->Mass = 0.0f;
		this->Time = 0.0f;
		this->Speed = 0.0f;
	}
	Shapes(float Coordinates1, float Coordinates2, float Coordinates3, float Color1, float Color2, float Color3){
		this->Coordinates1 = Coordinates1;
		this->Coordinates2 = Coordinates2;
		this->Coordinates3 = Coordinates3;
		this->Color1 = Color1;
		this->Color2 = Color2;
		this->Color3 = Color3;
	}


	//TODO:To draw 2D shapes
	virtual void draw_2D(int x, int y) = 0;

	//TODO:To draw 3D shapes
	virtual void draw_3D(int x, int y, int z) = 0;

	//TODO:To move the Shapes
	virtual float Move_Shape( float S, float T, float M) = 0;

	//TODO:To Collision
	virtual void Collision2() = 0;


};
#endif // !1