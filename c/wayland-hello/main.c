#include <stdio.h>
#include <wayland-client-core.h>
#include <wayland-client-protocol.h>
#include <wayland-client.h>

int main(int argc, char *argv[]) {
  struct wl_display *display = wl_display_connect(NULL);
  if (!display) {
    fprintf(stderr, "failed to connect to wayland display\n");
    return 1;
  }

  fprintf(stderr, "Connection established\n");

  int32_t v = wl_display_get_version(display);
  fprintf(stderr, "version: %d\n", v);

  return 0;
}
