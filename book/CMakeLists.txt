set(module_name book)

SUBDIRLIST(subdir_list ${CMAKE_CURRENT_SOURCE_DIR})

foreach(dirname IN LISTS subdir_list)
  if (EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${dirname}/CMakeLists.txt)
    add_subdirectory(${dirname})
  endif()
endforeach()
