//Programa 2 - Dos motores
//Consideren cuatro variables, la primera llamada DIR_A, la segunda VEL_A, la tercera DIR_B, la cuarta VEL_B
//DIR_A y DIR_B tendrá cambiará de valor lógico (1 y 0).
//
//Deberán definir diferentes funciones de la siguiente manera:
//Adelante -> Los dos motores A y B, girarán permitiendo un movimiento hacia adelante de una base móvil de tipo diferencial (Twinbot)
//Atrás -> Los dos motores A y B, girarán permitiendo un movimiento hacia atrás de una base móvil de tipo diferencial (Twinbot)
//Derecha -> Los dos motores A y B, girarán de manera que el Twinbot gire a la derecha
//Izquierda -> Los dos motores A y B, girarán de manera que el Twinbot gire a la izquierda
//Detenido -> El Twinbot se quedará detenido
//
//El programa hará que el Twinbot se mueva de la siguiente manera:
//Adelante durante 1 segundo, 
//Derecha por 1 segundo
//Detenido por medio segundo
//Atrás por 1 segundo 
//Izquierda por 1 segundo 
//Detenido por medio segundo repitiéndose indefinidamente

int DIR_A=0;
int DIR_B=0;
int VEL_A=255;
int VEL_B=200;

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
  delay(3000);
  DERECHA();
  delay(3000);
  DETENER();
  delay(500);
  ATRAS();
  delay(3000);
  IZQUIERDA();
  delay(3000);
  DETENER();
  delay(500);
}

//FUNCION MOVER ADELANTE
void ADELANTE()
{
  DIR_A=1;
  DIR_B=1;
  ledcWrite(0,VEL_A);
  ledcWrite(1,0);
  ledcWrite(2,VEL_A);
  ledcWrite(3,0);
}

//FUNCION MOVER ATRAS
void ATRAS()
{
  DIR_A=0;
  DIR_B=0;
  ledcWrite(0,0);
  ledcWrite(1,VEL_A);
  ledcWrite(2,0);
  ledcWrite(3,VEL_A);
}

//FUNCION DETENER
void DETENER()
{
  DIR_A=0;
  DIR_B=0;
  ledcWrite(0,0);
  ledcWrite(1,0);
  ledcWrite(2,0);
  ledcWrite(3,0);
}

//FUNCION DERECHA
void DERECHA()
{
  DIR_A=1;
  DIR_B=0;
  ledcWrite(0,VEL_A);
  ledcWrite(1,0);
  ledcWrite(2,VEL_B);
  ledcWrite(3,0);
}

//FUNCION IZQUIERDA
void IZQUIERDA()
{
  DIR_A=0;
  DIR_B=1;
  ledcWrite(0,VEL_B);
  ledcWrite(1,0);
  ledcWrite(2,VEL_A);
  ledcWrite(3,0);
}
