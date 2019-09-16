set(module_name ${module_name}_aoj)
file(GLOB file_list "[a-zA-Z]*.cpp")

# message("${file_list}")

foreach(fname IN LISTS file_list)
  get_filename_component(bname ${fname} NAME_WE)
  add_executable(${module_name}_${bname} ${fname})
  target_link_libraries(${module_name}_${bname} debug glog)
endforeach()
