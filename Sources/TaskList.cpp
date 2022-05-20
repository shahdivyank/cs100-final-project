#include "../Headers/TaskList.h"

TaskList::TaskList()
{
    this->size = 0;
}

int TaskList::getSize()
{
    return this->size;
}

void TaskList::addTask(std::string title, std::string description, unsigned int classification, unsigned int priority, std::string date, unsigned int duration)
{
    Task task;
    task.title.setInfo(title);
    task.description.setInfo(description);
    task.classification.setInfo(classification);
    task.priority.setInfo(priority);
    task.duration.setInfo(duration);
    task.date.setInfo(date);

    tasks.push_back(task);
    this->size++;
}

void TaskList::deleteTask(std::string title)
{
    int count = 0;
    std::list<Task>::iterator ptr;
    for (ptr = this->tasks.begin(); ptr != this->tasks.end(); ++ptr)
    {
        if ((*ptr).title.getInfo("") == title)
        {
            std::advance(ptr, count);
            tasks.erase(ptr);
            this->size--;
            break;
        }
        ++count;
    }
}

Task* TaskList::getTask(std::string title)
{
    for (std::list<Task>::iterator ptr = this->tasks.begin(); ptr != this->tasks.end(); ++ptr)
    {
        if ((*ptr).title.getInfo("") == title)
        {
            return &(*ptr);
        }
    }
    return nullptr;
}