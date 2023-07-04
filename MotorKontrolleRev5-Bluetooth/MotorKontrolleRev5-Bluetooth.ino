int LeftMotorsOn = 12;
int RightMotorsOn = 13;

int leftMotors_PWM_Pin = 3;
int rightMotors_PWM_Pin = 11;

int brakesLeft = 9;
int brakesRight = 8;

int velocity=150;

const int ledPin = 13;//the led attach to
const int HC_05_power_pin = 2; // The power supply for the HC-05
char val[4];

int counter=0;

void setup() {
  //Schritt 1: Setze die Richtung (Polaritaet) des Motor
  pinMode(LeftMotorsOn, OUTPUT);
  pinMode(RightMotorsOn, OUTPUT);
  
  //Schritt 2: Loese (disengage) die Bremse
  pinMode(brakesLeft, OUTPUT);
  digitalWrite(brakesLeft, LOW);

  pinMode(brakesRight, OUTPUT);
  digitalWrite(brakesRight, LOW);

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
  digitalWrite(LeftMotorsOn, LOW);    
  analogWrite(leftMotors_PWM_Pin, velocity);
  digitalWrite(RightMotorsOn, HIGH);    
  analogWrite(leftMotors_PWM_Pin, velocity);

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
        digitalWrite(LeftMotorsOn, LOW);    
        analogWrite(leftMotors_PWM_Pin, velocity);
      break;

      case '2':
        Serial.println("now entered case 2");
        digitalWrite(LeftMotorsOn, HIGH);
        analogWrite(leftMotors_PWM_Pin, -velocity);
      break;

      case '3':
        Serial.println("now entered case 3");
        digitalWrite(RightMotorsOn, LOW);
        analogWrite(rightMotors_PWM_Pin, velocity);
      break;

      case '4':
        Serial.println("now entered case 4");
        digitalWrite(RightMotorsOn, HIGH);
        analogWrite(rightMotors_PWM_Pin, -velocity);
      break;

      case '5':
        Serial.println("now entered case 5");
        analogWrite(leftMotors_PWM_Pin, 0);
      break;

      case '6':
        Serial.println("now entered case 6");
        analogWrite(rightMotors_PWM_Pin, 0);
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
    analogWrite(leftMotors_PWM_Pin, 0);
  }else if(motor=="B"){
    analogWrite(rightMotors_PWM_Pin, 0);
  }
  
}



