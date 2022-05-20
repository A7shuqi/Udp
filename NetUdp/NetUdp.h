/**
 * @file NetUdp.h
 * @author zk (zk@domain.com)
 * @brief   UDP Create
 * @version 0.1
 * @date 2022-05-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef __UDP__
#define __UDP__
// include  -------------------------------------------------------------------------------------------------------------------------------------




//def---------------------------------------------------------------------------------
class NetUdp
{
private:
    /* data */
    int m_hSocket;
public:
    NetUdp(/* args */);
    ~NetUdp();
    void CreateU(char * strIp,unsigned short port);
    static void * thread_recv_send(void *argv);
};





#endif