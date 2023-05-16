// es gibt keine Schalterumsetzung in diesem Code
const int X_pin = A0; // analog pin connected to X output
const int Y_pin = A1; // analog pin connected to Y output

const int capacSens_1 = 2;
const int capacSens_2 = 3;

int touch_1=0;
int touch_2=0;

int x_pin_reading=0;
int y_pin_reading=0;

int left_right=0;
int forward_backward=0;
bool left_active;
bool right_active;
bool forward_active;
bool backward_active;
int padding=30;
int JoystickFactor=1;
int boost=0;

int vel=0;


void setup() {

  pinMode(capacSens_1,INPUT);
  pinMode(capacSens_2,INPUT);
  Serial.begin(19200);

  
}

void loop() {

  touch_1=digitalRead(capacSens_1);
  touch_2=digitalRead(capacSens_2);
  x_pin_reading=analogRead(X_pin);
  y_pin_reading=analogRead(Y_pin);
  

  if(x_pin_reading<(328-padding))
  {
    right_active=false;
    left_active=true;
    left_right=(328-x_pin_reading)*JoystickFactor;
    Serial.print("left=");
    Serial.println(left_right);
  }

  if(x_pin_reading>(328+padding))
  {
    left_active=false;
    right_active=true;
    left_right=(328-x_pin_reading)*JoystickFactor;
    Serial.print("right = ");
    Serial.println(left_right);
  }

  if(y_pin_reading>(330+padding))
  {
    backward_active=false;
    forward_active=true;
    forward_backward=(330-y_pin_reading)*JoystickFactor;
    Serial.print("foward = ");
    Serial.println(forward_backward);
    boost=boost-1;
  }

  if(y_pin_reading<(330-padding))
  {
    forward_active=false;
    backward_active=true;    
    forward_backward=(330-y_pin_reading)*JoystickFactor;
    Serial.print("backward = ");
    Serial.println(forward_backward);
    boost=boost+1;
  }

  if(y_pin_reading>(330-padding) && y_pin_reading<(330+padding))
  {
    if(boost<0)
    {
      boost = boost + 1;
    }
    else if(boost > 0)
    {
     boost = boost - 1; 
    }
    else
    {
      boost=0;
    }
  }

  if(boost>5){
    boost=5;
  }else if(boost < -5){
    boost=-5;
  }


  if(touch_1==1 && vel !=5)
  {
    vel=vel+1;
    //Serial.println("capacSens pad 2 is HIGH");
  }
  

  if(touch_2==1 && vel != -5)
  {
    vel=vel-1;
  }

  
   
  
  if(right_active==true)
  {
    Serial.println("turning left");
  }
  else if(left_active== true)
  {
    Serial.println("turning right");
  }
  
  Serial.print("total velocity = ");
  Serial.println(vel + boost);
  
  delay(500);
}
