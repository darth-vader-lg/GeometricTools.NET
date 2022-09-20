using GeometricTools;
using System;
using System.Collections.Generic;
using Xunit;
using Xunit.Abstractions;

namespace Mathematics
{
   public class NumericalMethods : TestEnv
   {
      #region Methods
      /// <summary>
      /// Constructor
      /// </summary>
      /// <param name="output">Optional output interface</param>
      public NumericalMethods(ITestOutputHelper output = null) : base(output) { }
      /// <summary>
      /// Minimum finder
      /// </summary>
      [Fact]
      public void Minimize1()
      {
         var minimize1 = new Minimize1(x => -Math.Sin(x));
         minimize1.GetMinimum(0, Math.PI, out var tMin, out var fMin);
         Assert.Equal(1.570796, tMin, 6);
         Assert.Equal(-1, fMin);
      }
      #endregion
   }
}
