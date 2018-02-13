#ifndef FASTNOISEJS_H
#define FASTNOISEJS_H

#include <node.h>
#include <node_object_wrap.h>
#include "./vendor/FastNoise.h"

namespace fastnoisejs {
  using v8::Function;
  using v8::FunctionCallbackInfo;
  using v8::Isolate;
  using v8::Object;
  using v8::Value;
  using v8::Persistent;
  using node::ObjectWrap;

  class FastNoiseJs : public ObjectWrap {
    public:
      static void Init(Isolate* isolate);
      static void NewInstance(const FunctionCallbackInfo<Value>& args);

    private:
      explicit FastNoiseJs(int seed = 1337);
      ~FastNoiseJs();

      static void GetSeed(const FunctionCallbackInfo<Value>& args);
      static void SetSeed(const FunctionCallbackInfo<Value>& args);
      static void SetFrequency(const FunctionCallbackInfo<Value>& args);
      static void SetInterp(const FunctionCallbackInfo<Value>& args);
      static void SetNoiseType(const FunctionCallbackInfo<Value>& args);
      static void SetFractalOctaves(const FunctionCallbackInfo<Value>& args);
      static void SetFractalLacunarity(const FunctionCallbackInfo<Value>& args);
      static void SetFractalGain(const FunctionCallbackInfo<Value>& args);
      static void SetFractalType(const FunctionCallbackInfo<Value>& args);
      static void SetCellularDistanceFunction(const FunctionCallbackInfo<Value>& args);
      static void SetCellularReturnType(const FunctionCallbackInfo<Value>& args);
      // static void SetCellularNoiseLookup(const FunctionCallbackInfo<Value>& args); TODO
      static void SetCellularDistance2Indices(const FunctionCallbackInfo<Value>& args);
      static void SetCellularJitter(const FunctionCallbackInfo<Value>& args);

      static void GetNoise(const FunctionCallbackInfo<Value>& args);
      static void GetValue(const FunctionCallbackInfo<Value>& args);
      static void GetValueFractal(const FunctionCallbackInfo<Value>& args);
      static void GetPerlin(const FunctionCallbackInfo<Value>& args);
      static void GetPerlinFractal(const FunctionCallbackInfo<Value>& args);
      static void GetSimplex(const FunctionCallbackInfo<Value>& args);
      static void GetSimplexFractal(const FunctionCallbackInfo<Value>& args);
      static void GetCellular(const FunctionCallbackInfo<Value>& args);
      static void GetWhiteNoise(const FunctionCallbackInfo<Value>& args);
      static void GetCubic(const FunctionCallbackInfo<Value>& args);
      static void GetCubicFractal(const FunctionCallbackInfo<Value>& args);
      static void New(const FunctionCallbackInfo<Value>& args);
      static Persistent<Function> constructor; 
      FastNoise noise;
  };
}

#endif
