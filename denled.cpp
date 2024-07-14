#include <Windows.h>
#include <iostream>

class Screen {
 HANDLE _handle;
public:
 Screen() { _handle = GetStdHandle(STD_OUTPUT_HANDLE); }

 Screen& SetCursor(int x, int y) {
  COORD coord = { x, y };
  SetConsoleCursorPosition(_handle, coord);
 
  return *this;
 }
 Screen& SetColor(int text, int background = 0) {
  SetConsoleTextAttribute(_handle, (background << 4) | text);
  return *this;
 }

 Screen& Wait(int ms) {
  Sleep(ms);
  return *this;
 }

 Screen& ShowCursor(int show) {
  CONSOLE_CURSOR_INFO info;
  info.dwSize = 100;
  info.bVisible = show;

  SetConsoleCursorInfo(_handle, &info);
  return *this;
 }
};
class LED {
 int _lev;

public:
 int X, Y;
 int Color;

public:
 LED(int color = 10) {
  X = Y = 0;
  _lev = 0;
 }

public:
 void SetValue(int v) {
  if (_lev == v) return;

  _lev = v ? 1 : 0;
  Screen().SetColor(_lev ? Color : 8).SetCursor(X, Y);
  std::cout << (char)254;
 }
 void Switch() { SetValue(_lev ^ 1); }
 void On() { SetValue(1); }
 void Off() { SetValue(0); }
};
int main() {
 const int n = 16;
 LED leds[n];

 Screen().ShowCursor(false);
 for (int i = 0; i < n; i++) {
  
  leds[i].X = i << 1;
  leds[i].Y = i;
  leds[i].Color = i;
  leds[i].On();
 }

 while (true) {
  for (int i = 0; i < n; i++) {
   leds[i].Switch();
  }
  Screen().Wait(500);
 }

}
