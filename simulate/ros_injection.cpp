#include "ros_injection.hpp"

namespace injection_space
{
    
    void beforeMjStep(const mjModel *model, mjData *data) noexcept
    {
        // Only take action when the model is our whisker model
        if (state.isBadScene) return;

    }

    void afterMjStep(const mjModel *model, mjData *data) noexcept
    {
        // If
        // Record a step after its happened
        state.step++;

        // Only take action when the model is our whisker model
        if (state.isBadScene) return;


        // Only take action when the model is our whisker model
        if (mj_name2id(model, mjtObj::mjOBJ_NUMERIC, "whskmdl") == -1) return;

        std::cout << model->names[0] << std::endl;
    }
       
} // namespace injection_space