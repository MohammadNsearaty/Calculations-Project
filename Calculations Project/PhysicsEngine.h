
#ifndef PhysicsEngine_H
#define PhysicsEngine_H
#pragma once
#include <vector>
#include "Shape.h"
#include "Plane.h"
using namespace std;

class PhysicsEngine {
private:
	vector<Shapes*> Objects;
	vector<Plane> planes;
	vector<Vector3f> forces;
public:
	PhysicsEngine();

	int getLength() { return Objects.size(); }

	Shapes* getElement(int i)
	{
		return Objects[i];
	}
	void addPlane(Plane plane);
	Plane getPlane(int i);
	void addForce(Vector3f force);
	Vector3f getForce(int i);
	int GetNumVector();

	Shapes* GetPhysicsObject(unsigned int pos);

	void AddObject(Shapes *obj);

	void Simulate(float alpha);
	
	void HandlerCollision();


};


void PhysicsEngine::HandlerCollision()
{
	for (auto x : Objects)
	{
		//Compare With The OTher Objects
		for (auto y : Objects)
		{
			if (x != y)
			{
				Collision_Data res1 = x->Collision(y);
				if (res1.getisCollision())
				{
					//handle The Collision  of the Object x with the object y
				}
			}
		}
		//Compare With The Palnes
		for (auto z : planes)
		{
			Collision_Data res2 = z.Collision_Plane(x);
			if (res2.getisCollision())
			{
				//handle the Collision of the Object x With Plane z

			}
		}
	}
}
void PhysicsEngine::addForce(Vector3f force)
{
	forces.push_back(force);
}
Vector3f PhysicsEngine::getForce(int i)
{
	return forces[i];
}

Plane PhysicsEngine::getPlane(int i)
{
	return planes[i];
}
    void PhysicsEngine::addPlane(Plane plane)
     {
		planes.push_back(plane);
     }
	PhysicsEngine::PhysicsEngine() {

	}


	int PhysicsEngine::GetNumVector() {

		return (unsigned int)Objects.size();
	}

	Shapes* PhysicsEngine::GetPhysicsObject(unsigned int pos) {
		return Objects[pos];
	}

	void PhysicsEngine::AddObject(Shapes* obj) {
		Objects.push_back(obj);
	}

	void PhysicsEngine::Simulate(float alpha) {

		//for (unsigned int i = 0; i < Objects.size(); i++) {
			Objects[0]->Integrate(alpha);
			Objects[1]->Integrate(alpha);

	//	}
	}




	
#endif // !PhysicsEngine_H
	