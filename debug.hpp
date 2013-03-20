#ifndef _DEBUG_
#define _DEBUG_

#include <iostream>
#include <stdlib.h>

#ifndef NASSERT

#define ASSERT(expr) \
  if(!(expr)) {\
    std::cerr << "Assertion violation in file " << __FILE__ << " and line " << __LINE__ << ": " << #expr << std::endl;\
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

#ifndef NDEBUG
#define TRACE(fmt, ...) \
  fprintf(stdout, "%s:%d:%s(): " fmt "\n", __FILE__, \
          __LINE__, __func__, __VA_ARGS__);
#else
#define TRACE(fmt, ...) (void);
#endif

#endif