 #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 5351
#define SERVER_ADDR "192.168.0.232"

typedef struct {
    unsigned int seq;
    int body_len;
} Point;

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    Point p = {12, 22};

    // 创建socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // 设置服务器地址结构体
    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // 将IP地址转换为网络字节序
    if (inet_pton(AF_INET, SERVER_ADDR, &serv_addr.sin_addr) <= 0) {
        perror("invalid address");
        exit(EXIT_FAILURE);
    }

    // 连接服务器
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connection failed");
        exit(EXIT_FAILURE);
    }

    // 发送结构体
    if (send(sock, &p, sizeof(p), 0) < 0) {
        perror("send failed");
        exit(EXIT_FAILURE);
    }

    printf("Sent: (%d, %d)\n", p.seq, p.body_len);

    // 接收回复
    Point reply;
    if (recv(sock, &reply, sizeof(reply), 0) < 0) {
        perror("recv failed");
        exit(EXIT_FAILURE);
    }

    printf("Received: (%u, %d)\n", reply.seq, reply.body_len);

    // 关闭连接
    close(sock);

    return 0;
}
