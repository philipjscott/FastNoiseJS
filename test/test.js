const { expect } = require('chai')
const noise = require('../index')

describe('FastNoiseJS library', function () {
  describe('Getting noise values from getter functions', function () {
    let x, y, z

    beforeEach(function () {
      x = Math.random() * 50
      y = Math.random() * 50
      z = Math.random() * 50
    })

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
})
