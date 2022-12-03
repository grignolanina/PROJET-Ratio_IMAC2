#include <string>

#include "RatioException.hpp"

// convert enum to string
std::string ErrorType2Sstring(const ErrorType &errorType){
	std::string errorTypeString;
	switch(errorType){
		case ErrorType::minor :
			errorTypeString = "minor";
			break;
		case ErrorType::major :
			errorTypeString = "major";
			break;
		case ErrorType::fatal :
			errorTypeString = "fatal";
			break;
		default : 
			errorTypeString = "unknown";
	};

	return errorTypeString;
}


RatioException::RatioException(const std::string &description, const int &errorId, const ErrorType &errorType) noexcept	
{
	m_what	= std::string("\nException launched:")
	        + "\n   Type   : " + ErrorType2Sstring(errorType)
	        + "\n   Code    : " + std::to_string(errorId)
	        + "\n   Message : " + description;
}