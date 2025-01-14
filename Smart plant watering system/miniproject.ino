#define AOUT_PIN 36   // GPIO36 pin of ESP32 (ADC0) connected to the AOUT pin of the moisture sensor
#define LED_PIN_1 16   // GPIO13 pin of ESP32 connected to the first LED YELLOW
#define LED_PIN_2 4   // GPIO14 pin of ESP32 connected to the second LED GREEN
#define LED_PIN_3 0   // GPIO15 pin of ESP32 connected to the third LED RED
int SPEAKER_PIN = 15; // GPIO16 pin of ESP32 connected to the speaker

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN_1, OUTPUT);
  pinMode(LED_PIN_2, OUTPUT);
  pinMode(LED_PIN_3, OUTPUT);
  pinMode(SPEAKER_PIN, OUTPUT);
}

void loop() {
  int value = analogRead(AOUT_PIN); // read the analog value from the sensor
  float percent = ((float)value / 4095) * 100; // convert the value to percentage

  Serial.print("Moisture value: ");
  Serial.print(percent);
  Serial.println("%");

  if (percent < 40) {
    digitalWrite(LED_PIN_1, HIGH); // turn on the first LED
    digitalWrite(LED_PIN_2, LOW);  // turn off the second LED
    digitalWrite(LED_PIN_3, LOW);  // turn off the third LED
    digitalWrite(SPEAKER_PIN,HIGH);            // turn off the speaker
  } else if (percent >= 40 && percent < 80) {
    digitalWrite(LED_PIN_1, LOW);   // turn off the first LED
    digitalWrite(LED_PIN_2, HIGH);  // turn on the second LED
    digitalWrite(LED_PIN_3, LOW);   // turn off the third LED
    digitalWrite(SPEAKER_PIN,HIGH);            // turn off the speaker
 } else if (percent >= 80 && percent <= 100) {
    digitalWrite(LED_PIN_1, LOW);   // turn off the first LED
    digitalWrite(LED_PIN_2, LOW);   // turn off the second LED
    digitalWrite(LED_PIN_3, HIGH);  // turn on the third LED
    digitalWrite(SPEAKER_PIN, LOW);  // turn on the speaker with a frequency of 1000 Hz
    delay(100);
    digitalWrite(SPEAKER_PIN, HIGH);  // turn on the speaker with a frequency of 1000 Hz
    delay(100);
  }
  delay(500);
}