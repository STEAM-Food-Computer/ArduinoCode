
//TEST CLIENT.

'use strict';
const serverIPandPort = 'http://localhost:5006';//IP ADDRESS AND PORT NUMBER OF THE SERVER.
const socket = require('socket.io-client')(serverIPandPort);
const interval = 5006; //Interval to send data
var info = {};

socket.on('connect', function () {
  console.log('connected to server');
});

//after a set interval, send data to server
setInterval( function() {
    info.battery = Math.random().toFixed(4); //dummy data
    info.cpu = Math.random().toFixed(4);
    info.memory = Math.random().toFixed(4);
    console.log('battery: ' + info.battery + ', CPU: ' + info.cpu + ', memory: ' + info.memory);
  socket.emit('sendDataToServer', info); //Send data to server
}, interval);
