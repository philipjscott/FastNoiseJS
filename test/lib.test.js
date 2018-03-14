const { expect } = require('chai')
const fastnoise = require('../index')

describe('FastNoiseJS library', function () {
  let x, y, z
  const noise = new fastnoise.Noise()

  beforeEach(function () {
    x = Math.random() * 50
    y = Math.random() * 50
    z = Math.random() * 50
  })

  describe('Getting noise values from getter functions', function () {
    it('should work for GetValue', function () {
      expect(noise.GetValue(x, y, z)).to.be.within(-1, 1)
      expect(noise.GetValue(x, y)).to.be.within(-1, 1)
    })

    it('should work for GetValueFractal', function () {
      expect(noise.GetValueFractal(x, y, z)).to.be.within(-1, 1)
      expect(noise.GetValueFractal(x, y)).to.be.within(-1, 1)
    })

    it('should work for GetPerlin', function () {
      expect(noise.GetPerlin(x, y, z)).to.be.within(-1, 1)
      expect(noise.GetPerlin(x, y)).to.be.within(-1, 1)
    })

    it('should work for GetPerlinFractal', function () {
      expect(noise.GetPerlinFractal(x, y, z)).to.be.within(-1, 1)
      expect(noise.GetPerlinFractal(x, y)).to.be.within(-1, 1)
    })

    it('should work for GetSimplex', function () {
      expect(noise.GetSimplex(x, y, z)).to.be.within(-1, 1)
      expect(noise.GetSimplex(x, y)).to.be.within(-1, 1)
    })

    it('should work for GetSimplexFractal', function () {
      expect(noise.GetSimplexFractal(x, y, z)).to.be.within(-1, 1)
      expect(noise.GetSimplexFractal(x, y)).to.be.within(-1, 1)
    })

    it('should work for GetCellular', function () {
      expect(noise.GetCellular(x, y, z)).to.be.within(-1, 1)
      expect(noise.GetCellular(x, y)).to.be.within(-1, 1)
    })

    it('should work for GetCubic', function () {
      expect(noise.GetCubic(x, y, z)).to.be.within(-1, 1)
      expect(noise.GetCubic(x, y)).to.be.within(-1, 1)
    })

    it('should work for GetCubicFractal', function () {
      expect(noise.GetCubicFractal(x, y, z)).to.be.within(-1, 1)
      expect(noise.GetCubicFractal(x, y)).to.be.within(-1, 1)
    })

    it('should work for GetWhiteNoise', function () {
      expect(noise.GetWhiteNoise(x, y, z)).to.be.within(-1, 1)
      expect(noise.GetWhiteNoise(x, y)).to.be.within(-1, 1)
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
