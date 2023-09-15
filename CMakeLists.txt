# CMakeList.txt: проект CMake для Class_template_packet; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#

# Добавьте источник в исполняемый файл этого проекта.
add_executable (Class_template_packet "Class_template_packet.cpp" "Class_template_packet.h"  )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Class_template_packet PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
