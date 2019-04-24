project('Oxygen', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3', 'cpp_std=c++2a'])

subproject('nlohmann_json')
subproject('fmt')

# These arguments are only used to build the shared library
# not the executables that use the library.
lib_args = ['-DBUILDING_OXYGEN']

shlib = shared_library('oxygen',
  install : true,
  cpp_args : lib_args,
  gnu_symbol_visibility : 'hidden',
)

test_exe = executable('oxygen', 'oxygen_test.cpp',
  link_with : shlib)
test('oxygen', test_exe)

# Make this library usable as a Meson subproject.
oxygen_dep = declare_dependency(
  include_directories: include_directories('.', '/boost/boost_1_70_0/boost', '/SFML-2.5.1/include'),
  link_with : shlib)

# Make this library usable from the system's
# package manager.
install_headers('oxygen.hpp', subdir : 'oxygen')

pkg_mod = import('pkgconfig')
pkg_mod.generate(
  name : 'Oxygen',
  filebase : 'oxygen',
  description : 'Meson sample project.',
  subdirs : 'oxygen',
  libraries : shlib,
  version : '0.1',
)
