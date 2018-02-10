const noise = require('../index')

for (let x = 0; x < 5; x++) {
  for (let y = 0; y < 5; y++) {
    console.log(noise.GetPerlin(x, y))
  }
}
