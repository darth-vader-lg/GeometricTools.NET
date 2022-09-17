using GeometricTools;
using Xunit;
using Xunit.Abstractions;

namespace Mathematics
{
   public class Intersections : TestEnv
   {
      #region Methods
      /// <summary>
      /// Constructor
      /// </summary>
      /// <param name="output">Optional output interface</param>
      public Intersections(ITestOutputHelper output = null) : base(output) { }
      /// <summary>
      /// Intersection line / plane
      /// </summary>
      [Fact]
      public void IntrLine3Plane3()
      {
         var line = new Line3(new Vector3(10, 0, 0), new Vector3(1, 0, 0));
         var plane = new Plane3(new Vector3(-1, 0, 0), new Vector3(100, 0, 0));
         var query = Intersection.FIQuery<Line3, Plane3>();
         var result = query(line, plane);
         Assert.Equal(100, result.point.x);
         Assert.Equal(0, result.point.y);
         Assert.Equal(0, result.point.z);
      }
      /// <summary>
      /// Intersection ray / plane
      /// </summary>
      [Fact]
      public void IntrRay3Plane3()
      {
         var ray = new Ray3(new Vector3(10, 0, 0), new Vector3(1, 0, 0));
         var plane = new Plane3(new Vector3(-1, 0, 0), new Vector3(100, 0, 0));
         var query = Intersection.FIQuery<Ray3, Plane3>();
         var result = query(ray, plane);
         Assert.Equal(100, result.point.x);
         Assert.Equal(0, result.point.y);
         Assert.Equal(0, result.point.z);
      }
      #endregion
   }
}
