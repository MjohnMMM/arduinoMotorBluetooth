// am 28/06/2023 erstellt

int counter=0;
void setup() {
  Serial.begin(9600);
}

void loop() {
  delay(2000);

  Serial.print("HC-05 - Hello World. Counter: ");
  Serial.println(counter);
  counter++;
}
