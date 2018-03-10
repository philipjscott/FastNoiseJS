#ifndef FASTNOISEJS_H
#define FASTNOISEJS_H

#include <napi.h>
#include "./vendor/FastNoise.h"

class FastNoiseJs : public Napi::ObjectWrap<FastNoiseJs> {
  public:
    static Napi::Object Init(Napi::Env env, Napi::Object exports);
    FastNoise(const Napi::CallbackInfo& info);

  private:
    static Napi::FunctionReference constructor;

    Napi::Number GetSeed(const Napi::CallbackInfo& info);
    Napi::Number SetSeed(const Napi::CallbackInfo& info);
    Napi::Number SetFrequency(const Napi::CallbackInfo& info);
    Napi::Number SetInterp(const Napi::CallbackInfo& info);
    Napi::Number SetNoiseType(const Napi::CallbackInfo& info);
    Napi::Number SetFractalOctaves(const Napi::CallbackInfo& info);
    Napi::Number SetFractalLacunarity(const Napi::CallbackInfo& info);
    Napi::Number SetFractalGain(const Napi::CallbackInfo& info);
    Napi::Number SetFractalType(const Napi::CallbackInfo& info);
    Napi::Number SetCellularDistanceFunction(const Napi::CallbackInfo& info);
    Napi::Number SetCellularReturnType(const Napi::CallbackInfo& info);
    // SetCellularNoiseLookup(const Napi::CallbackInfo& info); TODO
    Napi::Number SetCellularDistance2Indices(const Napi::CallbackInfo& info);
    Napi::Number SetCellularJitter(const Napi::CallbackInfo& info);

    Napi::Number GetNoise(const Napi::CallbackInfo& info);
    Napi::Number GetValue(const Napi::CallbackInfo& info);
    Napi::Number GetValueFractal(const Napi::CallbackInfo& info);
    Napi::Number GetPerlin(const Napi::CallbackInfo& info);
    Napi::Number GetPerlinFractal(const Napi::CallbackInfo& info);
    Napi::Number GetSimplex(const Napi::CallbackInfo& info);
    Napi::Number GetSimplexFractal(const Napi::CallbackInfo& info);
    Napi::Number GetCellular(const Napi::CallbackInfo& info);
    Napi::Number GetWhiteNoise(const Napi::CallbackInfo& info);
    Napi::Number GetCubic(const Napi::CallbackInfo& info);
    Napi::Number GetCubicFractal(const Napi::CallbackInfo& info);

    FastNoise noise;
}

#endif
