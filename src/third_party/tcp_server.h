// snatched from https://habr.com/ru/post/503432/


#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <cstdint>
#include <functional>
#include <thread>
#include <list>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>


//Буффер для приёма данных от клиента
static constexpr uint16_t buffer_size = 4096;

struct TcpServer
{
    class Client;
    //Тип Callback-функции обработчика клиента
    typedef std::function<void(Client)> handler_function_t;
    //Статус сервера
    enum class status : uint8_t
    {
        up = 0,
        err_socket_init = 1,
        err_socket_bind = 2,
        err_socket_listening = 3,
        close = 4
    };

private:
    in_port_t port; //Порт
    status _status = status::close;
    handler_function_t handler;

    std::thread handler_thread;
    std::list<std::thread> client_handler_threads;
    std::list<std::thread::id> client_handling_end;

    volatile sig_atomic_t sig_stop;

    int serv_socket;

    void handlingLoop();

public:
    TcpServer(const in_port_t port, handler_function_t handler);
    ~TcpServer();

    //! Set client handler
    void setHandler(handler_function_t handler);

    in_port_t getPort() const;
    in_port_t setPort(const in_port_t port);

    status getStatus() const { return _status; }

    status restart();
    status start();
    void stop();
    inline void setSigStop() { sig_stop = 1; }

    void joinLoop();
};

class TcpServer::Client
{
    int _socket;
    struct sockaddr_in address;
    char buffer[buffer_size];

public:
    Client(int socket, struct sockaddr_in address);
    Client(const Client &other);
    ~Client();
    in_addr_t getHost() const;
    in_port_t getPort() const;

    ssize_t loadData();
    char *getData();

    bool sendData(const char *buffer, const size_t size) const;
};

#endif // TCPSERVER_H
