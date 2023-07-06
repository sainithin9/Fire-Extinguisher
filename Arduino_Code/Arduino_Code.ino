#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>
#define BLYNK_TEMPLATE_ID "TMPLylhr_IAB"
#define BLYNK_DEVICE_NAME "FlameDetector"
#define BLYNK_AUTH_TOKEN "fk5lpQ6mRKg8swaRpBHJ92n3JjnMbfqu"
char auth[] =BLYNK_AUTH_TOKEN  ; // your Blynk auth token
char ssid[] = "Nithin"; // your WiFi network SSID
char pass[] = "nithin123"; // your WiFi network password
Servo servo1;
const int FlamePin = 16;
int BUZ_PIN= 5;
int LED_PIN= 4;
void setup()
{
  servo1.attach(2);
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  pinMode(FlamePin, INPUT);
  pinMode(BUZ_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
}
void loop()
{
  int FlameValue = digitalRead(FlamePin);
  Serial.print("Flame value: ");
  Serial.println(FlameValue);
  if (FlameValue == LOW) {
    digitalWrite(BUZ_PIN, HIGH);
    digitalWrite(LED_PIN, HIGH);
    Serial.print("fire alerrt ");
    Blynk.logEvent("Fire", "Fire detected");  
// Send notification to Blynk Log Event widget
    servo1.write(180);
}
  else{
    digitalWrite(BUZ_PIN, LOW);
    digitalWrite(LED_PIN, LOW);
    Serial.print("No fire ");
    servo1.write(0);
  }
  Blynk.run();
  delay(1000);
}
