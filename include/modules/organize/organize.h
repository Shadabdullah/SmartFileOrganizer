#ifndef ORGANIZE_H
#define ORGANIZE_H

#include "cli.h"

// Creating default directory and hard link to it.

int organize(sfo_state *state);

void options_list();

int organize_default();

// Organizing directories based on the files in cwd

int organize_images();
int organize_videos();
int organize_texts();
int organize_others();

// Future: Creating organize modules/methods/etc. to receive input from AI output that is generated based on assumptions from different factors ( images ( count, sizes, names/etc. ), videos/etc )
// So the AI/ML could give output based on many factors that could be used/received in the new modules/methods/functions/etc.
//
// 	user input -> AI/ML output -> input to organize methods -> output to user ( newly created directories, shortcuts/desktop icons, hard/soft links/etc ) 


#endif
