#include "ros_injection.hpp"

namespace injection_space
{
    
    void beforeMjStep() noexcept
    {

    }

    void afterMjStep() noexcept
    {
        std::cout << "Step" << std::endl;
    }
       
} // namespace injection_space