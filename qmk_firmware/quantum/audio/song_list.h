/* Copyright 2016 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "musical_notes.h"

#ifndef SONG_LIST_H
#define SONG_LIST_H

#define NO_SOUND

#define LP_NUMB	\
	H__NOTE(_CS5), H__NOTE(_E5), H__NOTE(_CS5), WD_NOTE(_FS5), \
	WD_NOTE(_A5), WD_NOTE(_GS5),   WD_NOTE(_REST),  H__NOTE(_CS5), H__NOTE(_E5), \
	H__NOTE(_CS5), WD_NOTE(_A5), WD_NOTE(_GS5), WD_NOTE(_E5),


#define ODE_TO_JOY                                          \
    Q__NOTE(_E4), Q__NOTE(_E4), Q__NOTE(_F4), Q__NOTE(_G4), \
    Q__NOTE(_G4), Q__NOTE(_F4), Q__NOTE(_E4), Q__NOTE(_D4), \
    Q__NOTE(_C4), Q__NOTE(_C4), Q__NOTE(_D4), Q__NOTE(_E4), \
    QD_NOTE(_E4), E__NOTE(_D4), H__NOTE(_D4),

#define ROCK_A_BYE_BABY                            \
    QD_NOTE(_B4), E__NOTE(_D4), Q__NOTE(_B5),      \
    H__NOTE(_A5), Q__NOTE(_G5),                    \
    QD_NOTE(_B4), E__NOTE(_D5), Q__NOTE(_G5),      \
    H__NOTE(_FS5),

#define CLOSE_ENCOUNTERS_5_NOTE  \
	Q__NOTE(_D5),                \
	Q__NOTE(_E5),                \
	Q__NOTE(_C5),                \
	Q__NOTE(_C4),                \
	Q__NOTE(_G4),

#define DOE_A_DEER              \
	QD_NOTE(_C4), E__NOTE(_D4), \
	QD_NOTE(_E4), E__NOTE(_C4), \
	Q__NOTE(_E4), Q__NOTE(_C4), \
	Q__NOTE(_E4),

/* Requires: PLAY_NOTE_ARRAY(..., ..., STACCATO); */
#define IN_LIKE_FLINT \
    E__NOTE(_AS4), E__NOTE(_AS4), QD_NOTE(_B4),  \
    E__NOTE(_AS4), E__NOTE(_B4),  QD_NOTE(_CS4), \
    E__NOTE(_B4),  E__NOTE(_CS4), QD_NOTE(_DS4), \
    E__NOTE(_CS4), E__NOTE(_B4),  QD_NOTE(_AS4), \
    E__NOTE(_AS4), E__NOTE(_AS4), QD_NOTE(_B4),

#define IMPERIAL_MARCH \
  HD_NOTE(_A4), HD_NOTE(_A4), HD_NOTE(_A4), QD_NOTE(_F4), QD_NOTE(_C5), \
  HD_NOTE(_A4), QD_NOTE(_F4),  QD_NOTE(_C5), WD_NOTE(_A4), \
  HD_NOTE(_E5), HD_NOTE(_E5), HD_NOTE(_E5), QD_NOTE(_F5), QD_NOTE(_C5), \
  HD_NOTE(_A4), QD_NOTE(_F4),  QD_NOTE(_C5), WD_NOTE(_A4)

#define CLUEBOARD_SOUND \
    HD_NOTE(_C3), HD_NOTE(_D3), HD_NOTE(_E3), HD_NOTE(_F3), HD_NOTE(_G3), HD_NOTE(_A4), HD_NOTE(_B4), HD_NOTE(_C4)
/*
    HD_NOTE(_G3), HD_NOTE(_E3), HD_NOTE(_C3), \
    Q__NOTE(_E3), Q__NOTE(_C3), Q__NOTE(_G3), \
    Q__NOTE(_E3)
*/
/*
    HD_NOTE(_C3), HD_NOTE(_G3), HD_NOTE(_E3), \
    Q__NOTE(_G3), Q__NOTE(_E3), Q__NOTE(_G3), \
    Q__NOTE(_F3)
*/

#define BASKET_CASE \
    QD_NOTE(_G3), E__NOTE(_F3), E__NOTE(_E3), Q__NOTE(_F3), M__NOTE(_G3, 8+32), Q__NOTE(_REST), \
    Q__NOTE(_B4), Q__NOTE(_C4), Q__NOTE(_B4), E__NOTE(_A4), Q__NOTE(_G3), M__NOTE(_G3, 8+32), Q__NOTE(_REST), \
    Q__NOTE(_B4), Q__NOTE(_C4), Q__NOTE(_B4), E__NOTE(_A4), Q__NOTE(_G3), Q__NOTE(_G3), Q__NOTE(_G3), Q__NOTE(_G3), E__NOTE(_A4), E__NOTE(_C4), QD_NOTE(_B4), HD_NOTE(_B4)

#define STARTUP_SOUND  \
    E__NOTE(_E6),     \
    E__NOTE(_A6),     \
    ED_NOTE(_E7),

#define GOODBYE_SOUND \
    E__NOTE(_E7),     \
    E__NOTE(_A6),     \
    ED_NOTE(_E6),

#define PLANCK_SOUND  \
    ED_NOTE(_E7 ),     \
    E__NOTE(_CS7),     \
    E__NOTE(_E6 ),     \
    E__NOTE(_A6 ),     \
    M__NOTE(_CS7, 20),

#define PREONIC_SOUND \
    M__NOTE(_B5, 20),  \
    E__NOTE(_B6),      \
    M__NOTE(_DS6, 20), \
    E__NOTE(_B6),

#define QWERTY_SOUND \
    E__NOTE(_GS6 ),  \
    E__NOTE(_A6  ),  \
    S__NOTE(_REST),  \
    Q__NOTE(_E7  ),

#define COLEMAK_SOUND \
    E__NOTE(_GS6 ),   \
    E__NOTE(_A6  ),   \
    S__NOTE(_REST),   \
    ED_NOTE(_E7  ),   \
    S__NOTE(_REST),   \
    ED_NOTE(_GS7 ),

#define DVORAK_SOUND \
    E__NOTE(_GS6 ),  \
    E__NOTE(_A6  ),  \
    S__NOTE(_REST),  \
    E__NOTE(_E7  ),  \
    S__NOTE(_REST),  \
    E__NOTE(_FS7 ),  \
    S__NOTE(_REST),  \
    E__NOTE(_E7  ),

#define PLOVER_SOUND \
    E__NOTE(_GS6 ),  \
    E__NOTE(_A6  ),  \
    S__NOTE(_REST),  \
    ED_NOTE(_E7  ),  \
    S__NOTE(_REST),  \
    ED_NOTE(_A7  ),

#define PLOVER_GOODBYE_SOUND \
    E__NOTE(_GS6 ),  \
    E__NOTE(_A6  ),  \
    S__NOTE(_REST),  \
    ED_NOTE(_A7  ),  \
    S__NOTE(_REST),  \
    ED_NOTE(_E7  ),

#define MUSIC_ON_SOUND \
    E__NOTE(_A5 ),        \
    E__NOTE(_B5 ),        \
    E__NOTE(_CS6),        \
    E__NOTE(_D6 ),        \
    E__NOTE(_E6 ),        \
    E__NOTE(_FS6),        \
    E__NOTE(_GS6),        \
    E__NOTE(_A6 ),

#define AUDIO_ON_SOUND \
    E__NOTE(_A5 ),        \
    E__NOTE(_A6 ),

#define AUDIO_OFF_SOUND \
    E__NOTE(_A6 ),        \
    E__NOTE(_A5 ),

#define MUSIC_SCALE_SOUND MUSIC_ON_SOUND

#define MUSIC_OFF_SOUND \
    E__NOTE(_A6 ),        \
    E__NOTE(_GS6 ),        \
    E__NOTE(_FS6),        \
    E__NOTE(_E6 ),        \
    E__NOTE(_D6 ),        \
    E__NOTE(_CS6),        \
    E__NOTE(_B5),        \
    E__NOTE(_A5 ),

#define VOICE_CHANGE_SOUND \
    Q__NOTE(_A5 ),        \
    Q__NOTE(_CS6),        \
    Q__NOTE(_E6 ),        \
    Q__NOTE(_A6 ),

#define CHROMATIC_SOUND \
    Q__NOTE(_A5 ),        \
    Q__NOTE(_AS5 ),        \
    Q__NOTE(_B5),        \
    Q__NOTE(_C6 ),        \
    Q__NOTE(_CS6 ),

#define MAJOR_SOUND \
    Q__NOTE(_A5 ),        \
    Q__NOTE(_B5 ),        \
    Q__NOTE(_CS6),        \
    Q__NOTE(_D6 ),        \
    Q__NOTE(_E6 ),

#define MINOR_SOUND \
    Q__NOTE(_A5 ),        \
    Q__NOTE(_B5 ),        \
    Q__NOTE(_C6 ),        \
    Q__NOTE(_D6 ),        \
    Q__NOTE(_E6 ),

#define GUITAR_SOUND \
    Q__NOTE(_E5 ),        \
    Q__NOTE(_A5),        \
    Q__NOTE(_D6 ),        \
    Q__NOTE(_G6 ),

#define VIOLIN_SOUND \
    Q__NOTE(_G5 ),        \
    Q__NOTE(_D6),        \
    Q__NOTE(_A6 ),        \
    Q__NOTE(_E7 ),

#define CAPS_LOCK_ON_SOUND \
    E__NOTE(_A3),          \
    E__NOTE(_B3),

#define CAPS_LOCK_OFF_SOUND \
    E__NOTE(_B3),           \
    E__NOTE(_A3),

#define SCROLL_LOCK_ON_SOUND \
    E__NOTE(_D4),            \
    E__NOTE(_E4),

#define SCROLL_LOCK_OFF_SOUND \
    E__NOTE(_E4),             \
    E__NOTE(_D4),

#define NUM_LOCK_ON_SOUND \
    E__NOTE(_D5),         \
    E__NOTE(_E5),

#define NUM_LOCK_OFF_SOUND \
    E__NOTE(_E5),          \
    E__NOTE(_D5),

#define AG_NORM_SOUND \
    E__NOTE(_A5),      \
    E__NOTE(_A5),

#define AG_SWAP_SOUND \
    SD_NOTE(_B5),      \
    SD_NOTE(_A5),      \
    SD_NOTE(_B5),      \
    SD_NOTE(_A5),

#define UNICODE_WINDOWS \
    E__NOTE(_B5),       \
    S__NOTE(_E6),

#define UNICODE_LINUX \
    E__NOTE(_E6),     \
    S__NOTE(_B5),

#define COIN_SOUND \
    E__NOTE(_A5  ),      \
    HD_NOTE(_E6  ),

#define ONE_UP_SOUND \
    Q__NOTE(_E6  ),  \
    Q__NOTE(_G6  ),  \
    Q__NOTE(_E7  ),  \
    Q__NOTE(_C7  ),  \
    Q__NOTE(_D7  ),  \
    Q__NOTE(_G7  ),

#define SONIC_RING \
    E__NOTE(_E6),  \
    E__NOTE(_G6),  \
    HD_NOTE(_C7),

#define ZELDA_PUZZLE \
    Q__NOTE(_G5),     \
    Q__NOTE(_FS5),    \
    Q__NOTE(_DS5),     \
    Q__NOTE(_A4),    \
    Q__NOTE(_GS4),     \
    Q__NOTE(_E5),     \
    Q__NOTE(_GS5),     \
    HD_NOTE(_C6),

#define ZELDA_TREASURE \
    Q__NOTE(_A4 ), \
    Q__NOTE(_AS4), \
    Q__NOTE(_B4 ), \
    HD_NOTE(_C5 ), \

#define TERMINAL_SOUND \
    E__NOTE(_C5 )

#define OVERWATCH_THEME \
    HD_NOTE(_A4 ), \
    Q__NOTE(_E4 ), \
    Q__NOTE(_A4 ), \
    HD_NOTE(_B4 ), \
    Q__NOTE(_E4 ), \
    Q__NOTE(_B4 ), \
    W__NOTE(_CS5),

#define MARIO_THEME \
    Q__NOTE(_E5), \
    H__NOTE(_E5), \
    H__NOTE(_E5), \
    Q__NOTE(_C5), \
    H__NOTE(_E5), \
    W__NOTE(_G5), \
    Q__NOTE(_G4),

#define MARIO_GAMEOVER \
    HD_NOTE(_C5 ), \
    HD_NOTE(_G4 ), \
    H__NOTE(_E4 ), \
    H__NOTE(_A4 ), \
    H__NOTE(_B4 ), \
    H__NOTE(_A4 ), \
    H__NOTE(_AF4), \
    H__NOTE(_BF4), \
    H__NOTE(_AF4), \
    WD_NOTE(_G4 ),

#define MARIO_MUSHROOM \
    S__NOTE(_C5 ), \
    S__NOTE(_G4 ), \
    S__NOTE(_C5 ), \
    S__NOTE(_E5 ), \
    S__NOTE(_G5 ), \
    S__NOTE(_C6 ), \
    S__NOTE(_G5 ), \
    S__NOTE(_GS4), \
    S__NOTE(_C5 ), \
    S__NOTE(_DS5), \
    S__NOTE(_GS5), \
    S__NOTE(_DS5), \
    S__NOTE(_GS5), \
    S__NOTE(_C6 ), \
    S__NOTE(_DS6), \
    S__NOTE(_GS6), \
    S__NOTE(_DS6), \
    S__NOTE(_AS4), \
    S__NOTE(_D5 ), \
    S__NOTE(_F5 ), \
    S__NOTE(_AS5), \
    S__NOTE(_D6 ), \
    S__NOTE(_F6 ), \
    S__NOTE(_AS6), \
    S__NOTE(_F6 )

#define E1M1_DOOM  \
    Q__NOTE(_E3 ), \
    Q__NOTE(_E3 ), \
    Q__NOTE(_E4 ), \
    Q__NOTE(_E3 ), \
    Q__NOTE(_E3 ), \
    Q__NOTE(_D4 ), \
    Q__NOTE(_E3 ), \
    Q__NOTE(_E3 ), \
    Q__NOTE(_C4 ), \
    Q__NOTE(_E3 ), \
    Q__NOTE(_E3 ), \
    Q__NOTE(_BF3), \
    Q__NOTE(_E3 ), \
    Q__NOTE(_E3 ), \
    Q__NOTE(_B3 ), \
    Q__NOTE(_C4 ), \
    Q__NOTE(_E3 ), \
    Q__NOTE(_E3 ), \
    Q__NOTE(_E4 ), \
    Q__NOTE(_E3 ), \
    Q__NOTE(_E3 ), \
    Q__NOTE(_D4 ), \
    Q__NOTE(_E3 ), \
    Q__NOTE(_E3 ), \
    Q__NOTE(_C4 ), \
    Q__NOTE(_E3 ), \
    Q__NOTE(_E3 ), \
    H__NOTE(_BF3),

#define DISNEY_SONG \
    H__NOTE(_G3 ),  \
    H__NOTE(_G4 ),  \
    H__NOTE(_F4 ),  \
    H__NOTE(_E4 ),  \
    H__NOTE(_CS4),  \
    H__NOTE(_D4 ),  \
    W__NOTE(_A4 ),  \
    H__NOTE(_B3 ),  \
    H__NOTE(_B4 ),  \
    H__NOTE(_A4 ),  \
    H__NOTE(_G4 ),  \
    H__NOTE(_FS4),  \
    H__NOTE(_G4 ),  \
    W__NOTE(_C5 ),  \
    H__NOTE(_D5 ),  \
    H__NOTE(_C5 ),  \
    H__NOTE(_B4 ),  \
    H__NOTE(_A4 ),  \
    H__NOTE(_G4 ),  \
    H__NOTE(_F4 ),  \
    H__NOTE(_E4 ),  \
    H__NOTE(_D4 ),  \
    W__NOTE(_A4 ),  \
    W__NOTE(_B3 ),  \
    W__NOTE(_C4 ),

#define NUMBER_ONE \
    HD_NOTE(_F4 ), \
    Q__NOTE(_C5 ), \
    E__NOTE(_B4 ), \
    E__NOTE(_C5 ), \
    E__NOTE(_B4 ), \
    E__NOTE(_C5 ), \
    Q__NOTE(_B4 ), \
    Q__NOTE(_C5 ), \
    H__NOTE(_AF4), \
    HD_NOTE(_F4 ), \
    Q__NOTE(_F4 ), \
    Q__NOTE(_AF4), \
    Q__NOTE(_C5 ), \
    H__NOTE(_DF5), \
    H__NOTE(_AF4), \
    H__NOTE(_DF5), \
    H__NOTE(_EF5), \
    Q__NOTE(_C5 ), \
    Q__NOTE(_DF5), \
    Q__NOTE(_C5 ), \
    Q__NOTE(_DF5), \
    H__NOTE(_C5 ),

#define CABBAGE_SONG \
    H__NOTE(_C4),    \
    H__NOTE(_A4),    \
    H__NOTE(_B4),    \
    H__NOTE(_B4),    \
    H__NOTE(_A4),    \
    H__NOTE(_G4),    \
    H__NOTE(_E4),

#define OLD_SPICE  \
    Q__NOTE(_A4 ), \
    Q__NOTE(_A4 ), \
    H__NOTE(_B4 ), \
    H__NOTE(_D5 ), \
    H__NOTE(_CS5), \
    Q__NOTE(_E5 ), \
    H__NOTE(_FS5), \
    H__NOTE(_D5 ), \

#define VICTORY_FANFARE_SHORT \
    ED_NOTE(_C6), \
    ED_NOTE(_C6), \
    ED_NOTE(_C6), \
    ED_NOTE(_C6), \
    W__NOTE(_REST), \
    QD_NOTE(_GS5), \
    QD_NOTE(_AS5), \
    Q__NOTE(_C6), \
    Q__NOTE(_AS5), \
    Q__NOTE(_C6), \

#define ALL_STAR \
    H__NOTE(_AS4), W__NOTE(_FS4), Q__NOTE(_FS4), Q__NOTE(_DS4), H__NOTE(_FS4), W__NOTE(_FS4), Q__NOTE(_FS4), Q__NOTE(_DS4), \
    H__NOTE(_FS4), W__NOTE(_FS4), W__NOTE(_FS4), QD_NOTE(_AS4), \
    H__NOTE(_AS4), W__NOTE(_FS4), Q__NOTE(_FS4), Q__NOTE(_DS4), H__NOTE(_FS4), W__NOTE(_FS4), Q__NOTE(_FS4), Q__NOTE(_DS4), \
    H__NOTE(_FS4), W__NOTE(_FS4), W__NOTE(_FS4), W__NOTE(_AS4), H__NOTE(_REST),\
    W__NOTE(_AS4), W__NOTE(_CS5), H__NOTE(_B4),  H__NOTE(_CS5), H__NOTE(_DS5), W__NOTE(_FS5), \
    H__NOTE(_GS5), W__NOTE(_GS5), H__NOTE(_FS4), H__NOTE(_FS4), H__NOTE(_GS4), H__NOTE(_FS4), \
    H__NOTE(_AS4), W__NOTE(_GS4), W__NOTE(_GS4), W__NOTE(_FS4), W__NOTE(_GS4), \
    H__NOTE(_AS4), WD_NOTE(_DS4)

#define RICK_ROLL      \
    Q__NOTE(_F4),      \
    Q__NOTE(_G4),      \
    Q__NOTE(_BF4),     \
    Q__NOTE(_G4),      \
    HD_NOTE(_D5),      \
    HD_NOTE(_D5),      \
    W__NOTE(_C5),      \
    S__NOTE(_REST),    \
    Q__NOTE(_F4),      \
    Q__NOTE(_G4),      \
    Q__NOTE(_BF4),     \
    Q__NOTE(_G4),      \
    HD_NOTE(_C5),      \
    HD_NOTE(_C5),      \
    W__NOTE(_BF4),     \
    S__NOTE(_REST),    \
    Q__NOTE(_F4),      \
    Q__NOTE(_G4),      \
    Q__NOTE(_BF4),     \
    Q__NOTE(_G4),      \
    W__NOTE(_BF4),     \
    H__NOTE(_C5),      \
    H__NOTE(_A4),      \
    H__NOTE(_A4),      \
    H__NOTE(_G4),      \
    H__NOTE(_F4),      \
    H__NOTE(_F4),      \
    W__NOTE(_C5),      \
    W__NOTE(_BF4),

/* Prelude music from Final Fantasy */
#define FF_PRELUDE \
  M__NOTE(_C3, 20), M__NOTE(_D3, 20), M__NOTE(_E3, 20), M__NOTE(_G3, 20), \
  M__NOTE(_C4, 20), M__NOTE(_D4, 20), M__NOTE(_E4, 20), M__NOTE(_G4, 20), \
  M__NOTE(_C5, 20), M__NOTE(_D5, 20), M__NOTE(_E5, 20), M__NOTE(_G5, 20), \
  M__NOTE(_C6, 20), M__NOTE(_D6, 20), M__NOTE(_E6, 20), M__NOTE(_G6, 20), \
  M__NOTE(_C7, 20), M__NOTE(_G6, 20), M__NOTE(_E6, 20), M__NOTE(_D6, 20), \
  M__NOTE(_C6, 20), M__NOTE(_G5, 20), M__NOTE(_E5, 20), M__NOTE(_D5, 20), \
  M__NOTE(_C5, 20), M__NOTE(_G4, 20), M__NOTE(_E4, 20), M__NOTE(_D4, 20), \
  M__NOTE(_C4, 20), M__NOTE(_G3, 20), M__NOTE(_E3, 20), M__NOTE(_D3, 20), \
  M__NOTE(_A2, 20), M__NOTE(_B2, 20), M__NOTE(_C3, 20), M__NOTE(_E3, 20), \
  M__NOTE(_A3, 20), M__NOTE(_B3, 20), M__NOTE(_C4, 20), M__NOTE(_E4, 20), \
  M__NOTE(_A4, 20), M__NOTE(_B4, 20), M__NOTE(_C5, 20), M__NOTE(_E5, 20), \
  M__NOTE(_A5, 20), M__NOTE(_B5, 20), M__NOTE(_C6, 20), M__NOTE(_E6, 20), \
  M__NOTE(_A6, 20), M__NOTE(_E6, 20), M__NOTE(_C6, 20), M__NOTE(_B5, 20), \
  M__NOTE(_A5, 20), M__NOTE(_E5, 20), M__NOTE(_C5, 20), M__NOTE(_B4, 20), \
  M__NOTE(_A4, 20), M__NOTE(_E4, 20), M__NOTE(_C4, 20), M__NOTE(_B3, 20), \
  M__NOTE(_A3, 20), M__NOTE(_E3, 20), M__NOTE(_C3, 20), M__NOTE(_B2, 20),

/* Melody from the main themes of Star Trek TNG and the original series */
#define TO_BOLDLY_GO \
  W__NOTE(_BF3 ), \
  Q__NOTE(_EF4 ), \
  WD_NOTE(_AF4 ), \
  W__NOTE(_REST), \
  H__NOTE(_G4  ), \
  Q__NOTE(_EF4 ), \
  H__NOTE(_C4  ), \
  W__NOTE(_REST), \
  QD_NOTE(_F4  ), \
  M__NOTE(_BF4, 128),

#define KATAWARE_DOKI \
  W__NOTE(_G5), HD_NOTE(_G5), Q__NOTE(_G5), H__NOTE(_G5), H__NOTE(_E5), H__NOTE(_D5), Q__NOTE(_D5), Q__NOTE(_C5), \
  B__NOTE(_E5), H__NOTE(_C5), W__NOTE(_G5), HD_NOTE(_G5), Q__NOTE(_C5), H__NOTE(_C6), Q__NOTE(_B5), \
  Q__NOTE(_A5), H__NOTE(_G5), Q__NOTE(_G5), Q__NOTE(_A5), W__NOTE(_G5), QD_NOTE(_E5), \
  QD_NOTE(_F5), Q__NOTE(_E5), WD_NOTE(_D5), H__NOTE(_C5), W__NOTE(_G5), HD_NOTE(_G5), Q__NOTE(_G5), \
  H__NOTE(_G5), H__NOTE(_E5), H__NOTE(_D5), Q__NOTE(_D5), Q__NOTE(_C5), B__NOTE(_E5), H__NOTE(_G4), \
  Q__NOTE(_C5), Q__NOTE(_D5), Q__NOTE(_E5), H__NOTE(_D5), Q__NOTE(_C5), Q__NOTE(_C5), \
  Q__NOTE(_A4), H__NOTE(_C5), Q__NOTE(_C5), W__NOTE(_C5), Q__NOTE(_F4), Q__NOTE(_C5), \
  Q__NOTE(_D5), Q__NOTE(_E5), H__NOTE(_D5), H__NOTE(_C5), Q__NOTE(_C5), H__NOTE(_G5), \
  Q__NOTE(_C5), HD_NOTE(_D5), H__NOTE(_G4), Q__NOTE(_C5), Q__NOTE(_D5), Q__NOTE(_E5), \
  H__NOTE(_D5), Q__NOTE(_C5), Q__NOTE(_C5), Q__NOTE(_A4), H__NOTE(_C5), Q__NOTE(_C5), \
  W__NOTE(_C5), Q__NOTE(_F4), Q__NOTE(_C5), Q__NOTE(_D5), Q__NOTE(_E5), H__NOTE(_D5), \
  H__NOTE(_C5), Q__NOTE(_C5), H__NOTE(_G5), Q__NOTE(_C5), HD_NOTE(_D5), \
  HD_NOTE(_G4), Q__NOTE(_C5), Q__NOTE(_D5), BD_NOTE(_C5), 
    
#define CAMPANELLA \
  Q__NOTE(_DS4), E__NOTE(_DS4), E__NOTE(_DS5), Q__NOTE(_DS5), E__NOTE(_DS5), E__NOTE(_DS6), Q__NOTE(_DS5), E__NOTE(_DS5), \
  E__NOTE(_DS6), Q__NOTE(_CS5), E__NOTE(_CS5), E__NOTE(_DS6), Q__NOTE(_B4), E__NOTE(_B4), E__NOTE(_DS6), \
  Q__NOTE(_B4), E__NOTE(_B4), E__NOTE(_DS6), Q__NOTE(_AS4), E__NOTE(_AS4), E__NOTE(_DS6), Q__NOTE(_GS4), \
  E__NOTE(_GS4), E__NOTE(_DS6), Q__NOTE(_G4), E__NOTE(_G4), E__NOTE(_DS6), Q__NOTE(_GS4), E__NOTE(_GS4), \
  E__NOTE(_DS6), Q__NOTE(_AS4), E__NOTE(_AS4), E__NOTE(_DS6), Q__NOTE(_DS4), E__NOTE(_DS4), E__NOTE(_DS6), \
  Q__NOTE(_DS5), E__NOTE(_DS5), E__NOTE(_DS6), Q__NOTE(_E5), E__NOTE(_E5), E__NOTE(_DS6), Q__NOTE(_DS5), \
  E__NOTE(_DS5), E__NOTE(_DS6), Q__NOTE(_CS5), E__NOTE(_CS5), E__NOTE(_DS6), Q__NOTE(_B4), E__NOTE(_B4), \
  E__NOTE(_DS6), Q__NOTE(_B4), E__NOTE(_B4), E__NOTE(_DS6), Q__NOTE(_AS4), E__NOTE(_AS4), E__NOTE(_DS6), \
  Q__NOTE(_GS4), E__NOTE(_GS4), E__NOTE(_DS6), Q__NOTE(_G4), E__NOTE(_G4), E__NOTE(_DS6), Q__NOTE(_GS4), \
  E__NOTE(_GS4), E__NOTE(_DS6), Q__NOTE(_AS4), E__NOTE(_AS4), E__NOTE(_DS6), Q__NOTE(_DS4), E__NOTE(_DS4), \
  E__NOTE(_DS5), Q__NOTE(_DS5), E__NOTE(_DS5), E__NOTE(_DS6), Q__NOTE(_DS6), E__NOTE(_DS6), E__NOTE(_DS7), \
  Q__NOTE(_DS6), E__NOTE(_DS6), E__NOTE(_DS7), Q__NOTE(_CS6), E__NOTE(_CS6), E__NOTE(_DS7), Q__NOTE(_B5), \
  E__NOTE(_B5), E__NOTE(_DS7), Q__NOTE(_B5), E__NOTE(_B5), E__NOTE(_DS7), Q__NOTE(_AS5), E__NOTE(_AS5), \
  E__NOTE(_DS7), Q__NOTE(_GS5), E__NOTE(_GS5), E__NOTE(_DS7), Q__NOTE(_G5), E__NOTE(_G5), E__NOTE(_DS7), \
  Q__NOTE(_GS5), E__NOTE(_GS5), E__NOTE(_DS7), Q__NOTE(_AS5), E__NOTE(_AS5), E__NOTE(_DS7), Q__NOTE(_DS5), \
  E__NOTE(_DS5), E__NOTE(_DS7), W__NOTE(_DS6), W__NOTE(_GS5), 

#define MEGALOVANIA \
  Q__NOTE(_D4), Q__NOTE(_D4), H__NOTE(_D5), HD_NOTE(_A4), H__NOTE(_AF4), H__NOTE(_G4), H__NOTE(_F4), \
  Q__NOTE(_D4), Q__NOTE(_F4), Q__NOTE(_G4), Q__NOTE(_C4), Q__NOTE(_C4), H__NOTE(_D5), HD_NOTE(_A4), \
  H__NOTE(_AF4), H__NOTE(_G4), H__NOTE(_F4), Q__NOTE(_D4), Q__NOTE(_F4), Q__NOTE(_G4), \
  Q__NOTE(_B3), Q__NOTE(_B3), H__NOTE(_D5), HD_NOTE(_A4), H__NOTE(_AF4), H__NOTE(_G4), H__NOTE(_F4), \
  Q__NOTE(_D4), Q__NOTE(_F4), Q__NOTE(_G4), Q__NOTE(_BF3), Q__NOTE(_BF3), H__NOTE(_D5), \
  HD_NOTE(_A4), H__NOTE(_AF4), H__NOTE(_G4), H__NOTE(_F4), Q__NOTE(_D4), Q__NOTE(_F4), \
  Q__NOTE(_G4),

#define MICHISHIRUBE \
  W__NOTE(_A5), H__NOTE(_A5), H__NOTE(_A5), W__NOTE(_B5), H__NOTE(_A5), H__NOTE(_B5), BD_NOTE(_CS6), W__NOTE(_E6), \
  W__NOTE(_CS6), WD_NOTE(_B5), H__NOTE(_A5), BD_NOTE(_A5), W__NOTE(_A5), H__NOTE(_A5), H__NOTE(_A5), \
  W__NOTE(_B5), H__NOTE(_A5), H__NOTE(_B5), W__NOTE(_A5), W__NOTE(_A6), W__NOTE(_GS6), H__NOTE(_CS6), \
  Q__NOTE(_E6), Q__NOTE(_CS6), W__NOTE(_B5), H__NOTE(_B5), H__NOTE(_CS6), W__NOTE(_B5), H__NOTE(_A5), \
  Q__NOTE(_B5), BD_NOTE(_A5), \
  H__NOTE(_E6), H__NOTE(_FS6), H__NOTE(_E6), H__NOTE(_B6), \
  W__NOTE(_A6), H__NOTE(_E6), H__NOTE(_B6), W__NOTE(_A6), H__NOTE(_A6), H__NOTE(_B6), \
  B__NOTE(_CS7), H__NOTE(_E6), H__NOTE(_FS6), H__NOTE(_E6), H__NOTE(_B6), W__NOTE(_A6), H__NOTE(_E6), \
  H__NOTE(_B6), W__NOTE(_A6), H__NOTE(_A6), H__NOTE(_GS6), B__NOTE(_E6), H__NOTE(_E6), \
  H__NOTE(_FS6), H__NOTE(_E6), H__NOTE(_B6), W__NOTE(_A6), H__NOTE(_E6), H__NOTE(_B6), \
  W__NOTE(_A6), H__NOTE(_A6), H__NOTE(_B6), H__NOTE(_CS7), B__NOTE(_CS7), H__NOTE(_E6), H__NOTE(_E6), \
  H__NOTE(_E6), H__NOTE(_E6), H__NOTE(_D6), H__NOTE(_D6), H__NOTE(_CS6), H__NOTE(_CS6), Q__NOTE(_B5), \
  BD_NOTE(_B5), W__NOTE(_A5), H__NOTE(_A5), H__NOTE(_A5), W__NOTE(_B5), H__NOTE(_A5), H__NOTE(_B5), \
  BD_NOTE(_CS6), W__NOTE(_E6), W__NOTE(_CS6), WD_NOTE(_B5), H__NOTE(_A5), BD_NOTE(_A5), W__NOTE(_A5), \
  H__NOTE(_A5), H__NOTE(_A5), W__NOTE(_B5), H__NOTE(_A5), H__NOTE(_B5), W__NOTE(_A5), W__NOTE(_A6), \
  W__NOTE(_GS6), H__NOTE(_CS6), Q__NOTE(_E6), Q__NOTE(_CS6), W__NOTE(_B5), H__NOTE(_B5), H__NOTE(_CS6), \
  W__NOTE(_B5), H__NOTE(_A5), Q__NOTE(_B5), BD_NOTE(_A5),
    
#define LIEBESLEID \
  Q__NOTE(_E4), Q__NOTE(_DS4), Q__NOTE(_E4), Q__NOTE(_F4), Q__NOTE(_E4), Q__NOTE(_FS4), Q__NOTE(_EF4), Q__NOTE(_G4), Q__NOTE(_D4), \
  Q__NOTE(_GS4), Q__NOTE(_CS4), W__NOTE(_A4), H__NOTE(_E5), H__NOTE(_E5), HD_NOTE(_G4), Q__NOTE(_E5), E__NOTE(_E5), \
  E__NOTE(_F5), ED_NOTE(_E5), HD_NOTE(_D5), Q__NOTE(_E5), H__NOTE(_F5), H__NOTE(_CS5), H__NOTE(_C5), W__NOTE(_G4), \
  H__NOTE(_D5), H__NOTE(_D5), HD_NOTE(_D5), Q__NOTE(_D5), E__NOTE(_D5), E__NOTE(_E5), E__NOTE(_D5), HD_NOTE(_C5), \
  Q__NOTE(_D5), H__NOTE(_E5), H__NOTE(_B4), H__NOTE(_BF4), W__NOTE(_F4), H__NOTE(_C5), H__NOTE(_C5), HD_NOTE(_EF4), \
  Q__NOTE(_C5), E__NOTE(_C5), E__NOTE(_D5), E__NOTE(_C5), HD_NOTE(_BF4), Q__NOTE(_C5), H__NOTE(_D5), H__NOTE(_FS4), \
  H__NOTE(_F4), HD_NOTE(_E4), Q__NOTE(_A4), HD_NOTE(_FS4), Q__NOTE(_A4), HD_NOTE(_GS4), Q__NOTE(_B4), Q__NOTE(_A4), \
  Q__NOTE(_E4), Q__NOTE(_DS4), Q__NOTE(_E4), Q__NOTE(_F4), Q__NOTE(_D4), Q__NOTE(_FS4), Q__NOTE(_CS4), Q__NOTE(_G4), \
  Q__NOTE(_C4), Q__NOTE(_GS4), Q__NOTE(_D4), WD_NOTE(_A4), 
    
#define MELODIES_OF_LIFE \
  H__NOTE(_B5), W__NOTE(_GS6), H__NOTE(_GS6), H__NOTE(_FS6), W__NOTE(_E6), H__NOTE(_E6), H__NOTE(_DS6), H__NOTE(_CS6), H__NOTE(_DS6), \
  H__NOTE(_E6), H__NOTE(_FS6), WD_NOTE(_B5), H__NOTE(_B5), H__NOTE(_CS6), H__NOTE(_DS6), H__NOTE(_E6), H__NOTE(_CS6), \
  H__NOTE(_CS6), H__NOTE(_B5), H__NOTE(_E6), H__NOTE(_GS6), H__NOTE(_A6), H__NOTE(_GS6), H__NOTE(_E6), H__NOTE(_GS6), \
  WD_NOTE(_FS6), H__NOTE(_GS6), WD_NOTE(_B6), H__NOTE(_CS7), H__NOTE(_B6), H__NOTE(_A6), H__NOTE(_A6), H__NOTE(_GS6), \
  H__NOTE(_GS6), H__NOTE(_FS6), H__NOTE(_FS6), H__NOTE(_GS6), WD_NOTE(_A6), Q__NOTE(_GS6), Q__NOTE(_FS6), Q__NOTE(_FS6), \
  Q__NOTE(_E6), W__NOTE(_E6), Q__NOTE(_B5), Q__NOTE(_CS6), WD_NOTE(_E6), Q__NOTE(_E6), Q__NOTE(_FS6), W__NOTE(_GS6), \
  H__NOTE(_A6), B__NOTE(_FS6), 

#define EYES_ON_ME \
  Q__NOTE(_A6), Q__NOTE(_G6), Q__NOTE(_FS6), Q__NOTE(_D6), Q__NOTE(_A5), Q__NOTE(_G5), Q__NOTE(_FS5), Q__NOTE(_D5), \
  W__NOTE(_A4), W__NOTE(_D5), W__NOTE(_E5), W__NOTE(_FS5), H__NOTE(_A5), M__NOTE(_FS5, 256), H__NOTE(_E5), \
  H__NOTE(_FS5), B__NOTE(_D5), H__NOTE(_B4), H__NOTE(_D5), BD_NOTE(_E5), H__NOTE(_A4), W__NOTE(_D5), W__NOTE(_E5), \
  W__NOTE(_FS5), H__NOTE(_A5), BD_NOTE(_CS6), W__NOTE(_A5), H__NOTE(_CS6), H__NOTE(_D6), WD_NOTE(_B5), \
  H__NOTE(_A5), H__NOTE(_B5), B__NOTE(_A5), WD_NOTE(_B4), W__NOTE(_CS5), WD_NOTE(_D6), H__NOTE(_D6), \
  W__NOTE(_CS6), H__NOTE(_B5), H__NOTE(_B5), H__NOTE(_B5), B__NOTE(_A5), H__NOTE(_A5), H__NOTE(_FS5), H__NOTE(_A5), \
  WD_NOTE(_B5), H__NOTE(_B5), H__NOTE(_A5), H__NOTE(_G5), H__NOTE(_D5), W__NOTE(_FS5), WD_NOTE(_E5), \
  H__NOTE(_CS4), H__NOTE(_E4), H__NOTE(_A4), H__NOTE(_CS5), W__NOTE(_D5), W__NOTE(_E5), W__NOTE(_FS5), H__NOTE(_G5), \
  H__NOTE(_A5), B__NOTE(_A5), H__NOTE(_A5), H__NOTE(_G5), H__NOTE(_D5), BD_NOTE(_FS5), W__NOTE(_E5), B__NOTE(_D5), \
  H__NOTE(_G4), H__NOTE(_FS4), W__NOTE(_E4), BD_NOTE(_D4),

#define SONG_OF_THE_ANCIENTS \
  H__NOTE(_D6), H__NOTE(_EF6), B__NOTE(_EF6), H__NOTE(_EF6), H__NOTE(_D6), H__NOTE(_BF5), H__NOTE(_G5), BD_NOTE(_C6), H__NOTE(_D6), \
  H__NOTE(_EF6), B__NOTE(_EF6), H__NOTE(_EF6), H__NOTE(_D6), H__NOTE(_BF5), H__NOTE(_G5), BD_NOTE(_G6), H__NOTE(_G5), \
  H__NOTE(_AF5), B__NOTE(_G6), H__NOTE(_AF6), H__NOTE(_G6), H__NOTE(_F6), H__NOTE(_D6), H__NOTE(_D6), H__NOTE(_EF6), \
  B__NOTE(_EF6), WD_NOTE(_G5), WD_NOTE(_BF5), H__NOTE(_D6), H__NOTE(_EF6), B__NOTE(_EF6), H__NOTE(_EF6), H__NOTE(_D6), \
  H__NOTE(_BF5), H__NOTE(_G5), BD_NOTE(_C6), WD_NOTE(_B5), WD_NOTE(_G5), WD_NOTE(_G6), W__NOTE(_G6), H__NOTE(_AF6), \
  W__NOTE(_G6), H__NOTE(_AF6), H__NOTE(_G6), H__NOTE(_F6), H__NOTE(_D6), H__NOTE(_D6), H__NOTE(_EF6), B__NOTE(_EF6), \
  WD_NOTE(_E6), H__NOTE(_E6), H__NOTE(_F6), H__NOTE(_G6), H__NOTE(_BF6), H__NOTE(_AF6), W__NOTE(_AF6), H__NOTE(_C6), \
  H__NOTE(_BF6), H__NOTE(_AF6), W__NOTE(_AF6), H__NOTE(_C6), H__NOTE(_AF6), BD_NOTE(_G6), WD_NOTE(_B5), WD_NOTE(_G6), \
  W__NOTE(_G6), H__NOTE(_AF6), W__NOTE(_G6), H__NOTE(_AF6), H__NOTE(_G6), H__NOTE(_F6), H__NOTE(_D6), H__NOTE(_D6), \
  H__NOTE(_EF6), B__NOTE(_EF6), WD_NOTE(_E6), H__NOTE(_E6), H__NOTE(_F6), H__NOTE(_G6), H__NOTE(_BF6), H__NOTE(_AF6), \
  W__NOTE(_AF6), H__NOTE(_C6), H__NOTE(_AF6), H__NOTE(_G6), W__NOTE(_G6), H__NOTE(_F6), H__NOTE(_D6), BD_NOTE(_EF6), \
  WD_NOTE(_F6), WD_NOTE(_G6), BD_NOTE(_C7), 

#define NIER_AMUSEMENT_PARK \
  H__NOTE(_D5), E__NOTE(_G6), E__NOTE(_GF6), Q__NOTE(_F6), Q__NOTE(_E6), Q__NOTE(_EF6), Q__NOTE(_DF6), Q__NOTE(_EF6), WD_NOTE(_D6), \
  Q__NOTE(_G5), Q__NOTE(_A5), H__NOTE(_BF5), H__NOTE(_D6), H__NOTE(_G6), H__NOTE(_A6), W__NOTE(_BF6), W__NOTE(_EF7), \
  H__NOTE(_D5), E__NOTE(_G6), E__NOTE(_GF6), Q__NOTE(_F6), Q__NOTE(_E6), Q__NOTE(_EF6), Q__NOTE(_DF6), Q__NOTE(_EF6), \
  WD_NOTE(_D6), Q__NOTE(_G5), Q__NOTE(_A5), H__NOTE(_BF5), H__NOTE(_D6), H__NOTE(_G6), H__NOTE(_A6), W__NOTE(_BF6), \
  H__NOTE(_EF7), H__NOTE(_D5), HD_NOTE(_A5), HD_NOTE(_BF5), B__NOTE(_D5), H__NOTE(_D5), HD_NOTE(_G5), HD_NOTE(_F5), \
  H__NOTE(_EF5), WD_NOTE(_D5), H__NOTE(_D5), HD_NOTE(_A5), HD_NOTE(_BF5), WD_NOTE(_D5), W__NOTE(_D5), B__NOTE(_G5), \
  H__NOTE(_D5), HD_NOTE(_A5), HD_NOTE(_BF5), B__NOTE(_D5), H__NOTE(_D5), HD_NOTE(_G5), HD_NOTE(_F5), H__NOTE(_EF5), \
  W__NOTE(_D5), W__NOTE(_C5), W__NOTE(_BF4), W__NOTE(_C5), W__NOTE(_D5), W__NOTE(_G5), B__NOTE(_D5), B__NOTE(_E5), \
  W__NOTE(_EF5), QD_NOTE(_C5), QD_NOTE(_D5), Q__NOTE(_EF5), H__NOTE(_G5), H__NOTE(_F5), H__NOTE(_EF5), H__NOTE(_F5), \
  B__NOTE(_D5), B__NOTE(_BF4), W__NOTE(_EF5), QD_NOTE(_C5), QD_NOTE(_D5), Q__NOTE(_EF5), H__NOTE(_G5), H__NOTE(_F5), \
  H__NOTE(_EF5), H__NOTE(_F5), W__NOTE(_D5), W__NOTE(_BF5), W__NOTE(_G5), W__NOTE(_D5), W__NOTE(_EF5), QD_NOTE(_C5), \
  QD_NOTE(_D5), Q__NOTE(_EF5), H__NOTE(_G5), H__NOTE(_F5), H__NOTE(_EF5), H__NOTE(_F5), B__NOTE(_D5), B__NOTE(_BF4), \
  B__NOTE(_C5), H__NOTE(_C5), H__NOTE(_D5), H__NOTE(_EF5), H__NOTE(_F5), WD_NOTE(_G5), H__NOTE(_C5), W__NOTE(_AF5), \
  WD_NOTE(_G5), 

#define COPIED_CITY \
  Q__NOTE(_F6), Q__NOTE(_BF5), Q__NOTE(_EF6), Q__NOTE(_G5), Q__NOTE(_AF5), Q__NOTE(_G6), Q__NOTE(_AF6), Q__NOTE(_EF6), Q__NOTE(_BF5), \
  Q__NOTE(_F6), Q__NOTE(_G5), Q__NOTE(_AF5), Q__NOTE(_EF6), Q__NOTE(_G5), Q__NOTE(_F5), Q__NOTE(_D6), Q__NOTE(_C6), \
  Q__NOTE(_G5), Q__NOTE(_BF5), Q__NOTE(_EF5), Q__NOTE(_AF5), Q__NOTE(_G5), Q__NOTE(_EF5), Q__NOTE(_BF4), H__NOTE(_C5), \
  Q__NOTE(_F5), Q__NOTE(_G5), Q__NOTE(_AF5), Q__NOTE(_EF6), Q__NOTE(_BF5), Q__NOTE(_G6), Q__NOTE(_EF6), Q__NOTE(_BF6), \
  Q__NOTE(_AF6), Q__NOTE(_EF6), Q__NOTE(_BF5), Q__NOTE(_F6), Q__NOTE(_G5), Q__NOTE(_F5), Q__NOTE(_EF6), Q__NOTE(_BF5), \
  Q__NOTE(_B6), Q__NOTE(_DF6), Q__NOTE(_EF6), Q__NOTE(_F6), Q__NOTE(_AF6), Q__NOTE(_EF7), Q__NOTE(_F6), Q__NOTE(_C6), \
  Q__NOTE(_G5), Q__NOTE(_AF5), Q__NOTE(_BF5), Q__NOTE(_C6), Q__NOTE(_EF6), Q__NOTE(_G5), Q__NOTE(_EF5), Q__NOTE(_F5), \
  Q__NOTE(_G5), Q__NOTE(_EF5), Q__NOTE(_F5), Q__NOTE(_C5), Q__NOTE(_EF5), Q__NOTE(_C5), Q__NOTE(_BF4), Q__NOTE(_G4), \
  Q__NOTE(_F4), Q__NOTE(_G4), H__NOTE(_AF4), Q__NOTE(_C5), Q__NOTE(_EF5), Q__NOTE(_F5), Q__NOTE(_C5), Q__NOTE(_EF5), \
  Q__NOTE(_F5), Q__NOTE(_G5), Q__NOTE(_BF5), Q__NOTE(_AF5), Q__NOTE(_G5), Q__NOTE(_EF5), Q__NOTE(_F5), Q__NOTE(_C5), \
  Q__NOTE(_AF4), Q__NOTE(_F5), Q__NOTE(_G5), Q__NOTE(_AF5), Q__NOTE(_G5), Q__NOTE(_F5), Q__NOTE(_EF5), Q__NOTE(_F5), \
  Q__NOTE(_G5), Q__NOTE(_BF5), Q__NOTE(_C6), Q__NOTE(_G6), Q__NOTE(_EF6), WD_NOTE(_F7), 

#define VAGUE_HOPE_COLD_RAIN \
  HD_NOTE(_D6), HD_NOTE(_E6), HD_NOTE(_CS6), HD_NOTE(_D6), HD_NOTE(_B5), Q__NOTE(_B5), Q__NOTE(_CS6), Q__NOTE(_D6), WD_NOTE(_A6), \
  HD_NOTE(_FS6), HD_NOTE(_G6), HD_NOTE(_D6), HD_NOTE(_E6), HD_NOTE(_FS6), Q__NOTE(_D5), Q__NOTE(_CS5), Q__NOTE(_A4), \
  W__NOTE(_FS4), H__NOTE(_D6), HD_NOTE(_E6), HD_NOTE(_FS6), HD_NOTE(_CS6), HD_NOTE(_E6), HD_NOTE(_D6), Q__NOTE(_CS6), \
  Q__NOTE(_D6), Q__NOTE(_E6), W__NOTE(_FS6), H__NOTE(_CS6), WD_NOTE(_D6), HD_NOTE(_D6), Q__NOTE(_D6), H__NOTE(_E6), \
  WD_NOTE(_CS6), HD_NOTE(_AS5), HD_NOTE(_B5), HD_NOTE(_B5), Q__NOTE(_B4), Q__NOTE(_CS5), Q__NOTE(_D5), HD_NOTE(_A5), \
  Q__NOTE(_B5), Q__NOTE(_CS6), Q__NOTE(_A6), HD_NOTE(_FS6), Q__NOTE(_D5), Q__NOTE(_CS5), Q__NOTE(_A4), H__NOTE(_FS4), \
  HD_NOTE(_FS6), HD_NOTE(_D6), HD_NOTE(_E6), HD_NOTE(_A6), HD_NOTE(_FS6), Q__NOTE(_CS5), Q__NOTE(_D5), Q__NOTE(_A5), \
  HD_NOTE(_FS5), Q__NOTE(_FS6), Q__NOTE(_FS6), Q__NOTE(_GS6), HD_NOTE(_A6), Q__NOTE(_B6), H__NOTE(_A6), H__NOTE(_GS6), \
  H__NOTE(_FS6), H__NOTE(_E6), H__NOTE(_CS6), H__NOTE(_FS6), E__NOTE(_FS5), E__NOTE(_CS5), Q__NOTE(_B4), H__NOTE(_AS4), \
  W__NOTE(_FS5), HD_NOTE(_FS6), HD_NOTE(_B5), H__NOTE(_D6), H__NOTE(_CS6), H__NOTE(_E6), HD_NOTE(_A6), HD_NOTE(_E6), \
  W__NOTE(_D6), Q__NOTE(_CS6), Q__NOTE(_D6), HD_NOTE(_E6), HD_NOTE(_FS6), WD_NOTE(_B6), HD_NOTE(_E6), HD_NOTE(_FS6), \
  HD_NOTE(_B5), Q__NOTE(_B5), Q__NOTE(_B5), Q__NOTE(_CS6), H__NOTE(_D6), H__NOTE(_E6), H__NOTE(_FS6), HD_NOTE(_E6), \
  HD_NOTE(_CS6), H__NOTE(_FS6), H__NOTE(_A6), H__NOTE(_B6), W__NOTE(_A6), H__NOTE(_FS6), BD_NOTE(_B6), 

#define KAINE_SALVATION \
  BD_NOTE(_D5), W__NOTE(_BF4), W__NOTE(_C5), W__NOTE(_F5), BD_NOTE(_D5), BD_NOTE(_BF4), BD_NOTE(_C5), W__NOTE(_BF4), W__NOTE(_C5), \
  W__NOTE(_D5), BD_NOTE(_C5), BD_NOTE(_F4), BD_NOTE(_D5), W__NOTE(_BF4), W__NOTE(_C5), W__NOTE(_F5), BD_NOTE(_D5), \
  BD_NOTE(_BF4), WD_NOTE(_EF5), WD_NOTE(_BF4), W__NOTE(_A4), W__NOTE(_BF4), W__NOTE(_C5), B__NOTE(_C5), H__NOTE(_B4), \
  H__NOTE(_C5), BD_NOTE(_D5), WD_NOTE(_G5), W__NOTE(_G5), H__NOTE(_FS5), H__NOTE(_G5), H__NOTE(_A5), H__NOTE(_B5), \
  H__NOTE(_A5), H__NOTE(_G5), H__NOTE(_FS5), WD_NOTE(_G5), W__NOTE(_G5), H__NOTE(_D6), H__NOTE(_C6), H__NOTE(_B5), \
  H__NOTE(_A5), WD_NOTE(_G5), WD_NOTE(_G5), W__NOTE(_G5), H__NOTE(_FS5), H__NOTE(_G5), H__NOTE(_A5), H__NOTE(_B5), \
  H__NOTE(_A5), H__NOTE(_G5), H__NOTE(_FS5), W__NOTE(_G5), H__NOTE(_B5), H__NOTE(_A5), H__NOTE(_G5), H__NOTE(_FS5), \
  BD_NOTE(_E5), WD_NOTE(_G5), W__NOTE(_G5), H__NOTE(_FS5), H__NOTE(_G5), H__NOTE(_A5), H__NOTE(_B5), H__NOTE(_A5), \
  H__NOTE(_G5), H__NOTE(_FS5), WD_NOTE(_G5), W__NOTE(_G5), H__NOTE(_D6), H__NOTE(_C6), H__NOTE(_B5), H__NOTE(_A5), \
  WD_NOTE(_G5), WD_NOTE(_G5), W__NOTE(_G5), H__NOTE(_FS5), H__NOTE(_G5), H__NOTE(_A5), H__NOTE(_B5), H__NOTE(_A5), \
  H__NOTE(_G5), H__NOTE(_FS5), W__NOTE(_G5), H__NOTE(_D6), WD_NOTE(_D6), W__NOTE(_F5), H__NOTE(_C6), H__NOTE(_C6), \
  H__NOTE(_BF5), H__NOTE(_A5), WD_NOTE(_G5), WD_NOTE(_F5), WD_NOTE(_G5), WD_NOTE(_A5), BD_NOTE(_G5),

#define WEIGHT_OF_THE_WORLD \
  H__NOTE(_B5), Q__NOTE(_C6), Q__NOTE(_C6), Q__NOTE(_B5), H__NOTE(_C6), H__NOTE(_G6), WD_NOTE(_G6), H__NOTE(_B5), Q__NOTE(_C6), \
  Q__NOTE(_C6), Q__NOTE(_B5), H__NOTE(_C6), H__NOTE(_G6), H__NOTE(_G6), Q__NOTE(_A6), W__NOTE(_G6), Q__NOTE(_C6), \
  Q__NOTE(_D6), H__NOTE(_E6), Q__NOTE(_F6), H__NOTE(_E6), H__NOTE(_F6), HD_NOTE(_E6), H__NOTE(_D6), H__NOTE(_C6), \
  H__NOTE(_D6), WD_NOTE(_D6), Q__NOTE(_C6), Q__NOTE(_B5), WD_NOTE(_B5), H__NOTE(_B5), Q__NOTE(_C6), Q__NOTE(_C6), \
  Q__NOTE(_B5), H__NOTE(_C6), H__NOTE(_G6), WD_NOTE(_G6), H__NOTE(_B5), Q__NOTE(_C6), Q__NOTE(_C6), Q__NOTE(_B5), \
  H__NOTE(_C6), H__NOTE(_G6), H__NOTE(_G6), Q__NOTE(_A6), W__NOTE(_G6), Q__NOTE(_C6), Q__NOTE(_D6), H__NOTE(_E6), \
  Q__NOTE(_F6), H__NOTE(_E6), H__NOTE(_F6), HD_NOTE(_E6), H__NOTE(_D6), H__NOTE(_C6), H__NOTE(_D6), BD_NOTE(_D6), \
  Q__NOTE(_E6), Q__NOTE(_D6), Q__NOTE(_C6), Q__NOTE(_B5), H__NOTE(_C6), Q__NOTE(_C6), H__NOTE(_C6), HD_NOTE(_C6), \
  H__NOTE(_B5), H__NOTE(_C6), H__NOTE(_E6), H__NOTE(_G6), WD_NOTE(_G6), Q__NOTE(_C6), B__NOTE(_C6), H__NOTE(_B6), \
  Q__NOTE(_C7), BD_NOTE(_C7), 

#define ISABELLAS_LULLABY \
  W__NOTE(_BF4), B__NOTE(_D5), W__NOTE(_EF5), B__NOTE(_F5), W__NOTE(_BF5), B__NOTE(_AF5), W__NOTE(_GF5), BD_NOTE(_F5), B__NOTE(_CS5), \
  W__NOTE(_F5), B__NOTE(_C5), W__NOTE(_EF5), BD_NOTE(_BF4), W__NOTE(_AF4), W__NOTE(_BF4), W__NOTE(_F5), W__NOTE(_GF5), \
  WD_NOTE(_AF5), H__NOTE(_FS5), W__NOTE(_F5), B__NOTE(_EF5), W__NOTE(_C6), B__NOTE(_AF5), W__NOTE(_F5), WD_NOTE(_AF5), \
  H__NOTE(_BF5), W__NOTE(_F5), WD_NOTE(_AF5), H__NOTE(_BF5), W__NOTE(_F5), W__NOTE(_EF5), W__NOTE(_BF4), W__NOTE(_AF5), \
  WD_NOTE(_F5), H__NOTE(_F5), H__NOTE(_BF5), H__NOTE(_C6), WD_NOTE(_CS6), H__NOTE(_C6), W__NOTE(_BF5), W__NOTE(_AF5), \
  W__NOTE(_F5), W__NOTE(_EF5), WD_NOTE(_EF5), H__NOTE(_DF5), W__NOTE(_AF5), BD_NOTE(_F5), WD_NOTE(_BF4), H__NOTE(_C5), \
  W__NOTE(_CS5), W__NOTE(_EF5), W__NOTE(_AF4), W__NOTE(_EF5), WD_NOTE(_GF5), H__NOTE(_F5), W__NOTE(_EF5), WD_NOTE(_F5), \
  H__NOTE(_F5), H__NOTE(_BF5), H__NOTE(_C6), WD_NOTE(_CS6), H__NOTE(_C6), W__NOTE(_CS6), W__NOTE(_EF6), W__NOTE(_AF5), \
  W__NOTE(_EF6), WD_NOTE(_GF6), H__NOTE(_F6), W__NOTE(_EF6), B__NOTE(_DF6), H__NOTE(_GF6), H__NOTE(_AF6), BD_NOTE(_DF6), \
  B__NOTE(_BF5), W__NOTE(_F6), BD_NOTE(_C6), W__NOTE(_AF5), WD_NOTE(_EF6), H__NOTE(_DF6), W__NOTE(_C6), B__NOTE(_BF5),

#define FANTASIE_IMPROMPTU \
  E__NOTE(_GS4), E__NOTE(_A4), E__NOTE(_GS4), E__NOTE(_REST), E__NOTE(_GS4), E__NOTE(_CS5), E__NOTE(_E5), E__NOTE(_DS5), E__NOTE(_CS5), \
  E__NOTE(_DS5), E__NOTE(_CS5), E__NOTE(_C5), E__NOTE(_CS5), E__NOTE(_E5), E__NOTE(_GS5), E__NOTE(_GS4), E__NOTE(_A4), \
  E__NOTE(_GS4), E__NOTE(_REST), E__NOTE(_GS4), E__NOTE(_CS5), E__NOTE(_E5), E__NOTE(_DS5), E__NOTE(_CS5), E__NOTE(_DS5), \
  E__NOTE(_CS5), E__NOTE(_C5), E__NOTE(_CS5), E__NOTE(_E5), E__NOTE(_GS5), E__NOTE(_A4), E__NOTE(_CS5), E__NOTE(_DS5), \
  E__NOTE(_FS5), E__NOTE(_A5), E__NOTE(_CS6), E__NOTE(_DS6), E__NOTE(_B6), E__NOTE(_A6), E__NOTE(_GS6), E__NOTE(_FS6), \
  E__NOTE(_E6), E__NOTE(_DS6), E__NOTE(_FS6), E__NOTE(_CS6), E__NOTE(_C5), E__NOTE(_DS6), E__NOTE(_A5), E__NOTE(_GS5), \
  E__NOTE(_FS5), E__NOTE(_A5), E__NOTE(_E5), E__NOTE(_DS5), E__NOTE(_FS5), E__NOTE(_CS5), E__NOTE(_C5), E__NOTE(_DS5), \
  E__NOTE(_A4), E__NOTE(_GS4), E__NOTE(_B4), E__NOTE(_A4), E__NOTE(_A4), E__NOTE(_GS4), E__NOTE(_A4), E__NOTE(_GS4), \
  E__NOTE(_REST), E__NOTE(_GS4), E__NOTE(_CS5), E__NOTE(_E5), E__NOTE(_DS5), E__NOTE(_CS5), E__NOTE(_DS5), E__NOTE(_CS5), \
  E__NOTE(_C5), E__NOTE(_CS5), E__NOTE(_E5), E__NOTE(_GS5), E__NOTE(_GS4), E__NOTE(_AS4), E__NOTE(_GS4), E__NOTE(_REST), \
  E__NOTE(_GS4), E__NOTE(_CS5), E__NOTE(_E5), E__NOTE(_DS5), E__NOTE(_CS5), E__NOTE(_DS5), E__NOTE(_CS5), E__NOTE(_C5), \
  E__NOTE(_CS5), E__NOTE(_E5), E__NOTE(_GS5), E__NOTE(_DS5), E__NOTE(_E5), E__NOTE(_DS5), E__NOTE(_REST), E__NOTE(_DS5), \
  E__NOTE(_B5), E__NOTE(_AS5), E__NOTE(_GS5), E__NOTE(_REST), E__NOTE(_E6), E__NOTE(_DS6), E__NOTE(_CS6), E__NOTE(_B5), \
  E__NOTE(_AS5), E__NOTE(_GS5), E__NOTE(_REST), E__NOTE(_AS5), WD_NOTE(_GS5), 

#define TERRAS_THEME \
  Q__NOTE(_GS5), Q__NOTE(_AS5), Q__NOTE(_B5), Q__NOTE(_EF6), BD_NOTE(_B5), Q__NOTE(_AS5), Q__NOTE(_GS5), W__NOTE(_AS5), \
  BD_NOTE(_DS5), Q__NOTE(_AF5), Q__NOTE(_BF5), Q__NOTE(_B5), Q__NOTE(_DS6), BD_NOTE(_B5), \
  Q__NOTE(_BF5), Q__NOTE(_AF5), W__NOTE(_AS5), BD_NOTE(_DS6), Q__NOTE(_B5), Q__NOTE(_CS6), Q__NOTE(_DS6), \
  Q__NOTE(_FS6), BD_NOTE(_DS6), Q__NOTE(_CS6), Q__NOTE(_B5), W__NOTE(_CS6), BD_NOTE(_FS5), \
  Q__NOTE(_B5), Q__NOTE(_AS5), BD_NOTE(_GS5), Q__NOTE(_B5), Q__NOTE(_AS5), BD_NOTE(_GS5),

#define RENAI_CIRCULATION \
  Q__NOTE(_E6), Q__NOTE(_B5), HD_NOTE(_CS6), HD_NOTE(_CS6), H__NOTE(_B5), HD_NOTE(_E6), HD_NOTE(_E6), Q__NOTE(_E6), Q__NOTE(_B5), \
  HD_NOTE(_CS6), HD_NOTE(_CS6), H__NOTE(_B5), HD_NOTE(_E6), HD_NOTE(_GS6), Q__NOTE(_E6), Q__NOTE(_B5), HD_NOTE(_CS6), \
  H__NOTE(_CS6), Q__NOTE(_CS6), H__NOTE(_B5), HD_NOTE(_E6), H__NOTE(_E6), Q__NOTE(_E6), H__NOTE(_FS6), HD_NOTE(_E6), \
  H__NOTE(_E6), Q__NOTE(_E6), H__NOTE(_CS6), WD_NOTE(_GS6), HD_NOTE(_E6), H__NOTE(_E6), Q__NOTE(_FS6), H__NOTE(_G6), \
  HD_NOTE(_GS6), HD_NOTE(_E6), Q__NOTE(_B5), Q__NOTE(_CS6), HD_NOTE(_E6), H__NOTE(_E6), Q__NOTE(_FS6), H__NOTE(_G6), \
  HD_NOTE(_GS6), HD_NOTE(_E6), H__NOTE(_CS6), H__NOTE(_E6), Q__NOTE(_CS6), HD_NOTE(_E6), H__NOTE(_CS6), H__NOTE(_E6), \
  Q__NOTE(_CS6), HD_NOTE(_E6), H__NOTE(_E6), Q__NOTE(_A6), H__NOTE(_GS6), HD_NOTE(_E6), H__NOTE(_FS6), WD_NOTE(_E6), \
  H__NOTE(_GS6), H__NOTE(_A6), H__NOTE(_GS6), H__NOTE(_A6), W__NOTE(_B6), H__NOTE(_GS6), H__NOTE(_A6), H__NOTE(_GS6), \
  H__NOTE(_A6), W__NOTE(_B6), H__NOTE(_B6), H__NOTE(_A6), H__NOTE(_GS6), H__NOTE(_A6), Q__NOTE(_GS6), H__NOTE(_E6), \
  H__NOTE(_E6), Q__NOTE(_E6), H__NOTE(_CS6), Q__NOTE(_GS6), H__NOTE(_E6), H__NOTE(_E6), Q__NOTE(_E6), H__NOTE(_CS6), \
  Q__NOTE(_E6), H__NOTE(_E6), H__NOTE(_E6), Q__NOTE(_E6), H__NOTE(_FS6), WD_NOTE(_E6), W__NOTE(_B6), W__NOTE(_GS6), \
  W__NOTE(_FS6), H__NOTE(_GS6), H__NOTE(_GS6), H__NOTE(_FS6), H__NOTE(_E6), H__NOTE(_FS6), B__NOTE(_GS6), H__NOTE(_GS6), \
  W__NOTE(_CS7), W__NOTE(_GS6), W__NOTE(_E6), H__NOTE(_GS6), H__NOTE(_GS6), HD_NOTE(_E6), H__NOTE(_E6), Q__NOTE(_E6), \
  H__NOTE(_FS6), WD_NOTE(_E6), 

#define PLATINUM_DISCO \
  H__NOTE(_DS6), H__NOTE(_FS6), H__NOTE(_GS6), H__NOTE(_AS6), H__NOTE(_DS6), H__NOTE(_FS6), W__NOTE(_GS6), H__NOTE(_DS6), H__NOTE(_FS6), \
  H__NOTE(_GS6), H__NOTE(_AS6), H__NOTE(_CS6), H__NOTE(_FS6), WD_NOTE(_FS6), H__NOTE(_CS6), W__NOTE(_DS6), H__NOTE(_FS6), \
  H__NOTE(_AS6), W__NOTE(_GS6), H__NOTE(_FS6), H__NOTE(_GS6), Q__NOTE(_AS6), Q__NOTE(_CS7), Q__NOTE(_GS6), Q__NOTE(_AS6), \
  Q__NOTE(_FS6), Q__NOTE(_GS6), Q__NOTE(_DS6), Q__NOTE(_FS6), Q__NOTE(_CS6), Q__NOTE(_DS6), Q__NOTE(_AS5), Q__NOTE(_CS6), \
  H__NOTE(_DS6), H__NOTE(_FS6), H__NOTE(_GS6), H__NOTE(_AS6), H__NOTE(_DS6), H__NOTE(_FS6), W__NOTE(_GS6), H__NOTE(_DS6), \
  H__NOTE(_FS6), H__NOTE(_GS6), H__NOTE(_AS6), H__NOTE(_CS7), H__NOTE(_GS6), WD_NOTE(_FS6), H__NOTE(_CS6), W__NOTE(_DS6), \
  H__NOTE(_FS6), H__NOTE(_AS6), WD_NOTE(_GS6), H__NOTE(_FS6), Q__NOTE(_FS6), Q__NOTE(_GS5), Q__NOTE(_AS5), Q__NOTE(_CS6), \
  Q__NOTE(_FS6), Q__NOTE(_GS6), Q__NOTE(_AS6), Q__NOTE(_CS7), WD_NOTE(_FS7), H__NOTE(_CS6), WD_NOTE(_DS6), H__NOTE(_CS6), \
  WD_NOTE(_DS6), H__NOTE(_CS6), H__NOTE(_DS6), H__NOTE(_FS6), H__NOTE(_GS6), H__NOTE(_AS6), WD_NOTE(_GS6), H__NOTE(_FS6), \
  WD_NOTE(_GS6), H__NOTE(_FS6), WD_NOTE(_GS6), H__NOTE(_FS6), H__NOTE(_GS6), H__NOTE(_AS6), H__NOTE(_DS6), H__NOTE(_FS6), \
  WD_NOTE(_FS6), H__NOTE(_CS6), WD_NOTE(_DS6), H__NOTE(_CS6), WD_NOTE(_DS6), H__NOTE(_CS6), H__NOTE(_DS6), H__NOTE(_FS6), \
  H__NOTE(_GS6), H__NOTE(_AS6), H__NOTE(_CS7), H__NOTE(_AS6), H__NOTE(_GS6), H__NOTE(_FS6), H__NOTE(_DS6), W__NOTE(_FS6), \
  H__NOTE(_CS6), H__NOTE(_DS6), W__NOTE(_FS6), H__NOTE(_FS6), H__NOTE(_GS6), H__NOTE(_FS6), H__NOTE(_GS6), H__NOTE(_FS6), \
  B__NOTE(_FS6), 

#define NOCTURNE_OP_9_NO_1 \
  H__NOTE(_BF5), H__NOTE(_C6), H__NOTE(_DF6), H__NOTE(_A5), H__NOTE(_BF5), H__NOTE(_GF5), W__NOTE(_F5), W__NOTE(_F5), W__NOTE(_F5), \
  W__NOTE(_F5), H__NOTE(_GF5), H__NOTE(_F5), H__NOTE(_EF5), H__NOTE(_C5), B__NOTE(_DF5), W__NOTE(_BF4), Q__NOTE(_BF5), \
  Q__NOTE(_C6), Q__NOTE(_DF6), Q__NOTE(_A5), Q__NOTE(_BF5), Q__NOTE(_A5), Q__NOTE(_GS5), Q__NOTE(_A5), Q__NOTE(_C6), \
  Q__NOTE(_BF5), Q__NOTE(_GF5), Q__NOTE(_F5), Q__NOTE(_GF5), Q__NOTE(_E5), Q__NOTE(_F5), Q__NOTE(_BF5), Q__NOTE(_A5), \
  Q__NOTE(_AF5), Q__NOTE(_G5), Q__NOTE(_GF5), Q__NOTE(_F5), Q__NOTE(_E5), Q__NOTE(_EF5), Q__NOTE(_D5), Q__NOTE(_DF5), \
  Q__NOTE(_C5), Q__NOTE(_DF5), Q__NOTE(_C5), Q__NOTE(_B4), Q__NOTE(_C5), Q__NOTE(_F5), Q__NOTE(_E5), Q__NOTE(_EF5), \
  B__NOTE(_DF5), W__NOTE(_BF4), W__NOTE(_BF5), W__NOTE(_BF5), W__NOTE(_BF5), BD_NOTE(_AF5), W__NOTE(_DF5), H__NOTE(_BF4), \
  H__NOTE(_C5), H__NOTE(_DF5), H__NOTE(_GF5), H__NOTE(_GF5), BD_NOTE(_F5), W__NOTE(_EF5), H__NOTE(_F5), H__NOTE(_EF5), \
  H__NOTE(_DF5), H__NOTE(_A4), B__NOTE(_AF4), W__NOTE(_DF5), W__NOTE(_EF5), H__NOTE(_F5), H__NOTE(_EF5), H__NOTE(_DF5), \
  H__NOTE(_EF5), BD_NOTE(_F5), 

#endif
