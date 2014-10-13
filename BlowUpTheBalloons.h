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

#ifndef BLOW_UP_THE_BALLOONS_H
#define BLOW_UP_THE_BALLOONS_H

#include "Allegro.h"
#include "GameOver.h"

class BlowUpTheBalloons : public Allegro {
public:
    BlowUpTheBalloons();
    virtual ~BlowUpTheBalloons();
    
    virtual void onTick();
    virtual void onMouseButtonPressed(const Mouse& mouse, Mouse::Button button);
    
    void onKaboom(const Point& p, bool hit);
    
    int getLevel() const { return level; }
    bool isGameOver() const { return gameOver; }
    
private:
    int ticks;
    bool gameOver;
    
    int level;
    Text levelText;

    int hitBalloons;
    Text hitBalloonsText;
    
    int lostBalloons;
    Text lostBalloonsText;

    CompositeSprite backgroundLayer;
    CompositeSprite middleLayer;
    CompositeSprite topLayer;

    SampleSound backgroundSound;
    SampleSound hitSound1;
    SampleSound hitSound2;
    SampleSound lostSound;
    SampleSound fireSound;
};

#endif

