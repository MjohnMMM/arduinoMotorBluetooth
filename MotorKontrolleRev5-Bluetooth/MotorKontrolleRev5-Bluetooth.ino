
int terminalA = 12;
int terminalB = 13;

int speedA = 3;
int speedB = 11;

int brakeA = 9;
int brakeB = 8;

int velocity=150;

const int ledPin = 13;//the led attach to
char val[4];

// test comment 3

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
  delay(1000);
  Serial.println("hello from HC-05."); 
}

void test_loop()
{
  digitalWrite(terminalA, LOW);    
  analogWrite(speedA, velocity*3);
  digitalWrite(terminalA, LOW);    
  analogWrite(speedA, velocity*3);
}

void loop() {
    
      if( Serial.available() )       // if data is available to read
     {
      //for(int i=0; i<4;i++)
      //{
       val[0] = Serial.read();         // read it and store it in 'val'
       Serial.print("I received: ");
       Serial.println(val[0]);
     // }
       
     }

      //digitalWrite(terminalA, LOW);    
      //analogWrite(speedA, velocity*3);


     if( val[0] == '1' ) digitalWrite(ledPin, HIGH);  // turn ON the LED
     if( val[0] == '2' ) digitalWrite(ledPin, HIGH);  // turn ON the LED

    switch(val[0])
    {
      case '1':
        digitalWrite(terminalA, LOW);    
        analogWrite(speedA, velocity);
      break;

      case '2':
        digitalWrite(terminalA, HIGH);
        analogWrite(speedA, -velocity);
      break;

      case '3':
        digitalWrite(terminalB, LOW);
        analogWrite(speedB, velocity);
      break;

      case '4':
        digitalWrite(terminalB, HIGH);
        analogWrite(speedB, -velocity);
      break;

      case '5':
        analogWrite(speedA, 0);
      break;

      case '6':
        analogWrite(speedB, 0);
      break;

      default:

      break;

    }
    
  delay(1000);
  
  
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



