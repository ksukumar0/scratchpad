#include "payload.h"
#include "nodeID.h"
#include <stdio.h>
#include <string.h>

extern linkaddr_t linkaddr_node_addr;
extern const nodeID_t nodes[];
r_table_t myrTable;

static void initNetworkDisc(void)
{
    linkaddr_node_addr.u16 = 0xf2f3;
    printf("Network Discovery Initiated\n");
    // reset routing table
    int i=0;
    for(i=0;i<TOTAL_NODES;i++)
    {
        myrTable.dest[i].u16 = nodes[i].rimeID;
        if(myrTable.dest[i].u16 == getMyRIMEID()->u16 )
        {
            myrTable.next_hop[i].u16 = nodes[i].rimeID;
            myrTable.cost[i] = 0;
        }
        else
        {
            myrTable.next_hop[i].u16 = 0xffff;
            myrTable.cost[i] = 0xff;
        }
    }

    linkaddr_t *t = getMyRIMEID();

    return;
}

static void printRTable(const char *text)
{
    int j;
    printf("%s\nMy Node ID: %d\n", text, getMyNodeID());
    printf("=========================================\n");
    for (j=0;j<TOTAL_NODES;j++)
    {
        printf("Destination: %x, Next Hop: %x, Cost: %d\n",myrTable.dest[j].u16,myrTable.next_hop[j].u16,myrTable.cost[j]);
    }
    printf("=========================================\n");
}

int main(void)
{
    payload_t p;
    strncpy(p.b.msg,"HelloWorld",12);
    p.b.bpkt = DISCOVERY;

    printf("Address of struct &p: %x\n",&p);
    printf("Address of struct &p.b: %x\n",&(p.b));
    printf("Address of struct &p.b.msg: %x\n",(p.b.msg));
    printf("Address of struct &p.b.msg[0]: %x\n",&(p.b.msg[0]));
    printf("Value of struct *p.b.msg[0]: %c\n",p.b.msg[0]);
    printf("Value of struct p.b.bpkt: %d\n",p.b.bpkt);

    printf("Size of Payload_t is %d\n", sizeof(payload_t));

    printf("Static function called from inside main and Returned %d\n",testStaticFcn());

    initNetworkDisc();
    printRTable("===== This is the Table after init =====\n");

    p.b.myRTable = myrTable;
    char *c = (char *)&p;
    for (int i=0; i < sizeof(payload_t); i++)
    {
        if (i < 16)
            printf("%c",*(c++));
        else
            printf("Byte %d - %x\n",i,(uint8_t)*(c++));
    }

    return 0;
}
