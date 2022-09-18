#pragma once
#include <Mathematics/IntrRay3Plane3.h>
#include "IntrLine3Plane3.h"
#include "Ray3.h"

namespace GeometricTools
{
   public ref class IntrRay3Plane3
   {
   private:
      using GTEFIQuery = gte::FIQuery<double, GTERay3, GTEPlane3>;
   public:
      ref struct FIResult : public IntrLine3Plane3::FIResult
      {
      internal:
         FIResult(const GTEFIQuery::Result& result) : IntrLine3Plane3::FIResult(result) { }
      };
   public:
      using FIQuery = Func<Ray3^, Plane3^, FIResult^>;
      static FIQuery^ CreateFIQuery() { return Query<GTEFIQuery, FIResult, Ray3, Plane3>::FIQuery(); }
   };
};
