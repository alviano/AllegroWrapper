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

#ifndef KABOOM_H
#define KABOOM_H

#include "Allegro.h"

class Kaboom : public Sprite {
public:
    Kaboom(const Point& center);
    
    virtual Drawable* clone() const { return new Kaboom(*this); }
    virtual void onTick() { ticks++; }
    virtual bool alive() const { return ticks < 100; }
    
private:
    int ticks;
};

#endif
