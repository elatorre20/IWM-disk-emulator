/*
 * Gabriel Guillermo, Emilio Latorre, RICM 2022
 * 
 * A Raspberry Pi Pico-based floppy drive emulator for a mac512k. This program (ideally will) allow
 * the pico to appear to the mac as an external floppy drive, allowing the easy transfer of files and
 * programs from the internet or an IDE to the mac for copy to diskettes. 
 * 
 * Thanks to the Rhode Island Computer Museum for their hardware and assistance.
 */
#include <stdio.h>
#include <stdint.h>
#include "pico/stdlib.h"
#include "pico/binary_info.h"

//pin defintions, mapped to the names on the mac motherboard diagram
//1. GND (connector pin numbers, as listed on the diagram)
//2. GND
//3. GND
//4. GND
//5. -12v
//6. +5v
//7. +12
//8. +12v
//9. NC
const uint PWM = 0; //10. PWM
const uint PH0 = 1; //11. Phase 0, the phase lines are programmable output from the IWM controller chip
const uint PH1 = 2; //12. Phase 1
const uint PH2 = 3; //13. Phase 2
const uint PH3 = 4; //14. Phase 4
const uint WRREQ = 5; //15. WRREQ, "this signal is a programmable buffered output line". Active low, connected to the controller
const uint HDSEL = 6; //16. HDSEL, connected to one of the port A data lines on the 6522
const uint ENBL2 = 7; //17. ENBL2, drive select for the external drive. Active low, must be pulled up to +5v 
const uint RD = 8; //18. RD, connected to SENSE and RDDATA on the controller
const uint WR = 9; //19. WR, connected through an inverter to WRDATA on the controller

const uint pins[10] = {PWM, PH0, PH1, PH2, PH3, WRREQ, HDSEL, ENBL2, RD, WR};

//registers

unsigned char state = 0;

//misc

unsigned int64_t clk = 0; //for counting system clock cycles. Will overflow after approximately 73117 years

void setup() {
  for(uint i: pins){
    gpio_init(i);
    gpio_set_dir(i, 0);
  }
  
  

}

void loop() {
  // put your main code here, to run repeatedly:

}
