#pragma once

#include <iostream>
#include <string>
#include "Vector.h"
#include "Segment3D.h"
#include "SegmentsIntersector.h"

int main() {	
	Vector3D a(0.0, 0.0, 0.0), b(1.0, 0.0, 0.0);
	Vector3D c(0.0, 0.0, -1.0), d(0.0, 0.0, 1.0);

	Segment3D ab (a, b), cd(c, d);

	std::optional<Vector3D> optPoint = SegmentIntersector::Intersect(ab, cd);
	if (optPoint)
	{
		std::cout << *optPoint;
	}
	else {

		std::cout << "No intersection" << std::endl;
	}

	return 0;
}