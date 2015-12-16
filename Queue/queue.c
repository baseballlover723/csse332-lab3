/* This is the shell you must fill in or replace in order to complete
   this project.  Do not forget to include your name in the initial
   comments in this file.
*/

#include <stdio.h>
#include "queue.h"

/****************************************************
 *  * Function: deleteQueue
 *   * Remove all the nodes from the queue, freeing the
 *    * space allocated to each node. The head and tail 
 *     * pointers must each be set to NULL.
 *      ****************************************************/
void deleteQueue(Queue *Aqueue) {

}



/************************************************************
 *  * Function: enqueue
 *   * Add a node to the tail of the queue. The space for the node 
 *    * will be allocated on the heap. The tail pointer will point 
 *     * to this node and the head pointer will continue to point to 
 *      * the node at the start of the queue. 
 *       * Return TRUE if successful, FALSE otherwise.
 *        ************************************************************/
Bool enqueue(Queue *Aqueue, int processId, int arrivalTime, 
                     int serviceTime, int remainingTime) {

    return FALSE;
}



/***************************************************
 *  * Function: printQueue
 *   * Display the values in each node in the queue. 
 *    * Starts at the head.
 *     * Return the number of nodes in the queue.
 *      ***************************************************/
int printQueue(Queue Aqueue) {
    return 0;
}



/****************************************************
 *  * Function: queueSize
 *   * Return the number of nodes in the queue.
 *    ***************************************************/
int queueSize(Queue Aqueue) {
    return 0;
}



/***************************************************
 *  * Function: dequeue
 *   * Remove a node from the head of the queue and return its value.
 *    * Free the space at the heap occupied by this node.
 *     * The head pointer is updated to point to the next node.
 *      * If this is the last item in the queue, then set the head
 *       * and tail pointers to NULL.
 *        * If the queue is empty, return an item with process id = -1.
 *         ***************************************************/
Node dequeue(Queue *Aqueue) {
    if (Aqueue->head == NULL) {
        Node* returnNode = (Node*) malloc(sizeof(Node));
        returnNode->processId = -1;
        return *returnNode;
    } 
    return *Aqueue->head;
}  

