/*
  www.CodeDecay.com.br
  Licença de uso: Apache 2.0

  Neste exercício vamos animar a figura exibida no display. O arquivo pusheen.h
  contém a imagem de um gatinho e o arquivo pusheen_flip.h contém o mesmo gatinho
  olhando para a direção oposta. Ao alternamos os frames, vamos produzir uma animação
  que simula o gatinho dançando :)
 */

 //Diz para este programa em que arquivo buscar as funções que serão utilizadas
#include <Sodaq_DS3231.h> // biblioteca do RTC
#include "U8glib.h" // biblioteca do display OLED
#include "pusheen.h" // arquivo da figura 1: gatinho olhando para a esquerda
#include "pusheen_flip.h" // arquivo da figura 2: gatinho olhando para a direita

int comprimento = 10; // Esta variavel sera utilizada mais tarde para dizer o comprimento dos nos nossos vetores
unsigned int flip = 0;
String hora; // Esta string (uma sequencia especial de caracteres) sera utilizada para armazenar nosso horario
char horaArray[10], tempArray[10]; // Estes vetores de caracteres serao utilizados para enviar texto ao Display pois nao eh possível enviar strings diretamente ;(

U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NO_ACK);  // Declara o nosso display OLED.

void draw();

void setup() {
  Serial.begin(9600); // Inicializa comunicacao serial com o computador
  rtc.begin();        //  Inicializa comunicacao serial I2C com o RTC
}

void loop() {

  DateTime agora = rtc.now();// Adquire o horário atual do módulo RTC e armazena no objeto 'agora'

  // Diz para o DS3231 realizar uma conversão de temperatura e deixá-la pronta para leitura. Sem este comando a temperatura é atualizada pelo DS3231 a cada 64 segundos.
  rtc.convertTemperature();
  float temp = rtc.getTemperature(); // Lê o valor de temperatura através da comunicação I2C

  // Sabemos que para printar a hora na porta serial, bastaria fazer Serial.print(agora.hora()); e assim por diante.
  // Mas agora.hora() nao são caracteres, sao numeros. Apesar de vermos do mesmo modo, sao informacoes muito diferentes para o computador/Arduino.
  // Para enviar texto para o display, preciamos enviar caracteres, nao numeros. As proximas linhas tratam desta conversao.

  //Concatenação da string 'hora' no formato 'agora.hora():agora.minute():agora.second()'
  hora = String(agora.hour()) + ":" + String(agora.minute()) + ":" + String(agora.second());

  // Transforma a string hora em um vetor de caracteres.
  // a diferença entre as duas coisas é muito sutil, mas é necessário para a biblioteca do display
  hora.toCharArray(horaArray, comprimento);

  //Aqui eh feita a mesma coisa, mas a temperatura eh transformada de float para int e de int para String e de string para vetor de caracteres na mesma linha
  (String(int(temp)) + " C").toCharArray(tempArray,comprimento);

  //Agora temos os vetores de caracteres com 'hora:minuto:segundo' e 'temperatura C' prontos para o display :)

  updateDisplay(); // Chama a funcao de atualizacao do display

  flip = !flip; // alterna a direcao do gatinho. observe que so podemos fazer
  //isso fora da funcao draw(). Nesse ponto, ela ja foi chamada pelo loop principal
  //a quantidade necessaria de vezes para produzir o desenho no display


}

//A função draw é responsável por desenhar todos os elementos do OLED:
void draw() {
  u8g.setFont(u8g_font_helvB14); // Seleciona a fonte Helvetica Bold tamanho 14
  u8g.drawStr(10, 20, horaArray); // Escreve a hora lida do RTC
  u8g.setFont(u8g_font_helvB12); // Seleciona a fonte Helvetica Bold tamanho 12
  u8g.drawStr(30, 50, tempArray); // Escreve a temperatura lida do RTC

  if (flip) u8g.drawXBMP(128-pusheen_width, 0, pusheen_width, pusheen_height, pusheen_bits); // Desenha o gatinho olhando para a esquerda se flip == 1
  else u8g.drawXBMP(128-pusheen_flip_width, 0, pusheen_flip_width, pusheen_flip_height, pusheen_flip_bits); // Desenha o gatinho olhando para a direita se flip == 0
}


void updateDisplay() {
  //Este é o loop principal da U8Glib:
  u8g.firstPage();
  do {
    draw(); // Draw será nossa função de desenho
  } while( u8g.nextPage() );
}
