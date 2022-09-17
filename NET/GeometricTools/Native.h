#pragma once
namespace GeometricTools
{
   template <typename T>
   ref struct Native abstract
   {
   protected:
      T* obj;
   public:
      T& operator()() { return *obj; }
      T& operator=(const T& value) { *obj = value; return *obj;  }
   };

   template <typename T>
   ref struct NativeValue : Native<T>
   {
   public:
      NativeValue()
      {
         obj = new T();
      }
      NativeValue(const T& obj)
      {
         this->obj = new T();
         *this->obj = obj;
      }
      ~NativeValue()
      {
         if (obj != 0) {
            delete obj;
            obj = 0;
         }
      }
   };

   template <typename T>
   ref struct NativePointer : Native<T>
   {
   public:
      NativePointer()
      {
         obj = new T();
      }
      NativePointer(T* obj)
      {
         this->obj = obj;
      }
   };
};

