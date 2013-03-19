#ifndef _LOGGING_
#define _LOGGING_

#include <iostream>
#include <stdlib.h>

#ifndef NASSERT
#define ASSERT(expr) \
  if(!(expr)) {\
    std::cerr << "Assertion violation in file " << __FILE__ << " and line " << __LINE__ << std::endl;\
    exit(-1);\
  }

#define REQUIRE(expr) \
  if(!(expr)) {\
    std::cerr << "Precondition violation in file " << __FILE__ << " and line " << __LINE__ << std::endl;\
    exit(-1);\
  }

#define REQUIRE(expr) \
  if(!(expr)) {\
    std::cerr << "Precondition violation in file " << __FILE__ << " and line " << __LINE__ << std::endl;\
    exit(-1);\
  }
  
#else
#define ASSERT(expr) (void);
#define REQUIRE(expr) (void);
#define ENSURE(expr) (void);
//TODO
#define INVARIANT(expr) (void);
#endif

#endif
