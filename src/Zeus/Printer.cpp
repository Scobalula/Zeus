#include "pch.h"
#include "Printer.h"

// Gets the Foreground Color
PLX::Printer::Color PLX::Printer::GetForegroundColor()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO lpBufferInfo;
    if (GetConsoleScreenBufferInfo(hConsole, &lpBufferInfo))
        return (Color)(lpBufferInfo.wAttributes & ForegroundMask);
    return Color::Black;
}

PLX::Printer::Color PLX::Printer::GetBackgroundColor()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO lpBufferInfo;
    if (GetConsoleScreenBufferInfo(hConsole, &lpBufferInfo))
        return (Color)((lpBufferInfo.wAttributes & BackgroundMask) >> 4);
    return Color::Black;
}

void PLX::Printer::SetForegroundColor(Color color)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    auto bgColor = (int)GetBackgroundColor();
    SetConsoleTextAttribute(hConsole, ((int)color & ForegroundMask) | (bgColor << 4));
}

void PLX::Printer::SetBackgroundColor(Color color)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    auto foreColor = (int)GetForegroundColor();
    SetConsoleTextAttribute(hConsole, (((int)color << 4) & BackgroundMask) | foreColor);
}

void PLX::Printer::ResetForegroundColor()
{
    SetForegroundColor(Color::White);
}

void PLX::Printer::ResetBackgroundColor()
{
    SetBackgroundColor(Color::Black);
}

void PLX::Printer::ResetColor()
{
    SetBackgroundColor(Color::White);
    SetBackgroundColor(Color::Black);
}