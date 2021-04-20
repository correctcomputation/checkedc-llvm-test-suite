
/*
 *
 * option.c
 *
 */

#include <string.h>

#define OPTION_CODE


/*
 *
 * Includes.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "channel.h"


/*
 *
 * Code.
 *
 */

void
Option(int argc, _Array_ptr<char *> argv : count(argc))
{
    /*
     * Check arguments.
     */
    if (argc != 2) _Checked {
	_Unchecked { printf("\nUsage: yacr2 <filename>\n\n"); };
	exit(1);
    }

    /*
     * Specified options.
     */
    channelFile = argv[1];
}
