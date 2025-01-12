#pragma once
#include <string>
#include <thread>
#include <chrono>
#include <iostream>
namespace nv
{
	class intr
	{
	public:
		static void loadBar(const std::string& msg, int length, int time, char ch = '#', char wrapl = '[', char wrapr = ']') {

			std::cout << msg << wrapl;
			for (int i = 0; i < length; ++i)
			{
				std::cout << " ";
			}
			std::cout << wrapr << "\r";
			std::cout.flush();
			std::cout << msg << wrapl;
			for (int i = 0; i < length; ++i)
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(time / length));
				std::cout << ch;
				std::cout.flush();
			}
			std::cout << wrapr;
		}
	};
}