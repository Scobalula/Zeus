#pragma once
#include "pch.h"
#include <Windows.h>

namespace PLX
{
    namespace Printer
    {
        // Console Colors, used with Set/GetFore/BackgroundColor
        enum class Color
        {
            Black       = 0,
            DarkBlue    = 1,
            DarkGreen   = 2,
            DarkCyan    = 3,
            DarkRed     = 4,
            DarkMagenta = 5,
            DarkYellow  = 6,
            Gray        = 7,
            DarkGray    = 8,
            Blue        = 9,
            Green       = 10,
            Cyan        = 11,
            Red         = 12,
            Magenta     = 13,
            Yellow      = 14,
            White       = 15
        };
        // Private Internal Properties
        namespace
        {
            constexpr uint16_t ForegroundMask = 0xF;
            constexpr uint16_t BackgroundMask = 0xF0;
            constexpr uint16_t ColorMask = 0xFF;
        }
        // Gets the Foreground Color
        Color GetForegroundColor();
        // Gets the Background Color
        Color GetBackgroundColor();
        // Sets the Foreground Color
        void SetForegroundColor(Color color);
        // Sets the Background Color
        void SetBackgroundColor(Color color);
        // Resets the Foreground Color to White
        void ResetForegroundColor();
        // Resets the Background Color to Black
        void ResetBackgroundColor();
        // Resets the Foreground and Background Colors to White/Black respectively
        void ResetColor();
        // Outputs the message to the Console
        template<typename ... Args>
        void Write(const std::string value, Args ... args)
        {
            size_t size = snprintf(nullptr, 0, value.c_str(), args ...) + 1;
            std::unique_ptr<char[]> buf(new char[size]);
            snprintf(buf.get(), size, value.c_str(), args ...);
            std::cout << value;
            std::cout.flush();
        }
        // Outputs the message to the Console
        template<typename ... Args>
        void WriteLine(const std::string value, Args ... args)
        {
            size_t size = snprintf(nullptr, 0, value.c_str(), args ...) + 1;
            std::unique_ptr<char[]> buf(new char[size]);
            snprintf(buf.get(), size, value.c_str(), args ...);
            std::cout << value << "\n";
            std::cout.flush();
        }
        // Outputs the message to the Console
        template<typename ... Args>
        void WriteHeader(const std::string header, std::string value, Args ... args)
        {
            SetBackgroundColor(Color::DarkBlue);
            SetForegroundColor(Color::White);
            std::cout << "[";
            std::cout << header << std::setw(12 - header.size());
            std::cout << "]";
            ResetBackgroundColor();
            ResetForegroundColor();
            size_t size = std::snprintf(nullptr, 0, value.c_str(), args ...) + 1;
            std::unique_ptr<char[]> buf(new char[size]);
            std::snprintf(buf.get(), size, value.c_str(), args ...);
            std::cout << ": " << buf.get();
            std::cout.flush();
        }
        // Outputs the message to the Console
        template<typename ... Args>
        void WriteLineHeader(const std::string header, std::string value, Args ... args)
        {
            SetBackgroundColor(Color::DarkBlue);
            SetForegroundColor(Color::White);
            std::cout << "[";
            std::cout << header << std::setw(12 - header.size());
            std::cout << "]";
            ResetBackgroundColor();
            ResetForegroundColor();
            size_t size = std::snprintf(nullptr, 0, value.c_str(), args ...) + 1;
            std::unique_ptr<char[]> buf(new char[size]);
            std::snprintf(buf.get(), size, value.c_str(), args ...);
            std::cout << ": " << buf.get() << "\n";
            std::cout.flush();
        }
        // Outputs the message to the Console
        template<typename ... Args>
        void WriteLineHeader(const std::string header, Color bgColor, Color fgColor, std::string value, Args ... args)
        {
            SetBackgroundColor(Color::DarkBlue);
            SetForegroundColor(Color::White);
            std::cout << "[";
            std::cout << header << std::setw(12 - header.size());
            std::cout << "]";
            ResetBackgroundColor();
            ResetForegroundColor();
            std::cout << ": ";
            SetBackgroundColor(bgColor);
            SetForegroundColor(fgColor);
            size_t size = std::snprintf(nullptr, 0, value.c_str(), args ...) + 1;
            std::unique_ptr<char[]> buf(new char[size]);
            std::snprintf(buf.get(), size, value.c_str(), args ...);
            std::cout << buf.get() << "\n";
            ResetBackgroundColor();
            ResetForegroundColor();
            std::cout.flush();
        }
    }
}