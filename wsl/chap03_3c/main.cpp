#include <cstdint>

#include "robo.h"

extern "C" void KernelMain(uint64_t frame_buffer_base,
                           uint64_t frame_buffer_size) {
  uint8_t *frame_buffer = reinterpret_cast<uint8_t *>(frame_buffer_base);
  for (uint64_t i = 0; i < frame_buffer_size; ++i) {
    frame_buffer[i] = 0;
  }
  const int frame_width = 800;
  const int size = 199;
  for (uint64_t x = 0; x < size; x++) {
    for (uint64_t y = 0; y < size; y++) {
      uint64_t i = (x + frame_width * y) * 4;
      uint64_t j = (x + size * y) * 3;
      frame_buffer[i] = array[j + 2];
      frame_buffer[i + 1] = array[j + 1];
      frame_buffer[i + 2] = array[j];
    }
  }
  while (1)
    __asm__("hlt");
}
