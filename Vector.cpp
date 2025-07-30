#include "Vector.h"
#include "Utils.h"
#include <cmath>
#include <iostream>
#include <optional>

Vector3D::Vector3D(double X, double Y, double Z)
	: mX(X), mY(Y), mZ(Z)
{
}	

double Vector3D::x() const
{
	return mX;
}

double Vector3D::y() const
{
	return mY;
}

double Vector3D::z() const
{
	return mZ;
}

double Vector3D::length() const
{
	return sqrt(mX * mX + mY * mY + mZ * mZ);
}

double Vector3D::lengthSquared() const
{
	return mX * mX + mY * mY + mZ * mZ;
}

Vector3D Vector3D::normalized()
{
	double len = lengthSquared();

	if (MathUtils::IsFuzzyNull(len - 1.0))
		return *this;

	if (!MathUtils::IsFuzzyNull(len)) {
		len = sqrt(len);
		return Vector3D{ mX / len, mY / len, mZ / len };
	}

	return Vector3D{ 1.0, 0.0, 0.0 };
}

Vector3D Vector3D::operator+(const Vector3D& v2) const
{
	return Vector3D(mX + v2.mX, mY + v2.mY, mZ + v2.mZ);
}

Vector3D Vector3D::operator-(const Vector3D& v2) const
{
	return Vector3D(mX - v2.mX, mY - v2.mY, mZ - v2.mZ);
}

Vector3D Vector3D::operator*(double k) const
{
	return Vector3D(k * mX, k * mY, k * mZ);
}

std::ostream& operator<<(std::ostream& out, const Vector3D& vector3D)
{
	out << "[ " << vector3D.x() << ", " << vector3D.y() << ", " << vector3D.z() << " ]" << std::endl;
	return out;
}

double Vector3D::dotProduct(const Vector3D& v1, const Vector3D& v2)
{
	return v1.x() * v2.x() + v1.y() * v2.y() + v1.z() * v2.z();
}