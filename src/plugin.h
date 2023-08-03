/*
 * Copyright 2021 CNRS-UM LIRMM, CNRS-AIST JRL
 */

#pragma once

#include <mc_control/GlobalPlugin.h>
#include "joystick/joystick.hh"
#include <mc_joystick_plugin/joystick_inputs.h>

namespace mc_plugin
{

struct mc_joystick_plugin : public mc_control::GlobalPlugin
{
  void init(mc_control::MCGlobalController & controller, const mc_rtc::Configuration & config) override;

  void reset(mc_control::MCGlobalController & controller) override;

  void before(mc_control::MCGlobalController &) override;

  void after(mc_control::MCGlobalController & controller) override;

  mc_control::GlobalPlugin::GlobalPluginConfiguration configuration() override;

  ~mc_joystick_plugin() override;

  void configure(const mc_rtc::Configuration & config)
  {
    mc_rtc::log::info("[mc_joystick_plugin] configuration:\n{}", config.dump(true, true));
  }

  double get_inputs(joystickButtonInputs input);
  double get_inputs(joystickAnalogicInputs input);
  double get_events(joystickButtonInputs in);

  Eigen::Vector2d get_stick_value(joystickAnalogicInputs input);

private:
  Joystick joystick_;
  JoystickEvent event_;
  bool joystickConnected_ = true;
  Eigen::Matrix<double, joystickButtonInputs::N_button_inputs, 1> joystick_button_state_;
  Eigen::Matrix<double, joystickButtonInputs::N_button_inputs, 1> joystick_button_event_;
  Eigen::Matrix<double, joystickAnalogicInputs::N_analogic_inputs, 2> joystick_analogical_state_;
  double leftTrigger_range_ = 1;
  double rightTrigger_range_ = 1;

  int t_indx = 0; // elapsed iteration;
};

} // namespace mc_plugin
