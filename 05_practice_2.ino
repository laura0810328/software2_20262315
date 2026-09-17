#define PIN_LED 7
unsigned int toggle = 0;
// 회로가 어딘가 잘못된 것 같아 led 밝기가 반대로 나왔습니다. 그래서 코드를 반대로 수정하였습니다.
int toggle_state(int toggle) {
  return !toggle;
}

void setup() {
  pinMode(PIN_LED, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  toggle = 0;
  digitalWrite(PIN_LED, toggle);
  delay(1000);

  for (int i = 0; i < 5; i++) {
    toggle = toggle_state(toggle); 
    digitalWrite(PIN_LED, toggle);
    delay(100);

    toggle = toggle_state(toggle); 
    digitalWrite(PIN_LED, toggle);
    delay(100);
  }

  digitalWrite(PIN_LED, 1); 
  
  while (1) { }
}
