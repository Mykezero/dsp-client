#include <stdlib.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <stdint.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <string.h>

/* 
 * Packet Structure
 * https://wiki.dspt.info/index.php/Packet_Header
 */
struct header
{
	uint8_t id;
	uint8_t size;
	uint16_t sync;
	uint8_t payload[12];
};

int main(void)
{
	int32_t map_server_port = 54230;
	struct sockaddr_in map_server_address;
	memset(&map_server_address, 0, sizeof(map_server_address));

	map_server_address.sin_port = htons(map_server_port);
	map_server_address.sin_addr.s_addr = INADDR_ANY;
	map_server_address.sin_family = AF_INET;

	printf("############################################################## \n");
	printf("DSP-Client \n");
	printf("############################################################## \n");

	int32_t sockfd = socket(AF_INET, SOCK_DGRAM, 0);

	if (sockfd < 0) 
	{
		perror("Failed to create socket");
		exit(EXIT_FAILURE);
	}

	printf("Socket created: fd=%d\n\n", sockfd);

	char* buffer = "TEST!";
	int32_t r = sendto(sockfd, &buffer, sizeof(buffer), 0, (struct sockaddr*)&map_server_address, sizeof(map_server_address));
	printf("Sending Packet Results: \n***ErrorCode: %d, \n***ErrorMessage: %s, \n***Result: %d", errno, strerror(errno), r);

	if(close(sockfd) < 0)
	{
		perror("Failed to close socket");
		exit(EXIT_FAILURE);
	}
}