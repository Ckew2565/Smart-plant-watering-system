int _moisture, sensor_analog;
const int sensor_pin = 36;  /* Soil moisture sensor O/P pin */
int led1 = 16; // GPI25 pin of ESP32 connected to the first LED RED
int led2 = 4; // GPIO12 pin of ESP32 connected to the second LED GREEN
int led3 = 0; // GPIO17 pin of ESP32 connected to the third LED RED
int buzzer = 15; /* ติดเมื่อความชื้นต่ำ */
const int in1Pin = 18;  // H-Bridge input pins
const int in2Pin = 19;

void setup(void){
  Serial.begin(9600); 
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(buzzer, OUTPUT);    /* Set the baudrate to 115200*/
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
}

void loop(void){
  sensor_analog = analogRead(sensor_pin);
  _moisture = ( 100 - ( (sensor_analog/4095.00) * 100 ) );
  Serial.print("Moisture = ");
  Serial.print(_moisture);  /* Print Temperature on the serial window */
  Serial.println("%");
  if (_moisture < 40) { 
    digitalWrite(led1, HIGH); /*ไฟขาวเปิด*/
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(buzzer,HIGH); /*เสียงเปิด*/
    delay(1000);
    digitalWrite(buzzer,LOW); 
    digitalWrite(in1Pin,HIGH);
    digitalWrite(in2Pin,LOW);
    
  }
  else if (_moisture < 60){
    digitalWrite(led1, LOW); 
    digitalWrite(led2, HIGH); /*ไฟเขียวเปิด*/
    digitalWrite(led3, LOW);
    digitalWrite(buzzer,HIGH);
    digitalWrite(in1Pin,LOW);
    digitalWrite(in2Pin,LOW);
  }
  else {
    digitalWrite(led1, LOW); 
    digitalWrite(led2, LOW); 
    digitalWrite(led3, HIGH); /*ไฟเหลืองเปิด*/
    digitalWrite(buzzer,HIGH);
    digitalWrite(in1Pin,LOW);
    digitalWrite(in2Pin,LOW);
  }
  delay(200);              /* Wait for 1000mS */
}