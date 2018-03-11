#include <SoftwareSerial.h> //biblioteca que emula portas para comunicaçao serial

#define LED 4 // define a palavra LED como 4

SoftwareSerial arduino(3, 2); // cria novas portas de comunicaço serial (RX e TX) no arduino
int var_controle; // Varivel de controle

void setup(){
  
  arduino.begin(9600); // inicia a comunicaçao serial com 9600 bps 
  pinMode(LED, OUTPUT); // define pino digital 4 como saida para o LED
  digitalWrite(LED, LOW); // inicia o LED apagado

}

void loop(){

    if(arduino.available() > 0){ // Verifica se portas seriais estao disponveis
      var_controle = arduino.read(); // le as informaçoes vindas do modulo bluetooth
      
      if(var_controle == 'l'){ // Se o byte enviado for l, ligue o LED
        digitalWrite(LED, HIGH);
        arduino.println("LED ligado");
      }
      
      if(var_controle == 'd'){ // se o byte enviado for d, desliga o LED
        digitalWrite(LED, LOW);
        arduino.println("LED desligado");
      }     
    }
}
