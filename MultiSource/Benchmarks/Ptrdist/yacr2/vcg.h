
/*
 *
 * vcg.h
 *
 */


/*
 *
 * Includes.
 *
 */

#include "types.h"


#ifndef VCG_H
#define VCG_H

/*
 *
 * Defines.
 *
 */

#define	EMPTY			0
#define	EMPTY_HALF_EMPTY	2
#define	EMPTY_FULL		3
#define	HALF_EMPTY		4
#define	HALF_EMPTY_FULL		5
#define	FULL			6


/*
 *
 * Types.
 *
 */

typedef struct _constraintVCGType {
    ulong	top;
    ulong	bot;
    ulong	col;
    ulong	removed;
} constraintVCGType;

typedef struct _nodeVCGType {
    _Array_ptr<constraintVCGType> netsAboveHook ;
    ulong			netsAbove;
    ulong			netsAboveLabel;
    ulong			netsAboveReached;
    _Array_ptr<constraintVCGType> netsBelowHook ;
    ulong			netsBelow;
    ulong			netsBelowLabel;
    ulong			netsBelowReached;
} nodeVCGType;


/*
 *
 * Globals.
 *
 */

extern ulong channelNets;

#ifdef VCG_CODE

nodeVCGType *			VCG ;
constraintVCGType *			storageRootVCG ;
constraintVCGType *			storageVCG ;
ulong					storageLimitVCG;
constraintVCGType * *		removeVCG ;
ulong					removeTotalVCG;
ulong *				SCC ;
ulong					totalSCC;
ulong *				perSCC ;

#else	/* VCG_CODE */

extern _Array_ptr<nodeVCGType> VCG ;
extern _Array_ptr<constraintVCGType> storageRootVCG ;
extern _Array_ptr<constraintVCGType> storageVCG ;
extern ulong					storageLimitVCG;
extern _Array_ptr<_Ptr<constraintVCGType>> removeVCG : count(removeTotalVCG) ;
extern ulong					removeTotalVCG;
extern _Array_ptr<ulong> SCC ;
extern ulong					totalSCC;
extern _Array_ptr<ulong> perSCC ;

#endif	/* VCG_CODE */


/*
 *
 * Prototypes.
 *
 */

#ifdef VCG_CODE

void
AllocVCG(void);

void
FreeVCG(void);

void
BuildVCG(void);

void
DFSClearVCG(nodeVCGType * );

void
DumpVCG(nodeVCGType * );

void
DFSAboveVCG(nodeVCGType * ,
	    ulong);

void
DFSBelowVCG(nodeVCGType * ,
	    ulong);

void
SCCofVCG(nodeVCGType * ,
		 ulong * ,
         ulong * );

void
SCC_DFSAboveVCG(nodeVCGType * ,
				ulong,
				ulong *);

void
SCC_DFSBelowVCG(nodeVCGType * ,
		ulong,
		ulong);

void
DumpSCC(ulong * ,
	    ulong * );

void
AcyclicVCG(void);

void
RemoveConstraintVCG(nodeVCGType * ,
					ulong * ,
					ulong * ,
					constraintVCGType * * );

ulong
ExistPathAboveVCG(nodeVCGType * ,
				  ulong above,
				  ulong below);

void
LongestPathVCG(nodeVCGType * ,
	       ulong);

ulong
DFSAboveLongestPathVCG(nodeVCGType * ,
		       ulong);

ulong
DFSBelowLongestPathVCG(nodeVCGType * ,
		       ulong);

ulong
VCV(nodeVCGType * ,
    ulong,
    ulong,
    ulong * );

#else	/* VCG_CODE */

extern void
AllocVCG(void);

extern void
FreeVCG(void);

extern void
BuildVCG(void);

extern void
DFSClearVCG(_Array_ptr<nodeVCGType> VCG);

extern void
DumpVCG(_Array_ptr<nodeVCGType> VCG);

extern void
DFSAboveVCG(_Array_ptr<nodeVCGType> VCG : count(net), ulong net);

extern void
DFSBelowVCG(_Array_ptr<nodeVCGType> VCG, ulong net);

extern void
SCCofVCG(_Array_ptr<nodeVCGType> VCG, _Array_ptr<ulong> SCC, _Array_ptr<ulong> tmpPerSCC);

extern void
SCC_DFSAboveVCG(_Array_ptr<nodeVCGType> VCG, ulong net, _Ptr<ulong> label);

extern void
SCC_DFSBelowVCG(_Array_ptr<nodeVCGType> VCG, ulong net, ulong label);

extern void
DumpSCC(_Array_ptr<ulong> SCC, _Array_ptr<ulong> perSCC);

extern void
AcyclicVCG(void);

extern void
RemoveConstraintVCG(_Array_ptr<nodeVCGType> VCG, _Array_ptr<ulong> SCC, _Array_ptr<ulong> perSCC, _Array_ptr<_Ptr<constraintVCGType>> removeVCG : count(0));

extern ulong
ExistPathAboveVCG(_Array_ptr<nodeVCGType> VCG : count(above), ulong above, ulong below);

extern void
LongestPathVCG(_Array_ptr<nodeVCGType> VCG : count(net), ulong net);

extern ulong
DFSAboveLongestPathVCG(_Array_ptr<nodeVCGType> VCG : count(net), ulong net);

extern ulong
DFSBelowLongestPathVCG(_Array_ptr<nodeVCGType> VCG : count(net), ulong net);

extern ulong
VCV(_Array_ptr<nodeVCGType> VCG : count(check), ulong check, ulong track, _Array_ptr<ulong> assign);

#endif	/* VCG_CODE */

#pragma CHECKED_SCOPE OFF
#endif	/* VCG_H */
