#pragma once
#include <string>
#include <iostream>

enum joystickButtonInputs
{
A,
B,
X,
Y,
LB,
RB,
SELECT,
START,
CENTER,
L_STICK_BUTTON,
R_STICK_BUTTON,
N_button_inputs
};

inline joystickButtonInputs strToButtons(const std::string & input)
{
    if(input == "A")
    {
        return joystickButtonInputs::A;
    }
    if(input == "B")
    {
        return joystickButtonInputs::B;
    }
    if(input == "X")
    {
        return joystickButtonInputs::X;
    }
    if(input == "Y")
    {
        return joystickButtonInputs::Y;
    }
    if(input == "LB")
    {
        return joystickButtonInputs::LB;
    }
    if(input == "RB")
    {
        return joystickButtonInputs::RB;
    }
    if(input == "SELECT")
    {
        return joystickButtonInputs::SELECT;
    }
    if(input == "START")
    {
        return joystickButtonInputs::START;
    }
    if(input == "CENTER")
    {
        return joystickButtonInputs::CENTER;
    }
    if(input == "L_STICK_BUTTON")
    {
        return joystickButtonInputs::L_STICK_BUTTON;
    }
    if(input == "R_STICK_BUTTON")
    {
        return joystickButtonInputs::R_STICK_BUTTON;
    }
    std::cout << "[joystick str2buttons] unrecognized string inputs" << std::endl;
    return joystickButtonInputs::A;
}

inline std::string buttons2str(const joystickButtonInputs & input)
{
    switch (input)
    {
    case joystickButtonInputs::A:
        return "A";
        break;
    case joystickButtonInputs::B:
        return "B";
    case joystickButtonInputs::Y:
        return "Y";
    case joystickButtonInputs::X:
        return "X";
    case joystickButtonInputs::LB:
        return "LB";
    case joystickButtonInputs::RB:
        return "RB";
    case joystickButtonInputs::START:
        return "START";
    case joystickButtonInputs::SELECT:
        return "SELECT";
    case joystickButtonInputs::L_STICK_BUTTON:
        return "L_STICK_BUTTON";
    case joystickButtonInputs::R_STICK_BUTTON:
        return "R_STICK_BUTTON";
    case joystickButtonInputs::CENTER:
        return "CENTER";
    default:
        std::cout << "[joystick str2buttons] unrecognized button inputs" << std::endl;
        break;
    }

    return "";
}

enum joystickAnalogicInputs
{
L_STICK,
R_STICK,
LT,
RT,
UP_PAD,
LEFT_PAD,
RIGHT_PAD,
DOWN_PAD,
N_analogic_inputs
};


