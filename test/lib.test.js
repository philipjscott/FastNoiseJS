const { expect } = require('chai')
const drawNoise = require('draw-noise')
const fastnoise = require('../')
const path = require('path')

const draw = (fn, filename) => {
  drawNoise((x, y) => fn(x * 10, y * 10), {
    width: 100,
    height: 100,
    filename: path.join(__dirname, `./images/${filename}`)
  })
}

describe('FastNoiseJS library', function () {
  let x, y, z
  const noise = fastnoise.Create()

  beforeEach(function () {
    x = Math.random() * 50
    y = Math.random() * 50
    z = Math.random() * 50
  })

  describe('Object constructors and factories', function () {
    it('produces an object with new fastnoise.Noise()', function () {
      expect(typeof (new fastnoise.Noise()) === 'object')
    })

    it('produces an object with fastnoise.Create()', function () {
      expect(typeof (fastnoise.Create()) === 'object')
    })

    it('will set the seed if an integer is passed', function () {
      const seed = 1000
      const myNoise = fastnoise.Create(seed)

      expect(typeof myNoise === 'object')
      expect(myNoise.GetSeed()).to.equal(seed)
    })
  })

  describe('Getting noise values from getter functions', function () {
    it('should work for GetValue', function () {
      expect(noise.GetValue(x, y, z)).to.be.within(-1, 1)
      expect(noise.GetValue(x, y)).to.be.within(-1, 1)
      draw(noise.GetValue.bind(noise), 'GetValue.png')
    })

    it('should work for GetValueFractal', function () {
      expect(noise.GetValueFractal(x, y, z)).to.be.within(-1, 1)
      expect(noise.GetValueFractal(x, y)).to.be.within(-1, 1)
      draw(noise.GetValueFractal.bind(noise), 'GetValueFractal.png')
    })

    it('should work for GetPerlin', function () {
      expect(noise.GetPerlin(x, y, z)).to.be.within(-1, 1)
      expect(noise.GetPerlin(x, y)).to.be.within(-1, 1)
      draw(noise.GetPerlin.bind(noise), 'GetPerlin.png')
    })

    it('should work for GetPerlinFractal', function () {
      expect(noise.GetPerlinFractal(x, y, z)).to.be.within(-1, 1)
      expect(noise.GetPerlinFractal(x, y)).to.be.within(-1, 1)
      draw(noise.GetPerlinFractal.bind(noise), 'GetPerlinFractal.png')
    })

    it('should work for GetSimplex', function () {
      expect(noise.GetSimplex(x, y, z)).to.be.within(-1, 1)
      expect(noise.GetSimplex(x, y)).to.be.within(-1, 1)
      draw(noise.GetSimplex.bind(noise), 'GetSimplex.png')
    })

    it('should work for GetSimplexFractal', function () {
      expect(noise.GetSimplexFractal(x, y, z)).to.be.within(-1, 1)
      expect(noise.GetSimplexFractal(x, y)).to.be.within(-1, 1)
      draw(noise.GetSimplexFractal.bind(noise), 'GetSimplexFractal.png')
    })

    it('should work for GetCellular', function () {
      expect(noise.GetCellular(x, y, z)).to.be.within(-1, 1)
      expect(noise.GetCellular(x, y)).to.be.within(-1, 1)
      draw(noise.GetCellular.bind(noise), 'GetCellular.png')
    })

    it('should work for GetCubic', function () {
      expect(noise.GetCubic(x, y, z)).to.be.within(-1, 1)
      expect(noise.GetCubic(x, y)).to.be.within(-1, 1)
      draw(noise.GetCubic.bind(noise), 'GetCubic.png')
    })

    it('should work for GetCubicFractal', function () {
      expect(noise.GetCubicFractal(x, y, z)).to.be.within(-1, 1)
      expect(noise.GetCubicFractal(x, y)).to.be.within(-1, 1)
      draw(noise.GetCubicFractal.bind(noise), 'GetCubicFractal.png')
    })

    it('should work for GetWhiteNoise', function () {
      expect(noise.GetWhiteNoise(x, y, z)).to.be.within(-1, 1)
      expect(noise.GetWhiteNoise(x, y)).to.be.within(-1, 1)
      draw(noise.GetWhiteNoise.bind(noise), 'GetWhiteNoise.png')
    })
  })

  describe('Getting noise by setting manually', function () {
    it('should work for GetValue', function () {
      noise.SetNoiseType(fastnoise.Value)
      expect(noise.GetNoise(x, y, z)).to.be.within(-1, 1)
      expect(noise.GetNoise(x, y)).to.be.within(-1, 1)
    })

    it('should work for GetValueFractal', function () {
      noise.SetNoiseType(fastnoise.ValueFractal)
      expect(noise.GetNoise(x, y, z)).to.be.within(-1, 1)
      expect(noise.GetNoise(x, y)).to.be.within(-1, 1)
    })

    it('should work for GetPerlin', function () {
      noise.SetNoiseType(fastnoise.Perlin)
      expect(noise.GetNoise(x, y, z)).to.be.within(-1, 1)
      expect(noise.GetNoise(x, y)).to.be.within(-1, 1)
    })

    it('should work for GetPerlinFractal', function () {
      noise.SetNoiseType(fastnoise.PerlinFractal)
      expect(noise.GetNoise(x, y, z)).to.be.within(-1, 1)
      expect(noise.GetNoise(x, y)).to.be.within(-1, 1)
    })

    it('should work for GetSimplex', function () {
      noise.SetNoiseType(fastnoise.Simplex)
      expect(noise.GetNoise(x, y, z)).to.be.within(-1, 1)
      expect(noise.GetNoise(x, y)).to.be.within(-1, 1)
    })

    it('should work for GetSimplexFractal', function () {
      noise.SetNoiseType(fastnoise.SimplexFractal)
      expect(noise.GetNoise(x, y, z)).to.be.within(-1, 1)
      expect(noise.GetNoise(x, y)).to.be.within(-1, 1)
    })

    it('should work for GetCellular', function () {
      noise.SetNoiseType(fastnoise.Cellular)
      expect(noise.GetNoise(x, y, z)).to.be.within(-1, 1)
      expect(noise.GetNoise(x, y)).to.be.within(-1, 1)
    })

    it('should work for GetCubic', function () {
      noise.SetNoiseType(fastnoise.Cubic)
      expect(noise.GetNoise(x, y, z)).to.be.within(-1, 1)
      expect(noise.GetNoise(x, y)).to.be.within(-1, 1)
    })

    it('should work for GetCubicFractal', function () {
      noise.SetNoiseType(fastnoise.CubicFractal)
      expect(noise.GetNoise(x, y, z)).to.be.within(-1, 1)
      expect(noise.GetNoise(x, y)).to.be.within(-1, 1)
    })

    it('should work for GetWhiteNoise', function () {
      noise.SetNoiseType(fastnoise.WhiteNoise)
      expect(noise.GetNoise(x, y, z)).to.be.within(-1, 1)
      expect(noise.GetNoise(x, y)).to.be.within(-1, 1)
    })
  })
})
