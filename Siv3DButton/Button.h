#pragma once

#include"ButtonInterface.h"
#include<Siv3D.hpp>
#include<functional>
#include<type_traits>

class ButtonBuilder;

class Button :
    public ButtonInterface
{
private:
    std::function<void(void)> onClicked_;
    State state_;
    Shape shape_;
    std::shared_ptr<ButtonView> view_;
protected:
    void setState(State state);
    virtual void fireOnClicked()override;
    virtual void transition()override;
public:
    static ButtonBuilder builder();
    Button(std::shared_ptr<ButtonView> view, Shape const &shape, std::function<void(void)> const &onClicked)
        :view_(view),
        shape_(shape),
        onClicked_(onClicked),
        state_(State::LEFT)
    {}
    virtual ~Button() = default;
    virtual void draw()const override;
    virtual State getState()const override;
    virtual Shape const &getShape()const;
};

class ButtonBuilder{
    std::function<void(void)> onClicked_;
    std::shared_ptr<ButtonView> view_;
    Shape shape_;
public:
    ButtonBuilder &onClicked(std::function<void(void)> onClicked)
    {
        onClicked_ = onClicked;
        return *this;
    }
    template<typename View, typename ...Args>
    ButtonBuilder &view(Args ...args)
    {
        static_assert(std::is_base_of<ButtonView, View>::value, "View is not base of ButtonView");
        view_ = std::make_shared<View>(args...);
        return *this;
    }
    template<typename SubShape>
    ButtonBuilder &shape(SubShape const &subShape)
    {
        shape_ = Shape(subShape);
        return *this;
    }
    std::shared_ptr<ButtonInterface> build()
    {
        return std::make_shared<Button>(view_, shape_, onClicked_);
    }
};