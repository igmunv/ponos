#include "memory.h"

void memcpy(void* src, void* dst, int n){
    for (int i = 0; i < n; i++){
        *((unsigned char*)(dst + i)) = *((unsigned char*)(src + i));
    }
}
