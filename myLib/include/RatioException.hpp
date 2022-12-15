#pragma once

#include <exception>
#include <string>

enum class ErrorType {minor, major, fatal};

std::string ErrorType2Sstring(const ErrorType &errorType);


class RatioException : public std::exception
{
	public:

		RatioException(const std::string &description, const int &errorId, const ErrorType &errorType) noexcept;	

		virtual ~RatioException() noexcept {}

	public:
		const char *what() const noexcept override 
		{
			return m_what.c_str();
		}

	private:
		std::string m_what;
};