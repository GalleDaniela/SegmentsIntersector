#pragma once

#include <optional>
#include "Vector.h"
#include "Segment3D.h"

class SegmentIntersector {
public:
	static std::optional<Vector3D> Intersect(const Segment3D& segment1, const Segment3D& segment2);
	static bool IsPointOnSegment(const Segment3D& segment, const Vector3D& e);
};

