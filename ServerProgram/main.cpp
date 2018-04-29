#include <zmq.hpp>
#include <iostream>
#include <unistd.h>

int main() {
    zmq::context_t context(1);
    zmq::socket_t socket(context, ZMQ_REP);
    socket.bind("tcp://*:8080");

    while (true) {
        zmq::message_t request;

        socket.recv(&request);
        std::string clientMessage = std::string(static_cast<char *>(request.data()), request.size());


        std::cout << "client: " + clientMessage << std::endl;
        sleep(1);

        std::string msgToClient("Get away from me kid."); //add user input later
        std::cout << "server: " << msgToClient << "\n";
        zmq::message_t reply(msgToClient.size());
        memcpy((void *) reply.data(), (msgToClient.c_str()), msgToClient.size());
        socket.send(reply);
    }
    return 0;
}
