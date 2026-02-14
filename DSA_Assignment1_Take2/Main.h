#pragma once
#include "User.h"
#include "Queue.h"

/// <summary>
/// Generates a random number between min and max.
/// </summary>
/// <param name="min"></param>
/// <param name="max"></param>
/// <returns>A random number between min and max, -1 guaranteed if max is greater than min.</returns>
unsigned int random(unsigned int min, unsigned int max);

/// <summary>
/// Generates a randomized user.
/// </summary>
/// <returns>A random user.</returns>
User generateUser();

/// <summary>
/// Fills a given queue with the given amount of users.
/// </summary>
/// <param name="queue"></param>
/// <param name="user"></param>
/// <returns>0 if the function executes, -1 if it doesn't.</returns>
int generateQueue(Queue* queue, unsigned int users);