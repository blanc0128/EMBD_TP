#include <Servo.h>

Servo myServo;
int motorPin = 9;
int recognizedID = 0;

void setup() {
    Serial.begin(115200);
    myServo.attach(motorPin);
}

void loop() {
    if (Serial.available()) {
        String idString = Serial.readStringUntil('\n');
        recognizedID = idString.toInt();
        Serial.print("Received recognized ID: ");
        Serial.println(recognizedID);
        
        if (recognizedID == 1) {
            moveMotor();
        }
    }
}

void moveMotor() {
    Serial.println("Target object detected! Moving motor...");
    
    myServo.write(90);
    delay(1000);
    myServo.write(0);
    delay(1000);
}
