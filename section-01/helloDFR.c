#include <avr/io.h>
#include <util/delay.h>

#define BAUD 9600
#define MYUBRR F_CPU/16/BAUD-1

void USARTinit(unsigned int ubrr){
    //set a baud rate
    UBRR0H = (unsigned char)(ubrr>>8);
    UBRR0L = (unsigned char)ubrr;

    //enable receiver and transmitter
    UCSR0B = (1<<TXEN0);

    //set the frame format: 8 data bits, 1 stop bit
    UCSR0C = (3<<UCSZ00);
}

void USARTtransmit(unsigned char data){
    //wait for empty transmit buffer
    while (!(UCSR0A & (1<<UDRE0)))

    //put data into buffer, then send data
    UDR0 = data;
}

void USARTprint(const char* str){
    while(*str){
        USARTtransmit(*str++);
    }
}

int main(void){
    USARTinit(MYUBRR);
    USARTprint("Hello DFRobot!\r\n");
    return 0;
}