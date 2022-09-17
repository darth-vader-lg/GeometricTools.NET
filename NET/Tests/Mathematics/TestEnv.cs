using Common;
using System;
using System.IO;
using System.Linq;
using Xunit.Abstractions;

namespace Mathematics
{
   /// <summary>
   /// Environment for the object detection tests
   /// </summary>
   public class TestEnv : BaseEnvironment
   {
      #region Properties
      #endregion
      #region Methods
      /// <summary>
      /// Constructor
      /// </summary>
      /// <param name="output">Optional output interface</param>
      internal TestEnv(ITestOutputHelper output = null) : base(output)
      {
      }
      #endregion
   }
}
