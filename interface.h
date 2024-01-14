#ifndef INTERFACE_H
#define INTERFACE_H

#include <vector>
#include <string>

class Cable;

class Interface {
    Interface();
    void send(std::string);
    std::string receive();
private:
    std::string name;
    Cable *cable;
};

class IDevice {

    void addInterface();
    void delInterface();

    std::vector<Interface> m_interfaces;
};

class Cable
{
public:
    Cable();

    IDevice* a;
    IDevice* b;

};

#endif // INTERFACE_H
