
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
	vector<Vector3f> ForceList;

public:
	PhysicsEngine();

	int getLength() { return Objects.size(); }

	Shapes* getElement(int i)
	{
		return Objects[i];
	}
	void addPlane(Plane plane);
	Plane getPlane(int i);
	int GetNumVector();

	Shapes* GetPhysicsObject(unsigned int pos);

	void AddObject(Shapes *obj);

	void Simulate(float alpha);
	
	void HandlerCollisionWithPlane(PhysicsEngine ObjVec) ;

	void HandlerForce(Vector3f force, Vector3f force2, Vector3f force3);

	void AddForce(Vector3f force);

	void HandlerDraw(PhysicsEngine ObjVec);

	Vector3f GetForce(int i);


};


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

	void PhysicsEngine::HandlerForce(Vector3f force, Vector3f force2, Vector3f force3) {

		Objects[0]->applyForce(force);
		Objects[1]->applyForce(force2);
		Objects[2]->applyForce(force3);

	}


	void PhysicsEngine::HandlerCollisionWithPlane(PhysicsEngine ObjVec) {

		Collision_Data c1,c2,c3,c4,c5,c6;
		

		c1 = planes[0].Collision_Shpere_Plane(Objects[1]);
		c2 = planes[1].Collision_Shpere_Plane(Objects[1]);
		c3 = planes[2].Collision_Shpere_Plane(Objects[0]);
		c4 = planes[3].Collision_Shpere_Plane(Objects[0]);
		c5 = planes[4].Collision_Shpere_Plane(Objects[2]);
		c6 = planes[5].Collision_Shpere_Plane(Objects[2]);


			if (c2.getisCollision() || c1.getisCollision()) {
				Shapes* sh2 = ObjVec.getElement(1);

				float f2 = ForceList[1].GetY() * -1;

				ForceList[1].Set(0, f2, 0);

				sh2->reverseSpeed(1, -1, 1);


			}
		if (c3.getisCollision() || c4.getisCollision())
		{
			Shapes* sh1 = ObjVec.getElement(0);
			float f1 = ForceList[0].GetX() * -1;
			ForceList[0].Set(f1, 0, 0);
			sh1->reverseSpeed(-1, 1, 1);
		}
		if (c5.getisCollision() || c6.getisCollision())
		{
			Shapes* sh3 = ObjVec.getElement(2);
			float f3 = ForceList[2].GetZ() * -1;
			ForceList[0].Set(0, 0, f3);
			sh3->reverseSpeed(1, 1, -1);
		}
		


	}

	void PhysicsEngine::AddForce(Vector3f force) {

		ForceList.push_back(force);

	}

	Vector3f PhysicsEngine::GetForce(int i) {

		return ForceList[i];

	}

	void PhysicsEngine::HandlerDraw(PhysicsEngine ObjVec){
	
		for (int i = 0; i < ObjVec.getLength(); i++)
		{
			Shapes* sh = ObjVec.getElement(i);
			sh->draw_3D();
		}
	
	}





	
#endif // !PhysicsEngine_H
	