
int terminalA = 12;
int terminalB = 13;

int speedA = 3;
int speedB = 11;

int brakeA = 9;
int brakeB = 8;

int velocity=50;

const int ledPin = 13;//the led attach to
char val[4];


void setup() {
  //Schritt 1: Setze die Rictung (Polaritaet) des Motor
  pinMode(terminalA, OUTPUT);
  pinMode(terminalB, OUTPUT);
  
  //Schritt 2: Loese (disengage) die Bremse
  pinMode(brakeA, OUTPUT);
  digitalWrite(brakeA, LOW);

  pinMode(brakeB, OUTPUT);
  digitalWrite(brakeB, LOW);

  pinMode(ledPin,OUTPUT);//initialize the ledPin as an output

  //Schritt 3: Setze die Geschwindigkeit (PWM Signal)
  
  // Zusaetzliche Initialisierungsdingen
  Serial.begin(9600); // zu auf dem Serial Fenster Potentiometerwerte ausdrucken

 
}

void loop() {

      if( Serial.available() )       // if data is available to read
     {
      for(int i=0; i<4;i++)
      {
       val[i] = Serial.read();         // read it and store it in 'val'
       Serial.print("I received: ");
       Serial.println(val[i]);
      }
       
     }
     if( val[0] == '1' ) digitalWrite(ledPin, HIGH);  // turn ON the LED
     if( val[0] == '2' ) digitalWrite(ledPin, HIGH);  // turn ON the LED

    // Seite A : Ruckwaerts
    if(val[0] == '1'){
      digitalWrite(terminalA, LOW);    
      analogWrite(speedA, velocity);
      stopMotor("B");
    }else if (val[0] == '2'){
      // Seite A : Vorwaerts
      digitalWrite(terminalA, HIGH);
      analogWrite(speedA, -velocity);
      stopMotor("B");
    }else if (val[0] == '0'){    
      // Seite A: Halte
      digitalWrite(terminalA, HIGH);
      analogWrite(speedA, 0);
      stopMotor("B");
    }else if (val[3] == '1'){
      // Seite B: Ruckwaerts
      digitalWrite(terminalB, LOW);
      analogWrite(speedB, velocity);
      stopMotor("A");
    }else if (val[0] == '2'){
      // Seite B : Vorwaerts
      digitalWrite(terminalB, HIGH);
      analogWrite(speedB, -velocity);
      stopMotor("A");
    }else if (val[0] == '0'){
      // Seite B: Halte
      analogWrite(speedB, 0);
      stopMotor("A");
    }
    
  delay(400);
  
}

void stopMotor(char motor)
{
  if(motor=="A")
  {
    analogWrite(speedA, 0);
  }else if(motor=="B"){
    analogWrite(speedB, 0);
  }
  
}



