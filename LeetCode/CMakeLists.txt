set(module_name leetcode)

SUBDIRLIST(subdir_list ${CMAKE_CURRENT_SOURCE_DIR})

foreach(dirname IN LISTS subdir_list)
  if (EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${dirname}/CMakeLists.txt)
    # set(mod_name "${module_name}_${dirname}")
    add_subdirectory(${dirname})
  endif()
endforeach()

ADD_CONTESTS()
