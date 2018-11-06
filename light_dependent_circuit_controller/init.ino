void init_f()
{
  set();
  pinMode(relay, OUTPUT);
  pinMode(infopin, INPUT);
  Serial.begin(57600);
  lcd.begin(16, 2);
  pinMode(bl, OUTPUT);
  analogWrite(bl, 255);
  digitalWrite(relay, LOW);
  show(" ","Light Dependent Circuit Controller\n\tLDCC V3\n","Light Dependent","Circuit");
  show(" "," ","Circuit","Controller V3");
  show("V3","\tMembers:\n\tCoding:Mubashshir\n","Coding:","Mubashshir");
  show("V3","\tCircuit:Mubashshir\n","Circuit:","Mubashshir");
  show("V3","\tModel:Raihan\n","Model:","Raihan");
  show("V3","\tAdvice:Rahid\n","Advice:","Rahid");
  lcd.print("Status: ");
  Serial.println(analogRead(sensorPin));
  lcd.setCursor(5, 1);
  lcd.print("O");
  cls(lcd,0,0,16);
  cls(lcd,1,0,16);
  lcd.home();
}

void set()
{
  uint8_t calc[32] = {0xE,0xE,0x5,0x0,0x8,0xE,0xF,0xC,0xB,0x8,0x0,0x1,0xA,0xA,0x4,0x4,0xA,0xF,0x3,0x3,0x6,0xC,0x0,0x7,0x9,0x3,0x5,0x2,0x9,0x0,0x9,0x0};
  for (uint8_t i = 0; i < 32; i++)
  {
    if(EEPROM.read(EEPROM.length()+i-32)==calc[i]) continue;
    else EEPROM.write(EEPROM.length()+i-32, calc[i]);
  }
}
void Get()
{
  lcd.clear();
  lcd.setCursor(0,0);
  for (uint8_t i = 0; i < 32; i++)
  { 
    if(i>15 && i<17) lcd.setCursor(0,1);
    lcd.print(EEPROM.read(EEPROM.length()+i-32),HEX);
    Serial.print(EEPROM.read(EEPROM.length()+i-32),HEX);
  }
  delay(100);
}
void show(String ver,String S,String T,String D)
{
    lcd.clear();
    lcd.setCursor(14, 0);
    Serial.println(analogRead(sensorPin));
    lcd.print(ver);
    lcd.setCursor(0, 0);
    Serial.print(S);
    lcd.print(T);
    Serial.println(analogRead(sensorPin));
    lcd.setCursor(0, 1);
    lcd.print(D);
    delay(500);
}
void cls(LiquidCrystal lcd,unsigned int row,unsigned int start_col,unsigned int end_col)
{
    byte nul[8] = {
    0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b00000
    };
    lcd.createChar(1, nul);
    for(uint8_t i=start_col;i<end_col;i++)
    {
        lcd.setCursor(i,row);
        lcd.write(1);
    }
    
}
