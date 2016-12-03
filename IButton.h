#pragma once;

class IButton
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
    virtual void update()
    {
        transition();
        if (getState() == State::RELEASED) {
            fireOnClicked();
        }
    }
    virtual void draw()const = 0;
    virtual State getState()const = 0;
    virtual ~IButton() = default;
};
