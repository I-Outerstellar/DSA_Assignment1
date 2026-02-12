#pragma once

/// <summary>
/// An enum representing the factions a user can be in.
/// </summary>
typedef enum Faction {
	ERROR, //For an error-handling case

	RED,
	GREEN,
	BLUE
} Faction;

/// <summary>
/// A struct representing a user.
/// </summary>
typedef struct User {
	char username[11];
	unsigned int level;
	Faction faction;
} User;

/// <summary>
/// Creates a user with the given attributes and within program limitations.
/// </summary>
/// <param name="level"></param>
/// <param name="faction"></param>
/// <param name="username"></param>
/// <returns>A user within the program's limits.</returns>
User createUser(unsigned int level, Faction faction, char* username);

/// <summary>
/// Returns the string name of the faction.
/// </summary>
/// <param name="faction"></param>
/// <returns>A string of the faction enum.</returns>
const char* factionToString(Faction faction);