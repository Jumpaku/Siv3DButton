#include"ButtonInterface.h"
#include<algorithm>

using namespace std;

void ButtonInterface::update()
{
    transition();
    if (getState() == State::RELEASED) {
        fireOnClicked();
    }
}

ButtonManager::ButtonManager(initializer_list<shared_ptr<ButtonInterface>> buttons)
    :buttons_(buttons.begin(), buttons.end())
{}

void ButtonManager::add(shared_ptr<ButtonInterface> button)
{
    buttons_.push_back(button);
}

void ButtonManager::update()
{
    for_each(buttons_.begin(), buttons_.end(), [](shared_ptr<ButtonInterface> const &button) {
        if (button != nullptr) {
            button->update();
        }
    });
}

void ButtonManager::draw()const
{
    for_each(buttons_.begin(), buttons_.end(), [](shared_ptr<ButtonInterface> const &button) {
        if (button != nullptr) {
            button->draw();
        }
    });
}