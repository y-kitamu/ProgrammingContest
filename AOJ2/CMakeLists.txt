set(module_name aoj2)

# フォルダ内のcppをexecutableに追加する
FILE(GLOB cpp_files "*.cpp")
FOREACH(cpp IN LISTS cpp_files)
  get_filename_component(bname ${cpp} NAME_WE)
  add_executable(${module_name}_${bname} ${cpp})
ENDFOREACH()
