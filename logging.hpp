#ifndef H_LOGGING
#define H_LOGGING

/*
 * Logging is different from debugging.
 * In debug.h we provide a TRACE macro that
 * pretty much do the same as those logging
 * macros but still has a different role. Tracing
 * is meant to be low level and help during program development,
 * and will be turned off in production, while logging will
 * always be active.
 */

#define LOG_OUT stdout

#define INFO(fmt, ...) \
  fprintf(LOG_OUT, "[INFO] %s:%d:%s(): " fmt "\n", __FILE__, \
          __LINE__, __func__, ##__VA_ARGS__);

#define WARNING(fmt, ...) \
  fprintf(LOG_OUT, "[WARNING] %s:%d:%s(): " fmt "\n", __FILE__, \
          __LINE__, __func__, ##__VA_ARGS__);

#define ERROR(fmt, ...) \
  fprintf(LOG_OUT, "[ERROR] %s:%d:%s(): " fmt "\n", __FILE__, \
          __LINE__, __func__, ##__VA_ARGS__);

#endif
