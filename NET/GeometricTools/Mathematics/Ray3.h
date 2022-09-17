#pragma once
#include <Mathematics/Ray.h>
#include "Vector3.h"

namespace GeometricTools
{
   using GTERay3 = gte::Ray3<double>;

   public ref struct Ray3
   {
   internal:
      Native<GTERay3>^ native;
      Ray3(const GTERay3& ray) { native = gcnew NativeValue<GTERay3>(ray); }
      Ray3(GTERay3* ray) { native = gcnew NativePointer<GTERay3>(ray); }
   public:
      property Vector3^ origin { Vector3^ get() { return gcnew Vector3(&native().origin); } void set(Vector3^ value) { native().origin = value->native(); } }
      property Vector3^ direction { Vector3^ get() { return gcnew Vector3(&native().direction); } void set(Vector3^ value) { native().direction = value->native(); } }
   public:
      Ray3() { native = gcnew NativeValue<GTERay3>(); }
      Ray3(const Ray3% ray) { operator=(ray); }
      Ray3(Vector3^ origin, Vector3^ direction) { native = gcnew NativeValue<GTERay3>(GTERay3(origin->native(), direction->native())); }
      Ray3% operator=(const Ray3% ray)
      {
         native = gcnew NativeValue<GTERay3>(ray.native());
         return *this;
      }
   };
};
