#pragma once 
#include <algorithm>
#include <limits>
#include <type_traits>
#include <assert.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>

#ifndef __STDC_FORMAT_MACROS
#define __STDC_FORMAT_MACROS
#endif

class Utils
{
public:
  static const char  digits[];
  static const char* zero;
  static const  char digitsHex[];

  static inline void memZero(void* p, size_t n)
  {
      memset(p, 0, n);
  }

  static size_t convertHex(char buf[], uintptr_t value);

  template<typename T>
  static size_t convert(char buf[], T value)
  {
    T i = value;
    char* p = buf;
    do
    {
      int lsd = static_cast<int>(i % 10);
      i /= 10;
      *p++ = zero[lsd];
    } while (i != 0);

    if (value < 0)
    {
      *p++ = '-';
    }
    *p = '\0';
    std::reverse(buf, p);
    return p - buf;
  }

  template<typename To, typename From>
  static inline To implicit_cast(From const &f)
  {
      return f;
  }
private:
  Utils(/* args */){}
  ~Utils(){}
};













