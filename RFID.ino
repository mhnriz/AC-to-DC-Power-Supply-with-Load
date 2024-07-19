#include <SPI.h>
#include <MFRC522.h>

MFRC522 mfrc522(53, 5); //(ss,rst)

int redPin = 11;
int greenPin = 12;
int bluePin = 13;
int buzzerPin = 2;
int counter = 0;

void setColor(int red, int green, int blue){
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  Serial.println("Scan a Rfid Card");
}

void loop() {
  
  if (!mfrc522.PICC_IsNewCardPresent()) return;
  if (!mfrc522.PICC_ReadCardSerial()) return;
  
  Serial.print("UID tag: ");
  Serial.print(mfrc522.uid.uidByte[0], HEX);
  Serial.println();

  String card = String(mfrc522.uid.uidByte[0], HEX);
  if(card == "f7"){
    counter++;
    if(counter != 5){
      setColor(random(0,255), random(0,255), random(0,255));
      for (int i = 0; i <80; i++)
      {
        digitalWrite(buzzerPin, HIGH);
        delay(1);
        digitalWrite(buzzerPin, LOW);
        delay (1);
      }
    }
    else{
      counter = 0;
      setColor(0,0,0);
    }
    
  }

  else{
    counter = 0;
    setColor(255, 0, 0);
    // for (int i = 0; i <30; i++)
    // {
    //   digitalWrite(buzzerPin, HIGH);
    //   delay(4);
    //   digitalWrite(buzzerPin, LOW);
    //   delay (4);
    // }
    delay(100);
    tone(buzzerPin, 131);
    delay(250);
    noTone(buzzerPin);
    delay(125);
    tone(buzzerPin, 131);
    delay(250);
    tone(buzzerPin, 147);
    delay(500);
    tone(buzzerPin, 131);
    delay(500);
    tone(buzzerPin, 175);
    delay(500);
    tone(buzzerPin, 165);
    delay(1000);
    tone(buzzerPin, 131);
    delay(250);
    noTone(buzzerPin);
    delay(125);
    tone(buzzerPin, 131);
    delay(250);
    tone(buzzerPin, 147);
    delay(500);
    tone(buzzerPin, 131);
    delay(500);
    tone(buzzerPin, 196);
    delay(500);
    tone(buzzerPin, 175);
    delay(1000);
    tone(buzzerPin, 131);
    delay(250);
    noTone(buzzerPin);
    delay(125);
    tone(buzzerPin, 131);
    delay(250);
    tone(buzzerPin, 262);
    delay(500);
    tone(buzzerPin, 220);
    delay(500);
    tone(buzzerPin, 175);
    delay(500);
    tone(buzzerPin, 165);
    delay(500);
    tone(buzzerPin, 147);
    delay(500);
    tone(buzzerPin, 233);
    delay(250);
    noTone(buzzerPin);
    delay(125);
    tone(buzzerPin, 233);
    delay(250);
    tone(buzzerPin, 220);
    delay(500);
    tone(buzzerPin, 175);
    delay(500);
    tone(buzzerPin, 196);
    delay(500);
    tone(buzzerPin, 175);
    delay(1000);
    noTone(buzzerPin);
    delay(100);
  }
  
  delay(1000);
}
