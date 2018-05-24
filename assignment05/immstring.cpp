#include "immstring.hpp"

// Functions from <cstring> may be used to ease working with
// null-terminated strings.
// Further reference: https://en.cppreference.com/w/cpp/header/cstring
#include <cstring>

// This header contains std::copy_n for copying sequences of data.
// Further reference: https://en.cppreference.com/w/cpp/header/algorithm
#include <algorithm>

namespace Util {

// NOTE: Compiler errors related to this constructor provide hints to
//        where else you need to use `const`.
ImmutableString::ImmutableString(const ImmutableString& other)
        : m_size{other.size()}, // Order of initialization is important here!
          m_data{new char[m_size+1]()} {
    // Note: The string consists of `m_size` characters and is terminated by a
    //       `\x0` character, thus: `m_size+1`.
    std::copy_n(other.c_str(), m_size + 1, m_data);
}

ImmutableString::ImmutableString(const char* src)
  : m_size{std::strlen(src)},
    m_data{new char[m_size+1]()} {

    std::copy_n(src, m_size+1, m_data);
}

ImmutableString ImmutableString::concat(ImmutableString other) const {
  char* buffer = new char[m_size + other.size() + 1]();
  std::strncat(std::strncpy(buffer, m_data, m_size), other.c_str(), other.size());

  ImmutableString newImm = ImmutableString(buffer, m_size + other.size());

  delete[] buffer;
  return newImm;
}

ImmutableString::~ImmutableString() {
  delete[] m_data;
}

ImmutableString::ImmutableString(char* buf, size_t len)
  : m_size{len},
    m_data{new char[m_size+1]()}  {
  std::strncpy(m_data, buf, m_size);
}

} // Util
