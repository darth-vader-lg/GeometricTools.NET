#pragma once
#include <Mathematics/Circle3.h>
#include "Vector3.h"

namespace GeometricTools
{
   using GTECircle3 = gte::Circle3<double>;

   public ref class Circle3
   {
   internal:
      Native<GTECircle3>^ native;
      Circle3(const GTECircle3& circle) { native = gcnew NativeValue<GTECircle3>(circle); }
      Circle3(GTECircle3* circle) { native = gcnew NativePointer<GTECircle3>(circle); }
   public:
      property Vector3^ center { Vector3^ get() { return gcnew Vector3(&native().center); } void set(Vector3^ value) { native().center = value->native(); } }
      property Vector3^ normal { Vector3^ get() { return gcnew Vector3(&native().normal); } void set(Vector3^ value) { native().normal = value->native(); } }
      property double radius { double get() { return native().radius; } void set(double value) { native().radius = value; } }
   public:
      Circle3() { native = gcnew NativeValue<GTECircle3>(); }
      Circle3(const Circle3% circle) { operator=(circle); }
      Circle3(Vector3^ center, Vector3^ normal, double radius) { native = gcnew NativeValue<GTECircle3>(GTECircle3(center->native(), normal->native(), radius)); }
      Circle3% operator=(const Circle3% circle)
      {
         native = gcnew NativeValue<GTECircle3>(circle.native());
         return *this;
      }
   };
}
