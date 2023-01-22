int relay_move_up = 13;
int relay_move_down = 12;

int elevator_button_up = 11;
int elevator_button_down = 10;
int elevator_button_stop = 9;
int button_call_up = 8;
int button_call_down = 7;

int limit_floor_up = 6;
int limit_floor_down = 5;

boolean in_move = false;
boolean task = false;

void setup() {
  pinMode(elevator_button_up, INPUT);
  pinMode(elevator_button_down, INPUT);
  pinMode(elevator_button_stop, INPUT);
  pinMode(button_call_up, INPUT);
  pinMode(button_call_down, INPUT);
  pinMode(limit_floor_up, INPUT);
  pinMode(limit_floor_down, INPUT);

  pinMode(relay_move_up, OUTPUT);
  pinMode(relay_move_down, OUTPUT);
}

void loop() {
  int elevator_button_up_state = digitalRead(elevator_button_up);
  int elevator_button_down_state = digitalRead(elevator_button_down);
  int elevator_button_stop_state = digitalRead(elevator_button_stop);
  int button_call_up_state = digitalRead(button_call_up);
  int button_call_down_state = digitalRead(button_call_down);

  int floor_up_state = digitalRead(limit_floor_up);
  int floor_down_state = digitalRead(limit_floor_down);

  //digitalWrite(relay_move_down, HIGH);
  //digitalWrite(relay_move_up, HIGH);

  //digitalWrite(relay_move_down, LOW);
  //digitalWrite(relay_move_up, LOW);

  if (elevator_button_up_state == HIGH) {
    if (floor_up_state == LOW) {
      in_move = true;

      if (in_move = true) {
        digitalWrite(relay_move_up, HIGH);
      } else {
         digitalWrite(relay_move_up, LOW);
      }
    } else {
      in_move = false;
      digitalWrite(relay_move_up, LOW);
    }
  }

  if (elevator_button_stop_state == HIGH) {
    digitalWrite(relay_move_up, LOW);
    digitalWrite(relay_move_down, LOW);
    in_move = false;
  }

  if (elevator_button_down_state == HIGH) {
    if (floor_down_state == LOW) {
      in_move = true;

      if (in_move = true) {
        digitalWrite(relay_move_down, HIGH);
      } else {
         digitalWrite(relay_move_down, LOW);
      }
    } else {
      in_move = false;
      digitalWrite(relay_move_down, LOW);
    }
  }
}
