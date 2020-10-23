int DIR=0;
int VEL=256;

void setup() {

  //SE ADJUNTAN PINES
  ledcAttachPin(12,0); 
  ledcAttachPin(13,1); 
  ledcAttachPin(26,2); 
  ledcAttachPin(27,3); 

  //SE DEFINEN PARAMETROS
  ledcSetup(0,6000,8);
  ledcSetup(1,6000,8);
  ledcSetup(2,6000,8);
  ledcSetup(3,6000,8);
}


void loop() {
  ADELANTE();
  delay(1000);
  DETENER();
  delay(500);
  ATRAS();
  delay(1000);
  DETENER();
  delay(500);
}

//FUNCION MOVER ADELANTE
void ADELANTE()
{
  DIR=1;
  ledcWrite(0,VEL);
  ledcWrite(1,0);
  ledcWrite(2,VEL);
  ledcWrite(3,0);
}

//FUNCION MOVER ATRAS
void ATRAS()
{
  DIR=0;
  ledcWrite(0,0);
  ledcWrite(1,VEL);
  ledcWrite(2,0);
  ledcWrite(3,VEL);
}

//FUNCION DETENER
void DETENER()
{
  DIR=0;
  ledcWrite(0,0);
  ledcWrite(1,0);
  ledcWrite(2,0);
  ledcWrite(3,0);
}
