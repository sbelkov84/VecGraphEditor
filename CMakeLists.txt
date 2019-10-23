cmake_minimum_required(VERSION 3.2)

if (DEFINED ENV{TRAVIS_BUILD_NUMBER})
    project(VecGraphEditor VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})
else()
    project(VecGraphEditor VERSION 0.0.1)
endif()

configure_file(version.h.in version.h)

add_executable(VecGraphEditor main.cpp mainform.h screen.h)
add_library(document_lib document.h document.cpp)
add_library(primitives_lib primitive_interface.h primitive_interface.cpp 
		           primitives_impl.h primitives_impl.cpp
			   primitives_storage.h primitives_storage.cpp)

set_target_properties(VecGraphEditor document_lib primitives_lib 
    PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
    LINKER_LANGUAGE CXX
)

target_link_libraries(VecGraphEditor PRIVATE
    document_lib primitives_lib
)

if (MSVC)
    target_compile_options(VecGraphEditor PRIVATE
        /W4
    )
    target_compile_options(document_lib PRIVATE
        /W4
    )
    target_compile_options(primitives_lib PRIVATE
        /W4
    )
else ()
    target_compile_options(VecGraphEditor PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(document_lib PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(primitives_lib PRIVATE
        -Wall -Wextra -pedantic -Werror
    )	
endif()


install(TARGETS VecGraphEditor RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)