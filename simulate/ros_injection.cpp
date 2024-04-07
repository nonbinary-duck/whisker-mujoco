#include "ros_injection.hpp"

namespace injection_space
{
    
    void beforeMjStep(const mjModel *model, mjData *data) noexcept
    {
        // Only take action when the model is our whisker model
        if (mj_name2id(model, mjtObj::mjOBJ_NUMERIC, "whskmdl") == -1) return;

    }

    void afterMjStep(const mjModel *model, mjData *data) noexcept
    {
        // Only take action when the model is our whisker model
        if (mj_name2id(model, mjtObj::mjOBJ_NUMERIC, "whskmdl") == -1) return;

        std::cout << "Found text!" << std::endl;
    }
       
} // namespace injection_space