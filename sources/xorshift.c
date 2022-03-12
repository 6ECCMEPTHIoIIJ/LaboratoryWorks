#include "xorshift.h"

#include <time.h>
#include <stdbool.h>

static XorshiftState _xorshift_state;

static bool _is_uninitialized = true;

XorshiftBase xorshift() {
  if (_is_uninitialized) {
    setXorshiftSeed((XorshiftState) {(uint32_t) time(NULL) ^ 0x0000FFFF,
                                     (uint32_t) time(NULL) ^ 0xFF0FFF,
                                     (uint32_t) time(NULL) ^ 0x00F000FF,
                                     (uint32_t) time(NULL) ^ 0xF00F000F});
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