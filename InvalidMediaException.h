#ifndef INVALIDMEDIAEXCEPTION_H
#define INVALIDMEDIAEXCEPTION_H

#include <stdexcept>
#include <string>

class InvalidMediaException : public std::runtime_error {
public:
    explicit InvalidMediaException(const std::string& message);
};

#endif
