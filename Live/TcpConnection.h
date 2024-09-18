#ifndef RTSPSERVER_TCPCONNECTION_H
#define RTSPSERVER_TCPCONNECTION_H
#include "../Scheduler/UsageEnvironment.h"
#include "../Scheduler/Event.h"
#include "Buffer.h"

class TcpConnection
{
public:
    typedef void (*DisConnectCallback)(void*, int);

    TcpConnection(UsageEnvironment* env, int clientFd);
    virtual ~TcpConnection();

    void setDisConnectCallback(DisConnectCallback cb, void* arg);

protected:
    void enableReadHandling();
    void enableWriteHandling();
    void enableErrorHandling();
    void disableReadeHandling();
    void disableWriteHandling();
    void disableErrorHandling();

    void handleRead();
    virtual void handleReadBytes();
    virtual void handleWrite();
    virtual void handleError();

    void handleDisConnect();

private:
    static void readCallback(void* arg);
    static void writeCallback(void* arg);
    static void errorCallback(void* arg);

protected:
    UsageEnvironment* mEnv;
    int mClientFd;
    IOEvent* mClientIOEvent;
    DisConnectCallback mDisConnectCallback;//在RtspServer实例化该类子类的实例时，设置的回调函数
    void* mArg;
    Buffer mInputBuffer;
    Buffer mOutBuffer;
    char mBuffer[2048];
};

#endif //RTSPSERVER_TCPCONNECTION_H