#include <gb/gb.h>
#include "hUGEDriver.h"

extern const hUGESong_t sample_song;

void main(void){
    NR52_REG = 0x80; // Master sound on
    NR50_REG = 0xFF; // Maximum volume for left/right speakers. 
    NR51_REG = 0xFF; // Turn on sound fully

    // ensure no interrupts occur while initializing the hUGEDriver
    __critical{
        hUGE_init(&sample_song);
        add_VBL(hUGE_dosound);
    }

    // Loop forever
    while(1){
        vsync();
    }
}
