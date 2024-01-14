#include "interface.h"
#include <iostream>

Cable::Cable()
    :m_a(nullptr), m_b(nullptr){
}

void Cable::transmit(Port port, const std::string data) {
    if (port == Port::A) {
        m_b->receiveData();
        // TODO
    }
}
Interface::Interface(const std::string &name)
    :m_name(name){ }

void Interface::connect(Cable &cable, Cable::Port p)
{
    m_holdPort = p;
    m_cable = &cable; // 去地址
    if (p == Cable::Port::A && cable.m_a == nullptr) {
        cable.m_a = this;
    } else if (p == Cable::Port::B && cable.m_b == nullptr){
        cable.m_b = this;
    } else {
        std::cout << "This port of cable is used ! \n";
        exit(-1);
    }
}


void Interface::send(Cable::Port p, const std::string &data)
{
    if (m_cable == nullptr) {
        std::cout << "Interface is not connected";
    }
    // TODO


}

