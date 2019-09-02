
/*
   Wireless Sensor Networks Laboratory 2019 -- Group 1

   Technische Universität München
   Lehrstuhl für Kommunikationsnetze
http://www.lkn.ei.tum.de

copyright (c) 2019 Chair of Communication Networks, TUM

project: SolarPro

contributors:
 * Karthik Sukumar
 * Johannes Machleid

 This header file is designed for all nodes to define specific Node IDs depending on the RIME ID.
 */

#ifndef PAYLOAD_H
#define PAYLOAD_H

#include "nodeID.h"
#include <stdint.h>

#define TOTAL_NODES  8
#define BROADCASTMSGSIZE_BYTES  16

typedef enum {
    DISCOVERY = 1,
    EMERGENCY = 2,
    ACK = 3,
}pkttype_t;

typedef struct {
    node_num_t destNode, originNode;
    uint16_t temp_mC;
    uint16_t battVolt_mV;
    uint16_t lightSensor;
    uint16_t servoPos_degs;
}__attribute__ ((packed)) unicastMsg_t;

// custom structures
typedef struct {
	linkaddr_t dest[TOTAL_NODES];			// Destination id. Every node should be able to reach every other node plus itself. Thus total entries are equal to total number of nodes.
	linkaddr_t next_hop[TOTAL_NODES];		// Next hop in route to destination.
    uint8_t cost[TOTAL_NODES]; 			    // Number of total hops of the packet route. Maximum 10.
}__attribute__ ((packed)) r_table_t;

typedef struct {
    char msg[BROADCASTMSGSIZE_BYTES];
    r_table_t myRTable;
    pkttype_t bpkt;
}__attribute__((packed)) broadcastMsg_t;

typedef union {
    broadcastMsg_t b;
    unicastMsg_t u;
}__attribute__((packed)) payload_t;

#endif
