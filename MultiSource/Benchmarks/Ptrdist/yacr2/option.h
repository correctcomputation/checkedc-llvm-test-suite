
/*
 *
 * option.h
 *
 */


/*
 *
 * Includes.
 *
 */

#ifndef OPTION_H
#define OPTION_H


/*
 *
 * Defines.
 *
 */


/*
 *
 * Types.
 *
 */


/*
 *
 * Globals.
 *
 */

#ifdef OPTION_CODE

#else	/* OPTION_CODE */

#endif	/* OPTION_CODE */


/*
 *
 * Prototypes.
 *
 */

#ifdef OPTION_CODE

void
Option(int argc,
       char * * );

#else	/* OPTION_CODE */

extern void
Option(int argc, _Array_ptr<_Nt_array_ptr<char>> argv : count(argc));

#endif	/* OPTION_CODE */

#pragma CHECKED_SCOPE OFF
#endif	/* OPTION_H */
