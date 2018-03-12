const fastnoisejs = require('./')

const noise = new fastnoisejs.Create(10)

for (let i = 0; i < 100; i++) {
  for (let j = 0; j < 100; j++) {
    console.log(noise.GetNoise(i/32,j/32))
  }
}
