#ifndef __M_LOGGING_H__
#define __M_LOGGING_H__

#define LOGINT(number) CCLOG(#number" = %d", number)
#define LOGNUMBER(number) CCLOG(#number" = %g", number)
#define LOGPOINT(point) CCLOG(#point": (%g, %g)", point.x, point.y)
#define LOGSIZE(size) CCLOG(#size": %g x %g", size.width, size.height)

#endif
