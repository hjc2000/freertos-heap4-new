# freertos-heap4-new
利用 freertos 的 heap4 重载 new, delete 运算符。target_import_freertos_heap4_new 中使用了链接器选项 `--whole-archive` . 

```cmake
include(target_import_bsp_interface)
include(target_import_freertos)

function(target_import_freertos_heap4_new target_name visibility)
	set(lib_name "freertos-heap4-new")
	target_include_directories(${target_name} ${visibility} ${libs_path}/${lib_name}/include)

	target_link_libraries(${ProjectName} PUBLIC -Wl,--whole-archive)
    target_auto_link_lib(${target_name} ${lib_name} ${libs_path}/${lib_name}/lib/)
	target_link_libraries(${ProjectName} PUBLIC -Wl,--no-whole-archive)

	target_import_bsp_interface(${target_name} ${visibility})
	target_import_freertos(${target_name} ${visibility})
endfunction()

```

