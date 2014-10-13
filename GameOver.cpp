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

#include "GameOver.h"

GameOver::GameOver() : CompositeSprite(640, 480), sound1("gameover1.wav", 255), sound2("gameover2.wav", 255), ticks(0) {
}

GameOver::GameOver(const GameOver& init) : CompositeSprite(init), sound1("gameover1.wav", 255), sound2("gameover2.wav", 255), ticks(init.ticks){
}

void GameOver::onTick() {
    if(ticks == 0)
        sound1.play();
    if(ticks > 500 || ++ticks < 100)
        return;
        
    static iterator it;
    if(ticks % 200 == 100) {
        it = add(Text("GAME OVER", Point(640/2, 480/2-80), Color(255,0,0), Text::ALIGN_CENTER, Font("arcanum_bold_48.tga")));
        sound2.play();
    }
    else if(ticks % 200 == 0)
        remove(it);
}
