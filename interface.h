#ifndef INTERFACE_H
#define INTERFACE_H

#include <vector>
#include <string>


class Interface;

class Cable
{
    friend Interface;
public:
    Cable();
    enum Port{A, B};
    void transmit(Port port, const std::string data);
private:
    Interface* m_a;
    Interface* m_b;

};


class Interface {
public:
    Interface(const std::string& name);
    void connect(Cable &cable, Cable::Port p);
    void send(Cable::Port p, const std::string data);
    void sendData(const std::string data);
    std::string receiveData();

private:
    std::string m_name;
    Cable::Port m_holdPort;
    Cable *m_cable;
};

class IDevice {

    void addInterface();
    void delInterface();

    void sendData(const Interface& interface, const std::string data);
    std::string receiveData(const Interface& interface);

    std::vector<Interface> m_interfaces;
};

#endif // INTERFACE_H
