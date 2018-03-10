{
  "targets": [
    {
      "target_name": "noise",
      "cflags!": [ "-fno-exceptions" ],
      "cflags_cc!": [ "-fno-exceptions" ],
      "sources": [
        "addon.cc",
        "FastNoiseJs.cc",
        "./vendor/FastNoise.cc"
      ],
      "include_dirs": [
        "<!@(node -p \"require('node-addon-api').include\")"
      ],
      "defines": [ "NAPI_DISABLE_CPP_EXCEPTIONS" ],
    }
  ]
}
