file(GLOB file_list *.cpp)

set(module_name ${module_name}_abc120)

foreach(fname IN LISTS file_list)
  get_filename_component(base_name ${fname} NAME_WE)
  add_executable(${module_name}_${base_name} ${fname})
endforeach()
