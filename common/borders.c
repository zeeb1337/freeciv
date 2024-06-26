/****************************************************************************
 Freeciv - Copyright (C) 2004 - The Freeciv Team
   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
****************************************************************************/

#ifdef HAVE_CONFIG_H
#include <fc_config.h>
#endif

/* utility */
#include "fcintl.h"
#include "log.h"

/* common */
#include "game.h"
#include "map.h"
#include "tile.h"
#include "unit.h"

#include "borders.h"

/*********************************************************************//**
  Border radius sq from given border source tile.
*************************************************************************/
int tile_border_source_radius_sq(struct tile *ptile)
{
  struct city *pcity;
  int radius_sq = 0;

  if (BORDERS_DISABLED == game.info.borders) {
    return 0;
  }

  pcity = tile_city(ptile);

  if (pcity) {
    radius_sq = game.info.border_city_radius_sq;
    /* Limit the addition due to the city size. A city size of 60 or more is
     * possible with a city radius of 5 (radius_sq = 26). */
    radius_sq += MIN(city_size_get(pcity), CITY_MAP_MAX_RADIUS_SQ)
                 * game.info.border_size_effect;
  } else {
    struct extra_type_list *terr_claimers = extra_type_list_of_terr_claimers();

    extra_type_list_iterate(terr_claimers, pextra) {
      if (tile_has_extra(ptile, pextra)) {
        struct base_type *pbase = extra_base_get(pextra);

        radius_sq = pbase->border_sq;
        break;
      }
    } extra_type_list_iterate_end;
  }

  return radius_sq;
}

/*********************************************************************//**
  Border source strength
*************************************************************************/
int tile_border_source_strength(struct tile *ptile)
{
  struct city *pcity;
  int strength = 0;

  if (BORDERS_DISABLED == game.info.borders) {
    return 0;
  }

  pcity = tile_city(ptile);

  if (pcity) {
    strength = (city_size_get(pcity) + 2)
      * (100 + get_city_bonus(pcity, EFT_BORDER_STRENGTH_PCT)) / 100;
  } else {
    struct extra_type_list *terr_claimers = extra_type_list_of_terr_claimers();

    extra_type_list_iterate(terr_claimers, pextra) {
      if (tile_has_extra(ptile, pextra)) {
        /* Base strength 100 / 100 = 1 */
        strength = (100 + get_tile_bonus(ptile, EFT_BORDER_STRENGTH_PCT)) / 100;
        break;
      }
    } extra_type_list_iterate_end;
  }

  return strength;
}

/*********************************************************************//**
  Border source strength at tile
*************************************************************************/
int tile_border_strength(struct tile *ptile, struct tile *source)
{
  int full_strength = tile_border_source_strength(source);
  int sq_dist = sq_map_distance(ptile, source);

  if (sq_dist > 0) {
    return full_strength * full_strength / sq_dist;
  } else {
    return FC_INFINITY;
  }
}

/*********************************************************************//**
  Is given tile source to borders.
*************************************************************************/
bool is_border_source(struct tile *ptile)
{
  if (tile_city(ptile)) {
    return TRUE;
  }

  if (extra_owner(ptile) != NULL) {
    struct extra_type_list *terr_claimers = extra_type_list_of_terr_claimers();

    extra_type_list_iterate(terr_claimers, pextra) {
      if (tile_has_extra(ptile, pextra)) {
        return TRUE;
      }
    } extra_type_list_iterate_end;
  }

  return FALSE;
}
