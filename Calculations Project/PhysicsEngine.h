
#ifndef PhysicsEngine_H
#define PhysicsEngine_H
#pragma once
#include <vector>
#include "PhysicsObject.h"
#include "Shape.h"
using namespace std;

class PhysicsEngine {
private:
	vector<Shapes*> Objects;

public:
	PhysicsEngine();

	int getLength() { return Objects.size(); }

	Shapes* getElement(int i)
	{
		return Objects[i];
	}

	int GetNumVector();

	Shapes* GetPhysicsObject(unsigned int pos);

	void AddObject(Shapes *obj);

	void Simulate(float alpha);
	
	void HandlerCollision();


};

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

	void PhysicsEngine::HandlerCollision() {

	//	for (unsigned int i = 0; i < Objects.size(); i++) {
			
	//		for (unsigned int j = i+1; j < Objects.size(); j++) {

				Collision_Data data = Objects[0]->Collision(Objects[1]);
				if (data.getisCollision()) {
					Objects[0]->reverseSpeed(0.005,-0.005, 0.005);
					Objects[1]->reverseSpeed(-0.005, 0.005, 0.005);
				}
		//	}
		

	//	}

	}

	
#endif // !PhysicsEngine_H
	