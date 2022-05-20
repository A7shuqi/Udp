cmake_minimum_required(VERSION 3.0.0)
project(UdpSerivce VERSION 0.1.0)

include(CTest)
enable_testing()

include_directories(NetUdp)



add_executable(UdpSerivce main.cpp NetUdp.cpp)
target_link_libraries(UdpSerivce pthread) # 要在程序生成是建立动态连连接

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
