#pragma once
#include <vector>
#include <iostream>
#include <optional>

class Vector3D
{
public:
	Vector3D() = default;
	Vector3D(double x, double y, double z);
	double x() const;
	double y() const;
	double z() const;

	double length() const;
	double lengthSquared() const;
	Vector3D normalized();
	Vector3D operator-(const Vector3D& v2) const;
	Vector3D operator+(const Vector3D& v2) const;
	Vector3D operator*(double k) const;
	friend std::ostream& operator<<(std::ostream& out, const Vector3D& vector3D);

	static double dotProduct(const Vector3D& v1, const Vector3D& v2);

private:
	double mX{ 0.0 };
	double mY{ 0.0 };
	double mZ{ 0.0 };
};