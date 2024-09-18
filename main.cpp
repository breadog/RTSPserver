#include "Scheduler/EventScheduler.h"
#include "Scheduler/ThreadPool.h"
#include "Scheduler/UsageEnvironment.h"
#include "Live/MediaSessionManager.h"
#include "Live/RtspServer.h"
#include "Live/H264FileMediaSource.h"
#include "Live/H264FileSink.h"
#include "Live/AACFileMediaSource.h"

#include "Live/AACFileSink.h"
#include "Base/Log.h"

// 函数指针 https://blog.csdn.net/m0_45388819/article/details/113822935

int main() {
    /*
    * 
    程序初始化了一份session名为test的资源，访问路径如下

    // rtp over tcp
    ffplay -i -rtsp_transport tcp  rtsp://127.0.0.1:8554/test

    // rtp over udp
    ffplay -i rtsp://127.0.0.1:8554/test
    
    */

    srand(time(NULL));//时间初始化

    EventScheduler* scheduler = EventScheduler::createNew(EventScheduler::POLLER_SELECT);
    ThreadPool* threadPool = ThreadPool::createNew(1);// 
    MediaSessionManager* sessMgr = MediaSessionManager::createNew();
    UsageEnvironment* env = UsageEnvironment::createNew(scheduler, threadPool);
 
    Ipv4Address rtspAddr("127.0.0.1", 8554);
    RtspServer* rtspServer = RtspServer::createNew(env, sessMgr,rtspAddr);

    LOGI("----------session init start------");
    {
        MediaSession* session = MediaSession::createNew("test");
        MediaSource* source = H264FileMediaSource::createNew(env, "../data/daliu.h264");
        Sink* sink = H264FileSink::createNew(env, source);
        session->addSink(MediaSession::TrackId0, sink);

        source = AACFileMeidaSource::createNew(env, "../data/daliu.aac");
        sink = AACFileSink::createNew(env, source);
        session->addSink(MediaSession::TrackId1, sink);

        //session->startMulticast(); //多播
        sessMgr->addSession(session);
    }
    LOGI("----------session init end------");


    rtspServer->start();

    env->scheduler()->loop();
    return 0;

}