class Lock
{
  private: bool ifLocked;
  public:
    Lock()
    {
      this->ifLocked=false;
    }
    void ch()
    {
      this->ifLocked=!this->ifLocked;
    }
    bool mode()
    {
      return this->ifLocked;
    }
};



int modSwPin=5;
Lock lc;
void setup()
{
  Serial.begin(9600);
  pinMode(modSwPin,INPUT);
}
void loop()
{
  if(digitalRead(modSwPin)==HIGH)
    lc.ch();
  else
  {
    if(lc.mode()) Serial.print("Locked");
    else Serial.print("UnLOcked");
  }
}
