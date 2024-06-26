/***********************************************************************
 Freeciv - Copyright (C) 1996 - A Kjeldberg, L Gregersen, P Unold
   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
***********************************************************************/

/***********************************************************************
                          colors.h  -  description
                             -------------------
    begin                : Mon Jul 15 2002
    copyright            : (C) 2002 by Rafał Bursig
    email                : Rafał Bursig <bursig@poczta.fm>
***********************************************************************/

#ifndef FC__COLORS_H
#define FC__COLORS_H

/* SDL3 */
#include <SDL3/SDL.h>

/* client */
#include "colors_g.h"

/* gui-sdl3 */
#include "themecolors.h"

struct color {
  SDL_Color *color;
};

struct color *color_alloc_rgba(int r, int g, int b, int a);
SDL_Color *get_theme_color(enum theme_color themecolor);
SDL_Color *get_game_color(enum color_std stdcolor);

#endif	/* FC__COLORS_H */
