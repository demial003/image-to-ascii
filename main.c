#include <stdio.h>
#include <string.h>
#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#define STB_IMAGE_RESIZE_IMPLEMENTATION
#include "stb_image.h"
#include "stb_image_resize.h"
#include "stb_image_write.h"

int main(void) {
  int initial_width, initial_height, componenets;
  unsigned char *data =
      stbi_load("arch.png", &initial_width, &initial_height, &componenets, 0);
  int scaled_width = initial_width / 10;
  int scaled_height = initial_height / 10;
  unsigned char *scaled_data =
      malloc(scaled_width * scaled_height * componenets);
  unsigned char *final_data = malloc(scaled_width * scaled_height);
  int err =
      stbir_resize_uint8(data, initial_width, initial_height, 0, scaled_data,
                         scaled_width, scaled_height, 0, componenets);
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
  printf("width: %d height: %d componenets %d\n", scaled_width, scaled_height,
         componenets);
  int j = 0;
  char *output = malloc(initial_width * initial_height);
  for (int i = componenets; i < scaled_width * scaled_height * 3;
       i += componenets) {
    final_data[j] =
        (scaled_data[i - 3] + scaled_data[i - 2] + scaled_data[i]) / 3;
    int idx = (final_data[j] >> 2);
    printf("%d ", idx);
    output[j] = stuff[idx];
    if (idx < 25) {
      output[j] = ' ';
    } else {
      output[j] = stuff[idx];
    }
    j++;
  }
  printf("\n");
  for (int i = 0; i < scaled_width * scaled_height; i++) {
    printf("%c", output[i]);
    printf("%c", output[i]);
    if (i % scaled_width == 0) {
      printf("\n");
    }
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
