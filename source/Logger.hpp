#pragma once

#include <iostream>
#include <string>

namespace cn
{
	class Logger final
	{
	public:
		const static char PREFIX_ERROR = 'E';
		const static char PREFIX_WARNING = 'W';
		const static char PREFIX_INFO = 'I';

		// Logger class is static
		Logger() = delete;

		// Logs given message to console 
		// You can use your own prefix or predefined const (Logger::PREFIX_name)
		static void log(const std::string& message, char prefix) { std::cout << "[" << prefix << "]: " << message << "\n"; }
	};
}