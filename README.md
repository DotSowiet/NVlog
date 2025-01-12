# NVlog/NV Library

NVlog is a logging and utility library designed for C++ applications. It provides a set of features for formatting logs with different styles, colors, and interactive utilities, such as loading bars. It is simple to integrate into your projects and can significantly enhance the readability and interactivity of your application's output.

## Features
- **Customizable Log Output**: Flexible log patterns with date, time, thread ID, function names, and more.
- **Text Styling**: Apply various text styles (bold, italic, strikethrough, etc.) and colors to the output.
- **Log Levels**: Supports different log levels (e.g., debug, error) with easy-to-use functions.
- **Interactive Utilities**: Includes utilities like loading bars for better user interaction during long processes.

## Installation

To use the NVlog/NV library in your project, simply follow these steps:

### 1. Clone the repository:
```bash
git clone https://github.com/DotSowiet/NVlog.git
```

### 2. Include necessary headers:
```cpp
#include "NVlog/classic.h"  // For logging functionality
#include "NVlog/color.h"    // For text styling and color functions
#include "NVlog/intr.h"     // For interactive utilities (e.g., loading bars)
```

### 3. link the library:

Make sure to link the compiled library to your project if you are not directly including the header files.


## Usage

Once the library is set up, you can start using its features to enhance your application's logging and interactivity.

### Initialize Logging

You can initialize logging with a custom pattern for better log readability:

```cpp
std::string logPattern = "$Date $Time [$Level] $ThreadID $Function - $StartColor $Message $EndColor $File:$Line";
nv::log::LogInit(logPattern);
```

### Log Messages

Log messages with different log levels:

```cpp
nv::log::Debug("This is a debug message");
nv::log::Error("An error occurred", 100);
```

### Customize Output Styles

You can apply styles to your output text, such as bold, italic, or color:

```cpp
nv::style::Paint(Yellow, "Hello, World!");
nv::style::Bold("This is bold text");
nv::style::Italic("This is italic text");
nv::style::Strikethrough("This text is struck through");
nv::style::Background(BrightBgGreen, "This text has a background color");
```

### Center Text

```cpp
nv::log::CenterText("This text is centered on the screen");
```

### Interactive Utilities

```cpp
nv::intr::loadBar("Loading... ", 40, 40000, '|', '<', '>');
```

### Example Code

Here's a full example demonstrating the library's capabilities:

```cpp
#include "classic.h"
#include <iostream>
#include "color.h"
#include "intr.h"

int main() {
    // Initialize logging
    std::string logPattern = "$Date $Time [$Level] $ThreadID $Function - $StartColor $Message $EndColor $File:$Line";
    nv::log::LogInit(logPattern);
    std::cout << nv::log::ConsoleWidth() << std::endl;

    // Log messages
    nv::log::Debug("Debug message");
    nv::log::Error("Error message", 100);

    // Apply styles
    nv::style::Paint(Yellow, "Styled Text");
    nv::style::Bold("Bold Text");
    nv::style::Italic("Italic Text");

    // Center text
    nv::log::CenterText("Centered Text");

    // Show loading bar
    nv::intr::loadBar("Loading... ", 40, 40000, '|', '<', '>');

    return 0;
}

```

### Contributing

If you'd like to contribute to NVlog, feel free to fork the 
repository and create a pull request. You can also report issues
or request features by creating an issue on the GitHub repository.

### License

This project is licensed under the MIT License - see the LICENSE file for details.

---

For any further questions or issues, feel free to open an issue on the repository. Happy coding!