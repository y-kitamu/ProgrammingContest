file(GLOB file_list *.cpp)

foreach(fname IN LISTS file_list)
  message("fname : ${fname}")
  get_filename_component(basename ${fname} NAME_WE)
  add_executable(${module_name}_${basename} ${fname})
endforeach()
