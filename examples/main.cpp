#include "NVlog/classic.h"   // Includes classic logging utilities
#include <iostream>     // Standard input-output stream
#include "NVlog/color.h"      // Includes color formatting utilities
#include "NVlog/intr.h"       // Includes interactive utilities like loading bars

int main()
{
    // Initialize logging with a custom log pattern
    // Pattern explanation: Shows date, time, log level, thread ID, function, color, message, and file info
    std::string logPattern = "$Date $Time [$Level] $ThreadID $Function - $StartColor $Message $EndColor $File:$Line";
    nv::log::LogInit(logPattern);

    // Print the console width (useful for formatting)
    std::cout << nv::log::ConsoleWidth() << std::endl;

    // Log a debug message
    nv::log::Debug("Error!");

    // Use the "Paint" function to display a colored text message
    nv::style::Paint(Yellow, "Hi there!");
    nv::log::Error("AfterTest");

    // Display centered text in the console
    nv::log::CenterText("Centered text");

    // Fill the current line with asterisks
    nv::log::FillLine('*');
    nv::log::endl();  // Output a new line

    // Apply bold styling to the text
    nv::style::Bold("Testing! :)");

    // Combine multiple styles: Bold and BrightMagenta color
    nv::style::Bold_start();
    nv::style::Paint(BrightMagenta, "Message :)");
    nv::style::EndAll();  // Reset all styles

    nv::log::endl();  // Line break

    // Apply italic and strikethrough styles
    nv::style::Italic("Testing italic style");
    nv::style::Strikethrough("Wow, that's cool!");

    // Apply a background color to the text
    nv::style::Background(BrightBgGreen, "Background color applied!");
    nv::log::endl();  // Line break

    // Log an error with a custom message and an error code
    nv::log::Error("WORD!|", 100);

    // Demonstrate a loading bar with custom characters and time intervals
    nv::intr::loadBar("Loading... ", 40, 40000, '#', '[', ']');

    return 0; // Program ends
}
