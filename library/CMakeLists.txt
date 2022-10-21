api2_add_library(
  NAME RegexAPI
  DEPENDENCIES PrinterAPI VarAPI
  TARGETS TARGET_LIST)

foreach(TARGET ${TARGET_LIST})
  target_link_libraries(${TARGET} PUBLIC ctre)
endforeach()

