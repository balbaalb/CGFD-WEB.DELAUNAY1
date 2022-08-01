#include "EngineInterface.h"
#include <vector>
#include <string>
using namespace std;
#include "Vector3D.h"
#include "DelaunayLifting.h"
int EngineInterface(std::string input)
{
	bool go_on = true;
	vector<double> Coords;
	while(go_on)
	{
		std::size_t found = input.find(",");
		double coord = 0;
		if (found != std::string::npos)
		{
			string coordStr = input.substr(0,found);
			coord = atof(coordStr.c_str());
			input.erase(0,found + 1);
		}
		else{
			coord = atof(input.c_str());
			go_on = false;
		}
		Coords.push_back(coord);
	}
	int numCoords = Coords.size();
	if (numCoords >= 6 && !(numCoords % 2))
	{
		try
		{
			double x = 0;
			vector<Vector3D> inputPoints;
			int numPoints = numCoords / 2;
			inputPoints.resize(numPoints);
			for (int i = 0; i < numCoords; ++i)
			{
				if (!(i % 2))
				{
					x = Coords[i];
				}
				else
				{
					double y = Coords[i];
					int n = (i - 1) / 2;
					inputPoints[n](0) = x;
					inputPoints[n](1) = y;
				}
			}
			Triangulation triangulation = DelaunayLifting::Triangulate(inputPoints);
			triangulation.Draw("public/images/Triangulation.bmp");
		}
		catch (char* e)
		{
			return -1;
		}
	}
	else{
		return -2;
	}
	return numCoords;
}