#include <node.h>
#include "./util/nodeplus.h"
#include "FastNoiseJs.h"

namespace fastnoisejs {
  using v8::FunctionCallbackInfo;
  using v8::Isolate;
  using v8::Local;
  using v8::Object;
  using v8::String;
  using v8::Value;

  void Create(const FunctionCallbackInfo<Value>& args) {
    FastNoiseJs::NewInstance(args);
  }

  void InitAll(Local<Object> exports) {
    Isolate* isolate = exports->GetIsolate();

    Local<Object> NoiseType = Object::New(isolate);
    Local<Object> Interp = Object::New(isolate);
    Local<Object> FractalType = Object::New(isolate);
    Local<Object> CellularDistanceFunction = Object::New(isolate);
    Local<Object> CellularReturnType = Object::New(isolate);

    NODE_DEFINE_CONST(NoiseType, "Value", FastNoise::Value);
    NODE_DEFINE_CONST(NoiseType, "ValueFractal", FastNoise::ValueFractal);
    NODE_DEFINE_CONST(NoiseType, "Perlin", FastNoise::Perlin);
    NODE_DEFINE_CONST(NoiseType, "PerlinFractal", FastNoise::PerlinFractal);
    NODE_DEFINE_CONST(NoiseType, "Simplex", FastNoise::Simplex);
    NODE_DEFINE_CONST(NoiseType, "SimplexFractal", FastNoise::SimplexFractal);
    NODE_DEFINE_CONST(NoiseType, "Cellular", FastNoise::Cellular);
    NODE_DEFINE_CONST(NoiseType, "Cubic", FastNoise::Cubic);
    NODE_DEFINE_CONST(NoiseType, "CubicFractal", FastNoise::CubicFractal);
    NODE_DEFINE_CONST(NoiseType, "WhiteNoies", FastNoise::WhiteNoise);

    NODE_DEFINE_CONST(Interp, "Linear", FastNoise::Linear);
    NODE_DEFINE_CONST(Interp, "Hermite", FastNoise::Hermite);
    NODE_DEFINE_CONST(Interp, "Quintic", FastNoise::Quintic);

    NODE_DEFINE_CONST(FractalType, "FBM", FastNoise::FBM);
    NODE_DEFINE_CONST(FractalType, "Billow", FastNoise::Billow);
    NODE_DEFINE_CONST(FractalType, "RigidMulti", FastNoise::RigidMulti);

    NODE_DEFINE_CONST(CellularDistanceFunction, "Euclidean", FastNoise::Euclidean);
    NODE_DEFINE_CONST(CellularDistanceFunction, "Manhattan", FastNoise::Manhattan);
    NODE_DEFINE_CONST(CellularDistanceFunction, "Natural", FastNoise::Natural);

    NODE_DEFINE_CONST(CellularReturnType, "CellValue", FastNoise::CellValue);
    NODE_DEFINE_CONST(CellularReturnType, "NoiseLookup", FastNoise::NoiseLookup);
    NODE_DEFINE_CONST(CellularReturnType, "Distance", FastNoise::Distance);
    NODE_DEFINE_CONST(CellularReturnType, "Distance2", FastNoise::Distance2);
    NODE_DEFINE_CONST(CellularReturnType, "Distance2Add", FastNoise::Distance2Add);
    NODE_DEFINE_CONST(CellularReturnType, "Distance2Sub", FastNoise::Distance2Sub);
    NODE_DEFINE_CONST(CellularReturnType, "Distance2Mul", FastNoise::Distance2Mul);
    NODE_DEFINE_CONST(CellularReturnType, "Distance2Div", FastNoise::Distance2Div);

    NODE_SET_OBJECT(exports, "NoiseType", NoiseType);
    NODE_SET_OBJECT(exports, "Interp", Interp);
    NODE_SET_OBJECT(exports, "FractalType", FractalType);
    NODE_SET_OBJECT(exports, "CellularDistanceFunction", CellularDistanceFunction);
    NODE_SET_OBJECT(exports, "CellularReturnType", CellularReturnType);
    NODE_SET_METHOD(exports, "Create", Create);
  }

  NODE_MODULE(NODE_GYP_MODULE_NAME, InitAll)
}
