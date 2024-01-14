#include "test.h"
#include "router.h"
#include <QDebug>
#include <QString>
#include <iostream>

Test::Test()
{

}

void Test::testRouter()
{
    RoutingTableEntry entry = {
        "192.168.10.0",
        "255.255.255.0",
        "eth0",
        "192.168.3.10"
    };
    Router  router("router1");
    router.addRouting(entry);
    router.addRouting({
                          "192.168.10.0",
                          "255.255.255.0",
                          "eth0",
                          "192.168.5.5"
                      });
    router.delRouting(entry);
    std::cout << router.getInfo();
    router.addRouting(entry);
    std::cout << router.getInfo();
}
