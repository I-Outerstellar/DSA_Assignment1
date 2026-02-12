#include "User.h"
#include <string.h>

//User.h Functions

User createUser(unsigned int level, Faction faction, char* username) {
	User user;
	
	//Clamp the level
	level = (level < 1) ? 1 : level;
	level = (level > 60) ? 60 : level;

	//Create and return user
	user.level = level;
	user.faction = faction;
	strcpy_s(user.username, 11, username);
	user.username[10] = '\0';
	return user;
}

const char* factionToString(Faction faction) {
	//Return string based on switch statement
	switch (faction) {
	case RED: return "red";
	case GREEN: return "green";
	case BLUE: return "blue";
	default: return "error/null";
	}
}