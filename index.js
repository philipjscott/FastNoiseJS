const fastnoise = require('bindings')('addon')

fastnoise.Create = function (seed) {
  const noise = (seed)
    ? new fastnoise.Noise(seed)
    : new fastnoise.Noise()

  return noise
}

module.exports = fastnoise
