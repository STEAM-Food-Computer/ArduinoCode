

  var socket = io();

  socket.on('connect', function(){
    document.getElementById('socket').innerHTML = 'connected to the server';
  });

  socket.on('sendDataToWebPage', function(info){
    document.getElementById('battery').innerHTML = 'Battery: ' + (info.battery*100).toFixed(2) + '%';
    document.getElementById('cpu').innerHTML = 'CPU: ' + (info.cpu*100).toFixed(2) + '%';
    document.getElementById('memory').innerHTML = 'Memory: ' + (info.memory*100).toFixed(2) + '%';
  });

  socket.on('disconnected',function(){
    document.getElementById('socket').innerHTML = 'disconnected';
  });
