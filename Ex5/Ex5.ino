/*
  www.CodeDecay.com.br
  Licença de uso: Apache 2.0
  Neste exercício vamos acrescentar uma figura ao display.
 */

//Diz para este programa em que arquivo buscar as funções que serão utilizadas
#include <Sodaq_DS3231.h>
#include <U8g2lib.h>
#include <U8x8lib.h>

// Arquivo da figura
#include "pusheen.h" 

String hora; // Esta string (uma sequencia especial de caracteres) sera utilizada para armazenar nosso horario
String temperatura; // Esta string (uma sequencia especial de caracteres) sera utilizada para armazenar a temperatura

U8G2_SSD1306_128X64_NONAME_F_HW_I2C oled(U8G2_R0);  // Declara o nosso display OLED.

void setup() {
    
    Serial.begin(9600); // Inicializa comunicacao serial com o computador
    rtc.begin();        //  Inicializa comunicacao serial I2C com o RTC
    oled.begin();       // Inicializa a comunicacao com o display
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
    
    
    //Executa os desenhos
    draw();
    //Envia os desenhos para o display
    oled.sendBuffer();

}

void draw() {
    oled.clearBuffer(); // Limpa a tela de desenho
    oled.setFont(u8g2_font_helvB14_tf); // Seleciona a fonte Helvetica Bold tamanho 14
    oled.setCursor(10, 20); // Posiciona o cursor de texto na coordenada (10,20)
    oled.print(hora); // Escreve a hora nas coordenadas (10,20) do display
    oled.setFont(u8g2_font_helvB12_tf); // Seleciona a fonte Helvetica Bold tamanho 12
    oled.setCursor(30, 50); // Posiciona o cursor de texto na coordenada (30,50)
    oled.print(temperatura); // Escreve a temperatura nas coordenadas (30,50) do display
    
    oled.drawXBMP(128-pusheen_width, 0, pusheen_width, pusheen_height, pusheen_bits); // Desenha uma figura
}