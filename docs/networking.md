# Networking

 - [BPF - the forgotten bytecode](https://blog.cloudflare.com/bpf-the-forgotten-bytecode/)
 - [Distributed computing](https://en.wikipedia.org/wiki/Distributed_computing)
 - [CAP theorem](https://en.wikipedia.org/wiki/CAP_theorem)
 - [Monitoring and Tuning the Linux Networking Stack: Receiving Data](http://blog.packagecloud.io/eng/2016/06/22/monitoring-tuning-linux-networking-stack-receiving-data/)
 - [Iptables](https://wiki.archlinux.org/index.php/iptables)
 - [SSH Tunnel - Local and Remote Port Forwarding Explained With Examples](http://blog.trackets.com/2014/05/17/ssh-tunnel-local-and-remote-port-forwarding-explained-with-examples.html)
 - [Escape and Evasion Egressing Restricted Networks](https://www.optiv.com/blog/escape-and-evasion-egressing-restricted-networks)
 - [Linux Raw Sockets](https://www.schoenitzer.de/blog/2018/Linux%20Raw%20Sockets.html)
 - [benjaminr/vimcap](https://github.com/benjaminr/vimcap) Hex edit pcaps from the comfort of Vim!
 - [How to Build a TCP Connection in Scapy](https://www.fir3net.com/Programming/Python/how-to-build-a-tcp-connection-in-scapy.html)
 - [The Art of Packet Crafting with Scapy](https://0xbharath.github.io/art-of-packet-crafting-with-scapy)

## TCP/IP

 - [The TCP/IP Drinking Game](http://valerieaurora.org/tcpip.html)
 - Let's code a TCP/IP stack
   - [Ethernet & ARP](http://www.saminiir.com/lets-code-tcp-ip-stack-1-ethernet-arp/)

## Bridge

 - [Tun/Tap interface tutorial](http://backreference.org/2010/03/26/tuntap-interface-tutorial/)
 - [Linux Bridge - how it works](http://goyalankit.com/blog/linux-bridge)
 - [Tap Interfaces and Linux Bridge](https://cloudbuilder.in/blogs/2013/12/08/tap-interfaces-linux-bridge/)

## Code example

```C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <arpa/inet.h>
#include <unistd.h>
 
#define LISTEN_PORT 56032
#define LENGTH 1024
 
/*
 $ gcc -o net net.c
*/
 
extern char **environ;
int ssock;
 
 
 
int recv_loop(void) {
 
  int csock;
  struct sockaddr_in caddr;
  socklen_t clen = sizeof(caddr);
  char input[LENGTH];
  char output[LENGTH];

  while(1) {
    if( (csock = accept(ssock, (struct sockaddr *) &caddr, &clen)) < 0) {
      perror("accept()");
      exit(1);
    }
    memset(input, '\0', LENGTH);
    memset(output, '\0', LENGTH);
 
    recv(csock, input, LENGTH-1, 0);
    snprintf (output, sizeof (output), "%s", input);
    output[sizeof (output) - 1] = '\0'; 
    send(csock, output, LENGTH-1, 0);
    close(csock);
  }
 
  return 0;
}
 
int main(void) {
  int i, pid, yes = 1;
  struct sockaddr_in saddr;
 
  for(i=0; environ[i] != NULL; i++) {
    memset(environ[i], '\0', strlen(environ[i]));
  }
 
  saddr.sin_family = AF_INET;
  saddr.sin_addr.s_addr = htonl(INADDR_ANY);
  saddr.sin_port = htons(LISTEN_PORT);
 
  while(1) {
    pid = fork();
    if( pid == 0 ) {
      printf("run (pid=%d)\n", getpid());
      if( (ssock = socket(PF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket()"); 
        exit(1); 
      }
 
      if(setsockopt(ssock, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) <0) {
         perror("setsockopt()");
         exit(1);
      }
 
      if( bind(ssock, (struct sockaddr*) &saddr, sizeof(saddr)) < 0) { 
        perror("bind()"); 
        exit(1); 
      }
 
      if( listen(ssock, 5) < 0) { 
        perror("listen()"); 
        exit(1); 
      }
 
      recv_loop();
    } else {
       wait(NULL);
       close(ssock);
    }
  }
 
  return 0;
}
```
