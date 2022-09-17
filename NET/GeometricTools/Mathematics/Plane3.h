#pragma once
#include <list>
#include <vector>
#include <Mathematics/Hyperplane.h>
#include "Vector3.h"

namespace GeometricTools
{
   using GTEPlane3 = gte::Plane3<double>;

   public ref class Plane3
   {
   internal:
      Native<GTEPlane3>^ native;
      Plane3(const GTEPlane3& plane) { native = gcnew NativeValue<GTEPlane3>(plane); }
      Plane3(GTEPlane3* plane) { native = gcnew NativePointer<GTEPlane3>(plane); }
   public:
      property Vector3^ origin { Vector3^ get() { return gcnew Vector3(&native().origin); } void set(Vector3^ value) { native().origin = value->native(); } }
      property Vector3^ normal { Vector3^ get() { return gcnew Vector3(&native().normal); } void set(Vector3^ value) { native().normal = value->native(); } }
      property double constant { double get() { return native().constant; } void set(double value) { native().constant = value; } }
   public:
      Plane3() { native = gcnew NativeValue<GTEPlane3>(); }
      Plane3(const Plane3% plane) { operator=(plane); }
      Plane3(Vector3^ normal, double constant) { native = gcnew NativeValue<GTEPlane3>(GTEPlane3(normal->native(), constant)); }
      Plane3(Vector3^ normal, Vector3^ origin) { native = gcnew NativeValue<GTEPlane3>(GTEPlane3(normal->native(), origin->native())); }
      Plane3(... array<Vector3^>^ p)
      {
         native = gcnew NativeValue<GTEPlane3>(GTEPlane3(std::array<gte::Vector3<double>, 3>({ p[0]->native(), p[1]->native(), p[2]->native() })));
      }
      Plane3% operator=(const Plane3% plane)
      {
         native = gcnew NativeValue<GTEPlane3>(plane.native());
         return *this;
      }
   };
};
