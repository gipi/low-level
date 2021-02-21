"""
Take in mind that there are some incomptibility issues regarding the
python and javascript socketio versions.

 $ pip install flask-socketio
 $ python3 flask_websocket.py 
 WebSocket transport not available. Install eventlet or gevent and gevent-websocket for improved performance.
  * Serving Flask app "flask_websocket" (lazy loading)
  * Environment: production
    WARNING: This is a development server. Do not use it in a production deployment.
    Use a production WSGI server instead.
  * Debug mode: off
  * Running on http://127.0.0.1:5000/ (Press CTRL+C to quit)
"""
from flask import Flask, request
from flask_socketio import SocketIO, emit


app = Flask(__name__)
socketio = SocketIO(app, async_mode='threading')  # very important the async_mode

clients = []

@socketio.on("connect")
def handle_connect():
    emit("after connect", {
        'data': "Let's dance",
    })
    clients.append(request.sid)


@socketio.on("disconnect")
def handle_disconnect():
    clients.remove(request.sid)


def send_message(client_id, name, data):
    socketio.emit(name, data, room=client_it)


@app.route('/')
def hello_world():
    return """<html>
<head></head>
<body>
    <script src="https://code.jquery.com/jquery-3.5.1.min.js"
        integrity="sha256-9/aliU8dGd2tb6OSsuzixeV4y/faTqgFtohetphbbj0="
        crossorigin="anonymous">
    </script>
    <script
        src="//cdnjs.cloudflare.com/ajax/libs/socket.io/3.1.1/socket.io.js"
        crossorigin="anonymous">
    </script>
    <script type="text/javascript">
    $(document).ready(function() {
        var socket = io();
        socket.on("after connect", function(msg) {
            console.log("msg: " + msg.data);
        });
    });
    </script>
</body>
"""

if __name__ == '__main__':
    socketio.run(app)
