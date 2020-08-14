#include <iostream>
#include "list6801.hh"
int main() {
  openmode o = (openmode::in | openmode::out) & ~openmode::binary;
  return o == openmode::ate;
}
