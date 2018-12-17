int data=0,i;
void setup() {
  for(i=2; i<11; i++){
    pinMode(i,OUTPUT);
    Serial.begin(9600);
  }

}
void sifir(){
  for(i=2; i<11; i++){
    digitalWrite(i,LOW);
  }
}
void loop() {
  if(Serial.available()){
    data = Serial.read();
    if(data=='1'){
      digitalWrite(8,HIGH);
      digitalWrite(2,LOW);
      digitalWrite(3,LOW);
      digitalWrite(4,LOW);
      digitalWrite(5,LOW);
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);
      digitalWrite(9,LOW);
      digitalWrite(10,LOW);
    }
    else if(data=='2'){
      digitalWrite(9,HIGH);
      digitalWrite(2,LOW);
      digitalWrite(3,LOW);
      digitalWrite(4,LOW);
      digitalWrite(5,LOW);
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);
      digitalWrite(8,LOW);
      digitalWrite(10,LOW);
    }
    else if(data=='3'){
      digitalWrite(10,HIGH);
      digitalWrite(2,LOW);
      digitalWrite(3,LOW);
      digitalWrite(4,LOW);
      digitalWrite(5,LOW);
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);
      digitalWrite(9,LOW);
      digitalWrite(8,LOW);
    }
    else if(data=='4'){
      digitalWrite(5,HIGH);
      digitalWrite(2,LOW);
      digitalWrite(3,LOW);
      digitalWrite(4,LOW);
      digitalWrite(8,LOW);
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);
      digitalWrite(9,LOW);
      digitalWrite(10,LOW);
    }
    else if(data=='5'){
      digitalWrite(6,HIGH);
      digitalWrite(2,LOW);
      digitalWrite(3,LOW);
      digitalWrite(4,LOW);
      digitalWrite(5,LOW);
      digitalWrite(8,LOW);
      digitalWrite(7,LOW);
      digitalWrite(9,LOW);
      digitalWrite(10,LOW);
    }
    else if(data=='6'){
      digitalWrite(7,HIGH);
      digitalWrite(2,LOW);
      digitalWrite(3,LOW);
      digitalWrite(4,LOW);
      digitalWrite(5,LOW);
      digitalWrite(6,LOW);
      digitalWrite(8,LOW);
      digitalWrite(9,LOW);
      digitalWrite(10,LOW);
    }
    else if(data=='7'){
      digitalWrite(2,HIGH);
      digitalWrite(8,LOW);
      digitalWrite(3,LOW);
      digitalWrite(4,LOW);
      digitalWrite(5,LOW);
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);
      digitalWrite(9,LOW);
      digitalWrite(10,LOW);
    }
    else if(data=='8'){
      digitalWrite(3,HIGH);
      digitalWrite(2,LOW);
      digitalWrite(8,LOW);
      digitalWrite(4,LOW);
      digitalWrite(5,LOW);
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);
      digitalWrite(9,LOW);
      digitalWrite(10,LOW);
    }
    else if(data=='9'){
      digitalWrite(4,HIGH);
      digitalWrite(2,LOW);
      digitalWrite(3,LOW);
      digitalWrite(8,LOW);
      digitalWrite(5,LOW);
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);
      digitalWrite(9,LOW);
      digitalWrite(10,LOW);
    }
    else{
      digitalWrite(4,LOW);
      digitalWrite(2,LOW);
      digitalWrite(3,LOW);
      digitalWrite(8,LOW);
      digitalWrite(5,LOW);
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);
      digitalWrite(9,LOW);
    }
  }
  
}
