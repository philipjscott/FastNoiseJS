#include <napi.h>
#include "./lib/FastNoiseJs.h"

Napi::Object InitAll(Napi::Env env, Napi::Object exports) {
  return FastNoiseJs::Init(env, exports);
}

NODE_API_MODULE(addon, InitAll)
