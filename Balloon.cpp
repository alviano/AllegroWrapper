/*
    BlowUpTheBalloons - A simple game powered by Allegro Wrapper
    Copyright (C) 2013, Mario Alviano

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "Balloon.h"

#include "BlowUpTheBalloons.h"

#include <sstream>

Balloon::Balloon(BlowUpTheBalloons& game_, const Point& center) : Sprite(imageName(game_.getLevel()), Point(center.getX() - 40, center.getY() - 40)), game(game_), level(game.getLevel()), hit(false), ticks(0) {
    assert(1 <= level && level <= 5);
}

string Balloon::imageName(int level) const {
    assert(1 <= level && level <= 5);
    stringstream ss;
    ss << "balloon" << level << ".bmp";
    return ss.str();
}

void Balloon::onTick() {
    if(++ticks % (11 - level*2) == 0) {
        int shiftX = rand() % 32 - 16;
        if(getLeftTopCorner().getX() + shiftX < 10)
            shiftX *= -1;
        else if(getLeftTopCorner().getX() + shiftX > 540)
            shiftX *= -1;
        int shiftY = rand() % 10;
        setLeftTopCorner(Point(getLeftTopCorner()).incrementX(shiftX).incrementY(-shiftY));
        setAngle(getAngle() + (rand() % 7 - 3));
    }
}

bool Balloon::alive() const {
    if(hit || getLeftTopCorner().getY() <= 40 || game.isGameOver()) {
        game.onKaboom(Point(getLeftTopCorner()).incrementX(40).incrementY(20), hit);
        return false;
    }
    return true;
}

void Balloon::onMouseButtonPressed(const Mouse& mouse, Mouse::Button button) {
    if(getLeftTopCorner().getX() <= mouse.getX() && mouse.getX() <= getLeftTopCorner().getX() + getWidth())
        if(getLeftTopCorner().getY() <= mouse.getY() && mouse.getY() <= getLeftTopCorner().getY() + getHeight())
            hit = true;
}
