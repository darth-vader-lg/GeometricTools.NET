#pragma once
#include <Mathematics/Line.h>
#include "Vector3.h"

namespace GeometricTools
{
   using GTELine3 = gte::Line3<double>;

   public ref struct Line3
   {
   internal:
      Native<GTELine3>^ native;
      Line3(const GTELine3& line) { native = gcnew NativeValue<GTELine3>(line); }
      Line3(GTELine3* line) { native = gcnew NativePointer<GTELine3>(line); }
   public:
      property Vector3^ origin { Vector3^ get() { return gcnew Vector3(&native().origin); } void set(Vector3^ value) { native().origin = value->native(); } }
      property Vector3^ direction { Vector3^ get() { return gcnew Vector3(&native().direction); } void set(Vector3^ value) { native().direction = value->native(); } }
   public:
      Line3() { native = gcnew NativeValue<GTELine3>(); }
      Line3(const Line3% line) { operator=(line); }
      Line3(Vector3^ origin, Vector3^ direction) { native = gcnew NativeValue<GTELine3>(GTELine3(origin->native(), direction->native())); }
      Line3% operator=(const Line3% line)
      {
         native = gcnew NativeValue<GTELine3>(line.native());
         return *this;
      }
   };
};
