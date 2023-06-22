#include "vector3d.h" // for creating Vector3d object
#include "point3d.h" // for creating Point3d object

int main()
{
	Point3d p{1.0, 2.0, 3.0};
	Vector3d v{2.0, 2.0, -3.0};

	p.print();
	p.moveByVector(v);
	p.print();

	return 0;
}