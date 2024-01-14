#include "router.h"
#include <iomanip>
#include <sstream>

Router::Router(const std::string& name)
    :m_name(name)
{ }

bool Router::addRouting(const RoutingTableEntry& entry)
{
    m_routingTable.insert(entry);
    return true;
}

bool Router::delRouting(const RoutingTableEntry& entry)
{

    for (auto it = m_routingTable.begin(); it != m_routingTable.end(); ++it) {
        if (*it == entry) {
            m_routingTable.erase(it);
            return true; // 成功删除
        }
    }
    // 未找到表项
    return false;

}
std::string Router::getInfo(void) {
    std::stringstream infoStream;

    infoStream << "name : " << m_name << "\n";

    infoStream << std::setw(15) << std::left << "Destination" << std::setw(15) << "Mask"
               << std::setw(15) << "Interface" << std::setw(15) << "NextHop" << "\n";

    for (auto it = m_routingTable.begin(); it != m_routingTable.end(); ++it) {
        infoStream << std::setw(15) << std::left << it->destination << std::setw(15) << it->mask
                   << std::setw(15) << it->interface << std::setw(15) << it->nextHop << "\n";
    }

    return infoStream.str();
}
