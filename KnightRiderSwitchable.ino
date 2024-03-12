bool changedState = false;
bool dir = false;
int OutputPINs[] = { 13, 12, 11, 10, 9, 8 };
int btnPin = 2;
int r = sizeof(OutputPINs) - 1;
int l = 0;
unsigned long lastTime;
unsigned long currTime;
bool lit = false;

void setup()
{
  lastTime = millis();
  for (int i = 0; i < sizeof(OutputPINs); i++)
  {
    pinMode(OutputPINs[i], OUTPUT);
  }

  pinMode(btnPin, INPUT);

  Serial.begin(9600);
}

void loop() 
{
  currTime = millis();
  if (digitalRead(btnPin) == 1)
  {
    if (!changedState)
    {
      // TODO: ChangeState
      changedState = true;
      dir = !dir;
      Serial.println("Ahoj, zmáčkli jsme tlačítko!");
    }
  }
  else if (changedState)
    changedState = false;

  if(currTime - lastTime >= 1000) {
    lastTime = currTime;
    digitalWrite(OutputPINs[l], lit);
    digitalWrite(OutputPINs[r], lit);
    if(lit == false) {
      if(dir) {
        r++;
        l--;
      }
      else {
        r--;
        l++;
      }
    }
    
    lit = !lit;
    
  }

  
}
