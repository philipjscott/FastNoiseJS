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
  exports.set("ENUM", Napi::Number::New(env, FastNoise::ENUM));

  return exports;
}

namespace fastnoisejs {
  using v8::Context;
  using v8::Function;
  using v8::FunctionCallbackInfo;
  using v8::FunctionTemplate;
  using v8::Isolate;
  using v8::Local;
  using v8::Number;
  using v8::Object;
  using v8::Persistent;
  using v8::String;
  using v8::Value;

  Persistent<Function> FastNoiseJs::constructor;

  FastNoiseJs::FastNoiseJs(int seed) {
    noise.SetSeed(seed);
  }

  FastNoiseJs::~FastNoiseJs() {
  }

  void FastNoiseJs::Init(Isolate* isolate) {
    Local<FunctionTemplate> tpl = FunctionTemplate::New(isolate, New);
    tpl->SetClassName(String::NewFromUtf8(isolate, "FastNoiseJsJs"));
    tpl->InstanceTemplate()->SetInternalFieldCount(1);

    NODE_SET_PROTOTYPE_METHOD(tpl, "GetSeed", GetSeed);

    constructor.Reset(isolate, tpl->GetFunction());
  }

  void FastNoiseJs::New(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();

    if (args.IsConstructCall()) {
      int seed = args[0]->IsUndefined() ? 1337 : args[0]->Int32Value();
      FastNoiseJs* obj = new FastNoiseJs(seed);
      obj->Wrap(args.This());
      args.GetReturnValue().Set(args.This());
    } else {
      NewInstance(args);
    }
  }

  void FastNoiseJs::NewInstance(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();

    const int argc = 1;
    Local<Value> argv[argc] = { args[0] };
    Local<Function> cons = Local<Function>::New(isolate, constructor);
    Local<Context> context = isolate->GetCurrentContext();
    Local<Object> instance =
      cons->NewInstance(context, argc, argv).ToLocalChecked();
    args.GetReturnValue().Set(instance);
  }

  void FastNoiseJs::GetSeed(const FunctionCallbackInfo<Value>& args) {
    FastNoiseJs* obj = ObjectWrap::Unwrap<FastNoiseJs>(args.Holder());
    args.GetReturnValue().Set(Number::New(args.GetIsolate(), obj->noise.GetSeed()));
  }

  void FastNoiseJs::SetSeed(const FunctionCallbackInfo<Value>& args) {
    FastNoiseJs* obj = ObjectWrap::Unwrap<FastNoiseJs>(args.Holder());
    obj->noise.SetSeed(args[0]->Int32Value());
  }

  void FastNoiseJs::SetFrequency(const FunctionCallbackInfo<Value>& args) {
    FastNoiseJs* obj = ObjectWrap::Unwrap<FastNoiseJs>(args.Holder());
    obj->noise.SetFrequency(args[0]->NumberValue());
  }

  void FastNoiseJs::SetInterp(const FunctionCallbackInfo<Value>& args) {
    FastNoiseJs* obj = ObjectWrap::Unwrap<FastNoiseJs>(args.Holder());
    obj->noise.SetInterp(static_cast<FastNoise::Interp>(args[0]->Int32Value()));
  }

  void FastNoiseJs::SetNoiseType(const FunctionCallbackInfo<Value>& args) {
    FastNoiseJs* obj = ObjectWrap::Unwrap<FastNoiseJs>(args.Holder());
    obj->noise.SetNoiseType(static_cast<FastNoise::NoiseType>(args[0]->Int32Value()));
  }

  void FastNoiseJs::SetFractalOctaves(const FunctionCallbackInfo<Value>& args) {
    FastNoiseJs* obj = ObjectWrap::Unwrap<FastNoiseJs>(args.Holder());
    obj->noise.SetFractalOctaves(args[0]->Int32Value());
  }

  void FastNoiseJs::SetFractalLacunarity(const FunctionCallbackInfo<Value>& args) {
    FastNoiseJs* obj = ObjectWrap::Unwrap<FastNoiseJs>(args.Holder());
    obj->noise.SetFractalLacunarity(args[0]->NumberValue());
  }

  void FastNoiseJs::SetFractalGain(const FunctionCallbackInfo<Value>& args) {
    FastNoiseJs* obj = ObjectWrap::Unwrap<FastNoiseJs>(args.Holder());
    obj->noise.SetFractalGain(args[0]->NumberValue());
  }

  void FastNoiseJs::SetFractalType(const FunctionCallbackInfo<Value>& args) {
    FastNoiseJs* obj = ObjectWrap::Unwrap<FastNoiseJs>(args.Holder());
    obj->noise.SetFractalType(static_cast<FastNoise::FractalType>(args[0]->Int32Value()));
  }

  void FastNoiseJs::SetCellularDistanceFunction(const FunctionCallbackInfo<Value>& args) {
    FastNoiseJs* obj = ObjectWrap::Unwrap<FastNoiseJs>(args.Holder());
    obj->noise.SetCellularDistanceFunction(static_cast<FastNoise::CellularDistanceFunction>(args[0]->Int32Value()));
  }

  void FastNoiseJs::SetCellularReturnType(const FunctionCallbackInfo<Value>& args) {
    FastNoiseJs* obj = ObjectWrap::Unwrap<FastNoiseJs>(args.Holder());
    obj->noise.SetCellularReturnType(static_cast<FastNoise::CellularReturnType>(args[0]->Int32Value()));
  }

  void FastNoiseJs::SetCellularDistance2Indices(const FunctionCallbackInfo<Value>& args) {
    FastNoiseJs* obj = ObjectWrap::Unwrap<FastNoiseJs>(args.Holder());
    obj->noise.SetCellularDistance2Indices(args[0]->Int32Value(), args[1]->Int32Value());
  }

  void FastNoiseJs::SetCellularJitter(const FunctionCallbackInfo<Value>& args) {
    FastNoiseJs* obj = ObjectWrap::Unwrap<FastNoiseJs>(args.Holder());
    obj->noise.SetCellularJitter(args[0]->NumberValue());
  }

  void FastNoiseJs::GetNoise(const FunctionCallbackInfo<Value>& args) {
    float res;

    FastNoiseJs* obj = ObjectWrap::Unwrap<FastNoiseJs>(args.Holder());

    switch(args.Length()) {
      case 2:
        res = obj->noise.GetNoise(args[0]->NumberValue(), args[1]->NumberValue());
        break;
      case 3:
        res = obj->noise.GetNoise(
            args[0]->NumberValue(),
            args[1]->NumberValue(),
            args[2]->NumberValue());
        break;
    }

    args.GetReturnValue().Set(Number::New(args.GetIsolate(), res));
  }

  void FastNoiseJs::GetValue(const FunctionCallbackInfo<Value>& args) {
    float res;

    FastNoiseJs* obj = ObjectWrap::Unwrap<FastNoiseJs>(args.Holder());

    switch(args.Length()) {
      case 2:
        res = obj->noise.GetValue(args[0]->NumberValue(), args[1]->NumberValue());
        break;
      case 3:
        res = obj->noise.GetValue(
            args[0]->NumberValue(),
            args[1]->NumberValue(),
            args[2]->NumberValue());
        break;
    }

    args.GetReturnValue().Set(Number::New(args.GetIsolate(), res));
  }

  void FastNoiseJs::GetValueFractal(const FunctionCallbackInfo<Value>& args) {
    float res;

    FastNoiseJs* obj = ObjectWrap::Unwrap<FastNoiseJs>(args.Holder());

    switch(args.Length()) {
      case 2:
        res = obj->noise.GetValueFractal(args[0]->NumberValue(), args[1]->NumberValue());
        break;
      case 3:
        res = obj->noise.GetValueFractal(
            args[0]->NumberValue(),
            args[1]->NumberValue(),
            args[2]->NumberValue());
        break;
    }

    args.GetReturnValue().Set(Number::New(args.GetIsolate(), res));
  }

  void FastNoiseJs::GetPerlin(const FunctionCallbackInfo<Value>& args) {
    float res;

    FastNoiseJs* obj = ObjectWrap::Unwrap<FastNoiseJs>(args.Holder());

    switch(args.Length()) {
      case 2:
        res = obj->noise.GetPerlin(args[0]->NumberValue(), args[1]->NumberValue());
        break;
      case 3:
        res = obj->noise.GetPerlin(
            args[0]->NumberValue(),
            args[1]->NumberValue(),
            args[2]->NumberValue());
        break;
    }

    args.GetReturnValue().Set(Number::New(args.GetIsolate(), res));
  }

  void FastNoiseJs::GetPerlinFractal(const FunctionCallbackInfo<Value>& args) {
    float res;

    FastNoiseJs* obj = ObjectWrap::Unwrap<FastNoiseJs>(args.Holder());

    switch(args.Length()) {
      case 2:
        res = obj->noise.GetPerlinFractal(args[0]->NumberValue(), args[1]->NumberValue());
        break;
      case 3:
        res = obj->noise.GetPerlinFractal(
            args[0]->NumberValue(),
            args[1]->NumberValue(),
            args[2]->NumberValue());
        break;
    }

    args.GetReturnValue().Set(Number::New(args.GetIsolate(), res));
  } 

  void FastNoiseJs::GetSimplex(const FunctionCallbackInfo<Value>& args) {
    float res;

    FastNoiseJs* obj = ObjectWrap::Unwrap<FastNoiseJs>(args.Holder());

    switch(args.Length()) {
      case 2:
        res = obj->noise.GetSimplex(args[0]->NumberValue(), args[1]->NumberValue());
        break;
      case 3:
        res = obj->noise.GetSimplex(
            args[0]->NumberValue(),
            args[1]->NumberValue(),
            args[2]->NumberValue());
        break;
      case 4:
        res = obj->noise.GetSimplex(
            args[0]->NumberValue(),
            args[1]->NumberValue(),
            args[2]->NumberValue(),
            args[3]->NumberValue());
        break;
    }

    args.GetReturnValue().Set(Number::New(args.GetIsolate(), res));
  } 

  void FastNoiseJs::GetSimplexFractal(const FunctionCallbackInfo<Value>& args) {
    float res;

    FastNoiseJs* obj = ObjectWrap::Unwrap<FastNoiseJs>(args.Holder());

    switch(args.Length()) {
      case 2:
        res = obj->noise.GetSimplexFractal(args[0]->NumberValue(), args[1]->NumberValue());
        break;
      case 3:
        res = obj->noise.GetSimplexFractal(
            args[0]->NumberValue(),
            args[1]->NumberValue(),
            args[2]->NumberValue());
        break;
    }

    args.GetReturnValue().Set(Number::New(args.GetIsolate(), res));
  } 

  void FastNoiseJs::GetCellular(const FunctionCallbackInfo<Value>& args) {
    float res;

    FastNoiseJs* obj = ObjectWrap::Unwrap<FastNoiseJs>(args.Holder());

    switch(args.Length()) {
      case 2:
        res = obj->noise.GetCellular(args[0]->NumberValue(), args[1]->NumberValue());
        break;
      case 3:
        res = obj->noise.GetCellular(
            args[0]->NumberValue(),
            args[1]->NumberValue(),
            args[2]->NumberValue());
        break;
    }

    args.GetReturnValue().Set(Number::New(args.GetIsolate(), res));
  }

  void FastNoiseJs::GetCubic(const FunctionCallbackInfo<Value>& args) {
    float res;

    FastNoiseJs* obj = ObjectWrap::Unwrap<FastNoiseJs>(args.Holder());

    switch(args.Length()) {
      case 2:
        res = obj->noise.GetCubic(args[0]->NumberValue(), args[1]->NumberValue());
        break;
      case 3:
        res = obj->noise.GetCubic(
            args[0]->NumberValue(),
            args[1]->NumberValue(),
            args[2]->NumberValue());
        break;
    }

    args.GetReturnValue().Set(Number::New(args.GetIsolate(), res));
  }

  void FastNoiseJs::GetCubicFractal(const FunctionCallbackInfo<Value>& args) {
    float res;

    FastNoiseJs* obj = ObjectWrap::Unwrap<FastNoiseJs>(args.Holder());

    switch(args.Length()) {
      case 2:
        res = obj->noise.GetCubicFractal(args[0]->NumberValue(), args[1]->NumberValue());
        break;
      case 3:
        res = obj->noise.GetCubicFractal(
            args[0]->NumberValue(),
            args[1]->NumberValue(),
            args[2]->NumberValue());
        break;
    }

    args.GetReturnValue().Set(Number::New(args.GetIsolate(), res));
  }

  void FastNoiseJs::GetWhiteNoise(const FunctionCallbackInfo<Value>& args) {
    float res;

    FastNoiseJs* obj = ObjectWrap::Unwrap<FastNoiseJs>(args.Holder());

    switch(args.Length()) {
      case 2:
        res = obj->noise.GetWhiteNoise(args[0]->NumberValue(), args[1]->NumberValue());
        break;
      case 3:
        res = obj->noise.GetWhiteNoise(
            args[0]->NumberValue(),
            args[1]->NumberValue(),
            args[2]->NumberValue());
        break;
      case 4:
        res = obj->noise.GetWhiteNoise(
            args[0]->NumberValue(),
            args[1]->NumberValue(),
            args[2]->NumberValue(),
            args[3]->NumberValue());
        break;
    }

    args.GetReturnValue().Set(Number::New(args.GetIsolate(), res));
  }

}
