#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Struct Initialization

struct Node {
	Node* nextNode;
	User user;
};

struct Queue {
	Node* head, *tail;
};

static User nullUser; //Error-case handling user for dequeue function


//Helper Functions

/// <summary>
/// Allocates memory for a queue node.
/// </summary>
/// <returns></returns>
static Node* createNode() {
	return malloc(sizeof(Node));
}

/// <summary>
/// Finds if the username given exists in the queue given.
/// </summary>
/// <param name="queue"></param>
/// <param name="username"></param>
/// <returns>True if the same username is found, false if not.</returns>
static bool findUsername(Queue* queue, const char* username) {
	Node* temp = queue->head;
	//Traverse the queue to find a matching username
	while (temp != NULL) {
		if (strcmp(temp->user.username, username) == 0) return true;
		temp = temp->nextNode;
	}
	return false;
}



//Queue.h Functions

Queue* queue_init() {
	//Initialize the null user for error-handling
	nullUser = createUser(1, ERROR, "");
	//Create and return the queue (if NULL is not returned)
	Queue* queue = malloc(sizeof(Queue));
	if (queue == NULL) return NULL;
	queue->head = queue->tail = NULL;
	return queue;
}

bool queue_isEmpty(Queue* queue) {
	if (queue_isFreed(queue)) return true;
	return queue->head == NULL;
}

bool queue_enqueue(Queue* queue, User user) {
	//Perform early returns
	if (queue_isFreed(queue)) {
		printf("ERROR: Queue has no allocated memory.\n");
		return false;
	}
	if (findUsername(queue, user.username)) {
		printf("Username of given user is not unique.\n");
		return false;
	}

	//Create and add a new node
	Node* newNode = createNode();
	newNode->user = user;
	newNode->nextNode = NULL;
	if (queue_isEmpty(queue)) //Make sure the head and tail exist
		queue->head = queue->tail = newNode;
	else 
		queue->tail->nextNode = newNode;
	return true;
}

User queue_dequeue(Queue* queue) {
	//Perform early returns
	if (queue_isFreed(queue)) {
		printf("ERROR: Queue has no allocated memory.\n");
		return nullUser;
	}
	if (queue_isEmpty(queue)) {
		printf("Queue has no users queued.\n");
		return nullUser;
	}
	
	//Remove and free the node and return the user
	Node* temp = queue->head;
	User save = temp->user;
	queue->head = temp->nextNode;
	if (queue_isEmpty(queue)) 
		queue->tail = NULL;
	free(temp);
	return save;
}

void queue_free(Queue* queue) {
	//Ensure a double free does not occur
	if (queue_isFreed(queue)) {
		printf("ERROR: Queue has no allocated memory.\n");
		return;
	}
	//Free all nodes
	while (queue->head != NULL) queue_dequeue(queue);
	//Free the queue and set to NULL to indicate it is freed
	free(queue);
	queue = NULL;
}

bool queue_isFreed(Queue* queue) {
	return queue == NULL;
}