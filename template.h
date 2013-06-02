/*
A simple template file that I use for almost all my projects
Probably not the MOST optimised, but GETs things DONE

If you are using it, please keep this NOTE intact
(Give credit where credit is due)

Send me a line at email@zaidpirwani.com if you have something to ADD/REMOVE/EDIT

THANKS....

Most of the code here is either common-sense, staraightforward,
copied from AVRFreaks.net and other AVR Projects that I have browsed worked on.

LAST UPDATED: 27 Jul, 2012
*/

// For Bitvise Operation Simplification Defines
#define CLR(port,pin)	(PORT ## port &= ~(1<<pin))
#define SET(port,pin)	(PORT ## port |=  (1<<pin))
#define TOGL(port,pin)	(PORT ## port ^=  (1<<pin))
#define READ(port,pin)	(PIN  ## port &   (1<<pin))
#define OUT(port,pin)	(DDR  ## port |=  (1<<pin))
#define IN(port,pin)	(DDR  ## port &= ~(1<<pin))
#define PUP(port,pin)	(DDR  ## port &= ~(1<<pin));(PORT ## port |=  (1<<pin))
#define BIT(x)			_BV(x)
// TOGL==TOGGLE and PUP==Input+Pull-Up

#define SetBit(address,bit) (address|=(1<<bit))
#define ClrBit(address,bit) (address&=~(1<<bit))
#define InvBit(address,bit) (address^=(1<<bit))
#define IsBitOn(address,bit)  (address&(1<<bit))
#define IsBitOff(address,bit) (!(address&(1<<bit)))

#define delay(x)		_delay_ms(x)

#define BTBOUNCE	10	// in ms for button DEBOUNCING

#define LOW		0
#define HIGH	1


#define TRUE 1
#define FALSE 0

// define CPU frequency in Mhz here if not defined in Project
// To define your OWN F_CPU, define it before including this file
#ifndef F_CPU
#define F_CPU 4000000UL
#endif

// Include Files
#include <avr/io.h>
#include <util/delay.h>
#include <avr/wdt.h>

// Additional INCLUDE FILES
#include <avr/interrupt.h>
#include <avr/eeprom.h> 
#include <avr/pgmspace.h>
#include <avr/sleep.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


