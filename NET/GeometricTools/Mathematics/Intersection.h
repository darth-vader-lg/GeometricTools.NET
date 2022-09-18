#pragma once
#include "IntrLine3Plane3.h"
#include "IntrPlane3Plane3.h"
#include "IntrRay3Plane3.h"

using namespace System;

namespace GeometricTools
{
   public ref class Intersection
   {
   internal:
      template <class TQuery, class TResult, class T1, class T2>
      ref class Query
      {
      private:
         Native<TQuery>^ native;
      public:
         static Func<T1^, T2^, TResult^>^ FIQuery()
         {
            auto query = gcnew Query();
            query->native = gcnew NativeValue<TQuery>(TQuery());
            return gcnew Func<T1^, T2^, TResult^>(query, &Query::DoQuery);
         }
      private:
         TResult^ DoQuery(T1^ prm1, T2^ prm2) { return gcnew TResult(native()(prm1->native(), prm2->native())); }
      };
   public:
      generic <class T1, class T2> where T1 : Line3 where T2 : Plane3
      static IntrLine3Plane3::FIQuery^ FIQuery() { return IntrLine3Plane3::CreateFIQuery(); }
      static IntrLine3Plane3::FIResult^ Find(Line3^ line, Plane3^ plane) { return IntrLine3Plane3::CreateFIQuery()(line, plane); }
      generic <class T1, class T2> where T1 : Plane3 where T2 : Plane3
      static IntrPlane3Plane3::FIQuery^ FIQuery() { return IntrPlane3Plane3::CreateFIQuery(); }
      static IntrPlane3Plane3::FIResult^ Find(Plane3^ plane0, Plane3^ plane1) { return IntrPlane3Plane3::CreateFIQuery()(plane0, plane1); }
      generic <class T1, class T2> where T1 : Ray3 where T2 : Plane3
      static IntrRay3Plane3::FIQuery^ FIQuery() { return IntrRay3Plane3::CreateFIQuery(); }
      static IntrRay3Plane3::FIResult^ Find(Ray3^ ray, Plane3^ plane) { return IntrRay3Plane3::CreateFIQuery()(ray, plane); }
   };
};

