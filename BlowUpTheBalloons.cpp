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

#include "BlowUpTheBalloons.h"

#include "Kaboom.h"
#include "Balloon.h"
#include "LevelUp.h"
#include "Viewfinder.h"

#include <sstream>
#include <cmath>
#include <typeinfo>

BlowUpTheBalloons::BlowUpTheBalloons() 
    : Allegro(640, 480, 24, false, false),
      ticks(0),
      gameOver(false),
      level(1),
      levelText("Level: 1", Point(25,75), Color(255,255,255)),
      hitBalloons(0),
      hitBalloonsText("Hit:   0", Point(25,55), Color(255,255,255)),
      lostBalloons(0),
      lostBalloonsText("Miss:  0", Point(25,65), Color(255,255,255)),
      backgroundLayer(640, 480),
      middleLayer(640, 480),
      topLayer(640, 480),
      backgroundSound("background.wav"),
      hitSound1("hit1.wav"),
      hitSound2("hit2.wav"),
      lostSound("lost.wav"),
      fireSound("fire.wav") {
    add(DrawablePointer(backgroundLayer));
    add(DrawablePointer(middleLayer));
    add(DrawablePointer(topLayer));
    
    middleLayer.setNotification(ON_MOUSE_BUTTON_PRESSED).setNotification(ON_TICK);
    topLayer.setNotification(ON_MOUSE_MOVE);
    
    Sprite background("background.bmp", Point(0, 60));
    background.setScaleWidth(1.2);
    background.setScaleHeight(0.75);
    backgroundLayer.add(background);

    for(int i = 10; i < 640; i += 16)
        backgroundLayer.add(Sprite("chiodo.bmp", Point(i, 0)));
        
    for(int i = 0; i < 480; i += 80) {
        backgroundLayer.add(Sprite("wall.bmp", Point(0, i)));
        backgroundLayer.add(Sprite("wall.bmp", Point(620, i)));
    }
    
    backgroundLayer.add(Text("Blow up the balloons!", Point(615,55), Color(255,255,255), Text::ALIGN_RIGHT));
    backgroundLayer.add(Text("Press Q to exit", Point(25, 470), Color(255,255,255)));
    backgroundLayer.add(Text("Copyright (C) 2013, Mario Alviano", Point(615,470), Color(255,255,255), Text::ALIGN_RIGHT));

    backgroundLayer.add(DrawablePointer(hitBalloonsText));
    backgroundLayer.add(DrawablePointer(lostBalloonsText));
    backgroundLayer.add(DrawablePointer(levelText));
    
    backgroundSound.setLoop(true);
    backgroundSound.play();
    
    topLayer.add(Viewfinder());
}

BlowUpTheBalloons::~BlowUpTheBalloons() {
}

void BlowUpTheBalloons::onTick() {
    Allegro::onTick();
    
    ++ticks;
    
    if(getKeyboard().isKeyPressed(KEY_Q))
        exit = true;
    if(ticks % 5 == 0)
        draw();

    if(gameOver)
        return;
            
    if(hitBalloons / 10 >= level && level < 5) {
        middleLayer.add(LevelUp());
        stringstream ss;
        ss << "Level: " << ++level;
        levelText.setText(ss.str());
    }
    
    if(ticks % (static_cast<int>(log(level * 1000) * 5)) == 0) {
        middleLayer.add(Balloon(*this, Point(rand() % 520 + 60,500)));
    }

    if(lostBalloons >= 10) {
        gameOver = true;
        backgroundSound.stop();
        middleLayer.unsetNotification(ALL).setNotification(ON_TICK);
        topLayer.clear();
        topLayer.add(GameOver());
        topLayer.unsetNotification(ALL).setNotification(ON_TICK);
    }
}

void BlowUpTheBalloons::onMouseButtonPressed(const Mouse& mouse, Mouse::Button button) {
    if(!gameOver) {
        fireSound.play();
        backgroundLayer.add(Sprite("gunhole.bmp", Point(mouse.getX()-12, mouse.getY()-12)));
    }
    Allegro::onMouseButtonPressed(mouse, button);
}

void BlowUpTheBalloons::onKaboom(const Point& p, bool hit) {
    if(rand() % 2 == 0)
        hitSound1.play();
    else
        hitSound2.play();

    middleLayer.add(Kaboom(p));
    
    if(hit) {
        stringstream ss;
        ss << "Hit:   " << ++hitBalloons;
        hitBalloonsText.setText(ss.str());
    }
    else {
        lostSound.play();
        stringstream ss;
        ss << "Miss:  " << ++lostBalloons;
        lostBalloonsText.setText(ss.str());
    }
}
