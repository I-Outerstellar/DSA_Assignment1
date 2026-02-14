# Take 2 of this assignment

Funnily enough, I already wrote this. I just didn't have a GitHub repo.

It should be easier to write the second time around, though.

I won't peek at what I wrote before :)

#

# Data Structures & Algorithms Assignment 1

Using the command line as input, queue the amount of randomly generated User structs specified by the user of the program, then dequeue all of them while displaying their data.

## Details

### ``User-Defined Types``

Faction Enum -- ERROR, RED, GREEN, BLUE

User Struct -- Username (string, max 10 characters), Faction, Level (unsigned int)

Queue Node -- Next Node (Node\*), User

Queue -- Head Node (Node*), Tail Node (Node*)

### ``Files & Functions``

### User

User.h 
- createUser(unsigned int level, Faction faction, char* username)
- factionToString(Faction faction)

User.c
- User.h

### Queue

Queue.h 
- queue_init()
- queue_isEmpty(Queue* queue)
- queue_enqueue(Queue* queue, User user)
- queue_dequeue(Queue* queue)
- queue_free(Queue* queue)
- queue_isFreed(Queue* queue)

Queue.c 
- Queue.h
- createNode()
- findUsername(Queue* queue, const char* username)

### Main

Main.h 
- random(int min, int max)
- generateUser()
- generateQueue(Queue* queue)

Main.c 
- **main(int argc, char\* argv[])**
- Main.h

### GitHub

README.md

.gitignore
