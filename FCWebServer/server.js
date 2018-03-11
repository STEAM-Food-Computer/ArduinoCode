'use strict';
const express = require('express');
const app = express();
const http = require('http').Server(app);
const io = require('socket.io')(http);
const port = 5006; //PORT NUMBER FOR SOCKET

app.get('/', function(req, res){
    res.sendFile(__dirname+'/index.html');
});

io.on('connect', function(socket){
  console.log('someone connected from: ' + socket.handshake.address);

    //listens for client data
    socket.on('data', incoming => {
        console.log(incoming);
    });
    socket.on('sendDataToServer', function(incoming){
        var info = {temperature:25, humidity:50, watersensor:99};
        console.log(incoming);
        io.emit('sendDataToWebPage', info);
    });
});



http.listen(port, function(){
    console.log('listening on *:5006');
});
