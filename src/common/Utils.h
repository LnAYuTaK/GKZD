/**
 * @file Utils.h
 * @author LnAYuTaK (807874484@qq.com)
 * @brief 
 * @version 0.1
 * @date 2023-07-02
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#pragma once 

#include <algorithm>
#include <limits>
#include <type_traits>
#include <assert.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>
#include <google/protobuf/util/json_util.h>

using google::protobuf::util::JsonStringToMessage;
#ifndef __STDC_FORMAT_MACROS
#define __STDC_FORMAT_MACROS
#endif

class Utils
{
public:

  static const char  digits[];
  static const char* zero;
  static const char digitsHex[];
  
  static inline void memZero(void* p, size_t n)
  {
      memset(p, 0, n);
  }
  //Proto 类转换Json-string
  static bool protoToJson(const google::protobuf::Message& message, std::string& json) {
      google::protobuf::util::JsonPrintOptions options;
      options.add_whitespace = true;
      options.always_print_primitive_fields = true;
      options.preserve_proto_field_names = true;
      return MessageToJsonString(message, &json, options).ok();
  }
  //Json string 转换Proto
  static bool jsonToProto(const std::string& json, google::protobuf::Message& message) {
      return JsonStringToMessage(json, &message).ok();
  }
  //16进制转换
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













