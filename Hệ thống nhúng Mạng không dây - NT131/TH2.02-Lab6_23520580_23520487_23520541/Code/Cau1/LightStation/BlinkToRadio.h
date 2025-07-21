
#ifndef BLINKTORADIO_H
#define BLINKTORADIO_H
#define NEW_PRINTF_SEMANTICS
enum {
  AM_BLINKTORADIO = 202,
  TIMER_PERIOD_MILLI = 1000
};

typedef nx_struct SenseToRadioMsg{
  nx_uint16_t nodeid;
  nx_uint16_t value;
} SenseToRadioMsg;

#endif
