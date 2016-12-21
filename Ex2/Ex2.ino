/*
  www.CodeDecay.com.br
  Licença de uso: Apache 2.0
  Neste exercício vamos aprender a ler as informações guardadas pelo RTC
 */

//Diz para este programa em que arquivo buscar as funções que serão utilizadas
#include <Sodaq_DS3231.h>

String hora; // Esta string (uma sequencia especial de caracteres) sera utilizada para armazenar nosso horario
String temperatura; // Esta string (uma sequencia especial de caracteres) sera utilizada para armazenar a temperatura

void setup() {
  Serial.begin(9600); // Inicializa comunicacao serial com o computador
  rtc.begin();        //  Inicializa comunicacao serial I2C com o RTC
}

void loop() {
    
    // Adquire o horário atual do módulo RTC e armazena no objeto 'agora'
    DateTime agora = rtc.now();

    // Diz para o DS3231 realizar uma conversão de temperatura e deixá-la pronta para leitura. Sem este comando a temperatura é atualizada pelo DS3231 a cada 64 segundos.
    rtc.convertTemperature();
    // Lê o valor de temperatura através da comunicação I2C
    float temp = rtc.getTemperature(); 


    //Concatenação da string 'hora' no formato 'agora.hora():agora.minute():agora.second()'
    hora = String( agora.hour() ) + ":" + String( agora.minute() ) + ":" + String( agora.second() );

    //Aqui eh feita a mesma coisa, mas a temperatura eh transformada de float para int e de int para String e de string para vetor de caracteres na mesma linha
    temperatura = String( int(temp) ) + " C";

}