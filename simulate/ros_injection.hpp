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
    /**
     * @brief Records the current state 
     */
    struct RosInjectionState
    {
        // Step counter (counts afterMjStep)
        size_t step;
        // False when current scene is the whisker
        bool isBadScene;
    };
    
    
    /**
     * @brief Executed immediately before any appearance of mj_step in the simulate code
     * 
     * @param model The MuJoCo model (initial pose)
     * @param data The current simulation state (current pose)
     */
    void beforeMjStep(const mjModel *model, mjData *data) noexcept;

    /**
     * @brief Executed immediately after any appearance of mj_step in the simulate code
     * 
     * @param model The MuJoCo model (initial pose)
     * @param data The current simulation state (current pose)
     */
    void afterMjStep(const mjModel *model, mjData *data) noexcept;

    /**
     * @brief A struct to record the current state across all steps
     */
    static RosInjectionState state{
        .step = 0,
        .isBadScene = false
    };
       
} // namespace injection_space



#endif