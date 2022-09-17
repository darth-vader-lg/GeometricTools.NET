#pragma once
#include "IntrLine3Plane3.h"
#include "IntrRay3Plane3.h"

using namespace System;

namespace GeometricTools
{
   public ref class Intersection
   {
   public:
      generic <class T1, class T2> where T1 : Line3 where T2 : Plane3
         static Func<Line3^, Plane3^, IntrLine3Plane3::Result^>^ FIQuery()
      {
         return gcnew Func<Line3^, Plane3^, IntrLine3Plane3::Result^>(IntrLine3Plane3::DoQuery);
      }
      generic <class T1, class T2> where T1 : Ray3 where T2 : Plane3
         static Func<Ray3^, Plane3^, IntrRay3Plane3::Result^>^ FIQuery()
      {
         return gcnew Func<Ray3^, Plane3^, IntrRay3Plane3::Result^>(IntrRay3Plane3::DoQuery);
      }
   };
};

