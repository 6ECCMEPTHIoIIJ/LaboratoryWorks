#include "xorshift.h"

#include <time.h>
#include <stdbool.h>

static XorshiftState _xorshift_state;

static bool _is_uninitialized = true;

XorshiftBase xorshift() {
  if (_is_uninitialized) {
    uint32_t init_time = (uint32_t) time(NULL);
    setXorshiftSeed((XorshiftState) {init_time ^ 0x0000FFFF,
                                     init_time ^ 0xFFF +
                                                 init_time ^ 0xFF0000 >> 16,
                                     init_time ^ 0xFF +
                                                 init_time ^ 0xF000 >> 8,
                                     init_time ^ 0xF00F000F});
    _is_uninitialized = false;
  }
  XorshiftBase t = _xorshift_state._3;

  _xorshift_state._3 = _xorshift_state._2;
  _xorshift_state._2 = _xorshift_state._1;
  _xorshift_state._1 = _xorshift_state._0;

  t ^= t << 11;
  t ^= t >> 8;
  return _xorshift_state._0 =
             t ^ _xorshift_state._0 ^ (_xorshift_state._0 >> 19);
}

void setXorshiftSeed(const XorshiftState seed) {
  _xorshift_state = seed;
}