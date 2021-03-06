#ifndef CRANBERRIES_STREAMS_IO
#define CRANBERRIES_STREAMS_IO
#include <string>
#include <ios>
#include <iostream>
#include <fstream>
#include "utility.hpp"
#include "cranberries_magic/tag.hpp"

namespace cranberries {
namespace streams {

  enum class read_mode {
    line,
    byte,
  };


}
}

#endif