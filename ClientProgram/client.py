import zmq

context = zmq.Context()
socket = context.socket(zmq.REQ)
port = "8080"
socket.connect ("tcp://localhost:%s" % port)


for i in range (1,10):
    client_message = "Notice me senpai!!!!" #add user input later
    socket.send_string(client_message)
    print("client: ", client_message)
    message = socket.recv()
    print("server:", message.decode("utf-8"))
