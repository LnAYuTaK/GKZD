
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERVER_IP "192.168.0.232"
#define SERVER_PORT 5351
//Test Header

typedef struct TPkgHeader_s
{
	unsigned int  seq;
	int body_len;
}TPkgHeader;
//Test 
typedef struct TPkgBody_s 
{
	char name[30];
	short age;
	char desc[1];
}TPkgBody;
//Test body

typedef struct {
    int id;
    char name[20];
    float score;
} Student;

int main() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0); //创建socket
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(SERVER_PORT);
    addr.sin_addr.s_addr = inet_addr(SERVER_IP);

    int ret = connect(sockfd, (struct sockaddr*)&addr, sizeof(addr)); //连接服务器
    if (ret < 0) {
        perror("connect");
        exit(1);
    }
    

    TPkgHeader header;
    
    TPkgBody body;
    body.age = 12;
    memcpy(body.name,"123",6);
   // memcpy(body.desc,'c',1);
    header.body_len = sizeof(header);
    ret = send(sockfd, &header, sizeof(header), 0); //发送结构体
    if (ret < 0) {
        perror("send header error");
        exit(1);
    }
   // ret = send(sockfd, &body, sizeof(body), 0); //发送结构体
    if (ret < 0) {
        perror("send body error");
        exit(1);
    }
    close(sockfd); //关闭socket
    return 0;
}
