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
         result = Intersection.Find(line, plane);
         Assert.Equal(100, result.point.x);
         Assert.Equal(0, result.point.y);
         Assert.Equal(0, result.point.z);
      }
      /// <summary>
      /// Intersection plane / circle
      /// </summary>
      [Fact]
      public void IntrPlane3Circle3()
      {
         var plane = new Plane3(new Vector3(0, 1, 0), new Vector3(0, 10, 0));
         var circle = new Circle3(new Vector3(0, 0, 0), new Vector3(0, 0, 1), 100);
         var query = Intersection.FIQuery<Plane3, Circle3>();
         var result = query(plane, circle);
         Assert.True(result.intersect);
         Assert.Equal((nuint)2, result.numIntersections);
         Assert.Equal(-99.498743710662, result.point[0].x, 6);
         Assert.Equal(99.498743710662, result.point[1].x, 6);
         result = Intersection.Find(plane, circle);
         Assert.True(result.intersect);
         Assert.Equal((nuint)2, result.numIntersections);
         Assert.Equal(-99.498743710662, result.point[0].x, 6);
         Assert.Equal(99.498743710662, result.point[1].x, 6);
         circle = new Circle3(new Vector3(0, 0, 0), new Vector3(0, 0, 1), 10);
         result = query(plane, circle);
         Assert.True(result.intersect);
         Assert.Equal((nuint)1, result.numIntersections);
         Assert.Equal(10, result.point[0].y, 6);
         Assert.Equal(10, result.point[1].y, 6);
         result = Intersection.Find(plane, circle);
         Assert.True(result.intersect);
         Assert.Equal((nuint)1, result.numIntersections);
         Assert.Equal(10, result.point[0].y, 6);
         Assert.Equal(10, result.point[1].y, 6);
         circle = new Circle3(new Vector3(0, 10, 0), new Vector3(0, 1, 0), 10);
         result = query(plane, circle);
         Assert.True(result.intersect);
         Assert.Equal(nuint.MaxValue, result.numIntersections);
         Assert.Equal(10, result.circle.center.y, 6);
         result = Intersection.Find(plane, circle);
         Assert.True(result.intersect);
         Assert.Equal(nuint.MaxValue, result.numIntersections);
         Assert.Equal(10, result.circle.center.y, 6);
      }
      /// <summary>
      /// Intersection plane / plane
      /// </summary>
      [Fact]
      public void IntrPlane3Plane3()
      {
         var plane0 = new Plane3(new Vector3(1, 0, 0), new Vector3(0, 0, 0));
         var plane1 = new Plane3(new Vector3(0, 1, 0), new Vector3(10, 0, 0));
         var query = Intersection.FIQuery<Plane3, Plane3>();
         var result = query(plane0, plane1);
         Assert.True(result.isLine);
         Assert.Equal(0, result.line.origin.x);
         Assert.Equal(1, result.line.direction.z);
         result = Intersection.Find(plane0, plane1);
         Assert.True(result.isLine);
         Assert.Equal(0, result.line.origin.x);
         Assert.Equal(1, result.line.direction.z);
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
         result = Intersection.Find(ray, plane);
         Assert.Equal(100, result.point.x);
         Assert.Equal(0, result.point.y);
         Assert.Equal(0, result.point.z);
      }
      #endregion
   }
}
