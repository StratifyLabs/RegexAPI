
if(NOT DEFINED API_IS_SDK)
	include(API)
	cmsdk_include_target(RegexAPI "${API_CONFIG_LIST}")
endif()
