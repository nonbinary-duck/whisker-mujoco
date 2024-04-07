#ifndef MUJOCO_SIMULATE_ROS_INJECTION_H_
#define MUJOCO_SIMULATE_ROS_INJECTION_H_ 1

#pragma once

#include <iostream>
#include <mujoco/mujoco.h>

// Simple macros for before and after occurrences of calls to mjStep
#define ROS_INJECTION_BEFORE_MJ_STEP(model, data) injection_space::beforeMjStep(model, data);
#define ROS_INJECTION_AFTER_MJ_STEP(model, data)  injection_space::afterMjStep(model, data);

namespace injection_space
{
    
    void beforeMjStep(mjModel *model, mjData *data) noexcept;

    void afterMjStep(mjModel *model, mjData *data) noexcept;
       
} // namespace injection_space



#endif