file(GLOB file_list "[a-z]*.cpp")

foreach (fname IN LISTS file_list)
  add_executable(basename ${fname} NAME_WE)
endforeach()
