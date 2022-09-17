#pragma once
#include <Mathematics/Vector3.h>
#include "Native.h"

namespace GeometricTools
{
   using GTEVector3 = gte::Vector3<double>;

   public ref struct Vector3
   {
   internal:
      Native<GTEVector3>^ native;
      Vector3(const GTEVector3& vector) { native = gcnew NativeValue<GTEVector3>(vector); }
      Vector3(GTEVector3* vector) { native = gcnew NativePointer<GTEVector3>(vector); }
   public:
      property double x { double get() { return native()[0]; } void set(double value) { native()[0] = value; }}
      property double y { double get() { return native()[1]; } void set(double value) { native()[1] = value; }}
      property double z { double get() { return native()[2]; } void set(double value) { native()[2] = value; }}
   public:
      Vector3() { native = gcnew NativeValue<GTEVector3>(); }
      Vector3(const Vector3% vector) { operator=(vector); }
      Vector3(... array<double>^ values) { native = gcnew NativeValue<GTEVector3>(GTEVector3({ values[0], values[1], values[2] })); }
      Vector3(double x, double y, double z) { native = gcnew NativeValue<GTEVector3>(GTEVector3({ x, y, z })); }
      Vector3% operator=(const Vector3% vector)
      {
         native = gcnew NativeValue<GTEVector3>(vector.native());
         return *this;
      }
   };
};
