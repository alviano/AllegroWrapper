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

#ifndef BALLOON_H
#define BALLOON_H

#include "Allegro.h"

class BlowUpTheBalloons;

class Balloon : public Sprite {
public:
    Balloon(BlowUpTheBalloons& game, const Point& center);
    
    bool update();
    bool checkHit(int x, int y);
    
    virtual Drawable* clone() const { return new Balloon(*this); }
    
    virtual void onTick();
    virtual bool alive() const;
    
    virtual void onMouseButtonPressed(const Mouse& mouse, Mouse::Button button);
    
private:
    BlowUpTheBalloons& game;
    int level;
    bool hit;
    int ticks;
    
    string imageName(int level) const;
};

#endif
