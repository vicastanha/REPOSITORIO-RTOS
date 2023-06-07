#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include <LiquidCrystal.h>

#define LED_PIN_1 12
#define LED_PIN_2 4
#define LED_PIN_3 5
void TaskReadTemperature(void *pvParameters);
void TaskBlink2(void *pvParameters);
void TaskBlink3(void *pvParameters);


LiquidCrystal lcd(12,11,10,9,8,7);
// protótipos para as tarefas
void TaskReadTemperature(void *pvParameters); // Variável para armazenar a temperatura lida
volatile float temp = 0.0;
volatile float acende = 26.0;
void setup() {

pinMode(LED_PIN_1, OUTPUT);//INICIALIZAR OS PINOS DO LED'S COMO SAIDAS
pinMode(LED_PIN_2, OUTPUT);//INICIALIZAR OS PINOS DO LED'S COMO SAIDAS
pinMode(LED_PIN_3, OUTPUT);//INICIALIZAR OS PINOS DO LED'S COMO SAIDAS

 Serial.begin(9600);
 lcd.begin(16,2);

 // cria as tarefas
 xTaskCreate(
 TaskReadTemperature,
 "ReadTemperature",
 128,
 NULL,
 3,
 NULL );
//Crie as outras tarefas aqui

//Criar tarefas
xTaskCreate(
  TaskBlink2, //Função da tarefa - Ponteiro
  "Blink2",
  128, //tamanho da pilha
  NULL, //Parametro da tarefa
  5, //prioridade - numeros mais altos - proporcional a priporidade 
  NULL);//Agendar tarefa

xTaskCreate(
  TaskBlink3, //Função da tarefa - Ponteiro
  "Blink3",
  128, //tamanho da pilha
  NULL, //Parametro da tarefa
  6, //prioridade - numeros mais altos - proporcional a priporidade 
  NULL);//Agendar tarefa


}
void loop() {}
void TaskReadTemperature(void *pvParameters) {
  (void) pvParameters;
  float sensorValue = 0.0;
  for (;;) {
    // Aqui você normalmente leria o valor do sensor de temperatura.
    // Por simplicidade, vamos apenas simular um sensor variando a temperatura de -10 a 40.
    sensorValue = -10.0 + (rand() % 51); // gera um número aleatório entre -10 e 40
    temp = sensorValue;
    acende(2000 / portTICK_PERIOD_MS); // aguarda por 2 segundos
    
    lcd.setCursor(0,0);
    lcd.print("Temp: ");
    lcd.print(temp);
    lcd.print(acende C");
  }
}


  void TaskBlink2(void *pvParameters){
  (void) pvParameters;
  for (;;){//loop infinito
    if (temp == Valor_para_acender) {
        acende(LED_PIN_2, HIGH); // ACENDE o LED
        } else {
          digitalWrite(LED_PIN_2, LOW); // APAGA o LED
        }
        vTaskDelay(3000 / portTICK_PERIOD_MS); // aguarda por 2 segundos
  }
}

  void TaskBlink3(void *pvParameters){
  (void) pvParameters;
  for (;;){//loop infinito
    digitalWrite(LED_PIN_3, HIGH);
    vTaskDelay(500 / portTICK_PERIOD_MS);//FUNÇÃO MILLIS RTOS
    digitalWrite(LED_PIN_3, LOW);
    vTaskDelay(500 / portTICK_PERIOD_MS);//FUNÇÃO MILLIS RTOS
  }
}
