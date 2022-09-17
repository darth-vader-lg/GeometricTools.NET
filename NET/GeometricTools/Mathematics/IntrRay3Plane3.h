#pragma once
#include <Mathematics/IntrRay3Plane3.h>
#include "IntrLine3Plane3.h"
#include "Ray3.h"

namespace GeometricTools
{
   public ref class IntrRay3Plane3
   {
   public:
      using GTEResult = gte::FIQuery<double, GTERay3, GTEPlane3>::Result;
      ref struct Result : public IntrLine3Plane3::Result
      {
      internal:
         Result(const GTEResult& result) : IntrLine3Plane3::Result(result) { }
      };
   internal:
      static Result^ DoQuery(Ray3^ ray, Plane3^ plane)
      {
         return gcnew Result(gte::FIQuery<double, GTERay3, GTEPlane3>()(ray->native(), plane->native()));
      }
   };
};
