#include "InvalidMediaException.h"

InvalidMediaException::InvalidMediaException(const std::string& message)
    : std::runtime_error(message) {
}
