int terminalA = 12;
int terminalB = 13;

int speedA = 3;
int speedB = 11;

int brakeA = 9;
int brakeB = 8;

int velocity=150;

const int ledPin = 13;//the led attach to
const int HC_05_power_pin = 2; // The power supply for the HC-05
char val[4];

int counter=0;

void setup() {
  //Schritt 1: Setze die Richtung (Polaritaet) des Motor
  pinMode(terminalA, OUTPUT);
  pinMode(terminalB, OUTPUT);
  
  //Schritt 2: Loese (disengage) die Bremse
  pinMode(brakeA, OUTPUT);
  digitalWrite(brakeA, LOW);

  pinMode(brakeB, OUTPUT);
  digitalWrite(brakeB, LOW);

  pinMode(ledPin,OUTPUT);//initialize the ledPin as an output

  pinMode(HC_05_power_pin, OUTPUT);
  delay(500);
  digitalWrite(HC_05_power_pin, HIGH);
  delay(1000);
  

  //Schritt 3: Setze die Geschwindigkeit (PWM Signal)
  
  // Zusaetzliche Initialisierungsdingen
  Serial.begin(9600); // zu auf dem Serial Fenster Potentiometerwerte ausdrucken  
  delay(1000);
  Serial.println("hello from HC-05."); 
}

void test_loop()
{
  digitalWrite(terminalA, LOW);    
  analogWrite(speedA, velocity);
  digitalWrite(terminalB, HIGH);    
  analogWrite(speedA, velocity);

  delay(1000);
  Serial.print("hello from HC-05. ");
  Serial.println(counter);
  counter++;
  
}

void loop() {
    
      if( Serial.available() )       // if data is available to read
     {
       val[0] = Serial.read();         // read it and store it in 'val'
       Serial.print("I received: ");
       Serial.println(val[0]);       
     }


    // veraltete Code der geloescht sein soll
     //if( val[0] == '1' ) digitalWrite(ledPin, HIGH);  // turn ON the LED
     //if( val[0] == '2' ) digitalWrite(ledPin, HIGH);  // turn ON the LED

    switch(val[0])
    {
      case '1':
        Serial.println("now entered case 1");
        digitalWrite(terminalA, LOW);    
        analogWrite(speedA, velocity);
      break;

      case '2':
        Serial.println("now entered case 2");
        digitalWrite(terminalA, HIGH);
        analogWrite(speedA, -velocity);
      break;

      case '3':
        Serial.println("now entered case 3");
        digitalWrite(terminalB, LOW);
        analogWrite(speedB, velocity);
      break;

      case '4':
        Serial.println("now entered case 4");
        digitalWrite(terminalB, HIGH);
        analogWrite(speedB, -velocity);
      break;

      case '5':
        Serial.println("now entered case 5");
        analogWrite(speedA, 0);
      break;

      case '6':
        Serial.println("now entered case 6");
        analogWrite(speedB, 0);
      break;

      case '7':
        Serial.println("now entered case 7");
        if (velocity>=250)
        {
          velocity=0;
        }
        else
        {
          velocity = velocity + 25;
        }        
        Serial.print("velocity = ");
        Serial.println(velocity);
      break;

      default:

      break;
    
    }
  val[0]=0;
  delay(1000);
  Serial.print("hello from HC-05. ");
  Serial.println(counter);
  counter++;
  
  
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



