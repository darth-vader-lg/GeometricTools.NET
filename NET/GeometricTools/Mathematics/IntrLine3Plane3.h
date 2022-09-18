#pragma once
#include <Mathematics/IntrLine3Plane3.h>
#include "IntersectionQuery.h"
#include "Line3.h"
#include "Plane3.h"
#include "Vector3.h"

namespace GeometricTools
{
   public ref class IntrLine3Plane3
   {
   private:
      using GTEFIQuery = gte::FIQuery<double, GTELine3, GTEPlane3>;
   public:
      ref struct FIResult
      {
      internal:
         Native<GTEFIQuery::Result>^ native;
      public:
         property bool intersect { bool get() { return native().intersect; } }
         property int numIntersections { int get() { return native().numIntersections; } }
         property double parameter { double get() { return native().parameter; } }
         property Vector3^ point { Vector3^ get() { return gcnew Vector3(&native().point); } }
      internal:
         FIResult(const GTEFIQuery::Result& result) { native = gcnew NativeValue<GTEFIQuery::Result>(result); }
      };
   public:
      using FIQuery = Func<Line3^, Plane3^, FIResult^>;
      static FIQuery^ CreateFIQuery() { return Query<GTEFIQuery, FIResult, Line3, Plane3>::FIQuery(); }
   };
};

