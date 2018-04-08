#include <nanogui/nanogui.h>

#include "../clothMesh.h"
#include "../misc/sphere_drawing.h"
#include "sphere.h"

using namespace nanogui;
using namespace CGL;

void Sphere::collide(PointMass &pm) {
  // TODO (Part 3.1): Handle collisions with spheres.
	if (((origin - pm.position).norm() - radius) < 0) {
		Vector3D correction = (origin - pm.position) * ((origin - pm.position).norm() - radius);
		Vector3D temp = pm.position;
		pm.position += correction * (1 + friction);

		pm.last_position = temp;
	}


}

void Sphere::render(GLShader &shader) {
  // We decrease the radius here so flat triangles don't behave strangely
  // and intersect with the sphere when rendered
  Misc::draw_sphere(shader, origin, radius * 0.92);
}
