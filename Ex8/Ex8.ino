/*
  www.CodeDecay.com.br
  Licença de uso: Apache 2.0
  Neste exercício vamos substituir o relógio analógico por uma ampulheta para os segundos.
 */

//Diz para este programa em que arquivo buscar as funções que serão utilizadas
#include <Sodaq_DS3231.h>
#include <U8g2lib.h>
#include <U8x8lib.h>

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

    int ax, ay, bx, by, cx, cy, dx, dy, ex, ey;
    double alturaPercent;

    ax = 8; ay = 8;
    bx = 64 - ax; by = ay;
    cx = 32; cy = 32;
    dx = ax; dy = 64 - ay;
    ex = bx; ey = 64 - by;


    oled.clearBuffer(); // Limpa a tela de desenho

    DateTime agora = rtc.now();

    alturaPercent = agora.second()/60.0;

    oled.setDrawColor(1);
    oled.drawTriangle(ax + alturaPercent*(cx-ax), ay + alturaPercent*(cy-ay),
                        bx + alturaPercent*(cx-bx), by + alturaPercent*(cy-by),
                            cx, cy);

    oled.drawTriangle(cx, cy, dx, dy, ex, ey);

    oled.setDrawColor(0);
    oled.drawTriangle(cx, cy,
                        dx + alturaPercent*(cx-dx), dy + alturaPercent*(cy-dy),
                            ex + alturaPercent*(cx-ex), ey + alturaPercent*(cy-ey));


    oled.setDrawColor(1);
    oled.drawLine(ax, ay, ex, ey);
    oled.drawLine(bx, by, dx, dy);

    oled.drawLine(ax, ay, bx, by);
    oled.drawLine(ex, ey, dx, dy);

    oled.drawLine(ax, ay, dx, dy);
    oled.drawLine(bx, by, ex, ey);

    oled.drawRBox(0, dy, 64, 4, 1);
    oled.drawRBox(0, ay-4, 64, 4, 1);

    oled.setFont(u8g2_font_helvB14_tf); // Seleciona a fonte Helvetica Bold tamanho 14
    oled.setCursor(75, 32-14); // Posiciona o cursor de texto na coordenada (75,18)
    oled.print( String( agora.hour() ) + "h" + String( agora.minute() ) );

}
