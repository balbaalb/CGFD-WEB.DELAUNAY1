// Engine.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;
#include "Vector3D.h"
#include "DelaunayLifting.h"
int main(int argc, char* argv[])
{
	if (argc >= 7 && (argc % 2))
	{
		try
		{
			double x = 0;
			vector<Vector3D> input;
			int numPoints = argc / 2;
			cout << "numPoints = " << numPoints << endl;
			input.resize(numPoints);
			for (int i = 1; i < argc; ++i)
			{
				cout << " atof(argv[i]) = " << atof(argv[i]) << endl;
				if (i % 2)
				{
					x = atof(argv[i]);
				}
				else
				{
					double y = atof(argv[i]);
					int n = i / 2 - 1;
					input[n](0) = x;
					input[n](1) = y;
					cout << "Input[" << n << "] = (" << x << "," << y << ")" << endl;

				}
			}
			Triangulation triangulation = DelaunayLifting::Triangulate(input);
			triangulation.Draw("public/images/Triangulation.bmp");
			cout << "Triangulation bmp file is created successfully." << endl;
			return 0;
		}
		catch (char* e)
		{
			cout << "Error: " << e << endl;
		}
	}
	cout << "Not enough argc. argc = " << argc << endl;
	return 1;
}

