#include "ros_injection.hpp"

namespace injection_space
{
    
    void beforeMjStep(mjModel *model, mjData *data) noexcept
    {

    }

    void afterMjStep(mjModel *model, mjData *data) noexcept
    {    
        std::cout << model->names << std::endl;
    }
       
} // namespace injection_space