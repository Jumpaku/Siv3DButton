#include"ButtonManager.h"
#include<algorithm>

using namespace std;

ButtonManager::ButtonManager(initializer_list<shared_ptr<IButton>> buttons)
    :buttons_(buttons.begin(), buttons.end())
{}

void ButtonManager::add(shared_ptr<IButton> button)
{
    buttons_.push_back(button);
}

void ButtonManager::update()
{
    for_each(buttons_.begin(), buttons_.end(), [](shared_ptr<IButton> const &button) {
        if (button != nullptr) {
            button->update();
        }
    });
}

void ButtonManager::draw()const
{
    for_each(buttons_.begin(), buttons_.end(), [](shared_ptr<IButton> const &button) {
        if (button != nullptr) {
            button->draw();
        }
    });
}