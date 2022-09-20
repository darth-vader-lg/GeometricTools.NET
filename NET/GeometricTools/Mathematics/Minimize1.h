#pragma once
#include <Mathematics/Minimize1.h>
#include "Native.h"

using namespace System;
using namespace System::Runtime::InteropServices;

namespace GeometricTools
{
   static std::function<double(double)> GetMinimize1Function(double (*fPtr)(double))
   {
      return [fPtr](double value) { return fPtr(value); };
   }

   public ref class Minimize1
   {
   private:
      using GTENative = gte::Minimize1<double>;
   internal:
      Native<GTENative>^ native;
   public:
      delegate double Function(double);
   public:
      Minimize1(Function^ F) : Minimize1(F, maxSubdivisionsDefault) { }
      Minimize1(Function^ F, int maxSubdivisions) : Minimize1(F, maxSubdivisions, maxBisectionsDefault) { }
      Minimize1(Function^ F, int maxSubdivisions, int maxBisections) : Minimize1(F, maxSubdivisions, maxBisections, epsilonDefault) { }
      Minimize1(Function^ F, int maxSubdivisions, int maxBisections, double epsilon) : Minimize1(F, maxSubdivisions, maxBisections, epsilon, toleranceDefault) { }
      Minimize1(Function^ F, int maxSubdivisions, int maxBisections, double epsilon, double tolerance)
      {
         native = gcnew NativeValue<GTENative>(
            GTENative(
               GetMinimize1Function((double (*)(double))Marshal::GetFunctionPointerForDelegate(F).ToPointer()),
               maxSubdivisions,
               maxBisections,
               epsilon,
               tolerance));
      }
      void SetEpsilon(double epsilon) { native().SetEpsilon(epsilon); }
      void SetTolerance(double epsilon) { native().SetTolerance(epsilon); }
      double GetEpsilon() { return native().GetEpsilon(); }
      double GetTolerance() { return native().GetTolerance(); }
      void GetMinimum(double t0, double t1, [Out] double% tMin, [Out] double% fMin)
      {
         double _tMin, _fMin;
         native().GetMinimum(t0, t1, _tMin, _fMin);
         tMin = _tMin;
         fMin = _fMin;
      }
      void GetMinimum(double t0, double t1, double tInitial, [Out] double% tMin, [Out] double% fMin)
      {
         double _tMin, _fMin;
         native().GetMinimum(t0, t1, tInitial, _tMin, _fMin);
         tMin = _tMin;
         fMin = _fMin;
      }
   public:
      static const double epsilonDefault = 1E-8;
      static const int maxBisectionsDefault = std::numeric_limits<double>::max_exponent - std::numeric_limits<double>::min_exponent + std::numeric_limits<double>::digits;
      static const int maxSubdivisionsDefault = 1;
      static const double toleranceDefault = 1E-4;
   };
}
