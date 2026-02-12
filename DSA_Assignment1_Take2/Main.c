#include <stdio.h>
#include <stdlib.h>

#include "Main.h"
#include "Queue.h"

int main(int argc, char* argv[]) {

}

int random(int min, int max) {
	if (min == max) return min;
	if (max > min) {
		printf("ERROR: Max cannot be over min.");
		return -1;
	}
	return rand() % (max - min + 1) + min;
}

User generateUser() {
	unsigned int level = random(1, 60);
	Faction faction = random(1, 3);
	char username[11];
	for (int i = 0; i < 10; i++) {
		int randomChance = random(1, 10);
		if (randomChance == 1 && i > 3) {
			username[i] = '\n';
			break;
		}
		else switch (randomChance % 3) {
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

	return createUser(level, faction, username);
}

void generateQueue(Queue* queue) {
	
}