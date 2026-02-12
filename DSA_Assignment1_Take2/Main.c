#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Main.h"
#include "Queue.h"

//Main Function

int main(int argc, char* argv[]) {

}



//Main.h Functions

int random(int min, int max) {
	//Perform early returns
	if (min == max) return min;
	if (max > min) {
		printf("ERROR: Max cannot be over min.");
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
		if (randomChance == 1 && i > 3) { //Must be 3-10 characters
			username[i] = '\n';
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
		printf("Number of users must be 1 or above.");
		return -1;
	}
	//Fill queue with random users and return 0
	srand(time(NULL));
	for (int i = 0; i < users; i++)
		queue_enqueue(queue, generateUser());
	return 0;
}