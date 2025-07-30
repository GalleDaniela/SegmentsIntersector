#pragma once

#include <cmath>

class MathUtils
{
	MathUtils() = delete;

public:
	static bool IsFuzzyNull(double d);
	static bool IsFromInterval(double start, double end, double value);
};