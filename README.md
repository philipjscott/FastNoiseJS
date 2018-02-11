[![Build Status](https://travis-ci.org/ScottyFillups/FastNoiseJS.svg?branch=master)](https://travis-ci.org/ScottyFillups/FastNoiseJS)
[![semantic-release](https://img.shields.io/badge/%20%20%F0%9F%93%A6%F0%9F%9A%80-semantic--release-e10079.svg)](https://github.com/semantic-release/semantic-release)



# FastNoiseJS

FastNoiseJS is a noise library that uses [FastNoise](https://github.com/Auburns/FastNoise) as a C++ addon.

## Installation

```bash
$ yarn add fastnoisejs

# Or, if you're old school...

$ npm install fastnoisejs --save
```

## Usage

```js
const noise = require('fastnoisejs')

noise.SetNoiseType(noise.SIMPLEX)

for (let x = 0; x < 10; x++) {
  for (let y = 0; y < 10; y++) {
    console.log(noise.GetNoise(x, y))
  }
}
```

## Documentation

All functions are overloaded to support 2D and 3D noise:

* noise.GetNoise(x, y{, z})
* noise.GetValue(x, y{, z})
* noise.GetValueFractal(x, y{, z})
* noise.GetPerlin(x, y{, z})
* noise.GetPerlinFractal(x, y{, z})
* noise.GetSimplex(x, y{, z})
* noise.GetSimplexFractal(x, y{, z})
* noise.GetCellular(x, y{, z})
* noise.GetCubic(x, y{, z})
* noise.GetCubicFractal(x, y{, z})
* noise.GetWhiteNoise(x, y,{, z})

The noise type for `noise.GetNoise(x, y{, z})` is set manually.

* noise.SetNoiseType(noise.MY\_NOISE\_TYPE)

Below is a list of all the noise type enumerations:

* noise.VALUE
* noise.VALUE\_FRACTAL
* noise.PERLIN
* noise.PERLIN\_FRACTAL
* noise.SIMPLEX
* noise.SIMPLEX\_FRACTAL
* noise.CELLULAR
* noise.CUBIC
* noise.CUBIC\_FRACTAL
* noise.WHITE\_NOISE
