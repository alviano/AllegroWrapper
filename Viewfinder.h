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

#ifndef VIEWFINDER_H
#define VIEWFINDER_H

#include "Allegro.h"

class Viewfinder : public Sprite {
public:
    Viewfinder();
    
    virtual Drawable* clone() const { return new Viewfinder(*this); }
    virtual void onMouseMove(const Mouse& mouse);
};

#endif

