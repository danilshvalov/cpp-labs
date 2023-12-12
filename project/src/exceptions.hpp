#pragma once

#include <stdexcept>

struct Exception : std::exception {
    using exception::exception;
};

struct QuitCommandException : Exception {
    using Exception::Exception;
};
