 int Motor1A = 9;     //motor1
 int Motor1B = 10;    //motor1
 int Motor2A = 11;   //motor2
 int Motor2B = 12;   //motor2
 int MotorArma1 = 7;   //motor del Arma
 int MotorArma2 = 8;   //motor del Arma
 char bt = 0;       //BT 
 
 void setup()
 {
   Serial.begin(9600);
   
   pinMode(Motor1A,OUTPUT);
   pinMode(Motor1B,OUTPUT);
   pinMode(Motor2A,OUTPUT);
   pinMode(Motor2B,OUTPUT);
   pinMode(MotorArma1,OUTPUT);
   pinMode(MotorArma2,OUTPUT);
 }
 void loop()
 {
   if (Serial.available() > 0) //guarda los datos entrantes en la variable 'bt'
   {
     bt = Serial.read();

     if (bt == 'S')     //alto
     {   
       digitalWrite(Motor1A,LOW); //RUEDA LADO DER
       digitalWrite(Motor1B,LOW); //RUEDA LADO DER
       digitalWrite(Motor2A,LOW); //RUEDA LADO IZQ
       digitalWrite(Motor2B,LOW); //RUEDA LADO IZQ
     }   
     else if (bt == 'F')           //avanzar
     {
       digitalWrite(Motor1A,HIGH); //RUEDA LADO DER ADELANTE
       digitalWrite(Motor1B,LOW); //RUEDA LADO DER ATRAS
       digitalWrite(Motor2A,HIGH); //RUEDA LADO IZQ ADELANTE
       digitalWrite(Motor2B,LOW); //RUEDA LADO IZQ ATRAS
     }
     else if (bt == 'B')      //retroceder
     {
       digitalWrite(Motor1A,LOW);
       digitalWrite(Motor1B,HIGH);
       digitalWrite(Motor2A,LOW);
       digitalWrite(Motor2B,HIGH);
     }
     else if (bt== 'L')      //avanzar hacia la izquierda
     {
      digitalWrite(Motor1A,HIGH); //RUEDA LADO DER ADELANTE
      digitalWrite(Motor1B,LOW);  //RUEDA LADO DER ATRAS
      digitalWrite(Motor2A,LOW);  //RUEDA LADO IZQ ADELANTE
      digitalWrite(Motor2B,HIGH);  //RUEDA LADO IZQ ATRAS
     }
     else if (bt== 'R')      //avanzar hacia la derecha
     {
      digitalWrite(Motor1A,LOW);  //RUEDA LADO DER ADELANTE
      digitalWrite(Motor1B,HIGH);  //RUEDA LADO DER ATRAS
      digitalWrite(Motor2A,HIGH); //RUEDA LADO IZQ ADELANTE
      digitalWrite(Motor2B,LOW);  //RUEDA LADO IZQ ATRAS
     }
     //else if (bt== 'H')      //retroceder hacia la izquierda
    // {
    // digitalWrite(Motor1A,HIGH);  //RUEDA LADO DER ADELANTE
     //digitalWrite(Motor1B,LOW); //RUEDA LADO DER ATRAS
    // digitalWrite(Motor2A,LOW); //RUEDA LADO IZQ ADELANTE
    // digitalWrite(Motor2B,HIGH);  //RUEDA LADO IZQ ATRAS
     //}
     //else if (bt=='J')       //retroceder hacia la derecha
     //{
    // digitalWrite(Motor1A,LOW);  //RUEDA LADO DER ADELANTE
    // digitalWrite(Motor1B,HIGH); //RUEDA LADO DER ATRAS
    // digitalWrite(Motor2A,HIGH);  //RUEDA LADO IZQ ADELANTE
    // digitalWrite(Motor2B,LOW); //RUEDA LADO IZQ ATRAS
     //}
     else if (bt=='W')        //Activacion de arma 
     {
      digitalWrite(MotorArma1,HIGH);
      digitalWrite(MotorArma2,LOW);
     }
     else if (bt=='w')        //Activacion de arma 
     {
      digitalWrite(MotorArma1,LOW);
      digitalWrite(MotorArma2,HIGH);
     }
     else if (bt=='u')        //PARO de arma 
     {
      digitalWrite(MotorArma1,LOW);
      digitalWrite(MotorArma2,LOW);
     }
  }
}
 
