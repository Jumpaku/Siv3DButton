
#include <Siv3D.hpp>
#include"Button.h"
#include"ButtonManager.h"

class TextRoundRectView : public ButtonView
{
private:
    Font const font_;
public:
    void drawMouseOver()const override
    {
        RoundRect(20, 90, 300, 300, 10).draw(HSV(0.0, 0.8, 0.8));
        font_(L"increment").drawCenter(170, 240);
    }
    void drawPressed()const override
    {
        RoundRect(20, 92, 300, 300, 10).draw(HSV(0.0, 0.8, 0.8));
        font_(L"increment").drawCenter(170, 242);
    }
    void drawReleased()const override
    {
        RoundRect(20, 90, 300, 300, 10).draw(HSV(0.0, 0.8, 0.8));
        font_(L"increment").drawCenter(170, 240);
    }
    void drawLeft()const override
    {
        RoundRect(22, 92, 296, 296, 10).draw(HSV(0.0, 0.8, 0.7));
        font_(L"increment").drawCenter(170, 240);
    }
};

class TextureView : public ButtonView
{
private:
    Texture const texture_;
public:
    TextureView() :texture_(L"decrement.png") {}
    void drawMouseOver()const override
    {
        texture_.drawAt(470, 240);
    }
    void drawPressed()const override
    {
        texture_.drawAt(470, 242);
    }
    void drawReleased()const override
    {
        texture_.drawAt(470, 240);
    }
    void drawLeft()const override
    {
        texture_.scale(0.99).drawAt(470, 240);
    }
};

void Main()
{
    Font const font;
    int number = 0;

    auto inclement = Button::builder()
        .view<TextRoundRectView>()
        .shape(RoundRect(22, 92, 296, 296, 10))
        .onClicked([&number]() {
            ++number;
        })
        .build();
    auto declement = Button::builder()
        .view<TextureView>()
        .shape(Circle(470, 240, 148))
        .onClicked([&number]() {
            --number;
        })
        .build();

    ButtonManager buttonManager{inclement, declement};

    while (System::Update()) {
        buttonManager.update();
        buttonManager.draw();
        font(L"number = " + ToString(number)).drawCenter(320, 30);
    }
}
