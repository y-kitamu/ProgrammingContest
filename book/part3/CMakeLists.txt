file(GLOB file_list "[a-z]*.cpp")

foreach (fname IN LISTS file_list)
  get_filename_component(basename ${fname} NAME_WE)
  add_executable(${module_name}_${basename} ${fname})
endforeach()
