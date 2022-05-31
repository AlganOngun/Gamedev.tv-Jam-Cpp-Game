#include "EBO.hpp"

namespace JamEngine
{
    void EBO::generateBuffer()
    {
        glGenBuffers(1, &bufferId);
    }

    void EBO::initializeBuffer()
    {
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);
    }

    void EBO::bindBuffer()
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferId);
    }

    void EBO::unbindBuffer()
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

    void EBO::deleteBuffer()
    {
        glDeleteBuffers(1, &bufferId);
    }
}
