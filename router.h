#ifndef ROUTER_H
#define ROUTER_H

#include <string>
#include <list>
#include <unordered_set>
#include <QDebug>

typedef std::string IPAddr;
typedef std::string Cable;

struct RoutingTableEntry{
    IPAddr destination;        // 目的地址
    IPAddr mask;			   // 掩码
    Cable interface;       // 接口
    IPAddr nextHop;            // 下一跳地址
    bool operator==(const RoutingTableEntry& other) const {
        return this->destination == other.destination &&
               this->mask == other.mask &&
               this->interface == other.interface &&
               this->nextHop == other.nextHop;

    }
};
struct RoutingTqbleEntryHash{
    using StringHash = std::hash<std::string>;
    std::size_t operator()(const RoutingTableEntry& entry) {
        return StringHash()(entry.destination) &
               StringHash()(entry.mask) &
               StringHash()(entry.interface) &
               StringHash()(entry.nextHop);
    }
};



class Router
{
public:
    Router(const std::string& name);
    bool addRouting(const RoutingTableEntry& entry);
    bool delRouting(const RoutingTableEntry& entry);
    std::string getInfo(void);

private:
    std::string m_name;
    Cable m_interface;
    std::unordered_set<RoutingTableEntry, RoutingTqbleEntryHash> m_routingTable;
};

#endif // ROUTER_H
