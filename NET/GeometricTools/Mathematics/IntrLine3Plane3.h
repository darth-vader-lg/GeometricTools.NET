#pragma once
#include <Mathematics/IntrLine3Plane3.h>
#include "Line3.h"
#include "Native.h"
#include "Plane3.h"
#include "Vector3.h"

namespace GeometricTools
{
   public ref class IntrLine3Plane3
   {
   public:
      using GTEResult = gte::FIQuery<double, GTELine3, GTEPlane3>::Result;
      ref struct Result
      {
      internal:
         Native<GTEResult>^ native;
      public:
         property bool intersect { bool get() { return native().intersect; } }
         property int numIntersections { int get() { return native().numIntersections; } }
         property double parameter { double get() { return native().parameter; } }
         property Vector3^ point { Vector3^ get() { return gcnew Vector3(&native().point); } }
      internal:
         Result(const GTEResult& result) { native = gcnew NativeValue<GTEResult>(result); }
      };
   internal:
      static Result^ DoQuery(Line3^ line, Plane3^ plane)
      {
         return gcnew Result(gte::FIQuery<double, GTELine3, GTEPlane3>()(line->native(), plane->native()));
      }
   };
};

