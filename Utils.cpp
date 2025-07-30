#include "Utils.h"
#include "Constants.h"

bool MathUtils::IsFuzzyNull(double d)
{
    return std::abs(d) <= Constants::LINEAR_TOLERANCE;
}

bool MathUtils::IsFromInterval(double start, double end, double value)
{
    return value >= start && value <= end;
}
