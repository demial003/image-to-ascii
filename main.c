#include <stdio.h>
#include <string.h>
#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#define STB_IMAGE_RESIZE_IMPLEMENTATION
#include "stb_image.h"
#include "stb_image_resize.h"
#include "stb_image_write.h"

int main(void) {
  int x, y, n;
  unsigned char *data = stbi_load("arch.png", &x, &y, &n, 0);
  unsigned char *new_data = malloc(300);
  unsigned char *final_data = malloc(100);
  int err = stbir_resize_uint8(data, x, y, 0, new_data, 10, 10, 0, n);
  if (data == NULL) {
    fprintf(stderr, "failed to open image");
    exit(EXIT_FAILURE);
  }

  if (err != 1) {
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
  printf("width: %d height: %d componenets %d\n", x, y, n);
  int j = 0;
  for (int i = n; i < 300; i += n) {
    final_data[j] = data[i - 3] + 65;
    j++;
  }
  stbi_write_png("arch2.png", 10, 10, 1, final_data, 10);
  stbi_image_free(data);
  free(new_data);
  free(final_data);
}

/*
 * "`^\",:;Il!i~+_-?][}{1)(|\\/tfjrxnuvczXYUJCLQ0OZmwqpdbkhao*#MW&8%B@$ */
;
