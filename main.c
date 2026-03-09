#include "ascii_utils.h"
#include <stdio.h>
#include <string.h>
#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#define STB_IMAGE_RESIZE_IMPLEMENTATION
#include "stb_image.h"
#include "stb_image_resize.h"
#include "stb_image_write.h"

unsigned char average_rgb(unsigned char *data, int index) {
  return (data[index + 2] + data[index + 1] + data[index]) / 3;
}

unsigned char min_max_rgb(unsigned char *data, int index) {

  unsigned char r = data[index + 2];
  unsigned char g = data[index + 1];
  unsigned char b = data[index];
  return (max(r, g, b) + min(r, g, b)) / 2;
}

unsigned luminosity_rgb(unsigned char *data, int index) {
  unsigned char r = data[index + 2];
  unsigned char g = data[index + 1];
  unsigned char b = data[index];

  unsigned char r_new = (unsigned char)(0.21 * r);
  unsigned char g_new = (unsigned char)(0.72 * g);
  unsigned char b_new = (unsigned char)(0.07 * b);

  return r_new + g_new + b_new;
}
int main(void) {
  int initial_width, initial_height, components;
  unsigned char *data = stbi_load("triangle.png", &initial_width,
                                  &initial_height, &components, 0);
  int scaled_width = initial_width / 10 + 1;
  int scaled_height = initial_height / 10 + 1;
  unsigned char *scaled_data =
      malloc(scaled_width * scaled_height * components);
  unsigned char *final_data = malloc(scaled_width * scaled_height);
  int err =
      stbir_resize_uint8(data, initial_width, initial_height, 0, scaled_data,
                         scaled_width, scaled_height, 0, components);
  if (data == NULL) {
    fprintf(stderr, "failed to open image");
    exit(EXIT_FAILURE);
  }

  char *chars =
      "`^\",:;Il!i~+_-?][}{1)(|\\/tfjrxnuvczXYUJCLQ0OZmwqpdbkhao*#MW&8%B@";
  int len = strlen(chars);
  char stuff[len];
  for (int i = 0; i < len; i++) {
    stuff[i] = chars[i];
  }

  printf("width: %d height: %d components %d\n", scaled_width, scaled_height,
         components);

  int j = 0;
  char *output = malloc(scaled_width * scaled_height);
  for (int i = 0; i < scaled_width * scaled_height; i++) {
    int pixel_pos = i * components;
    final_data[j] = min_max_rgb(scaled_data, pixel_pos);

    int idx = (final_data[j] >> 2);
    printf("%c%c", stuff[idx], stuff[idx]);

    if ((i + 1) % scaled_width == 0) {
      printf("\n");
    }

    ++j;
  }

  printf("\n");
  stbi_image_free(data);
  free(output);
  free(scaled_data);
  free(final_data);
}

/*
 * "`^\",:;Il!i~+_-?][}{1)(|\\/tfjrxnuvczXYUJCLQ0OZmwqpdbkhao*#MW&8%B@$ */
;
