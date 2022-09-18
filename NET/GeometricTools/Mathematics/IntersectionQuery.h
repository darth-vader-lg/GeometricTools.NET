#pragma once
#include "Native.h"

using namespace System;

namespace GeometricTools
{
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
}
