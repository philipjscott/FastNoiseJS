#include "FastNoiseJs.h"
#include "./vendor/FastNoise.h"

Napi::FunctionReference FastNoiseJs::constructor;

Napi::Object FastNoiseJs::Init(Napi::Env env, Napi::Object exports) {
  Napi::HandleScope scope(env);

  Napi::Function func = DefineClass(env, "Create", {
    InstanceMethod("GetNoise", &FastNoiseJs::GetNoise),
    InstanceMethod("GetSeed", &FastNoiseJs::GetSeed),
    InstanceMethod("SetSeed", &FastNoiseJs::SetSeed),
    InstanceMethod("SetFrequency", &FastNoiseJs::SetFrequency),
    InstanceMethod("SetInterp", &FastNoiseJs::SetInterp),
    InstanceMethod("SetNoiseType", &FastNoiseJs::SetNoiseType),
    InstanceMethod("SetFractalOctaves", &FastNoiseJs::SetFractalOctaves),
    InstanceMethod("SetFractalLacunarity", &FastNoiseJs::SetFractalLacunarity),
    InstanceMethod("SetFractalGain", &FastNoiseJs::SetFractalGain),
    InstanceMethod("SetFractalType", &FastNoiseJs::SetFractalType),
    InstanceMethod("SetCellularDistanceFunction", &FastNoiseJs::SetCellularDistanceFunction),
    InstanceMethod("SetCellularReturnType", &FastNoiseJs::SetCellularReturnType),
    // SetCellularNoiseLookup(const Napi::CallbackInfo& info); TODO
    InstanceMethod("SetCellularDistance2Indices", &FastNoiseJs::SetCellularDistance2Indices),
    InstanceMethod("SetCellularJitter", &FastNoiseJs::SetCellularJitter),

    InstanceMethod("GetNoise", &FastNoiseJs::GetNoise),
    InstanceMethod("GetValue", &FastNoiseJs::GetValue),
    InstanceMethod("GetValueFractal", &FastNoiseJs::GetValueFractal),
    InstanceMethod("GetPerlin", &FastNoiseJs::GetPerlin),
    InstanceMethod("GetPerlinFractal", &FastNoiseJs::GetPerlinFractal),
    InstanceMethod("GetSimplex", &FastNoiseJs::GetSimplex),
    InstanceMethod("GetSimplexFractal", &FastNoiseJs::GetSimplexFractal),
    InstanceMethod("GetCellular", &FastNoiseJs::GetCellular),
    InstanceMethod("GetWhiteNoise", &FastNoiseJs::GetWhiteNoise),
    InstanceMethod("GetCubic", &FastNoiseJs::GetCubic),
    InstanceMethod("GetCubicFractal", &FastNoiseJs::GetCubicFractal)
  });

  constructor = Napi::Persistent(func);
  constructor.SuppressDetruct();

  exports.set("Create", func);
  exports.set("Value", Napi::Number::New(env, FastNoise::Value));
  exports.set("ValueFractal", Napi::Number::New(env, FastNoise::ValueFractal));
  exports.set("Perlin", Napi::Number::New(env, FastNoise::Perlin));
  exports.set("PerlinFractal", Napi::Number::New(env, FastNoise::PerlinFractal));
  exports.set("Simplex", Napi::Number::New(env, FastNoise::Simplex));
  exports.set("SimplexFractal", Napi::Number::New(env, FastNoise::SimplexFractal));
  exports.set("Cellular", Napi::Number::New(env, FastNoise::Cellular));
  exports.set("Cubic", Napi::Number::New(env, FastNoise::Cubic));
  exports.set("CubicFractal", Napi::Number::New(env, FastNoise::CubicFractal));
  exports.set("WhiteNoise", Napi::Number::New(env, FastNoise::WhiteNoise));

  exports.set("Linear", Napi::Number::New(env, FastNoise::Linear));
  exports.set("Hermite", Napi::Number::New(env, FastNoise::Hermite));
  exports.set("Quintic", Napi::Number::New(env, FastNoise::Quintic));

  exports.set("FBM", Napi::Number::New(env, FastNoise::FBM));
  exports.set("Billow", Napi::Number::New(env, FastNoise::Billow));
  exports.set("RigidMulti", Napi::Number::New(env, FastNoise::RigidMulti));

  exports.set("Euclidean", Napi::Number::New(env, FastNoise::Euclidean));
  exports.set("Manhattan", Napi::Number::New(env, FastNoise::Manhattan));
  exports.set("Natural", Napi::Number::New(env, FastNoise::Natural));

  exports.set("CellValue", Napi::Number::New(env, FastNoise::CellValue));
  exports.set("NoiseLookup", Napi::Number::New(env, FastNoise::NoiseLookup));
  exports.set("Distance", Napi::Number::New(env, FastNoise::Distance));
  exports.set("Distance2", Napi::Number::New(env, FastNoise::Distance2));
  exports.set("Distance2Add", Napi::Number::New(env, FastNoise::Distance2Add));
  exports.set("Distance2Sub", Napi::Number::New(env, FastNoise::Distance2Sub));
  exports.set("Distance2Mul", Napi::Number::New(env, FastNoise::Distance2Mul));
  exports.set("Distance2Div", Napi::Number::New(env, FastNoise::Distance2Div));

  return exports;
}

FastNoiseJs::FastNoiseJs(const Napi::CallbackInfo& info) : Napi::ObjectWrap<FastNoiseJs>(info)  {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  int length = info.Length();

  if (length <= 0 || !info[0].IsNumber()) {
    if (!info[0].IsNumber()) {
      Napi::TypeError::New(env, "Number expected").ThrowAsJavaScriptException();
    } else {
      Napi::Number value = info[0].As<Napi::Number>();
      this->noise.SetSeed(value.Int32Value());
    }
  }
}

Napi::Number FastNoiseJs::GetSeed(const Napi::CallbackInfo& info) {
  return Napi::Number::New(info.Env(), this->noise.GetSeed());
}

Napi::Number FastNoiseJs::SetSeed(const Napi::CallbackInfo& info) {
  Napi::Number value = info[0].As<Napi::Number>();

  this->noise.SetSeed(value.Int32Value());

  return value;
}

Napi::Number FastNoiseJs::SetFrequency(const Napi::CallbackInfo& info) {
  Napi::Number value = info[0].As<Napi::Number>();

  this->noise.SetFrequency(value.Int32Value());

  return value;
}

Napi::Number FastNoiseJs::SetInterp(const Napi::CallbackInfo& info) {
  Napi::Number value = info[0].As<Napi::Number>();

  this->noise.SetInterp(value.Int32Value());

  return value;
}

Napi::Number FastNoiseJs::SetNoiseType(const Napi::CallbackInfo& info) {
  Napi::Number value = info[0].As<Napi::Number>();

  this->noise.SetNoiseType(value.Int32Value());

  return value;
}

Napi::Number FastNoiseJs::SetFractalOctaves(const Napi::CallbackInfo& info) {
  Napi::Number value = info[0].As<Napi::Number>();

  this->noise.SetFractalOctaves(value.Int32Value());

  return value;
}

Napi::Number FastNoiseJs::SetFractalLacunarity(const Napi::CallbackInfo& info) {
  Napi::Number value = info[0].As<Napi::Number>();

  this->noise.SetFractalLacunarity(value.Int32Value());

  return value;
}

Napi::Number FastNoiseJs::SetFractalGain(const Napi::CallbackInfo& info) {
  Napi::Number value = info[0].As<Napi::Number>();

  this->noise.SetFractalGain(value.Int32Value());

  return value;
}

Napi::Number FastNoiseJs::SetFractalType(const Napi::CallbackInfo& info) {
  Napi::Number value = info[0].As<Napi::Number>();

  this->noise.SetFractalType(value.Int32Value());

  return value;
}

Napi::Number FastNoiseJs::SetCellularDistanceFunction(const Napi::CallbackInfo& info) {
  Napi::Number value = info[0].As<Napi::Number>();

  this->noise.SetCellularDistanceFunction(value.Int32Value());

  return value;
}

Napi::Number FastNoiseJs::SetCellularReturnType(const Napi::CallbackInfo& info) {
  Napi::Number value = info[0].As<Napi::Number>();

  this->noise.SetCellularReturnType(value.Int32Value());

  return value;
}

Napi::Number FastNoiseJs::SetCellularDistance2Indices(const Napi::CallbackInfo& info) {
  Napi::Number value = info[0].As<Napi::Number>();

  this->noise.SetCellularDistance2Indices(value.Int32Value());

  return value;
}

Napi::Number FastNoiseJs::SetCellularJitter(const Napi::CallbackInfo& info) {
  Napi::Number value = info[0].As<Napi::Number>();

  this->noise.SetCellularJitter(value.Int32Value());

  return value;
}

Napi::Number FastNoiseJs::GetNoise(const Napi::CallbackInfo& info) {
  float res;

  switch(info.Length()) {
    case 2:
      res = this->noise.GetNoise(info[0].As<Napi::Number>().DoubleValue(), info[1].As<Napi::Number>().DoubleValue());
      break;
    case 3:
      res = this->noise.GetNoise(
          info[0].As<Napi::Number>().DoubleValue(),
          info[1].As<Napi::Number>().DoubleValue(),
          info[2].As<Napi::Number>().DoubleValue());
      break;
  }

  return Napi::Number::New(info.Env(), res);
}

Napi::Number FastNoiseJs::GetValue(const Napi::CallbackInfo& info) {
  float res;

  FastNoiseJs* obj = ObjectWrap::Unwrap<FastNoiseJs>(args.Holder());

  switch(info.Length()) {
    case 2:
      res = this->noise.GetValue(info[0].As<Napi::Number>().DoubleValue(), info[1].As<Napi::Number>().DoubleValue());
      break;
    case 3:
      res = this->noise.GetValue(
          info[0].As<Napi::Number>().DoubleValue(),
          info[1].As<Napi::Number>().DoubleValue(),
          info[2].As<Napi::Number>().DoubleValue());
      break;
  }

  return Napi::Number::New(info.Env(), res);
}

Napi::Number FastNoiseJs::GetValueFractal(const Napi::CallbackInfo& info) {
  float res;

  FastNoiseJs* obj = ObjectWrap::Unwrap<FastNoiseJs>(args.Holder());

  switch(info.Length()) {
    case 2:
      res = this->noise.GetValueFractal(info[0].As<Napi::Number>().DoubleValue(), info[1].As<Napi::Number>().DoubleValue());
      break;
    case 3:
      res = this->noise.GetValueFractal(
          info[0].As<Napi::Number>().DoubleValue(),
          info[1].As<Napi::Number>().DoubleValue(),
          info[2].As<Napi::Number>().DoubleValue());
      break;
  }

  return Napi::Number::New(info.Env(), res);
}

Napi::Number FastNoiseJs::GetPerlin(const Napi::CallbackInfo& info) {
  float res;

  FastNoiseJs* obj = ObjectWrap::Unwrap<FastNoiseJs>(args.Holder());

  switch(info.Length()) {
    case 2:
      res = this->noise.GetPerlin(info[0].As<Napi::Number>().DoubleValue(), info[1].As<Napi::Number>().DoubleValue());
      break;
    case 3:
      res = this->noise.GetPerlin(
          info[0].As<Napi::Number>().DoubleValue(),
          info[1].As<Napi::Number>().DoubleValue(),
          info[2].As<Napi::Number>().DoubleValue());
      break;
  }

  return Napi::Number::New(info.Env(), res);
}

Napi::Number FastNoiseJs::GetPerlinFractal(const Napi::CallbackInfo& info) {
  float res;

  FastNoiseJs* obj = ObjectWrap::Unwrap<FastNoiseJs>(args.Holder());

  switch(info.Length()) {
    case 2:
      res = this->noise.GetPerlinFractal(info[0].As<Napi::Number>().DoubleValue(), info[1].As<Napi::Number>().DoubleValue());
      break;
    case 3:
      res = this->noise.GetPerlinFractal(
          info[0].As<Napi::Number>().DoubleValue(),
          info[1].As<Napi::Number>().DoubleValue(),
          info[2].As<Napi::Number>().DoubleValue());
      break;
  }

  return Napi::Number::New(info.Env(), res);
} 

Napi::Number FastNoiseJs::GetSimplex(const Napi::CallbackInfo& info) {
  float res;

  FastNoiseJs* obj = ObjectWrap::Unwrap<FastNoiseJs>(args.Holder());

  switch(info.Length()) {
    case 2:
      res = this->noise.GetSimplex(info[0].As<Napi::Number>().DoubleValue(), info[1].As<Napi::Number>().DoubleValue());
      break;
    case 3:
      res = this->noise.GetSimplex(
          info[0].As<Napi::Number>().DoubleValue(),
          info[1].As<Napi::Number>().DoubleValue(),
          info[2].As<Napi::Number>().DoubleValue());
      break;
    case 4:
      res = this->noise.GetSimplex(
          info[0].As<Napi::Number>().DoubleValue(),
          info[1].As<Napi::Number>().DoubleValue(),
          info[2].As<Napi::Number>().DoubleValue(),
          info[3].As<Napi::Number>().DoubleValue());
      break;
  }

  return Napi::Number::New(info.Env(), res);
} 

Napi::Number FastNoiseJs::GetSimplexFractal(const Napi::CallbackInfo& info) {
  float res;

  FastNoiseJs* obj = ObjectWrap::Unwrap<FastNoiseJs>(args.Holder());

  switch(info.Length()) {
    case 2:
      res = this->noise.GetSimplexFractal(info[0].As<Napi::Number>().DoubleValue(), info[1].As<Napi::Number>().DoubleValue());
      break;
    case 3:
      res = this->noise.GetSimplexFractal(
          info[0].As<Napi::Number>().DoubleValue(),
          info[1].As<Napi::Number>().DoubleValue(),
          info[2].As<Napi::Number>().DoubleValue());
      break;
  }

  return Napi::Number::New(info.Env(), res);
} 

Napi::Number FastNoiseJs::GetCellular(const Napi::CallbackInfo& info) {
  float res;

  FastNoiseJs* obj = ObjectWrap::Unwrap<FastNoiseJs>(args.Holder());

  switch(info.Length()) {
    case 2:
      res = this->noise.GetCellular(info[0].As<Napi::Number>().DoubleValue(), info[1].As<Napi::Number>().DoubleValue());
      break;
    case 3:
      res = this->noise.GetCellular(
          info[0].As<Napi::Number>().DoubleValue(),
          info[1].As<Napi::Number>().DoubleValue(),
          info[2].As<Napi::Number>().DoubleValue());
      break;
  }

  return Napi::Number::New(info.Env(), res);
}

Napi::Number FastNoiseJs::GetCubic(const Napi::CallbackInfo& info) {
  float res;

  FastNoiseJs* obj = ObjectWrap::Unwrap<FastNoiseJs>(args.Holder());

  switch(info.Length()) {
    case 2:
      res = this->noise.GetCubic(info[0].As<Napi::Number>().DoubleValue(), info[1].As<Napi::Number>().DoubleValue());
      break;
    case 3:
      res = this->noise.GetCubic(
          info[0].As<Napi::Number>().DoubleValue(),
          info[1].As<Napi::Number>().DoubleValue(),
          info[2].As<Napi::Number>().DoubleValue());
      break;
  }

  return Napi::Number::New(info.Env(), res);
}

Napi::Number FastNoiseJs::GetCubicFractal(const Napi::CallbackInfo& info) {
  float res;

  FastNoiseJs* obj = ObjectWrap::Unwrap<FastNoiseJs>(args.Holder());

  switch(info.Length()) {
    case 2:
      res = this->noise.GetCubicFractal(info[0].As<Napi::Number>().DoubleValue(), info[1].As<Napi::Number>().DoubleValue());
      break;
    case 3:
      res = this->noise.GetCubicFractal(
          info[0].As<Napi::Number>().DoubleValue(),
          info[1].As<Napi::Number>().DoubleValue(),
          info[2].As<Napi::Number>().DoubleValue());
      break;
  }

  return Napi::Number::New(info.Env(), res);
}

Napi::Number FastNoiseJs::GetWhiteNoise(const Napi::CallbackInfo& info) {
  float res;

  FastNoiseJs* obj = ObjectWrap::Unwrap<FastNoiseJs>(args.Holder());

  switch(info.Length()) {
    case 2:
      res = this->noise.GetWhiteNoise(info[0].As<Napi::Number>().DoubleValue(), info[1].As<Napi::Number>().DoubleValue());
      break;
    case 3:
      res = this->noise.GetWhiteNoise(
          info[0].As<Napi::Number>().DoubleValue(),
          info[1].As<Napi::Number>().DoubleValue(),
          info[2].As<Napi::Number>().DoubleValue());
      break;
    case 4:
      res = this->noise.GetWhiteNoise(
          info[0].As<Napi::Number>().DoubleValue(),
          info[1].As<Napi::Number>().DoubleValue(),
          info[2].As<Napi::Number>().DoubleValue(),
          info[3].As<Napi::Number>().DoubleValue());
      break;
  }

  return Napi::Number::New(info.Env(), res);
}

}
