#include <stdlib.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <stdint.h>

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
	struct header header;
	header.id = 1;
	header.size = 8;
	header.sync = 0;
	header.payload[0] = 10;
}
