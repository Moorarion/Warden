const { warden } = require('../build/Release/warden');

const result = warden({
  x: 3.5, y: 4.7,
});

console.log(result);
