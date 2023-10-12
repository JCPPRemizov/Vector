//
// Created by Vladislav on 12.10.2023.
//

#ifndef ALLOCATOR_VECTOREXCEPTION_H
#define ALLOCATOR_VECTOREXCEPTION_H

#include <exception>
#include <string>

class VectorException : std::exception
{
private:
    std::string m_message;
public:
    explicit VectorException(std::string message) noexcept : m_message(std::move(message)) { }

    [[nodiscard]] const char* what() const noexcept override
    {
        return m_message.c_str();
    }
};

#endif //ALLOCATOR_VECTOREXCEPTION_H
