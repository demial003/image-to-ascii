#include <stdio.h>
#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image.h"
#include "stb_image_write.h"

int main(void) {
  int x, y, n;
  unsigned char *data = stbi_load("arch.png", &x, &y, &n, 0);
  if (data == NULL) {
    fprintf(stderr, "failed to open image");
    exit(EXIT_FAILURE);
  }

  printf("width: %d height: %d componenets %d\n", x, y, n);
  for (int i = 0; i < y * x * n; i++) {
    data[i] -= 100;
  }
  stbi_write_png("arch2.png", x, y, n, data, x * n);
  stbi_image_free(data);
}
