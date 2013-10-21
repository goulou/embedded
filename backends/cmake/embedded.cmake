if (NOT CMAKE_BUILD_TYPE)
	set (CMAKE_BUILD_TYPE Release)
endif()

set (SUPPORTED_MCU_ROOT_DIR ${CMAKE_CURRENT_LIST_DIR}/../stm32)

#define HAL path
set (BASE_HAL_DIR			"${CMAKE_CURRENT_LIST_DIR}/../../hal/")

function (show_available_arch)

	file(GLOB SUB_DIRECTORIES ${SUPPORTED_MCU_ROOT_DIR}/*)

	foreach (DIRECTORY ${SUB_DIRECTORIES})

		if (IS_DIRECTORY ${DIRECTORY})

			get_filename_component(SUB_DIR_NAME ${DIRECTORY} NAME)

			if (IS_DIRECTORY ${DIRECTORY}/cmake)
				
				if (EXISTS ${DIRECTORY}/cmake/${SUB_DIR_NAME}.cmake)
					list (APPEND SUPPORTED_ARCHITECTURE ${SUB_DIR_NAME})
				endif()

			endif()

		endif()
	endforeach()


	list (LENGTH SUPPORTED_ARCHITECTURE ARCHITECTURE_COUNT)

	if (${ARCHITECTURE_COUNT} EQUAL 0)
		message (FATAL_ERROR "There is no available architecture")
	endif()

	message ("Found ${ARCHITECTURE_COUNT} architecture(s) :")
	foreach (ARCH ${SUPPORTED_ARCHITECTURE})
		message ("\t- ${ARCH}")
	endforeach()

endfunction()

if (NOT arch)
	show_available_arch()
	message (FATAL_ERROR "Please run cmake again with option -Darch=<architecture>")
else()
	if (EXISTS ${SUPPORTED_MCU_ROOT_DIR}/${arch}/cmake/${arch}.cmake)
		include (${SUPPORTED_MCU_ROOT_DIR}/${arch}/cmake/${arch}.cmake)
	else()
		show_available_arch()
		message ("${arch} is not a valid architecure")
	endif()
endif()
