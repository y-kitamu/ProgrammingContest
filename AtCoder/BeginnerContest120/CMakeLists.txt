file(GLOB file_list *.cpp)

foreach(fname IN LISTS file_list)
  add_executable(${module_name}_${base_name} ${fname})
  get_filename_component(base_name ${fname} NAME_WE)
endforeach()
