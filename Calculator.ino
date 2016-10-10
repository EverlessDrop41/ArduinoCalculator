#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int pressed_count = 0;

const int CYCLE_BTN_PIN = 8;

void setup() {
  pinMode(CYCLE_BTN_PIN, INPUT);


  lcd.begin(16, 2);
  Serial.begin(9600);
  Serial.println("Setup Complete!");
}

bool cycle_btn_prev_pressed = false;

void loop() {
	lcd.clear();
	lcd.setCursor(0, 0);
	lcd.print("Pressed count:");
	lcd.setCursor(0, 1);
	lcd.print(pressed_count);

	bool cycle_btn_pressed = button_is_pressed(CYCLE_BTN_PIN); 
	
	if (cycle_btn_pressed && !cycle_btn_prev_pressed) {
		pressed_cycle_character();
	}

	cycle_btn_prev_pressed = cycle_btn_pressed;

	delay(100);
}

bool button_is_pressed(int pin) {
	return digitalRead(pin) == HIGH; 
}

void pressed_cycle_character() {
	Serial.println(pressed_count);
	pressed_count++;
}
