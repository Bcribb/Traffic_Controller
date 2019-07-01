#include "system.h"
#include "altera_avalon_pio_regs.h"
#include "unistd.h"
typedef struct linkedlist_struct {
	int value;
	struct linkedlist_struct* next;
} linkedlist;
int main(void)
{
	linkedlist* firstNode = (linkedlist*)malloc(sizeof(linkedlist)); //allocate memory for node 1
	(*firstNode).value = 1; //store the value of node 1
	linkedlist* tempNode = (linkedlist*)malloc(sizeof(linkedlist)); //allocate memory for node 2
	(*tempNode).value = 2; //store the value of node 2
	(*firstNode).next = tempNode; //connects node 1 to node 2
	tempNode = (linkedlist*)malloc(sizeof(linkedlist)); //allocate memory for node 3
	(*tempNode).value = 3; //store the value of node 3
	(*(*firstNode).next).next = tempNode; //connects node 2 to node 3
	tempNode = (linkedlist*)malloc(sizeof(linkedlist)); //allocate memory for node 4
	(*tempNode).value = 4; //store the value of node 4
	(*(*(*firstNode).next).next).next = tempNode; //connects node 3 to node 4
	tempNode = (linkedlist*)malloc(sizeof(linkedlist)); //allocate memory for node 5
	(*tempNode).value = 5; //store the value of node 5
	(*(*(*(*firstNode).next).next).next).next = tempNode; //connects node 4 to node 5
	(*tempNode).next = firstNode; //connects node 5 to node 1
	tempNode = firstNode; //sets node 1 as the starting node to step though
	while((*tempNode).next != 0) { //while the next node is not null
		printf("%d\n",(*tempNode).value); //print the value of the node
		tempNode = (*tempNode).next; //goto next node
		usleep(1000000); //wait 1 second
	}
}
