/**
 * @file NetUdp.cpp
 * @author zk (zk@domain.com)
 * @brief  方法实现
 * @version 0.1
 * @date 2022-05-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */
//include ---------------------------------------------------------------------------------
#include<sys/socket.h>
#include<string.h>
#include<stdio.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<pthread.h>

#include"NetUdp/NetUdp.h"
//come true ----------------------------------------------------------------

NetUdp::NetUdp(/* args */)
{
}


/**
 * @brief 创建UDP
 * 
 * @param strIp 
 * @param port 
 */
void    NetUdp::CreateU(char * strIp,unsigned short port)
{
    if(strIp == NULL) 
    {
        perror("IP error");
    }

    //创建Udp 通信的套接子 应用层
    m_hSocket = socket(AF_INET,SOCK_DGRAM,0);
    if(m_hSocket  <  0 )
    {
        perror("socket error");
    }
    
    //创建地址格式
    struct sockaddr_in local; //
    local.sin_family = AF_INET; //IP v4
    local.sin_port = htons(port);
    local.sin_addr.s_addr = inet_addr(strIp);

    if(bind(m_hSocket,(struct sockaddr*)&local,sizeof(local)) < 0)
    {
        perror("bind error");
    }

       pthread_t tid;
    pthread_create(&tid,NULL,thread_recv_send,this);
    pthread_detach(tid);
   
 // thread_recv_send(this);
}

/**
 * @brief Udp的接受与发送
 * 
 * @param argv 
 * @return void* 
 */
void * NetUdp::thread_recv_send(void *argv)
{
    char buffer[1024];
    sockaddr_in peer;
    socklen_t len = sizeof(peer);
    NetUdp* tu = (NetUdp*)argv;
    while (1)
    {
        memset(buffer,0,1024);
        recvfrom(tu->m_hSocket,buffer,sizeof(buffer),0,(sockaddr *)&peer,&len) ;
         printf("get a client,socket: %s:%d\n",inet_ntoa(peer.sin_addr),ntohs(peer.sin_port));

         printf("#########################\n");
         if(sizeof(buffer)>1)
         {
             printf("client : %s ,echo client!\n",buffer);
            printf("#########################\n");
              sendto(tu->m_hSocket,buffer,sizeof(buffer),0,(struct sockaddr*)&peer,len);
         }
    }
}

NetUdp::~NetUdp()
{
    if(m_hSocket < 0 )
    {
        close(m_hSocket);
    }
}