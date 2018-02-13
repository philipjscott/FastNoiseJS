const segfaultHandler = require('segfault-handler')

segfaultHandler.registerHandler('crash.log')

const fastnoise = require('./index')
const noise = fastnoise.Create()

console.log('done')
