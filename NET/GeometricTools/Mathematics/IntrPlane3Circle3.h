#pragma once
#include <Mathematics/IntrPlane3Circle3.h>
#include "IntersectionQuery.h"
#include "Circle3.h"
#include "Plane3.h"

namespace GeometricTools
{
   public ref class IntrPlane3Circle3
   {
   private:
      using GTEFIQuery = gte::FIQuery<double, GTEPlane3, GTECircle3>;
   public:
      ref struct FIResult
      {
      internal:
         Native<GTEFIQuery::Result>^ native;
      public:
         property bool intersect { bool get() { return native().intersect; } }
         property size_t numIntersections { size_t get() { return (int)native().numIntersections; } }
         property array<Vector3^>^ point { array<Vector3^>^ get() { return gcnew array<Vector3^> {gcnew Vector3(native().point[0]), gcnew Vector3(native().point[1]) }; } }
         property Circle3^ circle { Circle3^ get() { return gcnew Circle3(&native().circle); } }
      internal:
         FIResult(const GTEFIQuery::Result& result) { native = gcnew NativeValue<GTEFIQuery::Result>(result); }
      };
   internal:
      using FIQuery = Func<Plane3^, Circle3^, FIResult^>;
      static FIQuery^ CreateFIQuery() { return Query<GTEFIQuery, FIResult, Plane3, Circle3>::FIQuery(); }
   };
};
