# C

## Network

### inet_addr 함수

문자열 => struct in_addr

```c
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
int main()
{
	struct sockaddr_in	server_addr;

	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(4000);
	server_addr.sin_addr.s_addr= inet_addr("192.168.0.77"); // 서버

	// ~~~ socket 사용 ~~~/

	return 0;
}
```