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
const char PWM = 0; //10. PWM
const char PH0 = 1; //11. Phase 0, the phase lines are programmable output from the IWM controller chip
const char PH1 = 2; //12. Phase 1
const char PH2 = 3; //13. Phase 2
const char PH3 = 4; //14. Phase 4
const char WRREQ = 5; //15. WRREQ, "this signal is a programmable buffered output line". Active low, connected to the controller
const char HDSEL = 6; //16. HDSEL, connected to one of the port A data lines on the 6522
const char ENBL2 = 7; //17. ENBL2, drive select for the external drive. Active low, must be pulled up to +5v 
const char RD = 8; //18. RD, connected to SENSE and RDDATA on the controller
const char WR = 9; //19. WR, connected through an inverter to WRDATA on the controller

const char pins[10] = {PWM, PH0, PH1, PH2, PH3, WRREQ, HDSEL, ENBL2, RD, WR};

//registers

unsigned char state = 0;
unsigned char current_track = 0;

//misc
const char tracks_0 = 4;//number of tracks in each speed zone
const char tracks_1 = 4;
const char tracks_2 = 4;
const char tracks_3 = 4;
const char bytes = 4192;//bytes per sector


struct{ //struct to represent the floppy disk and data written on it
  unsigned char disk_name[128];//the name of the floppy disk
  bool sided; //true for double-sided disk
  bool wp; //true for write-protected
  unsigned char zone0[tracks_0][bytes];
  unsigned char zone1[tracks_1][bytes];
  unsigned char zone2[tracks_2][bytes];
  unsigned char zone3[tracks_3][bytes];
  unsigned char side0[4]={zone0,zone1,zone2,zone3};
  } disk;

void setup() {
  Serial.begin(9600);
  for(int i: pins){
    pinMode(i, OUTPUT);
  }
  
  

}

void loop() {
  // put your main code here, to run repeatedly:

}
