#ifndef ASCII_UTILS_H
#define ASCII_UTILS_H

unsigned char max(unsigned char r, unsigned char g, unsigned char b) {
  if (r > g && r > b) {
    return r;
  } else if (g > r && g > b) {
    return g;
  }
  return b;
}

unsigned char min(unsigned char r, unsigned char g, unsigned char b) {
  if (r < g && r < b) {
    return r;
  } else if (g < r && g < b) {
    return g;
  }
  return b;
}
#endif
