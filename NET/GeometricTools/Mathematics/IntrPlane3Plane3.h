#pragma once
#include <Mathematics/IntrPlane3Plane3.h>
#include "IntersectionQuery.h"
#include "Line3.h"
#include "Plane3.h"

namespace GeometricTools
{
   public ref class IntrPlane3Plane3
   {
   private:
      using GTEFIQuery = gte::FIQuery<double, GTEPlane3, GTEPlane3>;
   public:
      ref struct FIResult
      {
      internal:
         Native<GTEFIQuery::Result>^ native;
      public:
         property bool intersect { bool get() { return native().intersect; } }
         property bool isLine { bool get() { return native().isLine; } }
         property Line3^ line { Line3^ get() { return gcnew Line3(&native().line); } }
         property Plane3^ plane { Plane3^ get() { return gcnew Plane3(&native().plane); } }
      internal:
         FIResult(const GTEFIQuery::Result& result) { native = gcnew NativeValue<GTEFIQuery::Result>(result); }
      };
   public:
      using FIQuery = Func<Plane3^, Plane3^, FIResult^>;
      static FIQuery^ CreateFIQuery() { return Query<GTEFIQuery, FIResult, Plane3, Plane3>::FIQuery(); }
   };
};


