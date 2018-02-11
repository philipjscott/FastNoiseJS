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

  FastNoise noise;
  FastNoise::NoiseType configNoiseType;

  int VALUE = FastNoise::Value;
  int VALUE_FRACTAL = FastNoise::ValueFractal;
  int PERLIN = FastNoise::Perlin;
  int PERLIN_FRACTAL = FastNoise::PerlinFractal;
  int SIMPLEX = FastNoise::Simplex;
  int SIMPLEX_FRACTAL = FastNoise::SimplexFractal;
  int CELLULAR = FastNoise::Cellular;
  int CUBIC = FastNoise::Cubic;
  int CUBIC_FRACTAL = FastNoise::CubicFractal; 
  int WHITE_NOISE = FastNoise::WhiteNoise;

  void SetNoiseType(const FunctionCallbackInfo<Value>& args) {
    configNoiseType = static_cast<FastNoise::NoiseType>(args[0]->Int32Value());
    noise.SetNoiseType(configNoiseType);
  }

  float GetNoiseValue(const FunctionCallbackInfo<Value>& args) {
    float res;
    float n[4];

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

  float GetNoiseOnce(const FunctionCallbackInfo<Value>& args, FastNoise::NoiseType noiseType) {
    float res;

    noise.SetNoiseType(noiseType);
    res = GetNoiseValue(args);
    noise.SetNoiseType(configNoiseType);

    return res;
  }

  void GetNoise(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();
    args.GetReturnValue().Set(Number::New(isolate, GetNoiseValue(args)));
  }
  void GetValue(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();
    args.GetReturnValue().Set(Number::New(isolate, GetNoiseOnce(args, FastNoise::Value)));
  }
  void GetValueFractal(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();
    args.GetReturnValue().Set(Number::New(isolate, GetNoiseOnce(args, FastNoise::ValueFractal)));
  }
  void GetPerlin(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();
    args.GetReturnValue().Set(Number::New(isolate, GetNoiseOnce(args, FastNoise::Perlin)));
  }
  void GetPerlinFractal(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();
    args.GetReturnValue().Set(Number::New(isolate, GetNoiseOnce(args, FastNoise::PerlinFractal)));
  }
  void GetSimplex(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();
    args.GetReturnValue().Set(Number::New(isolate, GetNoiseOnce(args, FastNoise::Simplex)));
  }
  void GetSimplexFractal(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();
    args.GetReturnValue().Set(Number::New(isolate, GetNoiseOnce(args, FastNoise::SimplexFractal)));
  }
  void GetCellular(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();
    args.GetReturnValue().Set(Number::New(isolate, GetNoiseOnce(args, FastNoise::Cellular)));
  }
  void GetCubic(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();
    args.GetReturnValue().Set(Number::New(isolate, GetNoiseOnce(args, FastNoise::Cubic)));
  }
  void GetCubicFractal(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();
    args.GetReturnValue().Set(Number::New(isolate, GetNoiseOnce(args, FastNoise::CubicFractal)));
  }
  void GetWhiteNoise(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();
    args.GetReturnValue().Set(Number::New(isolate, GetNoiseOnce(args, FastNoise::WhiteNoise)));
  }

  void Initialize(Local<Object> exports) {
    NODE_SET_METHOD(exports, "GetNoise", GetNoise);
    NODE_SET_METHOD(exports, "GetValue", GetValue);
    NODE_SET_METHOD(exports, "GetValueFractal", GetValueFractal);
    NODE_SET_METHOD(exports, "GetPerlin", GetPerlin);
    NODE_SET_METHOD(exports, "GetPerlinFractal", GetPerlinFractal);
    NODE_SET_METHOD(exports, "GetSimplex", GetSimplex);
    NODE_SET_METHOD(exports, "GetSimplexFractal", GetSimplexFractal);
    NODE_SET_METHOD(exports, "GetCellular", GetCellular);
    NODE_SET_METHOD(exports, "GetCubic", GetCubic);
    NODE_SET_METHOD(exports, "GetCubicFractal", GetCubicFractal);
    NODE_SET_METHOD(exports, "GetWhiteNoise", GetWhiteNoise);
    NODE_SET_METHOD(exports, "SetNoiseType", SetNoiseType);
    NODE_DEFINE_CONSTANT(exports, VALUE);
    NODE_DEFINE_CONSTANT(exports, VALUE_FRACTAL);
    NODE_DEFINE_CONSTANT(exports, PERLIN);
    NODE_DEFINE_CONSTANT(exports, PERLIN_FRACTAL);
    NODE_DEFINE_CONSTANT(exports, SIMPLEX);
    NODE_DEFINE_CONSTANT(exports, SIMPLEX_FRACTAL);
    NODE_DEFINE_CONSTANT(exports, CELLULAR);
    NODE_DEFINE_CONSTANT(exports, CUBIC);
    NODE_DEFINE_CONSTANT(exports, CUBIC_FRACTAL);
    NODE_DEFINE_CONSTANT(exports, WHITE_NOISE);
  }

  NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize)
}
