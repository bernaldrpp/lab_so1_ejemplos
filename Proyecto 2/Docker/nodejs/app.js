const express = require('express');

const app = express();

app.use((req, res, err) => {
  res.send('<h1>Hola desde Nodejs/Express en Docker</h1>')
});

app.listen(3000);