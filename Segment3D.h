#pragma once

#include "Vector.h"

class Segment3D
{
public:
	Segment3D(Vector3D start, Vector3D end);

	const Vector3D& start() const;
	const Vector3D& end() const;
	double length() const;
	Vector3D guidingVector() const;

	static bool areCollinear(const Segment3D& first, const Segment3D& second);

private:
	Vector3D mStart{};
	Vector3D mEnd{};
};
