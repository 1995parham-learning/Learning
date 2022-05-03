project('wayland-hello', 'c',
  version : '0.1',
  default_options : ['warning_level=3'])

wayland = dependency('wayland-client')

executable('wayland-hello',
           'main.c',
           dependencies : [wayland])
