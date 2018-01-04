#include <Arduino.h>
#include <SoftwareSerial.h>

bool stringComplete;
char inChar;
String msg;
#define TX 11
#define RX 10
SoftwareSerial sserial(RX, TX);

void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);
    sserial.begin(9600);
    stringComplete = false;
    msg = "";
    sserial.println("Inicia el Arduino");
}

void loop() {
    // put your main code here, to run repeatedly:
    stringComplete = false;
    delay(10);
}

void serialEvent(){
    int digito = 0;
    sserial.println("Evento en el servial");
    if (stringComplete == false) {
        sserial.println("Recibido algo");
        while (Serial.available()) {
            inChar = (char)Serial.read();
            sserial.println(inChar);
            if ((inChar != '\r') && (inChar != '\n')) {
                msg += inChar;
            } else if (inChar == 'a') { //((inChar == '\r') || (inChar == '\n')) {
                sserial.println("Recibido = " + msg);
                stringComplete = true;
                msg = "";
            }
        }
    }
}