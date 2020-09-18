#ifndef _SPIROENTRYPOINTS_H
#define _SPIROENTRYPOINTS_H
#include "bezctx_intf.h"
#include "spiro.h"

#ifdef __cplusplus
extern "C" {
#endif

/* _ * Constants * _ */

/* Possible values of the "ty" field. */
static const char SPIRO_CORNER = 'v';
static const char SPIRO_G4 = 'o';
static const char SPIRO_G2 = 'c';
static const char SPIRO_LEFT = '[';
static const char SPIRO_RIGHT = ']';

/* For a closed contour add an extra cp with a ty set to */
static const char SPIRO_END = 'z';
/* For an open contour the first cp must have a ty set to*/
static const char SPIRO_OPEN_CONTOUR = '{';
/* For an open contour the last cp must have a ty set to */
static const char SPIRO_END_OPEN_CONTOUR = '}';

/* Curve crossing point with a 'fixed angle' of crossing */
static const char SPIRO_ANCHOR = 'a';
/* Curve crossing handle cp(hx,hy) relative to cp(ax,ay) */
static const char SPIRO_HANDLE = 'h';

/* int ncq flags and values */
static const int SPIRO_INCLUDE_LAST_KNOT = 0x0100;
static const int SPIRO_RETRO_VER1 = 0x0400;
static const int SPIRO_REVERSE_SRC = 0x0800;
static const int SPIRO_ARC_CUB_QUAD_CLR = 0x7FFF;
static const int SPIRO_ARC_CUB_QUAD_MASK = 0x7000;
static const int SPIRO_CUBIC_TO_BEZIER = 0x0000;
static const int SPIRO_CUBIC_MIN_MAYBE = 0x1000;
static const int SPIRO_ARC_MAYBE = 0x2000;
static const int SPIRO_ARC_MIN_MAYBE = 0x3000;
static const int SPIRO_QUAD0_TO_BEZIER = 0x4000;

/* _ * Functions * _ */
/* Backwards compatibility functions */

/* These 6 functions are kept for backwards compatibility for older */
/* programs. Please use the functions listed afterwards that return */
/* success/failure replies when done. See version 20190731 or later */
extern void TaggedSpiroCPsToBezier(spiro_cp *spiros,void* bc);
extern void SpiroCPsToBezier(spiro_cp *spiros,int n,int isclosed,void* bc);

/* These functions are available in libspiro-0.2.20130930 or higher */
extern int TaggedSpiroCPsToBezier0(spiro_cp *spiros,void* bc);
extern int SpiroCPsToBezier0(spiro_cp *spiros,int n,int isclosed,void* bc);

/* These functions are available in libspiro-0.3.20150131 or higher */
extern void TaggedSpiroCPsToBezier1(spiro_cp *spiros,void* bc,int *done);
extern void SpiroCPsToBezier1(spiro_cp *spiros,int n,int isclosed,void* bc,int *done);

/* End backwards compatibility functions */

/* These functions are available in libspiro-20190731 or higher and */
/* give you best flexibility compared to earlier libspiro versions. */
extern const char *LibSpiroVersion(void);

/* The spiros array should indicate it's own end... So              */
/* Open contours must have the ty field of the first cp set to '{'  */
/*               and have the ty field of the last cp set to '}'    */
/* Closed contours must have an extra cp at the end whose ty is 'z' */
/*               the x&y values of this extra cp are ignored        */
/* ncq allows you to toggle different outputs independent of spiros */
extern int TaggedSpiroCPsToBezier2(spiro_cp *spiros,int ncq,void* bc);

/* The first argument is an array of spiro control points.          */
/* Open contours do not need to start with '{', nor to end with '}' */
/* Close contours do not need to end with 'z'                       */
/* ncq allows you to toggle different outputs independent of spiros */
extern int SpiroCPsToBezier2(spiro_cp *spiros,int n,int ncq,int isclosed,void* bc);

#ifdef __cplusplus
}
#endif
#endif
