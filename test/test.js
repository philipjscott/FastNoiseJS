const { expect } = require('chai')
const noise = require('../index')

describe('FastNoiseJS library', function () {
  let x, y, z

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
      noise.SetNoiseType(noise.VALUE)
      expect(noise.GetNoise(x, y, z)).to.be.within(-1, 1)
      expect(noise.GetNoise(x, y)).to.be.within(-1, 1)
    })

    it('should work for GetValueFractal', function () {
      noise.SetNoiseType(noise.VALUE_FRACTAL)
      expect(noise.GetNoise(x, y, z)).to.be.within(-1, 1)
      expect(noise.GetNoise(x, y)).to.be.within(-1, 1)
    })

    it('should work for GetPerlin', function () {
      noise.SetNoiseType(noise.PERLIN)
      expect(noise.GetNoise(x, y, z)).to.be.within(-1, 1)
      expect(noise.GetNoise(x, y)).to.be.within(-1, 1)
    })

    it('should work for GetPerlinFractal', function () {
      noise.SetNoiseType(noise.PERLIN_FRACTAL)
      expect(noise.GetNoise(x, y, z)).to.be.within(-1, 1)
      expect(noise.GetNoise(x, y)).to.be.within(-1, 1)
    })

    it('should work for GetSimplex', function () {
      noise.SetNoiseType(noise.SIMPLEX)
      expect(noise.GetNoise(x, y, z)).to.be.within(-1, 1)
      expect(noise.GetNoise(x, y)).to.be.within(-1, 1)
    })

    it('should work for GetSimplexFractal', function () {
      noise.SetNoiseType(noise.SIMPLEX_FRACTAL)
      expect(noise.GetNoise(x, y, z)).to.be.within(-1, 1)
      expect(noise.GetNoise(x, y)).to.be.within(-1, 1)
    })

    it('should work for GetCellular', function () {
      noise.SetNoiseType(noise.CELLULAR)
      expect(noise.GetNoise(x, y, z)).to.be.within(-1, 1)
      expect(noise.GetNoise(x, y)).to.be.within(-1, 1)
    })

    it('should work for GetCubic', function () {
      noise.SetNoiseType(noise.CUBIC)
      expect(noise.GetNoise(x, y, z)).to.be.within(-1, 1)
      expect(noise.GetNoise(x, y)).to.be.within(-1, 1)
    })

    it('should work for GetCubicFractal', function () {
      noise.SetNoiseType(noise.CUBIC_FRACTAL)
      expect(noise.GetNoise(x, y, z)).to.be.within(-1, 1)
      expect(noise.GetNoise(x, y)).to.be.within(-1, 1)
    })

    it('should work for GetWhiteNoise', function () {
      noise.SetNoiseType(noise.WHITE_NOISE)
      expect(noise.GetNoise(x, y, z)).to.be.within(-1, 1)
      expect(noise.GetNoise(x, y)).to.be.within(-1, 1)
    })
  })
})
