#pragma once
#include <stdbool.h>
#include "User.h"

/// <summary>
/// A struct representing a node of a queue.
/// </summary>
typedef struct Node Node;

/// <summary>
/// A struct representing a queue of users.
/// </summary>
typedef struct Queue Queue;

/// <summary>
/// Initializes a queue to be ready for use.
/// </summary>
/// <returns></returns>
Queue* queue_init();

/// <summary>
/// Checks if a queue has no users in it.
/// </summary>
/// <param name="queue"></param>
/// <returns>True if the queue is empty, false if not.</returns>
bool queue_isEmpty(Queue* queue);

/// <summary>
/// Adds a user to the queue.
/// </summary>
/// <param name="queue"></param>
/// <param name="user"></param>
/// <returns>True if the user is added, false if not.</returns>
bool queue_enqueue(Queue* queue, User user);

/// <summary>
/// Removes the user who was enqueued the latest.
/// </summary>
/// <param name="queue"></param>
/// <returns>The queued user, or an error-case user if the queue was empty.</returns>
User queue_dequeue(Queue* queue);

/// <summary>
/// Frees a queue and all queued users it contains.
/// </summary>
/// <param name="queue"></param>
void queue_free(Queue* queue);