// helloDFR.c
// A simple hello world program for AVR microcontrollers, I am using the arduino UNO atmega328p.
// This program initializes the UART and sends "Hello, DFR!" to a LCD display.

#include <avr/io.h> //this library allows us to use the AVR input/output ports as PORTx and DDRx
#include <util/delay.h> // this library allows us to use the _delay_ms() and _delay_us() functions
#include <stdint.h> // this library allows us to use the uint8_t data type

#define lcdRS PB4
#define lcdEN  PB3
void lcdPulseEnable(void);
void lcdSendNibble(uint8_t nibble);
void lcdCommand(uint8_t cmd);
void lcdData(uint8_t data);
void lcdInit(void);
void lcdPrint(const char *str);


void lcdPulseEnable(void) {
    PORTB |= (1 << lcdEN);
    _delay_us(1);
    PORTB &= ~(1 << lcdEN);
    _delay_us(100);
}
void lcdSendNibble(uint8_t nibble){
    //first we clear the data bits in GPIO PORTD 7 thru 4
    PORTD &= 0x0F;
    //now we mask the nibble and shift it to the upper half of the byte
    PORTD |= (nibble & 0x0F) << 4;
    lcdPulseEnable();
}
void lcdCommand(uint8_t cmd){
    //clear RS for a command
    PORTB &= ~(1<<lcdRS);
    //send the upper nibble of the command
    lcdSendNibble(cmd >> 4);
    //send the lower nibble of the command
    lcdSendNibble(cmd & 0x0F);
    _delay_ms(2);
}
void lcdData(uint8_t data){
    //set RS for data
    PORTB |= (1<<lcdRS);
    //send the upper nibble of the data
    lcdSendNibble(data >> 4);
    //send the lower nibble of the data
    lcdSendNibble(data & 0x0F);
    _delay_ms(2);
}
//initialize the LCD cause it requires special sequence or wtv
void lcdInit(void){
    //set the data GPIO PORTD pins 7 thru 4 as outputs
    DDRD |= 0xF0;
    //set the control GPIO PORTB pins 4 and 3 as outputs
    DDRB |= (1<<lcdRS) | (1<<lcdEN);
    _delay_ms(50);
    //Im using 4 bit mode therfore special init sequence:
    lcdSendNibble(0x03);
    _delay_ms(5);
    lcdSendNibble(0x03);
    _delay_us(200);
    lcdSendNibble(0x03);
    _delay_us(200);
    lcdSendNibble(0x02); //finally set to 4 bit mode

    //function set (4 bit mode, 2 line, 5x8 font)
    lcdCommand(0x28);
    //turn display on, no cursor, no blink
    lcdCommand(0x0C);
    //clear display command
    lcdCommand(0x01);
    _delay_ms(2);
    //set entry mode (increment cursor, no display shift)
    lcdCommand(0x06);
}
void lcdPrint(const char *str){
    while(*str){
        lcdData(*str++);
    }
}

int main(void){

    //initialize the LCD
    lcdInit();
    //print hello world to the LCD
    lcdPrint("Hello, DFR!");
    //main loop
    while(1){
        //now we loop forever
    }

    return 0; //hell yeah im a fucking Bare metal C developer
}
