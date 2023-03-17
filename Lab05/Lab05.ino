/*
  Electrónica Digital 2
  Autor: Luis Pablo Carranza
  Carnet: 21767
  Laboratorio 5 - Juego de carreras
*/

// most launchpads have a red LED
#define LED RED_LED

//see pins_energia.h for more LED definitions
#define LED2 GREEN_LED

#define STARTB PUSH1

#define J1L1 PA_6
#define J1L2 PA_5
#define J1L3 PB_4
#define J1L4 PE_5
#define J1L5 PE_4
#define J1L6 PB_1
#define J1L7 PB_0
#define J1L8 PB_5

#define J2L1 PB_3
#define J2L2 PC_4
#define J2L3 PC_5
#define J2L4 PC_6
#define J2L5 PC_7
#define J2L6 PD_6
#define J2L7 PA_2
#define J2L8 PA_3

#define J1_P PE_3
#define J2_P PE_2

#define J1WIN PA_7
#define J2WIN PA_4

int buttonState = 0;

int button1State = 0;
int button2State = 0;

int game = 0;
int p1cont;
int p2cont;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(LED, OUTPUT); 
  pinMode(LED2, OUTPUT); 
  pinMode(STARTB, INPUT_PULLUP);
   
  pinMode(J1_P, INPUT_PULLUP);   
  pinMode(J2_P, INPUT_PULLUP);
  
  pinMode(J1L1, OUTPUT);
  pinMode(J1L2, OUTPUT);
  pinMode(J1L3, OUTPUT);
  pinMode(J1L4, OUTPUT);
  pinMode(J1L5, OUTPUT);
  pinMode(J1L6, OUTPUT);
  pinMode(J1L7, OUTPUT);
  pinMode(J1L8, OUTPUT);
  pinMode(J1WIN, OUTPUT);
  
  pinMode(J2L1, OUTPUT);
  pinMode(J2L2, OUTPUT);
  pinMode(J2L3, OUTPUT);
  pinMode(J2L4, OUTPUT);
  pinMode(J2L5, OUTPUT);
  pinMode(J2L6, OUTPUT);
  pinMode(J2L7, OUTPUT);
  pinMode(J2L8, OUTPUT);
  pinMode(J2WIN, OUTPUT);
  
}

// the loop routine runs over and over again forever:
void loop() {
  buttonState = digitalRead(STARTB);
  
  // Inicia hasta que se presiona el botón
  if(buttonState == LOW){
    
    digitalWrite(J1L1, LOW);
    digitalWrite(J1L2, LOW);
    digitalWrite(J1L3, LOW);
    digitalWrite(J1L4, LOW);
    digitalWrite(J1L5, LOW);
    digitalWrite(J1L6, LOW);
    digitalWrite(J1L7, LOW);
    digitalWrite(J1L8, LOW);
    
    digitalWrite(J2L1, LOW);
    digitalWrite(J2L2, LOW);
    digitalWrite(J2L3, LOW);
    digitalWrite(J2L4, LOW);
    digitalWrite(J2L5, LOW);
    digitalWrite(J2L6, LOW);
    digitalWrite(J2L7, LOW);
    digitalWrite(J2L8, LOW);
    
  // Empieza en rojo
    digitalWrite(J1WIN, LOW);
    digitalWrite(J2WIN, LOW);
    analogWrite(LED, 255);   
    analogWrite(LED2, 0);    
    delay(1500);              
  // Pasa a amarillo
    analogWrite(LED, 245);  
    analogWrite(LED2, 230);    
    delay(1500);  
  // Pasa a verde
    analogWrite(LED, 0);   
    analogWrite(LED2, 255);    
    delay(1500); 

  // Apaga todo antes de que inicie el juego
    analogWrite(LED, 0);   
    analogWrite(LED2, 0); 
    p1cont = 0;
    p2cont = 0;
    game = 0;
    
    while(game == 0){
      
      button1State = digitalRead(J1_P);
      button2State = digitalRead(J2_P);
      
      if(button1State == LOW){
        delay(200);
        p1cont = p1cont + 1;
      }
      
      if(button2State == LOW){
        delay(200);
        p2cont = p2cont + 1;
      }
      switch(p1cont){
        case 0:
          digitalWrite(J1L1, LOW);
          digitalWrite(J1L2, LOW);
          digitalWrite(J1L3, LOW);
          digitalWrite(J1L4, LOW);
          digitalWrite(J1L5, LOW);
          digitalWrite(J1L6, LOW);
          digitalWrite(J1L7, LOW);
          digitalWrite(J1L8, LOW);
          break;
        case 1:
          digitalWrite(J1L1, HIGH);
          break;
        case 2:
          digitalWrite(J1L1, LOW);
          digitalWrite(J1L2, HIGH);
          break;
        case 3:
          digitalWrite(J1L2, LOW);
          digitalWrite(J1L3, HIGH);
          break;
        case 4:
          digitalWrite(J1L3, LOW);
          digitalWrite(J1L4, HIGH);
          break; 
        case 5:
          digitalWrite(J1L4, LOW);
          digitalWrite(J1L5, HIGH);
          break;    
        case 6:
          digitalWrite(J1L5, LOW);
          digitalWrite(J1L6, HIGH); 
          break;  
        case 7:
          digitalWrite(J1L6, LOW);
          digitalWrite(J1L7, HIGH);  
          break;
        case 8:
          digitalWrite(J1L7, LOW);
          digitalWrite(J1L8, HIGH);
          game = HIGH;
          break;
        }
      switch(p2cont){
        case 0:
          digitalWrite(J2L1, LOW);
          digitalWrite(J2L2, LOW);
          digitalWrite(J2L3, LOW);
          digitalWrite(J2L4, LOW);
          digitalWrite(J2L5, LOW);
          digitalWrite(J2L6, LOW);
          digitalWrite(J2L7, LOW);
          digitalWrite(J2L8, LOW);
          break;
        case 1:
          digitalWrite(J2L1, HIGH);
          break;
        case 2:
          digitalWrite(J2L1, LOW);
          digitalWrite(J2L2, HIGH);
          break;
        case 3:
          digitalWrite(J2L2, LOW);
          digitalWrite(J2L3, HIGH);
          break;
        case 4:
          digitalWrite(J2L3, LOW);
          digitalWrite(J2L4, HIGH);
          break; 
        case 5:
          digitalWrite(J2L4, LOW);
          digitalWrite(J2L5, HIGH);
          break;    
        case 6:
          digitalWrite(J2L5, LOW);
          digitalWrite(J2L6, HIGH); 
          break;  
        case 7:
          digitalWrite(J2L6, LOW);
          digitalWrite(J2L7, HIGH);  
          break;
        case 8:
          digitalWrite(J2L7, LOW);
          digitalWrite(J2L8, HIGH);
          game = 1;
          break;
        }
    }
    if(p1cont == 8) {
      digitalWrite(J1WIN, HIGH);
      digitalWrite(J2WIN, LOW);
      digitalWrite(J2L8, LOW);
      digitalWrite(J2L1, LOW);
      digitalWrite(J2L2, LOW);
      digitalWrite(J2L3, LOW);
      digitalWrite(J2L4, LOW);
      digitalWrite(J2L5, LOW);
      digitalWrite(J2L6, LOW);
      digitalWrite(J2L7, LOW);
      digitalWrite(J2L8, LOW);
      }
    if(p2cont == 8){
      digitalWrite(J1WIN, LOW);
      digitalWrite(J2WIN, HIGH);
      digitalWrite(J1L8, LOW);
      digitalWrite(J1L1, LOW);
      digitalWrite(J1L2, LOW);
      digitalWrite(J1L3, LOW);
      digitalWrite(J1L4, LOW);
      digitalWrite(J1L5, LOW);
      digitalWrite(J1L6, LOW);
      digitalWrite(J1L7, LOW);
      digitalWrite(J1L8, LOW);
      }
  }       
  
  // Si no está presionado apaga el RGB
  else {
    analogWrite(LED, 0);   
    analogWrite(LED2, 0);   
    }         
}
