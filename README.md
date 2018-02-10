# FastNoiseJS

FastNoiseJS is a noise library that uses [FastNoise](https://github.com/Auburns/FastNoise) as a C++ addon.

## Installation

```
$ yarn add fastnoisejs

# Or, if you're old sschool...

$ npm install fastnoisejs --save
```

## Usage

```js
const noise = require('fastnoisejs')

for (let x = 0; x < 10; x++) {
  for (let y = 0; y < 10; y++) {
    console.log(noise.GetSimplex(x, y))
  }
}
```

## Documentation

All functions are overloaded to support 2D and 3D noise:

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
