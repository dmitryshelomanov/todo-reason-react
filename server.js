const static = require('node-static')

const file = new static.Server('./', { cache: 0 })

require('http').createServer((request, response) => {
  request.addListener('end', () => {
    file.serve(request, response)
  }).resume()
})
.listen(8080)
