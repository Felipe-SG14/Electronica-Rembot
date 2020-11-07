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
int VEL_A=157;
int VEL_B=97;
int VEL_C=180;
int VEL_D=80;

void setup() {

  //SE ADJUNTAN PINES
  ledcAttachPin(17,0); //PIN ENABLE 1
  ledcAttachPin(16,3); //PIN ENABLE 2

  //SE DEFINEN PARAMETROS
  ledcSetup(0,6000,8);
  ledcSetup(3,6000,8);

  Serial.begin(115200);
}


void loop() {
  if (Serial.available())
  {
    char dato = Serial.read();
    if (dato=='w')
    {
      Serial.println('w');
      ADELANTE();
      delay(3000);
    }
    if (dato=='d')
    {
      Serial.println('d');
      DERECHA();
      delay(3000);
    }
    if (dato=='x')
    {
      Serial.println('x');
      ATRAS();
      delay(3000);
    }
    if (dato=='a')
    {
      Serial.println('a');
      IZQUIERDA();
      delay(3000);
    }
    if (dato=='s')
    {
      Serial.println('s');
      DETENER();
      delay(3000);
    }
  }
}

//FUNCION MOVER ADELANTE
void ADELANTE()
{
  DIR_A=1;
  DIR_B=1;
  ledcWrite(0,VEL_A);
  ledcWrite(3,VEL_B);
}

//FUNCION MOVER ATRAS
void ATRAS()
{
  DIR_A=0;
  DIR_B=0;
  ledcWrite(0,VEL_B);
  ledcWrite(3,VEL_A);
}

//FUNCION DETENER
void DETENER()
{
  DIR_A=0;
  DIR_B=0;
  ledcWrite(0,127);
  ledcWrite(3,127);
}

//FUNCION DERECHA
void IZQUIERDA()
{
  DIR_A=1;
  DIR_B=0;
  ledcWrite(0,VEL_A);
  ledcWrite(3,VEL_A);
}

//FUNCION IZQUIERDA
void DERECHA()
{
  DIR_A=0;
  DIR_B=1;
  ledcWrite(0,VEL_B);
  ledcWrite(3,VEL_B);
}
