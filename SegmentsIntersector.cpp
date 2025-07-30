#include "SegmentsIntersector.h"
#include "Utils.h"

namespace {
	double Det3x3(const Vector3D& iFirstRow, const Vector3D& iSecondRow, const Vector3D& iThirdRow) {
		double pos =
			iFirstRow.x() * iSecondRow.y() * iThirdRow.z() +
			iFirstRow.y() * iSecondRow.z() * iThirdRow.x() +
			iFirstRow.z() * iSecondRow.x() * iThirdRow.y();
		double neg =
			iFirstRow.z() * iSecondRow.y() * iThirdRow.x() +
			iFirstRow.x() * iSecondRow.z() * iThirdRow.y() +
			iFirstRow.y() * iSecondRow.x() * iThirdRow.z();

		return pos - neg;
	}

	double Det2x2(double a11, double a12, double a21, double a22) {
		return a11 * a22 - a12 * a21;
	}
}

std::optional<Vector3D> SegmentIntersector::Intersect(const Segment3D& segment1, const Segment3D& segment2)
{
	Vector3D firstGV = segment1.guidingVector();
	Vector3D secondGV = segment2.guidingVector();

	bool areOnTheSamePlane = MathUtils::IsFuzzyNull(Det3x3(segment2.start() - segment1.start(), firstGV, secondGV));
	if (!areOnTheSamePlane)
		return std::nullopt;

	//OX = u*OA + (1-u)*OB
	//OX = v+OC + (1-v)*OD

	bool areCollinear = Segment3D::areCollinear(segment1, segment2);
	if (areCollinear) {
		if (IsPointOnSegment(segment1, segment2.start()))
			return segment2.start();
		if (IsPointOnSegment(segment1, segment2.end()))
			return segment2.end();
		if (IsPointOnSegment(segment2, segment1.start()))
			return segment1.start();
		if (IsPointOnSegment(segment2, segment1.end()))
			return segment1.end();

		return std::nullopt;
	}

	double u{}, v{};


	Vector3D v1 = segment2.end() - segment1.end();
	Vector3D v2 = segment2.end() - segment2.start();
	Vector3D v3 = segment2.start() - segment1.end();
	Vector3D v4 = segment1.start() - segment1.end();

	if (double mainXYDet = Det2x2(v4.x(), v2.x(), v4.y(), v2.y()); !MathUtils::IsFuzzyNull(mainXYDet)) {
		u = Det2x2(v1.x(), v2.x(), v1.y(), v2.y()) / mainXYDet;
		v = Det2x2(v3.x(), v1.x(), v3.y(), v1.y()) / mainXYDet;
	}
	else if (double mainXZDet = Det2x2(v4.x(), v2.x(), v4.z(), v2.z()); !MathUtils::IsFuzzyNull(mainXZDet)) {
		u = Det2x2(v1.x(), v2.x(), v1.z(), v2.z()) / mainXZDet;
		v = Det2x2(v3.x(), v1.x(), v3.z(), v1.z()) / mainXZDet;

	}
	else if (double mainYZDet = Det2x2(v4.y(), v2.y(), v4.z(), v2.z()); !MathUtils::IsFuzzyNull(mainYZDet)) {
		u = Det2x2(v1.y(), v2.y(), v1.z(), v2.z()) / mainYZDet;
		v = Det2x2(v3.y(), v1.y(), v3.z(), v1.z()) / mainYZDet;
	}

	if (MathUtils::IsFromInterval(0.0, 1.0, u) && MathUtils::IsFromInterval(0.0, 1.0, v)) {
		return Vector3D(
			u * (segment1.start().x() - segment1.end().x()) + segment1.end().x(),
			u * (segment1.start().y() - segment1.end().y()) + segment1.end().y(),
			u * (segment1.start().z() - segment1.end().z()) + segment1.end().z()
		);
	}

	return std::nullopt;
}

bool SegmentIntersector::IsPointOnSegment(const Segment3D& segment, const Vector3D& e)
{
	Vector3D a(segment.start());
	Vector3D b(segment.end());

	Segment3D ae(a, e);
	Segment3D eb(e, b);

	if (MathUtils::IsFuzzyNull((ae.length() + eb.length()) - segment.length()))
		return true;

	return false;
}