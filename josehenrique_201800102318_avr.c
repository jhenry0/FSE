#include<stdlib.h>
#include<stdio.h>
#include<avr/io.h>
#include <util/delay.h>
#include<stdint.h>
#define F_CPU 16000000UL
#define BAUD 9600
#define traco 600
#define ponto 200
#define mid 200
#define espaco 1400
#include<util/setbaud.h>
#include<string.h>
void inicializar_uart0(){
  UBRR0H = UBRRH_VALUE;
  UBRR0L = UBRRL_VALUE;
  UCSR0B = (1 << RXEN0) | (1 << TXEN0);
  UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}

int enviar_dado_uart0(char dado, FILE *fluxo){
  if(dado == '\n'){
    enviar_dado_uart0('\r', fluxo);
  }
  while(!(UCSR0A & (1 << UDRE0)));
  UDR0 = dado;
  return 0;
}

int receber_dado_uart0(FILE* fluxo){
  while(!(UCSR0A & (1 << RXC0)));
  return UDR0;
}

FILE stdin_uart0 = FDEV_SETUP_STREAM ( NULL ,
receber_dado_uart0 , _FDEV_SETUP_READ );
FILE stdout_uart0 = FDEV_SETUP_STREAM ( enviar_dado_uart0 ,
NULL , _FDEV_SETUP_WRITE );

char texto[100] = {0};

int main(){
  inicializar_uart0();
  DDRB = DDRB | (1 << DDB5 );
  stdin = &stdin_uart0;
  stdout = &stdout_uart0;

  while(1){
    gets(texto);
    for(int i = 0; i <strlen(texto);i++){
      if(texto[i] == ' '){
      PORTB = PORTB & ~(1 << PORTB5);
		    _delay_ms(espaco);  
      }
      if(texto[i] == 'a'|| texto[i] == 'A'){
        PORTB = PORTB | (1 << PORTB5);
		    _delay_ms(ponto);
         PORTB = PORTB & ~(1 << PORTB5);
		    _delay_ms(mid);
         PORTB = PORTB | (1 << PORTB5);
		    _delay_ms(traco);       
      }else if(texto[i] == 'b' || texto[i] == 'B'){
        PORTB = PORTB | (1 << PORTB5);
		    _delay_ms(traco);
         PORTB = PORTB & ~(1 << PORTB5);
		    _delay_ms(mid);
         PORTB = PORTB | (1 << PORTB5);
		    _delay_ms(ponto);
         PORTB = PORTB & ~(1 << PORTB5);
		    _delay_ms(mid);
         PORTB = PORTB | (1 << PORTB5);
		    _delay_ms(ponto);
         PORTB = PORTB & ~(1 << PORTB5);
		    _delay_ms(mid);
         PORTB = PORTB | (1 << PORTB5);
		    _delay_ms(ponto);       
      }else if(texto[i] == 'c'|| texto[i]== 'C'){
        PORTB = PORTB | (1 << PORTB5);
		    _delay_ms(traco);
         PORTB = PORTB & ~(1 << PORTB5);
		    _delay_ms(mid);
         PORTB = PORTB | (1 << PORTB5);
		    _delay_ms(ponto);
         PORTB = PORTB & ~(1 << PORTB5);
		    _delay_ms(mid);
         PORTB = PORTB | (1 << PORTB5);
		    _delay_ms(traco);
         PORTB = PORTB & ~(1 << PORTB5);
		    _delay_ms(mid);
         PORTB = PORTB | (1 << PORTB5);
		    _delay_ms(ponto);   
      }else if(texto[i] == 'd'|| texto[i]== 'D'){
        PORTB = PORTB | (1 << PORTB5);
		    _delay_ms(traco);
         PORTB = PORTB & ~(1 << PORTB5);
		    _delay_ms(mid);
         PORTB = PORTB | (1 << PORTB5);
		    _delay_ms(ponto);
         PORTB = PORTB & ~(1 << PORTB5);
		    _delay_ms(mid);
         PORTB = PORTB | (1 << PORTB5);
		    _delay_ms(ponto);   
      }else if(texto[i] == 'e'){
        PORTB = PORTB | (1 <<PORT5);
        _delay_ms(ponto);
      }else if(texto[i] == 'f' || texto[i] == 'F'){
        PORTB = PORTB | (1 << PORTB5);
		    _delay_ms(ponto);
         PORTB = PORTB & ~(1 << PORTB5);
		    _delay_ms(mid);
         PORTB = PORTB | (1 << PORTB5);
		    _delay_ms(ponto);
         PORTB = PORTB & ~(1 << PORTB5);
		    _delay_ms(mid);
         PORTB = PORTB | (1 << PORTB5);
		    _delay_ms(traco);
         PORTB = PORTB & ~(1 << PORTB5);
		    _delay_ms(mid);
         PORTB = PORTB | (1 << PORTB5);
		    _delay_ms(ponto);   
      }else if(texto[i] == 'g' || texto[i] == 'G'){
        PORTB = PORTB | (1 << PORTB5);
		    _delay_ms(traco);
         PORTB = PORTB & ~(1 << PORTB5);
		    _delay_ms(mid);
         PORTB = PORTB | (1 << PORTB5);
		    _delay_ms(traco);
         PORTB = PORTB & ~(1 << PORTB5);
		    _delay_ms(mid);
         PORTB = PORTB | (1 << PORTB5);
		    _delay_ms(ponto);   
      }else if(texto[i] == 'h' || texto[i] == 'H'){
        PORTB = PORTB | (1 << PORTB5);
		    _delay_ms(ponto);
         PORTB = PORTB & ~(1 << PORTB5);
		    _delay_ms(mid);
         PORTB = PORTB | (1 << PORTB5);
		    _delay_ms(ponto);
         PORTB = PORTB & ~(1 << PORTB5);
		    _delay_ms(mid);
         PORTB = PORTB | (1 << PORTB5);
		    _delay_ms(ponto);
         PORTB = PORTB & ~(1 << PORTB5);
		    _delay_ms(mid);
         PORTB = PORTB | (1 << PORTB5);
		    _delay_ms(ponto);   
      }else if(texto[i] == 'i' || texto[i] == 'I'){
        PORTB = PORTB | (1 << PORTB5);
		    _delay_ms(ponto);
         PORTB = PORTB & ~(1 << PORTB5);
		    _delay_ms(mid);
         PORTB = PORTB | (1 << PORTB5);
         _delay_ms(ponto);
      }else if(texto[i] == 'j' || texto[i] == 'J'){
        PORTB = PORTB | (1 << PORTB5);
		    _delay_ms(ponto);
         PORTB = PORTB & ~(1 << PORTB5);
		    _delay_ms(mid);
         PORTB = PORTB | (1 << PORTB5);
		    _delay_ms(traco);
         PORTB = PORTB & ~(1 << PORTB5);
		    _delay_ms(mid);
         PORTB = PORTB | (1 << PORTB5);
		    _delay_ms(traco);
         PORTB = PORTB & ~(1 << PORTB5);
		    _delay_ms(mid);
         PORTB = PORTB | (1 << PORTB5);
		    _delay_ms(traco);   
      }else if(texto[i] == 'k' || texto[i] == 'K'){
        PORTB = PORTB | (1 << PORTB5);
		    _delay_ms(traco);
         PORTB = PORTB & ~(1 << PORTB5);
		    _delay_ms(mid);
         PORTB = PORTB | (1 << PORTB5);
		    _delay_ms(ponto);
         PORTB = PORTB & ~(1 << PORTB5);
		    _delay_ms(mid);
         PORTB = PORTB | (1 << PORTB5);
		    _delay_ms(traco);   
      }else if(texto[i] == 'l' || texto[i] == 'L'){
        PORTB = PORTB | (1 << PORTB5);
		    _delay_ms(ponto);
         PORTB = PORTB & ~(1 << PORTB5);
		    _delay_ms(mid);
         PORTB = PORTB | (1 << PORTB5);
		    _delay_ms(traco);
         PORTB = PORTB & ~(1 << PORTB5);
		    _delay_ms(mid);
         PORTB = PORTB | (1 << PORTB5);
		    _delay_ms(ponto);
         PORTB = PORTB & ~(1 << PORTB5);
		    _delay_ms(mid);
         PORTB = PORTB | (1 << PORTB5);
		    _delay_ms(ponto);   
      }else if(texto[i] == 'm' || texto[i] == 'M'){
        PORTB = PORTB | (1 << PORTB5);
		    _delay_ms(traco);
         PORTB = PORTB & ~(1 << PORTB5);
		    _delay_ms(mid);
         PORTB = PORTB | (1 << PORTB5);
		    _delay_ms(traco);   
      }else if(texto[i] == 'n' || texto[i] == 'N'){
        PORTB = PORTB | (1 << PORTB5);
		    _delay_ms(traco);
         PORTB = PORTB & ~(1 << PORTB5);
		    _delay_ms(mid);
         PORTB = PORTB | (1 << PORTB5);
		    _delay_ms(ponto);   
      }else if(texto[i] == 'o' || texto[i] == 'O'){
        PORTB = PORTB | (1 << PORTB5);
		    _delay_ms(traco);
         PORTB = PORTB & ~(1 << PORTB5);
		    _delay_ms(mid);
         PORTB = PORTB | (1 << PORTB5);
		    _delay_ms(traco);
         PORTB = PORTB & ~(1 << PORTB5);
		    _delay_ms(mid);
         PORTB = PORTB | (1 << PORTB5);
		    _delay_ms(traco);   
      }else if(texto[i] == 'p' || texto[i] == 'P'){
        PORTB = PORTB | (1 << PORTB5);
		    _delay_ms(ponto);
         PORTB = PORTB & ~(1 << PORTB5);
		    _delay_ms(mid);
         PORTB = PORTB | (1 << PORTB5);
		    _delay_ms(traco);
         PORTB = PORTB & ~(1 << PORTB5);
		    _delay_ms(mid);
         PORTB = PORTB | (1 << PORTB5);
		    _delay_ms(traco);
         PORTB = PORTB & ~(1 << PORTB5);
		    _delay_ms(mid);
         PORTB = PORTB | (1 << PORTB5);
		    _delay_ms(ponto);   
      }else if(texto[i] == 'q' || texto[i] == 'Q'){
        PORTB = PORTB | (1 << PORTB5);
		    _delay_ms(traco);
         PORTB = PORTB & ~(1 << PORTB5);
		    _delay_ms(mid);
         PORTB = PORTB | (1 << PORTB5);
		    _delay_ms(traco);
         PORTB = PORTB & ~(1 << PORTB5);
		    _delay_ms(mid);
         PORTB = PORTB | (1 << PORTB5);
		    _delay_ms(ponto);
         PORTB = PORTB & ~(1 << PORTB5);
		    _delay_ms(mid);
         PORTB = PORTB | (1 << PORTB5);
		    _delay_ms(traco);   
      }else if(texto[i] == 'r' || texto[i] == 'R'){
        PORTB = PORTB | (1 << PORTB5);
		    _delay_ms(ponto);
         PORTB = PORTB & ~(1 << PORTB5);
		    _delay_ms(mid);
         PORTB = PORTB | (1 << PORTB5);
		    _delay_ms(traco);
         PORTB = PORTB & ~(1 << PORTB5);
		    _delay_ms(mid);
         PORTB = PORTB | (1 << PORTB5);
		    _delay_ms(ponto);   
      }else if(texto[i] == 's' || texto[i] == 'S'){
        PORTB = PORTB | (1 << PORTB5);
		    _delay_ms(ponto);
         PORTB = PORTB & ~(1 << PORTB5);
		    _delay_ms(mid);
         PORTB = PORTB | (1 << PORTB5);
		    _delay_ms(ponto);
         PORTB = PORTB & ~(1 << PORTB5);
		    _delay_ms(mid);
         PORTB = PORTB | (1 << PORTB5);
		    _delay_ms(ponto);  
      }else if(texto[i] == 't' || texto[i] == 'T'){
        PORTB = PORTB | (1 << PORTB5);
		    _delay_ms(traco);
    }else if(texto[i] == 'u' || texto[i] == 'U'){
        PORTB = PORTB | (1 << PORTB5);
		    _delay_ms(ponto);
         PORTB = PORTB & ~(1 << PORTB5);
		    _delay_ms(mid);
         PORTB = PORTB | (1 << PORTB5);
		    _delay_ms(ponto);
         PORTB = PORTB & ~(1 << PORTB5);
		    _delay_ms(mid);
         PORTB = PORTB | (1 << PORTB5);
		    _delay_ms(traco);   
      }else if(texto[i] == 'v' || texto[i] == 'V'){
        PORTB = PORTB | (1 << PORTB5);
		    _delay_ms(ponto);
         PORTB = PORTB & ~(1 << PORTB5);
		    _delay_ms(mid);
         PORTB = PORTB | (1 << PORTB5);
		    _delay_ms(ponto);
         PORTB = PORTB & ~(1 << PORTB5);
		    _delay_ms(mid);
         PORTB = PORTB | (1 << PORTB5);
		    _delay_ms(ponto);
         PORTB = PORTB & ~(1 << PORTB5);
		    _delay_ms(mid);
         PORTB = PORTB | (1 << PORTB5);
		    _delay_ms(traco);   
      }else if(texto[i] == 'w' || texto[i] == 'W'){
        PORTB = PORTB | (1 << PORTB5);
		    _delay_ms(ponto);
         PORTB = PORTB & ~(1 << PORTB5);
		    _delay_ms(mid);
         PORTB = PORTB | (1 << PORTB5);
		    _delay_ms(traco);
         PORTB = PORTB & ~(1 << PORTB5);
		    _delay_ms(mid);
         PORTB = PORTB | (1 << PORTB5);
		    _delay_ms(traco);  
      }else if(texto[i] == 'x' || texto[i] == 'X'){
        PORTB = PORTB | (1 << PORTB5);
		    _delay_ms(traco);
         PORTB = PORTB & ~(1 << PORTB5);
		    _delay_ms(mid);
         PORTB = PORTB | (1 << PORTB5);
		    _delay_ms(ponto);
         PORTB = PORTB & ~(1 << PORTB5);
		    _delay_ms(mid);
         PORTB = PORTB | (1 << PORTB5);
		    _delay_ms(ponto);
         PORTB = PORTB & ~(1 << PORTB5);
		    _delay_ms(mid);
         PORTB = PORTB | (1 << PORTB5);
		    _delay_ms(traco);   
      }else if(texto[i] == 'y' || texto[i] == 'Y'){
        PORTB = PORTB | (1 << PORTB5);
		    _delay_ms(traco);
         PORTB = PORTB & ~(1 << PORTB5);
		    _delay_ms(mid);
         PORTB = PORTB | (1 << PORTB5);
		    _delay_ms(ponto);
         PORTB = PORTB & ~(1 << PORTB5);
		    _delay_ms(mid);
         PORTB = PORTB | (1 << PORTB5);
		    _delay_ms(traco);
         PORTB = PORTB & ~(1 << PORTB5);
		    _delay_ms(mid);
         PORTB = PORTB | (1 << PORTB5);
		    _delay_ms(traco);   
      }else if(texto[i] == 'z' || texto[i] == 'Z'){
        PORTB = PORTB | (1 << PORTB5);
		    _delay_ms(traco);
         PORTB = PORTB & ~(1 << PORTB5);
		    _delay_ms(mid);
         PORTB = PORTB | (1 << PORTB5);
		    _delay_ms(traco);
         PORTB = PORTB & ~(1 << PORTB5);
		    _delay_ms(mid);
         PORTB = PORTB | (1 << PORTB5);
		    _delay_ms(ponto);
         PORTB = PORTB & ~(1 << PORTB5);
		    _delay_ms(mid);
         PORTB = PORTB | (1 << PORTB5);
		    _delay_ms(ponto);   
      }
      PORTB = PORTB & ~(1 << PORTB5);
      _delay_ms(mid);
  }
}
}
