#pragma once

#include <string>

class Task
{
public:
    explicit Task(std::string name)
        : m_name(std::move(name))
        , m_completed(false)
    {}

    const std::string& name() const { return m_name; }

    bool isCompleted() const { return m_completed; }
    void complete() { m_completed = true; }

private:
    std::string m_name;
    bool m_completed;
};
