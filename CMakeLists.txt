cmake_minimum_required(VERSION 3.10)
project(RtspServer)

#set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread ")

set(CMAKE_BUILD_TYPE DEBUG)
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

set(INCLUDE_DIR /usr/local/include)
set(LIB_DIR /usr/local/lib)
include_directories(${INCLUDE_DIR})
link_directories(${LIB_DIR})

add_executable(RtspServer
        trunk/Live/Buffer.cpp
        trunk/Live/InetAddress.cpp
        trunk/Live/MediaSessionManager.cpp
        trunk/Live/MediaSession.cpp
        trunk/Live/AACFileMediaSource.cpp
        trunk/Live/H264FileMediaSource.cpp
        trunk/Live/Rtp.cpp
#        trunk/Live/RtpMediaSource.cpp
        trunk/Live/MediaSource.cpp
#        trunk/Live/AACSink.cpp
#        trunk/Live/H264Sink.cpp
        trunk/Live/H264FileSink.cpp
        trunk/Live/AACFileSink.cpp

        trunk/Live/Sink.cpp
        trunk/Live/RtspConnection.cpp
        trunk/Live/RtspServer.cpp
        trunk/Live/TcpConnection.cpp
        trunk/Scheduler/Event.cpp
        trunk/Scheduler/EventScheduler.cpp
        trunk/Scheduler/Poller.cpp
        trunk/Scheduler/SelectPoller.cpp
        trunk/Scheduler/SocketsOps.cpp
        trunk/Scheduler/Thread.cpp
        trunk/Scheduler/ThreadPool.cpp
        trunk/Scheduler/Timer.cpp
        trunk/Scheduler/UsageEnvironment.cpp
        trunk/main.cpp
        )