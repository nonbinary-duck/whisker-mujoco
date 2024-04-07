#ifndef MUJOCO_SIMULATE_ROS_INJECTION_H_
#define MUJOCO_SIMULATE_ROS_INJECTION_H_ 1

#pragma once

#include <iostream>

// Simple macros for before and after occurrences of calls to mjStep
#define ROS_INJECTION_BEFORE_MJ_STEP injection_space::beforeMjStep();
#define ROS_INJECTION_AFTER_MJ_STEP  injection_space::afterMjStep();

namespace injection_space
{
    
    void beforeMjStep() noexcept;

    void afterMjStep() noexcept;
       
} // namespace injection_space



#endif