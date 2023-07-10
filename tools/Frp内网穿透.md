##  **项目SSH端口映射方法**

1. 准备具有公网IP的服务器 这里使用的是阿里云服务器 
2. 阿里云服务器安装frp软件 阿里云服务器是amd64架构安装 解压tools/frp_0.49.0_linux_amd64.tar.gz 
3. 修改frps.ini  
```ini
[common]
bind_port = 7000 
dashboard_port = 7500
token =12345678
dashboard_user = root
dashboard_pwd = root
vhost_rdp_port = 7001
vhost_ssh_port = 6000 #设置映射ssh端口
```
4. 启动frp服务 
```
./frps -c frps.ini
```
5. Linux嵌入式端 解压
tools/frp_0.49.0_linux_arm64.tar.gz
6. 修改frpc.ini
```ini
[common]
server_addr = 47.98.232.35 #你的服务器ID
server_port = 7000 #与服务器对应
token = 12345678  #与服务器对应
[ssh]
type = tcp
local_ip =127.0.0.1
local_port =22
remote_port =6000
```
7. 启动frp服务 
```
./frpc -c frpc.ini
```
8. ssh登录 IP:47.98.232.35  Port:6000







