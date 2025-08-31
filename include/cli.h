#ifndef SFO_CLI_H
#define SFO_CLI_H

// Standard includes
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <linux/limits.h>

#define CMD_BACKUP "backup"
#define CMD_EXIT "exit"
#define CMD_ORGANIZE "organize"
#define CMD_STATUS "status"

#define USER_COMMAND_READ_ERROR -1
#define USER_COMMAND_READ_SUCCESS 0

#define USER_INPUT_BUFFER_LENGTH 32

#ifndef PATH_MAX
#define PATH_MAX 4096
#endif

// Main structure for the state of the cli app
typedef struct state
{
	int 	command_status; 				//command status tracker
    	bool    is_running;                 			// stores the current state of the program

    	char    user_input[USER_INPUT_BUFFER_LENGTH];   	// holds the user input
    	char    path[PATH_MAX];    				// Holds the path that the user want to use the program
} sfo_state;

/*
    The function signature for a command handler function.

    The handler must take a single argument of type `sfo_state *`,
        and it must return `void`.
*/
typedef void (*command_handler_t)(sfo_state *);

// This struct groups a user command with its corresponding handler function
typedef struct
{
	char *command;
    command_handler_t handler;
} command_dispatch_table_t;

// Command handler prototypes
void handle_organize(sfo_state *state);
void handle_backup(sfo_state *state);
void handle_status(sfo_state *state);
void handle_exit(sfo_state *state);

extern int read_int(void);
extern void flush_stdin(void);

/*
    This function is responsible to get the user input and handle it
*/
int read_input(sfo_state *state);

/*
 * Main loop of the SmartFileOrganizer app
 * */

int command_state(sfo_state *state);

// Initializer of SmartFileOrganizer app
int init();

#endif
