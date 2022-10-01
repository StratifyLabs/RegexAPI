# These are the depedencies
set(LIBRARIES PrinterAPI VarAPI)


api2_add_library(
  NAME RegexAPI
  DEPENDENCIES PrinterAPI VarAPI
)


