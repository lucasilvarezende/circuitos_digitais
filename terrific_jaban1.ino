const int INPUT_LED_RED = 13;
const int INPUT_LED_BLUE = 12;
const int OUTPUT_LED_GREEN = 11;

bool func_or(bool b1, bool b2) {
  return b1 || b2;
}

bool func_nor(bool b1, bool b2) {
  return !(b1 || b2);
}

bool func_xor(bool b1, bool b2) {
  return (b1 && b2) || (b2 && b1);
}

bool func_xnor(bool b1, bool b2) {
  return !((b1 && b2) || (b2 && b1));
}

bool func_and(bool b1, bool b2) {
  return b1 && b2;
}

bool func_nand(bool b1, bool b2) {
  return !(b1 && b2);
}

void setup()
{
  pinMode(INPUT_LED_RED, OUTPUT);
  pinMode(INPUT_LED_BLUE, OUTPUT);
  pinMode(OUTPUT_LED_GREEN, OUTPUT);
  
  Serial.begin(9600);
}

void loop()
{
  bool tabVerdA[4] = {false,false,true,true};
  bool tabVerdB[4] = {false,true,false,true};
  
  for(int i = 0; i < 4; i++){

    digitalWrite(INPUT_LED_RED, tabVerdA[i]);
    Serial.println(tabVerdA[i]);
    digitalWrite(INPUT_LED_BLUE, tabVerdB[i]);
    Serial.println(tabVerdB[i]);
    	digitalWrite(OUTPUT_LED_GREEN, func_and(tabVerdA[i], tabVerdB[i]));
                 delay(1500);
    	digitalWrite(OUTPUT_LED_GREEN, func_nand(tabVerdA[i], tabVerdB[i]));
                 delay(1500);
		digitalWrite(OUTPUT_LED_GREEN, func_or(tabVerdA[i], tabVerdB[i]));
                 delay(1500);
		digitalWrite(OUTPUT_LED_GREEN, func_nor(tabVerdA[i], tabVerdB[i]));
                 delay(1500);
		digitalWrite(OUTPUT_LED_GREEN, func_xor(tabVerdA[i], tabVerdB[i]));
                 delay(1500);
		digitalWrite(OUTPUT_LED_GREEN, func_xnor(tabVerdA[i], tabVerdB[i]));
                 delay(1500);

  }
}

