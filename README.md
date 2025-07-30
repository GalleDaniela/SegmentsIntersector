Есть класс трёхмерного вектора и трёхмерного отрезка, заданного двумя Vector3D:

class Vector3D
{
double X;
double Y;
double Z;
...
}

class Segment3D
{
Vector3D start;
Vector3D end;
...
}

Требуется написать функцию Intersect, которая будет находить точку Vector3D пересечения двух заданных на вход Segment3D.
