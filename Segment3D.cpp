#include "Segment3D.h"
#include "Constants.h"

Segment3D::Segment3D(Vector3D start, Vector3D end)
	: mStart(start), mEnd(end)
{
}

const Vector3D& Segment3D::start() const
{
	return mStart;
}

const Vector3D& Segment3D::end() const
{
	return mEnd;
}

double Segment3D::length() const
{
	return (mEnd - mStart).length();
}

Vector3D Segment3D::guidingVector() const
{
	return (mEnd - mStart).normalized();
}

bool Segment3D::areCollinear(const Segment3D& first, const Segment3D& second)
{
	auto firstGV = first.guidingVector();
	auto secondGV = second.guidingVector();

	double delta1 = firstGV.y() * secondGV.z() - secondGV.y() * firstGV.z();
	double delta2 = firstGV.x() * secondGV.z() - secondGV.x() * firstGV.z();
	double delta3 = firstGV.x() * secondGV.y() - secondGV.x() * firstGV.y();

	return
		(std::abs(delta1) < Constants::LINEAR_TOLERANCE) &&
		(std::abs(delta2) < Constants::LINEAR_TOLERANCE) &&
		(std::abs(delta3) < Constants::LINEAR_TOLERANCE);
}