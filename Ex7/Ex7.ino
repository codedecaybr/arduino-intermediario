/*
  www.CodeDecay.com.br
  Licença de uso: Apache 2.0
  Neste exercício vamos substituir o relógio digital por um relógio analógico.
 */

//Diz para este programa em que arquivo buscar as funções que serão utilizadas
#include <Sodaq_DS3231.h>
#include <U8g2lib.h>
#include <U8x8lib.h>
#include <math.h> //para as operações com ângulos

U8G2_SSD1306_128X64_NONAME_F_HW_I2C oled(U8G2_R0);  // Declara o nosso display OLED.

void setup() {

    Serial.begin(9600); // Inicializa comunicacao serial com o computador
    rtc.begin();        //  Inicializa comunicacao serial I2C com o RTC
    oled.begin();       // Inicializa a comunicacao com o display
}

void loop() {


    //Executa os desenhos
    draw();
    //Envia os desenhos para o display
    oled.sendBuffer();


    delay(500);

}

void draw() {
    double passoHoras, passoMin, passoSeg, posicao;
    int x0, y0, raio;

    /*
    Vamos calcular o passo, em radianos, que cada ponteiro anda.
      - O ponteiro das horas anda 2.pi radianos (360 graus)
    para cada 12 horas, portanto, 2.pi/12 radianos por hora
      - Os ponteiros dos minutos anda 2.pi radianos a cada 60 minutos,
    portanto, 2.pi/60 radianos por minuto.
      - O ponteiro dos segundos anda 2.pi radianos a cada 60 segundos,
    portanto, 2.pi/60 radianos por segundo (mesmo valor que o passo dos
    minutos).
    */

    passoHoras = 2*PI/12.0;
    passoMin = 2*PI/60.0;
    passoSeg = passoMin;

    oled.clearBuffer(); // Limpa a tela de desenho

    DateTime agora = rtc.now();

    // Circunferecia de raio = 30 e centro em (x0 = 32, y0 = 32)
    x0 = 32;
    y0 = 32;
    raio = 30;
    oled.drawCircle(x0, y0, raio);

    // Ponteiro das horas
    // A posicao atual do ponteiro em radianos é: hora atual * passoHoras
    // Desenha uma linha que parte de (x0, y0) e vai até
    // (x0 + raio*cos(posição do ponteiro), y0 - raio*sen(posição do ponteiro))
    posicao = agora.hour()*passoHoras;
    raio = 13;
    oled.drawLine( x0, y0, x0 + raio*sin(posicao), y0 - raio*cos(posicao) );

    // Ponteiro dos minutos
    // A posicao atual do ponteiro em radianos é: minuto atual * passoMin
    // Desenha uma linha que parte de (x0, y0) e vai até
    // (x0 + raio*cos(posição do ponteiro), y0 - raio*sen(posição do ponteiro))
    posicao = agora.minute()*passoMin;
    raio = 20;
    oled.drawLine( x0, y0, x0 + raio*sin(posicao), y0 - raio*cos(posicao) );

    // Ponteiro dos segundos
    // A posicao atual do ponteiro em radianos é: minuto atual * passoSeg
    // Desenha uma linha que parte de (x0, y0) e vai até
    // (x0 + raio*cos(posição do ponteiro), y0 - raio*sen(posição do ponteiro))
    posicao = agora.second()*passoSeg;
    raio = 20;
    oled.drawLine( x0, y0, x0 + raio*sin(posicao), y0 - raio*cos(posicao) );

    oled.setFont(u8g2_font_helvB14_tf); // Seleciona a fonte Helvetica Bold tamanho 14
    oled.setCursor(75, 32-14); // Posiciona o cursor de texto na coordenada (75,18)
    oled.print( String( agora.hour() ) + "h" + String( agora.minute() ) );

}
