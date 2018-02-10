#include <node.h>
#include <string>
#include "FastNoise.h"

namespace noise {
  using v8::FunctionCallbackInfo;
  using v8::Isolate;
  using v8::Local;
  using v8::Object;
  using v8::Number;
  using v8::Value;

  // use an enum

  float GetNoise(const FunctionCallbackInfo<Value>& args, FastNoise::NoiseType noiseType) {
    float res;
    float n[4];
    FastNoise noise;

    noise.SetNoiseType(noiseType);

    for (int i = 0; i < args.Length(); i++) {
      n[i] = args[i]->NumberValue();
    }

    switch(args.Length()) {
      case 2: 
        res = noise.GetNoise(n[0], n[1]);
        break;
      case 3:
        res = noise.GetNoise(n[0], n[1], n[2]);
        break;
    }

    return res;
  }

  void GetValue(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();
    args.GetReturnValue().Set(Number::New(isolate, GetNoise(args, FastNoise::Value)));
  }
  void GetValueFractal(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();
    args.GetReturnValue().Set(Number::New(isolate, GetNoise(args, FastNoise::ValueFractal)));
  }
  void GetPerlin(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();
    args.GetReturnValue().Set(Number::New(isolate, GetNoise(args, FastNoise::Perlin)));
  }
  void GetPerlinFractal(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();
    args.GetReturnValue().Set(Number::New(isolate, GetNoise(args, FastNoise::PerlinFractal)));
  }
  void GetSimplex(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();
    args.GetReturnValue().Set(Number::New(isolate, GetNoise(args, FastNoise::Simplex)));
  }
  void GetSimplexFractal(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();
    args.GetReturnValue().Set(Number::New(isolate, GetNoise(args, FastNoise::SimplexFractal)));
  }
  void GetCellular(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();
    args.GetReturnValue().Set(Number::New(isolate, GetNoise(args, FastNoise::Cellular)));
  }
  void GetCubic(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();
    args.GetReturnValue().Set(Number::New(isolate, GetNoise(args, FastNoise::Cubic)));
  }
  void GetCubicFractal(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();
    args.GetReturnValue().Set(Number::New(isolate, GetNoise(args, FastNoise::CubicFractal)));
  }
  void GetWhiteNoise(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();
    args.GetReturnValue().Set(Number::New(isolate, GetNoise(args, FastNoise::WhiteNoise)));
  }

  void Initialize(Local<Object> exports) {
    NODE_SET_METHOD(exports, "GetValue", GetValue);
    NODE_SET_METHOD(exports, "GetValueFractal", GetValueFractal);
    NODE_SET_METHOD(exports, "GetPerlin", GetPerlin);
    NODE_SET_METHOD(exports, "GetPerlinFractal", GetPerlinFractal);
    NODE_SET_METHOD(exports, "GetSimplex", GetSimplex);
    NODE_SET_METHOD(exports, "GetSimplexFractal", GetSimplexFractal);
    NODE_SET_METHOD(exports, "GetCellular", GetCellular);
    NODE_SET_METHOD(exports, "GetCubic", GetCubic);
    NODE_SET_METHOD(exports, "GetWhiteNoise", GetWhiteNoise);
  }

  NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize)
}
