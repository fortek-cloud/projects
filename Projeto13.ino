#include "DHT.h"
 
#define DHTPIN A1 // o sensor dht11 foi conectado ao pino A1 no nosso tutorial
#define DHTTYPE DHT11 //Tipo do DHT (DHT11, DHHT22), no nosso caso eh o DHT11
 
DHT dht(DHTPIN, DHTTYPE);
 
void setup() 
{
Serial.begin(9600);
Serial.println("DHT11!");
dht.begin();
}
 
void loop() 
{
  
float umidade = dht.readHumidity(); //A variavel umidade recebe o valor da funcao de leitura de umidade do sensor;
float temperatura = dht.readTemperature(); ////A variavel temperatura recebe o valor da funcao de leitura de temperatura do sensor;

if (isnan(temperatura) || isnan(umidade)) // Se as variaveis temperatura e umidade nao forem valores validos, acusara falha de leitura.( "isnan" siginficada "is not a number");
{
Serial.println("Falha na leitura do DHT11...");
} 
else 
{
  //Imprime os dados no monitor serial
  Serial.print("Umidade: ");
  Serial.print(umidade);
  Serial.println(" %"); //quebra de linha
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" C");
  delay(1000);// Espera de 1 segundo
}
}
