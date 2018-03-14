#include "FastNoiseJs.h"

Napi::FunctionReference FastNoiseJs::constructor;

Napi::Object FastNoiseJs::Init(Napi::Env env, Napi::Object exports) {
  Napi::HandleScope scope(env);

  Napi::Function func = DefineClass(env, "FastNoiseJs", {
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
  constructor.SuppressDestruct();

  exports.Set("Noise", func);
  exports.Set("Value", Napi::Number::New(env, FastNoise::Value));
  exports.Set("ValueFractal", Napi::Number::New(env, FastNoise::ValueFractal));
  exports.Set("Perlin", Napi::Number::New(env, FastNoise::Perlin));
  exports.Set("PerlinFractal", Napi::Number::New(env, FastNoise::PerlinFractal));
  exports.Set("Simplex", Napi::Number::New(env, FastNoise::Simplex));
  exports.Set("SimplexFractal", Napi::Number::New(env, FastNoise::SimplexFractal));
  exports.Set("Cellular", Napi::Number::New(env, FastNoise::Cellular));
  exports.Set("Cubic", Napi::Number::New(env, FastNoise::Cubic));
  exports.Set("CubicFractal", Napi::Number::New(env, FastNoise::CubicFractal));
  exports.Set("WhiteNoise", Napi::Number::New(env, FastNoise::WhiteNoise));

  exports.Set("Linear", Napi::Number::New(env, FastNoise::Linear));
  exports.Set("Hermite", Napi::Number::New(env, FastNoise::Hermite));
  exports.Set("Quintic", Napi::Number::New(env, FastNoise::Quintic));

  exports.Set("FBM", Napi::Number::New(env, FastNoise::FBM));
  exports.Set("Billow", Napi::Number::New(env, FastNoise::Billow));
  exports.Set("RigidMulti", Napi::Number::New(env, FastNoise::RigidMulti));

  exports.Set("Euclidean", Napi::Number::New(env, FastNoise::Euclidean));
  exports.Set("Manhattan", Napi::Number::New(env, FastNoise::Manhattan));
  exports.Set("Natural", Napi::Number::New(env, FastNoise::Natural));

  exports.Set("CellValue", Napi::Number::New(env, FastNoise::CellValue));
  exports.Set("NoiseLookup", Napi::Number::New(env, FastNoise::NoiseLookup));
  exports.Set("Distance", Napi::Number::New(env, FastNoise::Distance));
  exports.Set("Distance2", Napi::Number::New(env, FastNoise::Distance2));
  exports.Set("Distance2Add", Napi::Number::New(env, FastNoise::Distance2Add));
  exports.Set("Distance2Sub", Napi::Number::New(env, FastNoise::Distance2Sub));
  exports.Set("Distance2Mul", Napi::Number::New(env, FastNoise::Distance2Mul));
  exports.Set("Distance2Div", Napi::Number::New(env, FastNoise::Distance2Div));

  return exports;
}

FastNoiseJs::FastNoiseJs(const Napi::CallbackInfo& info) : Napi::ObjectWrap<FastNoiseJs>(info)  {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);

  int length = info.Length();

  if (length > 0) {
    if (!info[0].IsNumber()) {
      Napi::TypeError::New(env, "Number expected").ThrowAsJavaScriptException();
    } else {
      Napi::Number value = info[0].As<Napi::Number>();
      this->noise.SetSeed(value.Int32Value());
    }
  }
}

Napi::Value FastNoiseJs::GetSeed(const Napi::CallbackInfo& info) {
  return Napi::Number::New(info.Env(), this->noise.GetSeed());
}

Napi::Value FastNoiseJs::SetSeed(const Napi::CallbackInfo& info) {
  Napi::Number value = info[0].As<Napi::Number>();

  this->noise.SetSeed(value.Int32Value());

  return value;
}

Napi::Value FastNoiseJs::SetFrequency(const Napi::CallbackInfo& info) {
  Napi::Number value = info[0].As<Napi::Number>();

  this->noise.SetFrequency(value.DoubleValue());

  return value;
}

Napi::Value FastNoiseJs::SetInterp(const Napi::CallbackInfo& info) {
  Napi::Number value = info[0].As<Napi::Number>();

  this->noise.SetInterp(static_cast<FastNoise::Interp>(value.Int32Value()));

  return value;
}

Napi::Value FastNoiseJs::SetNoiseType(const Napi::CallbackInfo& info) {
  Napi::Number value = info[0].As<Napi::Number>();

  this->noise.SetNoiseType(static_cast<FastNoise::NoiseType>(value.Int32Value()));

  return value;
}

Napi::Value FastNoiseJs::SetFractalOctaves(const Napi::CallbackInfo& info) {
  Napi::Number value = info[0].As<Napi::Number>();

  this->noise.SetFractalOctaves(value.Int32Value());

  return value;
}

Napi::Value FastNoiseJs::SetFractalLacunarity(const Napi::CallbackInfo& info) {
  Napi::Number value = info[0].As<Napi::Number>();

  this->noise.SetFractalLacunarity(value.DoubleValue());

  return value;
}

Napi::Value FastNoiseJs::SetFractalGain(const Napi::CallbackInfo& info) {
  Napi::Number value = info[0].As<Napi::Number>();

  this->noise.SetFractalGain(value.DoubleValue());

  return value;
}

Napi::Value FastNoiseJs::SetFractalType(const Napi::CallbackInfo& info) {
  Napi::Number value = info[0].As<Napi::Number>();

  this->noise.SetFractalType(static_cast<FastNoise::FractalType>(value.Int32Value()));

  return value;
}

Napi::Value FastNoiseJs::SetCellularDistanceFunction(const Napi::CallbackInfo& info) {
  Napi::Number value = info[0].As<Napi::Number>();

  this->noise.SetCellularDistanceFunction(static_cast<FastNoise::CellularDistanceFunction>(value.Int32Value()));

  return value;
}

Napi::Value FastNoiseJs::SetCellularReturnType(const Napi::CallbackInfo& info) {
  Napi::Number value = info[0].As<Napi::Number>();

  this->noise.SetCellularReturnType(static_cast<FastNoise::CellularReturnType>(value.Int32Value()));

  return value;
}

Napi::Value FastNoiseJs::SetCellularDistance2Indices(const Napi::CallbackInfo& info) {
  Napi::Number i1 = info[0].As<Napi::Number>();
  Napi::Number i2 = info[0].As<Napi::Number>();

  this->noise.SetCellularDistance2Indices(i1.Int32Value(), i2.Int32Value());

  return i1;
}

Napi::Value FastNoiseJs::SetCellularJitter(const Napi::CallbackInfo& info) {
  Napi::Number value = info[0].As<Napi::Number>();

  this->noise.SetCellularJitter(value.DoubleValue());

  return value;
}

Napi::Value FastNoiseJs::GetNoise(const Napi::CallbackInfo& info) {
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

Napi::Value FastNoiseJs::GetValue(const Napi::CallbackInfo& info) {
  float res;

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

Napi::Value FastNoiseJs::GetValueFractal(const Napi::CallbackInfo& info) {
  float res;

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

Napi::Value FastNoiseJs::GetPerlin(const Napi::CallbackInfo& info) {
  float res;

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

Napi::Value FastNoiseJs::GetPerlinFractal(const Napi::CallbackInfo& info) {
  float res;

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

Napi::Value FastNoiseJs::GetSimplex(const Napi::CallbackInfo& info) {
  float res;

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

Napi::Value FastNoiseJs::GetSimplexFractal(const Napi::CallbackInfo& info) {
  float res;

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

Napi::Value FastNoiseJs::GetCellular(const Napi::CallbackInfo& info) {
  float res;

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

Napi::Value FastNoiseJs::GetCubic(const Napi::CallbackInfo& info) {
  float res;

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

Napi::Value FastNoiseJs::GetCubicFractal(const Napi::CallbackInfo& info) {
  float res;

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

Napi::Value FastNoiseJs::GetWhiteNoise(const Napi::CallbackInfo& info) {
  float res;

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
