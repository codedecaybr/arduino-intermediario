/*
  www.CodeDecay.com.br
  Licença de uso: Apache 2.0
*/

#define pusheen_width 101
#define pusheen_height 64
static unsigned char pusheen_bits[] U8G_PROGMEM = {
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x80, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0xe0, 0x03, 0x00, 0x98, 0x01, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x60, 0x06, 0x00, 0x0c, 0x03, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x0c, 0x00, 0x06, 0x02, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x18, 0x00, 0x06, 0x06, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x30, 0x00, 0x03, 0x0c,
   0xf8, 0xff, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0xe0, 0xff, 0x01,
   0xec, 0xff, 0xff, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0xe0, 0xdc,
   0x01, 0xf8, 0x80, 0x3f, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0xe0,
   0xdc, 0x01, 0x00, 0x80, 0x3f, 0xfc, 0x01, 0x00, 0x00, 0x00, 0x00, 0x06,
   0xc0, 0x8c, 0x00, 0x00, 0x80, 0x3f, 0xfc, 0x07, 0x00, 0x00, 0x00, 0x00,
   0x02, 0x00, 0x00, 0x00, 0x00, 0x80, 0x1f, 0xfc, 0x0d, 0x00, 0x00, 0x00,
   0x00, 0xf3, 0xff, 0xff, 0xff, 0x03, 0x00, 0x1f, 0xfc, 0x19, 0x00, 0x00,
   0x00, 0x1c, 0xfb, 0xff, 0xff, 0xff, 0x03, 0x1f, 0x00, 0xfc, 0x30, 0x00,
   0x00, 0x00, 0xfe, 0xf9, 0xff, 0xc0, 0xff, 0xe3, 0x1f, 0x00, 0x78, 0x60,
   0x00, 0x00, 0x00, 0x80, 0xf1, 0xff, 0xc0, 0xff, 0x03, 0x00, 0x00, 0x00,
   0xc0, 0x00, 0x00, 0x00, 0x80, 0xf0, 0xff, 0xcc, 0xff, 0x03, 0x00, 0x00,
   0x00, 0x80, 0x01, 0x00, 0x00, 0xf0, 0xf0, 0xff, 0xcc, 0xff, 0xe3, 0x07,
   0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0xde, 0xf0, 0x7f, 0xbf, 0xff, 0xc1,
   0x1f, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0xc2, 0xe0, 0x7f, 0xbf, 0xff,
   0x01, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x40, 0xc0, 0x3f, 0x00,
   0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x60, 0x00, 0x0f,
   0x00, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x60, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x20,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00,
   0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0xc0,
   0x07, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18,
   0xe0, 0x07, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x10, 0xf0, 0x0f, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x10, 0x98, 0x0f, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x30, 0x1c, 0x07, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x30, 0x1f, 0x06, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0xe0, 0x3d, 0x03, 0x10, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xbc, 0x03, 0x10, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xf8, 0x01, 0x18, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x78, 0x00, 0x18, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x3c, 0x00, 0x18,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x0f, 0x00,
   0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x01,
   0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30,
   0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x30, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x30, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x10, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x30, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x30, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x20,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00,
   0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00,
   0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02,
   0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x03, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x80, 0x01, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x80, 0x01, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x30,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00,
   0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x03, 0x00, 0x00, 0x00,
   0x00, 0x80, 0xf9, 0xff, 0xfc, 0xff, 0x9f, 0xff, 0xcf, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x80, 0xfd, 0xff, 0xfc, 0xff, 0x9f, 0xff, 0xd8, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x07, 0x80, 0x07, 0x00, 0xf0, 0x00, 0x70, 0x00,
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00 };
