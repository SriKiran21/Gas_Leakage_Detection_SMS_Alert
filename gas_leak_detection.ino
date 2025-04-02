#include <SoftwareSerial.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); 
SoftwareSerial mySerial(9, 10);

int sensor = 7;
int speaker = 8;
int gas_value, Gas_alert_val, Gas_shut_val;
int Gas_Leak_Status = 0;
int sms_count = 0;
const int max_sms_count = 2;

const char* phone_numbers[] = {
  "+917036768646",
  "+917981297508",
  "+919490784800"
};

void setup() {
    pinMode(sensor, INPUT);
    pinMode(speaker, OUTPUT);
    Serial.begin(9600);
    lcd.begin(16, 2);
    delay(500);
}

void loop() {
    CheckGas();
    CheckShutDown();
}

void CheckGas() {
    lcd.setCursor(0, 0);
    lcd.print("Gas Scan - ON");

    Gas_alert_val = ScanGasLevel();
    if (Gas_alert_val == LOW) {
        SetAlert(); 
    }
}

int ScanGasLevel() {
    gas_value = digitalRead(sensor); 
    return gas_value;
}

void SetAlert() {
    digitalWrite(speaker, HIGH);  
    while (sms_count < max_sms_count) {
        SendTextMessage();
        sms_count++; 
    }
    Gas_Leak_Status = 1; 
    lcd.setCursor(0, 1);
    lcd.print("Gas Alert! SMS Sent!");
}

void CheckShutDown() {
    if (Gas_Leak_Status == 1) {
        Gas_shut_val = ScanGasLevel();
        if (Gas_shut_val == HIGH) {
            lcd.setCursor(0, 1);
            lcd.print("Gas Cleared");
            digitalWrite(speaker, LOW);
            sms_count = 0;
            Gas_Leak_Status = 0;
        }
    }
}

void SendTextMessage() {
    for (int i = 0; i < 3; i++) {
        Serial.println("AT+CMGF=1");    
        delay(1000);
        Serial.print("AT+CMGS=\"");
        Serial.print(phone_numbers[i]);
        Serial.println("\"\r");
        delay(1000);
        Serial.println("Gas Leaking! Please help!"); 
        delay(200);
        Serial.write(26); 
        delay(1000);
    }
}
