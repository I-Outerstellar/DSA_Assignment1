#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Main.h"

//Helper Function

/// <summary>
/// Converts a string to an integer.
/// </summary>
/// <param name="string"></param>
/// <returns>The integer form of the string, or 0 if it fails.</returns>
static unsigned int parseInt(const char* string) {
	unsigned int buffer;
	int success = sscanf_s(string, "%d", &buffer);
	if (success) return buffer;
	else return 0;
}



//Main Function

int main(int argc, char* argv[]) {
	//Seed randomness
	srand(time(NULL));

	//Create queue and get cmdline argument
	Queue* q = queue_init();
	unsigned int users = parseInt(argv[1]);

	//Generate the queue
	generateQueue(q, users);
	//Then dequeue all the users while printing them
	while (queue_isEmpty(q) == false) {
		User user = queue_dequeue(q);
		printf("%10s | %02d - %s\n", user.username, user.level, factionToString(user.faction));
	}

	queue_free(q);
	
	return 0;
}



//Main.h Functions

unsigned int random(unsigned int min, unsigned int max) {
	//Perform early returns
	if (min == max) return min;
	if (max < min) {
		printf("ERROR: Max cannot be over min.\n");
		return -1;
	}
	//Generate random number
	return rand() % (max - min + 1) + min;
}

User generateUser() {
	//Generate random level and faction
	unsigned int level = random(1, 60);
	Faction faction = random(1, 3);
	//Generate random username
	char username[11];
	for (int i = 0; i < 10; i++) {
		int randomChance = random(1, 10);
		if (randomChance == 1 && i > 3) { //Must be 4-10 characters
			username[i] = '\0';
			break;
		}
		else switch (randomChance % 3) { //Arbitrary assoication
		case 0:
			username[i] = random(48, 57); //0-9
			break;
		case 1:
			username[i] = random(65, 90); //A-Z
			break;
		default:
			username[i] = random(97, 122); //a-z
		}
	}
	username[10] = '\0';

	//Return randomly generated user
	return createUser(level, faction, username);
}

int generateQueue(Queue* queue, unsigned int users) {
	//Perform early return
	if (users == 0) {
		printf("Number of users must be 1 or above.\n");
		return -1;
	}
	//Fill queue with random users and return 0
	for (unsigned int i = 0; i < users; i++) {
		queue_enqueue(queue, generateUser());
	}
	return 0;
}