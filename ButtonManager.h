#pragma once

#include<memory>
#include<list>
#include<initializer_list>
#include"IButton.h"

class ButtonManager
{
private:
    std::list<std::shared_ptr<IButton>> buttons_;
public:
    ButtonManager() = default;
    ButtonManager(std::initializer_list<std::shared_ptr<IButton>> buttons);
    ~ButtonManager() = default;
    void add(std::shared_ptr<IButton> button);
    void update();
    void draw()const;
};
