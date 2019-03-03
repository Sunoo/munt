# - Try to find wiringPi
# Once done this will define
#  WIRINGPI_FOUND - System has wiringPi
#  WIRINGPI_INCLUDE_DIRS - The location of the wiringPi include directory
#  WIRINGPI_LIBRARIES - The location of the wiringPi library

find_path(WIRINGPI_INCLUDE_DIR wiringPi.h)

find_library(WIRINGPI_LIBRARY wiringPi)

include(FindPackageHandleStandardArgs)
# Handle the QUIETLY and REQUIRED arguments and set WIRINGPI_FOUND to TRUE if
# all listed variables are TRUE
find_package_handle_standard_args(WIRINGPI DEFAULT_MSG WIRINGPI_LIBRARY WIRINGPI_INCLUDE_DIR)

set(WIRINGPI_LIBRARIES ${WIRINGPI_LIBRARY} ${WIRINGPI_EXT_LIBS})
set(WIRINGPI_INCLUDE_DIRS ${WIRINGPI_INCLUDE_DIR})

mark_as_advanced(WIRINGPI_EXT_LIBS WIRINGPI_LIBRARY WIRINGPI_INCLUDE_DIR)
