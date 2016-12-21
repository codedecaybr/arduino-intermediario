/*
  www.CodeDecay.com.br
  Licença de uso: Apache 2.0
  Sketch baseado no exemplo 'ajust' da biblioteca Sodaq_DS3231
  Neste exercício vamos fazer a configuração inicial do RTC, ajustando
  o relógio para a data e hora atuais.
 */

//Diz para este programa em que arquivo buscar as funções que serão utilizadas
#include "Sodaq_DS3231.h"

//A informação de dia da semana é entregue pelo RTC como um numero de 0 a 6. Este vetor serve para fazer
//uma correspondência com texto
char semana[][4] = {"Dom", "Seg", "Ter", "Qua", "Qui", "Sex", "Sab" };

// o objeto dt é inicializado com ano, mes, dia, hora, minuto, segundo e dia da semana nesta ordem
DateTime dt(2016, 7, 28, 12, 15, 0, 4);

void setup ()
{
    Serial.begin(9600); // inicializa comunicação serial com o computador
    rtc.begin();        // inicializa comunicação serial com o rtc
    rtc.setDateTime(dt); // método que ajusta o RTC conforme o objeto dt definido anteriormente
}

// A função loop lê o RTC e envia para a porta serial o horário atual
void loop () {
    DateTime agora = rtc.now(); // Inicializa o objeto do tipo DateTime chamado 'agora' e lê o horário do RTC
    Serial.print(agora.date());
    Serial.print('/');
    Serial.print(agora.month());
    Serial.print('/');
    Serial.print(agora.year());
    Serial.print(' ');
    Serial.print(agora.hour());
    Serial.print(':');
    Serial.print(agora.minute());
    Serial.print(':');
    Serial.print(agora.second());
    Serial.println();
    Serial.print(semana[agora.dayOfWeek()]); // Se imprimir apenas print(agora.dayOfWeek) o resultado é 0 para domingo, 1 para segunda etc.
    Serial.println();
    delay(1000);
}