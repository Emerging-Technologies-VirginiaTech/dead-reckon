// original code from https://github.com/craigpeacock/CAN-Examples/blob/master/canfilter.c 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/socket.h>

#include <linux/can.h>
#include <linux/can/raw.h>

/** Code is used to get WSS CAN data and print it to terminal **/
int main(int argc, char **argv)
{
	int s, i; 
	int nbytes;
	struct sockaddr_can addr;
	struct ifreq ifr;
	struct can_frame frame;

	// create a socket and check for error
	if ((s = socket(PF_CAN, SOCK_RAW, CAN_RAW)) < 0) {
		perror("Error opening socket");
		return -1;
	}

	// retrieve interface index for can0
	strcpy(ifr.ifr_name, "can0");
	ioctl(s, SIOCGIFINDEX, &ifr);

	// set address location and following bytes up to the size of addr with zeros
	memset(&addr, 0, sizeof(addr));

	// set can family
	addr.can_family = AF_CAN;
	addr.can_ifindex = ifr.ifr_ifindex;

	// bind socket to address and check for error
	if (bind(s, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
		perror("Error binding socket");
		return -2;
	}

	// instantiate array of can_filter structs
	struct can_filter rfilter[2];


	// set canIDs and filters
	rfilter[0].can_id   = 0x0C1; // front wheel sensors
	rfilter[0].can_mask = 0xFFFF;
	rfilter[1].can_id   = 0x0C5; // rear wheel sensors
	rfilter[1].can_mask = 0xFFFF;

	// loop used to print out the data for can IDs 0x0C1, 0x0C5
	for (int i = 0; i < 2; i++) {
		setsockopt(s, SOL_CAN_RAW, CAN_RAW_FILTER, &rfilter[i], sizeof(rfilter[1]));
		// read up to the size of the CAN frame starting at frame in the socket
		nbytes = read(s, &frame, sizeof(struct can_frame));

		// check for error while reading
		if (nbytes < 0) {
			perror("Error reading from socket");
			return -3;
		}

		// print can id as hexidecimal followed by frame payload length
		printf("0x%03X [%d] ",rfilter[i].can_id, frame.can_dlc);
		// print data
		for (int j = 0; j < frame.can_dlc; j++) {
			printf("%02X ",frame.data[j]);
		}
		printf("\r\n");
	}



	// close socket and check for error
	if (close(s) < 0) {
		perror("Error closing socket");
		return -4;
	}

	//return 0 if successfully completed
	return 0;
}
