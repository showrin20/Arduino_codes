
#define BRAKEVCC 0
#define CW   1
#define CCW  2
#define BRAKEGND 3
#define CS_THRESHOLD 100

/*  VNH2SP30 pin definitions
 xxx[0] controls '1' outputs
 xxx[1] controls '2' outputs */
int inApin[2] = {7, 4};  // INA: Clockwise input
int inBpin[2] = {8, 9}; // INB: Counter-clockwise input
int pwmpin[2] = {5, 6}; // PWM input
int cspin[2] = {2, 3}; // CS: Current sense ANALOG input
int enpin[2] = {0, 1}; // EN: Status of switches output (Analog pin)

int statpin = 13;

void setup()
{
  Serial.begin(9600);
  
  pinMode(statpin, OUTPUT);

  // Initialize digital pins as outputs
  for (int i=0; i<2; i++)
  {
    pinMode(inApin[i], OUTPUT);
    pinMode(inBpin[i], OUTPUT);
    pinMode(pwmpin[i], OUTPUT);
  }
  // Initialize braked
  for (int i=0; i<2; i++)
  {
    digitalWrite(inApin[i], LOW);
    digitalWrite(inBpin[i], LOW);
  }
  // motorGo(0, CW, 255);
  // motorGo(1, CCW, 255);
}

void loop()
{for(int i = 0; i < 255; i += 30){
  motorGo(0, CW, i);
  motorGo(1, CCW, i);
  delay(500);

  motorGo(0, CCW, i);
  motorGo(1, CW, i);
  delay(500);
}
  if ((analogRead(cspin[0]) < CS_THRESHOLD) && (analogRead(cspin[1]) < CS_THRESHOLD))
    digitalWrite(statpin, HIGH);
}

void motorOff(int motor)
{
  // Initialize braked
  for (int i=0; i<2; i++)
  {
    digitalWrite(inApin[i], LOW);
    digitalWrite(inBpin[i], LOW);
  }
  analogWrite(pwmpin[motor], 0);
}

/* motorGo() will set a motor going in a specific direction
 the motor will continue going in that direction, at that speed
 until told to do otherwise.
 
 motor: this should be either 0 or 1, will selet which of the two
 motors to be controlled
 
 direct: Should be between 0 and 3, with the following result
 0: Brake to VCC
 1: Clockwise
 2: CounterClockwise
 3: Brake to GND
 
 pwm: should be a value between ? and 255, higher the number, the faster
 it'll go
 */
void motorGo(uint8_t motor, uint8_t direct, uint8_t pwm)
{
  if (motor <= 1)
  {
    if (direct <=4)
    {
      // Set inA[motor]
      if (direct <=1)
        digitalWrite(inApin[motor], HIGH);
      else
        digitalWrite(inApin[motor], LOW);

      // Set inB[motor]
      if ((direct==0)||(direct==2))
        digitalWrite(inBpin[motor], HIGH);
      else
        digitalWrite(inBpin[motor], LOW);

      analogWrite(pwmpin[motor], pwm);
    }
  }
}


void arm_base(int pwm_speed, bool is_forward) {
    analogWrite(is_forward ? L_PWM_BASE : R_PWM_BASE, 0);
    analogWrite(is_forward ? R_PWM_BASE : L_PWM_BASE, pwm_speed);
}


void arm_act1(int pwm_speed, bool is_forward) {
    analogWrite(is_forward ? L_PWM_ACT1 : R_PWM_ACT1, 0);
    analogWrite(is_forward ? R_PWM_ACT1 : L_PWM_ACT1, pwm_speed);
}


void arm_act2(int pwm_speed, bool is_forward) {
    analogWrite(is_forward ? L_PWM_ACT2 : R_PWM_ACT2, 0);
    analogWrite(is_forward ? R_PWM_ACT2 : L_PWM_ACT2, pwm_speed);
}


void arm_act3(int pwm_speed, bool is_forward) {
    analogWrite(is_forward ? L_PWM_ACT3 : R_PWM_ACT3, 0);
    analogWrite(is_forward ? R_PWM_ACT3 : L_PWM_ACT3, pwm_speed);
}


void arm_wrist(int pwm_speed, bool is_forward) {
    analogWrite(is_forward ? L_PWM_WRST : R_PWM_WRST, 0);
    analogWrite(is_forward ? R_PWM_WRST : L_PWM_WRST, pwm_speed);
}


void arm_claw(int pwm_speed, bool is_forward) {
    analogWrite(is_forward ? L_PWM_CLAW : R_PWM_CLAW, 0);
    analogWrite(is_forward ? R_PWM_CLAW : L_PWM_CLAW, pwm_speed);
}


void wheel_onward(int pwm_speed, bool is_forward) {
    analogWrite(is_forward ? L_PWM_L_WHEEL : R_PWM_L_WHEEL, 0);
    analogWrite(is_forward ? L_PWM_R_WHEEL : R_PWM_R_WHEEL, 0);
    analogWrite(is_forward ? R_PWM_R_WHEEL : L_PWM_L_WHEEL, pwm_speed);
    analogWrite(is_forward ? R_PWM_L_WHEEL : L_PWM_R_WHEEL, pwm_speed);
}


void wheel_steering(int pwm_speed, bool is_right) {
    analogWrite(is_right ? L_PWM_L_WHEEL : R_PWM_L_WHEEL, 0);
    analogWrite(is_right ? R_PWM_R_WHEEL : L_PWM_R_WHEEL, 0);
    analogWrite(is_right ? R_PWM_L_WHEEL : L_PWM_L_WHEEL, pwm_speed);
    analogWrite(is_right ? L_PWM_R_WHEEL : R_PWM_R_WHEEL, pwm_speed);
}


void stop_all() {
  for(int PIN = 2; PIN <= 13; ++PIN) {
    analogWrite(PIN, 0);
  }
  for(int PIN = 44; PIN <= 47; ++PIN) {
    analogWrite(PIN, 0);
  }
}
