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

#include "LevelUp.h"

LevelUp::LevelUp() : CompositeSprite(100, 10, Point(rand() % 320 + 200, rand() % 240 + 100)), sound("levelup.wav", 255), ticks(0) {
    add(Text("LEVEL UP!", Point(), Color(0,0,255)));
    setScaleWidth(3);
    setScaleHeight(3);
    setAngle(rand() % 360);
}

LevelUp::LevelUp(const LevelUp& init) : CompositeSprite(init), sound("levelup.wav", 255), ticks(init.ticks) {
}

void LevelUp::onTick() {
    if(ticks == 0)
        sound.play();
    if(++ticks % 5 == 0)
        setAngle(getAngle() + 1);
}

