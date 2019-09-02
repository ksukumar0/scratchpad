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

#ifndef NODEID_H
#define NODEID_H

#include <stdint.h>

#define TOTAL_NODES 8

//extern const uint32_t TOTAL_NODES; // To make calculated Network size available to all files

typedef union {
  unsigned char u8[2];
  uint16_t u16;
} linkaddr_t;
typedef uint16_t node_num_t;
typedef struct nodeID{

    node_num_t nodeID;      // This is the nodeID in the network that we define
    uint16_t serialNumber;  // This is the serial number printed on the label on the mote
    uint16_t rimeID;        // This is the unique MAC address on the mote
}nodeID_t;

//extern const nodeID_t nodes[];

/**
 * @brief       prints a table of Node ID
 *
 *              This function will print the table of NodeIDs present in the
 *              each of the motes
 *
 *
 * @hideinitializer
 */
void print_node_IDs( void );

/**
 * @brief       Gets the current Node's Network node ID
 *
 * @return      The Node's Network ID
 *              This function prints the Nodes network ID. 
 *              Its basically a translation table
 *
 *
 * @hideinitializer
 */
node_num_t getMyNodeID( void );

/**
 * @brief       Gets the current Node's RIME ID
 *
 * @return      The Node's Network ID
 *              This function prints the Nodes network ID. 
 *              Its basically a translation table
 *
 *
 * @hideinitializer
 */
linkaddr_t * getMyRIMEID( void );
uint16_t getRIMEID(node_num_t index);

/**
 * @brief       Compares the RIME ID and returns the received Node's Index in the Routing table
 *
 * @return      The Node's Index in the routing table
 *              This function returns the Nodes Index by taking the
 *              after comparing it in the routing table
 *
 * @hideinitializer
 */
node_num_t getMyNodeIDIndex( void );

/**
 * @brief       Compares the RIME ID and returns the received Node's Nerwork Node ID
 * @param l     The RIME ID of the mote
 *
 * @return      The Node's Network ID
 *              This function prints the Nodes network ID by taking the
 *              RIME ID as the input. Its basically a translation table
 *
 *
 * @hideinitializer
 */
node_num_t returnIDIndex( const linkaddr_t *l );
#endif
