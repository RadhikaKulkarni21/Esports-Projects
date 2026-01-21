#pragma once
using namespace std;
#include <string>

//required wstring as korean input is not being read out by the console
struct term{
    wstring korean;//한국어 call out
    wstring english;//english call out
    wstring category;//game/theme/event specific
    wstring defination;//when/why to use
    wstring notes;//how to pronounce
};
