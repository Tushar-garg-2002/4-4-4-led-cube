/*
 * declaring components
 */
int cathode[16] = {13,12,11,10,9,8,7,6,5,4,3,2,1,0,A0,A1};
int anode[4] = {A2,A3,A4,A5}; 
int time = 500;
/*
 * initiating components
 */
void setup() {
  for(int i = 0 ; i<4; i++){
    pinMode(anode[i],OUTPUT);
  }
  for(int i = 0 ; i<16;i++){
    pinMode(cathode[i], OUTPUT);
  }
}

void loop() {
  everythingon();
  delay(time);
  everythingoff();
  delay(time);
  everythingon();
  delay(time);
  tetris();
  delay(time);
  columnfirst();
  delay(time);
}
/*
 *  defining functions
 */
/*
 * turns every led bulb on 
 */
void everythingon(){
  for(int i = 0 ; i<16;i++){
    digitalWrite(cathode[i], LOW);
  }
  for(int i = 0 ; i<4;i++){
    digitalWrite(anode[i], HIGH);
  }
}
/*
 * turns everybulb off
 */
void everythingoff(){
  for(int i = 0 ; i<16;i++){
    digitalWrite(cathode[i], HIGH);
  }
  for(int i = 0 ; i<4;i++){
    digitalWrite(anode[i], LOW);
  } 
}
/*
 * turns bulb on layerwise
 */
void tetris(){
  everythingoff();
   for(int i = 0 ; i<16;i++){
    digitalWrite(cathode[i], LOW);
  }
  for(int i = 0 ; i<4;i++){
    digitalWrite(anode[i], HIGH);
    delay(time);
  }
}
/*
 * starts a trail of led bulbs column wise
 */
void columnfirst(){
  everythingoff();
  for(int i = 0 ; i<4; i++){
    digitalWrite(anode[i], HIGH);
    
  }
  for(int i = 0 ; i<16;i++){
    digitalWrite(cathode[i],LOW);
    delay(time);
    digitalWrite(cathode[i],HIGH);
  }
}
