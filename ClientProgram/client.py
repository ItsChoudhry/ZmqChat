import zmq

context = zmq.Context()
socket = context.socket(zmq.REQ)
port = "8080"
socket.connect ("tcp://localhost:%s" % port)

while True:
    client_message = input("client: ")
    socket.send_string(client_message)
    message = socket.recv()
    print("server:", message.decode("utf-8"))
