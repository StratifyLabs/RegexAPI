
if(NOT DEFINED API_IS_SDK)
	include(API)
	cmsdk_include_target(LibraryAPI "${API_CONFIG_LIST}")
endif()
