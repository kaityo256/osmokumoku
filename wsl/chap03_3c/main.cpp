#include <cstdint>

#include "robo.h"

extern "C" void KernelMain(uint64_t frame_buffer_base,
                           uint64_t frame_buffer_size) {
  uint8_t *frame_buffer = reinterpret_cast<uint8_t *>(frame_buffer_base);
  for (uint64_t i = 0; i < frame_buffer_size; ++i) {
    frame_buffer[i] = 0;
  }
  const int LX = 800;
  const int size = 199;
  for (uint64_t i = 0; i < frame_buffer_size; ++i) {
    uint64_t j = i / 4;
    uint64_t x = j % LX;
    uint64_t y = j / LX;
    int index = (x + size * y) * 3;
    if (x < 199 && y < 199) {
			if(i%4==0){
        frame_buffer[i] = array[index+2];
			}
			if(i%4==1){
        frame_buffer[i] = array[index+1];
			}
			if(i%4==2){
        frame_buffer[i] = array[index];
			}
    }
  }
  while (1)
    __asm__("hlt");
}
