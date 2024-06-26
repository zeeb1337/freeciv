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
                          citydlg.h  -  description
                             -------------------
    begin                : Wed Sep 04 2002
    copyright            : (C) 2002 by Rafał Bursig
    email                : Rafał Bursig <bursig@poczta.fm>
***********************************************************************/

#ifndef FC__CITYDLG_H
#define FC__CITYDLG_H

/* SDL3 */
#include <SDL3/SDL.h>

/* common */
#include "effects.h"

/* client */
#include "citydlg_g.h"


void free_city_units_lists(void);
void enable_city_dlg_widgets(void);
void popup_hurry_production_dialog(struct city *pcity, SDL_Surface *pdest);
SDL_Surface *get_scaled_city_map(struct city *pcity);
void refresh_city_resource_map(SDL_Surface *pdest, int x, int y,
                               const struct city *pcity,
                               bool (*worker_check) (const struct city *,
                                                     int, int));
struct impr_type *get_building_for_effect(enum effect_type effect_type);

#endif	/* FC__CITYDLG_H */
