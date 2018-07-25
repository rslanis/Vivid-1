#pragma once

#include "Face.h"
#include <vector>

using namespace std;

class Surf {
private:
	vector<Face> vecFaces;
	vector<Point> vecPoints;
	string label;
	float * OG_points; // the original points that we got as an input

	
	Surf(float ** inputPoints, vector<Face> vecFaces, vector<Point> vecPoints, float quan[], string label);
	//Tomer: TODO: add a copy c~tor
	
	void runVorn(float ** inputPoints); //Tomer: why do we need inputPoints?
	void clearFaces(bool mask[]);
public:
	Surf* create(float ** inputPoints, bool mask[], float quan[], string label);
	void smooth(); //smooth the surf
	void reduce(); //Tomer: to think about it, I think using exportReducedObj is not clear use
	void exportObj(string output);
	void exportReducedObj(string output, int repeat); //export obj after reduce, repeat is the amount of times reduce will be ran(1 is usally the best)
	
	// Tomer: Shoudn't this be private?
	void removePoints(); //clears all the points who arent used from the vecPoints
};
