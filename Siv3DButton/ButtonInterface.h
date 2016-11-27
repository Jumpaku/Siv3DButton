#pragma once

#include<memory>
#include<list>
#include<initializer_list>

class ButtonView
{
public:
    virtual void drawMouseOver()const = 0;
    virtual void drawPressed()const = 0;
    virtual void drawReleased()const = 0;
    virtual void drawLeft()const = 0;
};

class ButtonInterface
{
protected:
    virtual void fireOnClicked() = 0;
    virtual void transition() = 0;
public:
    enum class State
    {
        MOUSE_OVER,
        PRESSED,
        RELEASED,
        LEFT,
    };
    virtual void update();
    virtual void draw()const = 0;
    virtual State getState()const = 0;
    virtual ~ButtonInterface() = default;

};

class ButtonManager
{
private:
    std::list<std::shared_ptr<ButtonInterface>> buttons_;
public:
    ButtonManager() = default;
    ButtonManager(std::initializer_list<std::shared_ptr<ButtonInterface>> buttons);
    ~ButtonManager() = default;
    void add(std::shared_ptr<ButtonInterface> button);
    void update();
    void draw()const;
};
