#ifndef NetworkManager_H
#define NetworkManager_H

#include <stdexcept>
#include <thread>
#include <raknet/RakPeerInterface.h>

class Connection;

class NetworkManager
{
public:
    NetworkManager();
    ~NetworkManager();
    void close();
    /**
     * Try to start up an server NetworkManager and start listenning on it.
     * @throw std::runtime_error if start up failed
     * @return `true` if start up successfully,`false` if already running,otherwise throws an exception
     */
    bool run(const char *addr,unsigned short port);
private:
    void loop();
    Connection *newConnection(RakNet::SystemAddress addr);
    void deleteConnection(RakNet::SystemAddress addr);
    RakNet::RakPeerInterface *mPeer;
    std::thread mThread;
    std::vector<Connection*> mConns;
};

/** The base class of any Connection class to it's NetworkManager
 *  @see NetworkManager
 *  @see NetworkManager
 */
class Connection
{
public:
    friend class NetworkManager;
    // TODO: method `send()` to send packet(flatbuffers)
private:
    Connection(NetworkManager &network,RakNet::RakPeerInterface *peer,RakNet::SystemAddress addr);
    ~Connection();
    void sendRawData(const char *data, int len,PacketPriority priority,PacketReliability reliability);
    NetworkManager &mNetwork;
    RakNet::RakPeerInterface *mPeer;
    RakNet::SystemAddress mAddr;
};

#endif
