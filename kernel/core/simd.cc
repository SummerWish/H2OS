#include "simd.h"

namespace SIMD
{

  void sse_enable() {
    __asm__ __volatile__ (
      "movq    %%cr0, %%rbx\n"
      "and     $0xFFFB, %%bx\n"
      "or      $0x2, %%bx\n"
      "movq    %%rbx, %%cr0\n"
      "movq    %%cr4, %%rbx\n"
      "or      $3 << 9, %%bx\n"
      "movq    %%rbx, %%cr4\n"
    : :
    );
  }

}
