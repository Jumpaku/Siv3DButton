#include "Button.h"

void Button::setState(State state)
{
    state_ = state;
}

void Button::fireOnClicked()
{
    onClicked_();
}

void Button::transition()
{
    switch (getState()) {
    case State::LEFT:
        if (getShape().mouseOver && !getShape().leftPressed) {
            setState(State::MOUSE_OVER);
        }
        break;
    case State::MOUSE_OVER:
        if (getShape().leftPressed) {
            setState(State::PRESSED);
        }
        else if (!getShape().mouseOver) {
            setState(State::LEFT);
        }
        break;
    case State::PRESSED:
        if (!getShape().mouseOver) {
            setState(State::LEFT);
        }
        else if (getShape().leftReleased) {
            setState(State::RELEASED);
        }
        break;
    case State::RELEASED:
        setState(State::MOUSE_OVER);
        break;
    default:
        break;
    }
}

ButtonBuilder Button::builder()
{
    return ButtonBuilder();
}



void Button::draw() const
{
    if (view_ != nullptr) {
        switch (getState()) {
        case ButtonInterface::State::LEFT:
            view_->drawLeft();
            break;
        case ButtonInterface::State::MOUSE_OVER:
            view_->drawMouseOver();
            break;
        case ButtonInterface::State::PRESSED:
            view_->drawPressed();
            break;
        case ButtonInterface::State::RELEASED:
            view_->drawReleased();
            break;
        default:
            break;
        }
    }
}

ButtonInterface::State Button::getState() const
{
    return state_;
}

Shape const &Button::getShape() const
{
    return shape_;
}
