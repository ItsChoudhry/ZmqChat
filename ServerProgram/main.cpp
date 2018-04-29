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
        std::string msgToSend = "";
        std::getline(std::cin, msgToSend);
        //std::string msgToClient("Get away from me kid.");
        std::cout << "server: " << msgToSend << "\n";
        zmq::message_t reply(msgToSend.size());
        memcpy((void *) reply.data(), (msgToSend.c_str()), msgToSend.size());
        socket.send(reply);
    }
    return 0;
}
