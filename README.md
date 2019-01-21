# FastNoiseJS

[![npm version](https://badge.fury.io/js/fastnoisejs.svg)](https://badge.fury.io/js/fastnoisejs)
[![Build Status](https://travis-ci.org/ScottyFillups/FastNoiseJS.svg?branch=master)](https://travis-ci.org/ScottyFillups/FastNoiseJS)
[![Coverage Status](https://coveralls.io/repos/github/ScottyFillups/FastNoiseJS/badge.svg?branch=master)](https://coveralls.io/github/ScottyFillups/FastNoiseJS?branch=master)

![Cellular](https://raw.githubusercontent.com/ScottyFillups/FastNoiseJS/master/images/GetCellular.png)
![Cubic](https://raw.githubusercontent.com/ScottyFillups/FastNoiseJS/master/images/GetCubic.png)
![Perlin](https://raw.githubusercontent.com/ScottyFillups/FastNoiseJS/master/images/GetPerlin.png)
![Simplex](https://raw.githubusercontent.com/ScottyFillups/FastNoiseJS/master/images/GetSimplex.png)
![PerlinFractal]( https://raw.githubusercontent.com/ScottyFillups/FastNoiseJS/master/images/GetPerlinFractal.png)
![SimplexFractal](https://raw.githubusercontent.com/ScottyFillups/FastNoiseJS/master/images/GetSimplexFractal.png)

FastNoiseJS is a noise library that uses [FastNoise](https://github.com/Auburns/FastNoise) as a C++ addon.

## Installation

```bash
$ npm install fastnoisejs --save
```

## Usage

```js
const fastnoise = require('fastnoisejs')
const noise = fastnoise.Create(123)

noise.SetNoiseType(fastnoise.Simplex)

for (let x = 0; x < 10; x++) {
  for (let y = 0; y < 10; y++) {
    console.log(noise.GetNoise(x, y))
  }
}
```

## API 

For more exhaustive documentation, refer to the [FastNoise wiki](https://github.com/Auburns/FastNoise/wiki). The example below highlights how `fastnoisejs` binds `FastNoise`'s methods and enumerated types:

```cc
#include "FastNoise.h"
#include <iostream>

int main() {
  FastNoise noise;

  noise.SetNoiseType(FastNoise::Simplex);
  std::cout << noise.GetNoise(21, 43) << std::endl;

  return 0;
}
```

```js
const fastnoise = require('fastnoisejs')

const noise = fastnoise.Create()
noise.SetNoiseType(fastnoise.Simplex)

console.log(noise.GetNoise(21, 43))
```

#### Noise constructor

```js
const fastnoise = require('fastnoisejs')

// Optional seed argument; must be an integer
const noise = fastnoise.Create(324)
```

#### Accessing enumerated types

```js
const fastnoise = require('fastnoisejs')

// This is not an exhaustive list; read the FastNoise wiki
const enums = [
  fastnoise.Simplex,
  fastnoise.Perlin,
  fastnoise.Linear,
  fastnoise.Quintic
]

console.log(enums)
```

#### Using FastNoise instance methods

```js
const fastnoise = require('fastnoisejs')

const noise = fastnoise.Create()

// SetNoiseType sets the algorithm for noise.GetNoise(x, y)
noise.SetNoiseType(noise.Simplex)

const noiseVals = [
  noise.GetSimplex(23, 43),
  noise.GetValue(23, 43),
  noise.GetPerlin(23, 43),
  noise.GetNoise(23, 43)
]

console.log(noiseVals)
```
