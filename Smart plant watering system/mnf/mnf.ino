#define AOUT_PIN 36 // ESP32 pin GPIO36 (ADC0) that connects to AOUT pin of moisture sensor
#define LED_PIN_1 16 // GPIO17 for first LED
#define LED_PIN_2 4 // GPIO18 for second LED
#define LED_PIN_3 0 // GPIO19 for third LED
#define SPEAKER_PIN 15 // GPIO32 for speaker
#define WATER_PUMP_PIN_1 18 // GPIO33 for water pump 1
#define WATER_PUMP_PIN_2 19 // GPIO34 for water pump 2

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN_1, OUTPUT);
  pinMode(LED_PIN_2, OUTPUT);
  pinMode(LED_PIN_3, OUTPUT);
  pinMode(SPEAKER_PIN, OUTPUT);
  pinMode(WATER_PUMP_PIN_1, OUTPUT);
  pinMode(WATER_PUMP_PIN_2, OUTPUT);
}

void loop() {
  int value = analogRead(AOUT_PIN); // อ่านค่าอนาล็อกจากเซ็นเซอร์

  // แปลงค่าความชื้นให้อยู่ในช่วง 0-100 โดยเปลี่ยนค่า 4095 เป็น 0% และ 0 เป็น 100%                                       
  float moisturePercentage = map(value, 0, 4095, 100, 0);
  Serial.print("Lost electricity bill: ");
  Serial.print(value);
  Serial.print(" (Humidity value: )");
  Serial.print(moisturePercentage);
  Serial.println("%");

  if (moisturePercentage < 40) {
    digitalWrite(LED_PIN_1, LOW);
    digitalWrite(LED_PIN_2, LOW);
    digitalWrite(LED_PIN_3, HIGH);
    digitalWrite(SPEAKER_PIN, LOW);
    delay(100);
    digitalWrite(SPEAKER_PIN, HIGH);
    delay(100);
    digitalWrite(WATER_PUMP_PIN_1, HIGH);
    digitalWrite(WATER_PUMP_PIN_2, LOW);
  } else if (moisturePercentage >= 40 && moisturePercentage <70) {
    digitalWrite(LED_PIN_1, LOW);
    digitalWrite(LED_PIN_2, HIGH);
    digitalWrite(LED_PIN_3, LOW);
    digitalWrite(SPEAKER_PIN, HIGH);
    digitalWrite(WATER_PUMP_PIN_1, LOW);
    digitalWrite(WATER_PUMP_PIN_2, LOW);
  } else if (moisturePercentage >= 70 && moisturePercentage <=100) {
    digitalWrite(LED_PIN_1, HIGH);
    digitalWrite(LED_PIN_2, LOW);
    digitalWrite(LED_PIN_3, LOW);
    digitalWrite(SPEAKER_PIN, HIGH);
    digitalWrite(WATER_PUMP_PIN_1, LOW);
    digitalWrite(WATER_PUMP_PIN_2, LOW);
  } else {
    digitalWrite(LED_PIN_1, LOW);
    digitalWrite(LED_PIN_2, LOW);
    digitalWrite(LED_PIN_3, LOW);
    digitalWrite(SPEAKER_PIN, LOW);
    digitalWrite(WATER_PUMP_PIN_1, LOW);
    digitalWrite(WATER_PUMP_PIN_2, LOW);
  }

  delay(500);
}