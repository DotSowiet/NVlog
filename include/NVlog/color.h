#include <iostream>

#if defined(_WIN32) || defined(_WIN64)
#include <Windows.h>
#else
#include<cstdlib>
#endif
#include "spdlog/spdlog.h"
#define Reset "\033[0m"
#define S_Bold "\033[1m"
#define S_Italic "\033[3m"
#define S_Underline "\033[4m"
#define S_Strikethrough "\033[9m"
#define S_Inverse "\033[7m"
#define S_Hidden "\033[8m"
#define FontDefault "\033[10m"
#define Font2 "\033[11m"
#define Font3 "\033[12m"
#define Font4 "\033[13m"
#define Font5 "\033[14m"

#define Black "\033[30m"
#define Red "\033[31m"
#define Green "\033[32m"
#define Yellow "\033[33m"
#define Blue "\033[34m"
#define Magenta "\033[35m"
#define Cyan "\033[36m"
#define White "\033[37m"

#define BrightBlack "\033[90m"
#define BrightRed "\033[91m"
#define BrightGreen "\033[92m"
#define BrightYellow "\033[93m"
#define BrightBlue "\033[94m"
#define BrightMagenta "\033[95m"
#define BrightCyan "\033[96m"
#define BrightWhite "\033[97m"

#define BgBlack "\033[40m"
#define BgRed "\033[41m"
#define BgGreen "\033[42m"
#define BgYellow "\033[43m"
#define BgBlue "\033[44m"
#define BgMagenta "\033[45m"
#define BgCyan "\033[46m"
#define BgWhite "\033[47m"

#define BrightBgBlack "\033[100m"
#define BrightBgRed "\033[101m"
#define BrightBgGreen "\033[102m"
#define BrightBgYellow "\033[103m"
#define BrightBgBlue "\033[104m"
#define BrightBgMagenta "\033[105m"
#define BrightBgCyan "\033[106m"
#define BrightBgWhite "\033[107m"

namespace nv
{
	class style
	{
	public:


        static void Paint(const std::string& color, const std::string& text) {
            std::cout << color << text << Reset;
        }

        static void Background(const std::string& color, const std::string& text) {
            std::cout << color << text << Reset;
        }

        static void Bold(const std::string& text) {
            std::cout << S_Bold << text << Reset;
        }

        static void Italic(const std::string& text) {
            std::cout << S_Italic << text << Reset;
        }

        static void Underline(const std::string& text) {
            std::cout << S_Underline << text << Reset;
        }

        static void Strikethrough(const std::string& text) {
            std::cout << S_Strikethrough << text << Reset;
        }

        static void Inverse(const std::string& text) {
            std::cout << S_Inverse << text << Reset;
        }

        static void Hidden(const std::string& text) {
            std::cout << S_Hidden << text << Reset;
        }

        // Funkcje do ustawiania stylów bez koñczenia
        static void Paint_start(const std::string& color) {
            std::cout << color;
        }

        static void Background_start(const std::string& color) {
            std::cout << color;
        }

        static void Bold_start() {
            std::cout << S_Bold;
        }

        static void Italic_start() {
            std::cout << S_Italic;
        }

        static void Underline_start() {
            std::cout << S_Underline;
        }

        static void Strikethrough_start() {
            std::cout << S_Strikethrough;
        }

        static void Inverse_start() {
            std::cout << S_Inverse;
        }

        static void Hidden_start() {
            std::cout << S_Hidden;
        }

        static void EndAll() {
            std::cout << Reset;
        }

        // Dodatkowe style czcionki
        static void Font2_start() {
            std::cout << Font2;
        }

        static void Font3_start() {
            std::cout << Font3;
        }

        static void Font4_start() {
            std::cout << Font4;
        }

        static void Font5_start() {
            std::cout << Font5;
        }
	};
}