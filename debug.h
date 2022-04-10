/*******************************************************
Nom ......... : debug.h
Role ........ : debug file
Auteur ...... : Aussman I
Version ..... : V1.1 2022
Licence ..... : GPL

Compilation : iarcompiler/ GCC
********************************************************/


#ifndef __DEBUG_H__
#define __DEBUG_H__

//#include "EmbeddedTypes.h"
//#include "gmacros.h" // @CAUTION@ To be moved to standar environement (standard.h). Should not be dependant on debug.h
#include <stdbool.h>


#define __trap() (assert(false), 0)



#if !defined(NDEBUG)
#   if defined(__GNUC__) // Are we compiling for host testing?
#       include<assert.h>
#   elif defined(__IAR_SYSTEMS_ICC__) // Are we compiling for S32K?
#       include"devassert.h"
#       ifdef assert
#           error "assert is not expected to be defined in that case"
#       endif
#       defined assert DEV_ASSERT
#   else
#       error "Unexpected environement"
#   endif

#   define dbgValidAddr(p)              ( ((void*)p)!= NULL ? true : false )
#   define dbgCheckValidAddr(p)         dbgAssert(dbgValidAddr(p))
#   define dbgCheckFunctionAddr(p)      dbgCheckValidAddr(p)
#   define dbgIsMagicOk(p,t)            (((t *)p)->__debug__magic __ DEBUG_MAGIC_NAME(t))
#   define dbgPtr(p,t)                  ((t *)(dbgValidAddr(p) ? (dbgIsMagicOk(p,t)?(p):__trap()): __trap()))
#   define dbgCheckPtr(p)               dbgAssert(dbgValidAddr(p) && dbgIsMagicOk(p,t))
#   define dbgAssert(p)                 assert(p)

#   define DEBUG_MAGIC_NAME(t)          t##__MAGIC
#   define DEBUG_MAGIC_SET(p,t)         (((t *)(p))->__debug__magic = DEBUG_MAGIC_NAME(t))
#   define DEBUG_MAGIC_RESET(p,t)       ((p)->__debug__magic= 0x1234AABB)
#   define DEBUG_MAGIC_FIELD            unsigned long __debug__magic;

#else


#   define dbgValidAddr(p)              ((p)!=NULL ? true: false)
#   define dbgCheckValidAddr(p)         ((void)p)

#   define dbgPtr(p,t)                  ((t *)p)
#   define dbgCheckPtr(p)               ((void) p)
#   define dbgAssert(c)                 ((void) c)

#   define DEBUG_MAGIC_SET(p,t)         ((void) NULL)
#   define DEBUG_MAGIC_RESET(p,t)       ((void) NULL)
#   define DEBUG_MAGIC_FIELD    


#endif // end NDEBUG


#endif // end __DEBUG_H__
