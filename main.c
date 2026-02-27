#include <stdio.h>
#include <string.h>
#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image.h"
#include "stb_image_write.h"

int main(void) {
  int x, y, n;
  unsigned char *data = stbi_load("triangle.png", &x, &y, &n, 0);
  unsigned char new_data[x * y];
  if (data == NULL) {
    fprintf(stderr, "failed to open image");
    exit(EXIT_FAILURE);
  }

  char *chars =
      "`^\",:;Il!i~+_-?][}{1)(|\\/tfjrxnuvczXYUJCLQ0OZmwqpdbkhao*#MW&8%B@$";
  int len = strlen(chars);
  char stuff[len];
  for (int i = 0; i < len; i++) {
    stuff[i] = chars[i];
  }
  printf("%c\n", chars[3]);
  printf("width: %d height: %d componenets %d\n", x, y, n);
  for (int i = 0; i < y * x * n; i++) {
    if (n % 3 == 0) {
      // unsigned char newColor = (data[i - 2] + data[i - 1] + data[i]) / 3;
      // data[i] += 65;
    }
  }
  stbi_write_png("triangle2.png", x, y, n, data, x * n);
  stbi_image_free(data);
}

/*
 * "`^\",:;Il!i~+_-?][}{1)(|\\/tfjrxnuvczXYUJCLQ0OZmwqpdbkhao*#MW&8%B@$ */
;
