#ifndef FASTNOISEJS_H
#define FASTNOISEJS_H

#include <napi.h>
#include "./vendor/FastNoise.h"

class FastNoiseJs : public Napi::ObjectWrap<FastNoiseJs> {
  public:
    static Napi::Object Init(Napi::Env env, Napi::Object exports);
    FastNoiseJs(const Napi::CallbackInfo& info);

  private:
    static Napi::FunctionReference constructor;

    Napi::Value GetSeed(const Napi::CallbackInfo& info);
    Napi::Value SetSeed(const Napi::CallbackInfo& info);
    Napi::Value SetFrequency(const Napi::CallbackInfo& info);
    Napi::Value SetInterp(const Napi::CallbackInfo& info);
    Napi::Value SetNoiseType(const Napi::CallbackInfo& info);
    Napi::Value SetFractalOctaves(const Napi::CallbackInfo& info);
    Napi::Value SetFractalLacunarity(const Napi::CallbackInfo& info);
    Napi::Value SetFractalGain(const Napi::CallbackInfo& info);
    Napi::Value SetFractalType(const Napi::CallbackInfo& info);
    Napi::Value SetCellularDistanceFunction(const Napi::CallbackInfo& info);
    Napi::Value SetCellularReturnType(const Napi::CallbackInfo& info);
    // SetCellularNoiseLookup(const Napi::CallbackInfo& info); TODO
    Napi::Value SetCellularDistance2Indices(const Napi::CallbackInfo& info);
    Napi::Value SetCellularJitter(const Napi::CallbackInfo& info);

    Napi::Value GetNoise(const Napi::CallbackInfo& info);
    Napi::Value GetValue(const Napi::CallbackInfo& info);
    Napi::Value GetValueFractal(const Napi::CallbackInfo& info);
    Napi::Value GetPerlin(const Napi::CallbackInfo& info);
    Napi::Value GetPerlinFractal(const Napi::CallbackInfo& info);
    Napi::Value GetSimplex(const Napi::CallbackInfo& info);
    Napi::Value GetSimplexFractal(const Napi::CallbackInfo& info);
    Napi::Value GetCellular(const Napi::CallbackInfo& info);
    Napi::Value GetWhiteNoise(const Napi::CallbackInfo& info);
    Napi::Value GetCubic(const Napi::CallbackInfo& info);
    Napi::Value GetCubicFractal(const Napi::CallbackInfo& info);

    FastNoise noise;
};

#endif
