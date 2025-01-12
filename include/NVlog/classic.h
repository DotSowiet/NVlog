#include <iostream>

#if defined(_WIN32) || defined(_WIN64)
#include <Windows.h>
#else
#include<cstdlib>
#endif
#include "spdlog/spdlog.h"

#include <regex>

#include "spdlog/sinks/stdout_color_sinks.h"


#include <iomanip>

namespace nv
{
	class log
	{
	public:

		static void LogInit(const std::string& command)
		{
			std::string text = command;
			const std::pair<std::string, std::string> repleacements[] = {
				{"\\$Clock\\(24\\)", "%H:%M:%S"},   // $Clock(24) -> %H:%M:%S
				{"\\$Level", "%l"},                 // $Level -> %l
				{"\\$ColorStart", "%^"},            // $ColorStart -> %^
				{"\\$ColorEnd", "%$"},              // $ColorEnd -> %$
				{"\\$StartColor", "%^"},            // $StartColor -> %^
				{"\\$EndColor", "%$"},              // $EndColor -> %$
				{"\\$Message", "%v"},               // $Message -> %v
				{"\\$Date", "%Y-%m-%d"},            // $Date -> %Y-%m-%d
				{"\\$Time", "%T"},                  // $Time -> %T
				{"\\$ThreadID", "%t"},              // $ThreadID -> %t
				{"\\$File", "%F"},                  // $File -> %F
				{"\\$Line", "%l"},                  // $Line -> %l
				{"\\$Function", "%!%"},             // $Function -> %!%
				{"\\$PID", "%P"},                   // $PID -> %P (Process ID)
				{"\\$Hostname", "%h"},              // $Hostname -> %h (Hostname)
				{"\\$AppName", "%n"},               // $AppName -> %n (Application Name)
				{"\\$LevelName", "%L"},             // $LevelName -> %L (Full Level Name)
				{"\\$UTCDate", "%+T"},              // $UTCDate -> %+T (Date and time in UTC)
				{"\\$DateTime", "%Y-%m-%d %H:%M:%S"}, // $DateTime -> %Y-%m-%d %H:%M:%S (Custom Date-Time)
				{"\\$ElapsedTime", "%E"},           // $ElapsedTime -> %E (Elapsed time since program start)
				{"\\$ShortFile", "%s"},             // $ShortFile -> %s (Short file name, no path)
				{"\\$ShortLine", "%S"},             // $ShortLine -> %S (Line number in file)
				{"\\$ThreadName", "%n"},            // $ThreadName -> %n (Thread name or ID)
				{"\\$Logger", "%L"}                 // $Logger -> %L (Logger name)
			};

			for (const auto& [pattern, replacement] : repleacements)
			{
				text = std::regex_replace(text, std::regex(pattern), replacement);
			}

			spdlog::set_pattern(text);
		}
		static int ConsoleWidth()
		{
#if defined(_WIN32) || defined(_WIN64)
			CONSOLE_SCREEN_BUFFER_INFO csbi;
			GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
			return csbi.srWindow.Right - csbi.srWindow.Left + 1;
#else
			const char* cmd = "tput cols";
			FILE* fp = popen(cmd, "r");
			int width = 0;
			if (fp) {
				fscanf(fp, "%d", &width);
				fclose(fp);
			}
			return width;
#endif
		}
		template<typename... Args>
		static void Info(fmt::v11::format_string<Args...> format, Args&&... args) {
			spdlog::info(format, std::forward<Args>(args)...);
		}

		template<typename... Args>
		static void Warn(fmt::v11::format_string<Args...> format, Args&&... args) {
			spdlog::warn(format, std::forward<Args>(args)...);
		}

		template<typename... Args>
		static void Error(fmt::v11::format_string<Args...>  format, Args&&... args) {
			spdlog::error(format, std::forward<Args>(args)...);
			
		}
		template<typename... Args>
		static void Debug(fmt::v11::format_string<Args...> format, Args&&... args) {
			spdlog::debug(format, std::forward<Args>(args)...);
		}
		template<typename... Args>
		static void Critical(fmt::v11::format_string<Args...>  format, Args&&... args) {
			spdlog::critical(format, std::forward<Args>(args)...);
		}

		template<typename... Args>
		static void Trace(fmt::v11::format_string<Args...>  format, Args&&... args) {
			spdlog::trace(format, std::forward<Args>(args)...);
		}

		template<typename... Args>
		static void Off(fmt::v11::format_string<Args...>  format, Args&&... args) {
			spdlog::log(spdlog::level::off, format, std::forward<Args>(args)...);
		}

		static void CenterText(const std::string& text)
		{
			int consoleWidth = ConsoleWidth();
			int textLength = text.length();
			int padding = (consoleWidth - textLength) / 2;

			if (padding > 0) {
				std::cout << std::string(padding, ' ');
			}
			std::cout << text;
		}
		static void FillLine(char character)
		{
			int c_W = ConsoleWidth();

			for (int i = 0; i != c_W; i++) {
				std::cout << character;
			}
		}

		// wraps
		static void endl() {
			std::cout << "\n";
		}

		static void ToTheLeft(const std::string& text)
		{
			std::cout << std::left << text;
		}
		static void ToTheRight(const std::string& text)
		{
			std::cout << std::right << text;
		}
		static void SetWidth(const std::string& text, int n)
		{
			std::cout << std::setw(n) << text;
		}





	};
}