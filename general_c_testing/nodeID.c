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

 This c-file is designed for all nodes to set specific Node IDs depending on the RIME ID.
 */


// Std file includes
#include <stdio.h>

// Private includes
#include "nodeID.h"

const nodeID_t nodes[] =
{
    {1,2048,0xBFED},
    {2,2215,0xF2F3},
    {3,2162,0x60EF},
    {4,2031,0xE7F3},
    {5,1982,0xDCF3},
    {6,2053,0xDDED},
    {7,2207,0xB0EE},
    {8,2071,0x0CF4}
};

linkaddr_t linkaddr_node_addr;

// static uint32_t TOTAL_NODES = (sizeof(nodes))/(sizeof(nodeID_t));

/** This prints the Network IDs of the nodes
* @brief function for printing the node IDs on the console
*/
void print_node_IDs( void )
{
    int i=0;
    printf("=========================================\n");
    for (i=0;i<TOTAL_NODES;i++)
    {
        printf("Node ID: %d, Serial No: %d, Rime ID: %x\n",nodes[i].nodeID,nodes[i].serialNumber,nodes[i].rimeID);
    }
    printf("=========================================\n");
}

linkaddr_t * getMyRIMEID( void )
{
	return &linkaddr_node_addr;
}

uint16_t getRIMEID(node_num_t index)
{
    return nodes[index].rimeID;
}

node_num_t getMyNodeID( void )
{
    int i=0;
    for (i=0;i<TOTAL_NODES;i++)
    {
        // printf("Mine is %x   Node ID is %x\n", linkaddr_node_addr.u16, nodes[i].rimeID);
        if ( linkaddr_node_addr.u16 == nodes[i].rimeID )
        {
            return nodes[i].nodeID;
        }
    }
    return -1;
}

node_num_t getMyNodeIDIndex( void )
{
    int i=0;
    for (i=0;i<TOTAL_NODES;i++)
    {
        if ( linkaddr_node_addr.u16 == nodes[i].rimeID )
        {
            return (nodes[i].nodeID-1);
        }
    }
    return -1;
}

node_num_t returnIDIndex( const linkaddr_t *l)
{
    int i=0;
    for (i=0;i<TOTAL_NODES;i++)
    {
        if ( l->u16 == nodes[i].rimeID )
        {
            return (nodes[i].nodeID-1);
        }
    }
    return -1;
}
