#pragma region Copyright (c) 2014-2016 OpenRCT2 Developers
/*****************************************************************************
 * OpenRCT2, an open source clone of Roller Coaster Tycoon 2.
 *
 * OpenRCT2 is the work of many authors, a full list can be found in contributors.md
 * For more information, visit https://github.com/OpenRCT2/OpenRCT2
 *
 * OpenRCT2 is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * A full copy of the GNU General Public License can be found in licence.txt
 *****************************************************************************/
#pragma endregion

#include "../../interface/viewport.h"
#include "../../paint/paint.h"
#include "../../paint/supports.h"
#include "../../world/sprite.h"
#include "../track.h"
#include "../track_paint.h"

enum {
	SPR_DINGHY_SLIDE_FLAT_SW_NE = 19720,
	SPR_DINGHY_SLIDE_FLAT_NW_SE = 19721,
	SPR_DINGHY_SLIDE_FLAT_FRONT_SW_NE = 19722,
	SPR_DINGHY_SLIDE_FLAT_FRONT_NW_SE = 19723,
	SPR_DINGHY_SLIDE_FLAT_CHAIN_SW_NE = 19724,
	SPR_DINGHY_SLIDE_FLAT_CHAIN_NW_SE = 19725,
	SPR_DINGHY_SLIDE_FLAT_CHAIN_FRONT_SW_NE = 19726,
	SPR_DINGHY_SLIDE_FLAT_CHAIN_FRONT_NW_SE = 19727,

	SPR_DINGHY_SLIDE_FLAT_COVERED_SW_NE = 19736,
	SPR_DINGHY_SLIDE_FLAT_COVERED_NW_SE = 19737,
	SPR_DINGHY_SLIDE_FLAT_COVERED_FRONT_SW_NE = 19738,
	SPR_DINGHY_SLIDE_FLAT_COVERED_FRONT_NW_SE = 19739,

	SPR_DINGHY_SLIDE_FLAT_TO_25_DEG_COVERED_SW_NE = 19812,
	SPR_DINGHY_SLIDE_FLAT_TO_25_DEG_COVERED_NW_SE = 19813,
	SPR_DINGHY_SLIDE_FLAT_TO_25_DEG_COVERED_NE_SW = 19814,
	SPR_DINGHY_SLIDE_FLAT_TO_25_DEG_COVERED_SE_NW = 19815,
	SPR_DINGHY_SLIDE_FLAT_TO_25_DEG_COVERED_FRONT_SW_NE = 19816,
	SPR_DINGHY_SLIDE_FLAT_TO_25_DEG_COVERED_FRONT_NW_SE = 19817,
	SPR_DINGHY_SLIDE_FLAT_TO_25_DEG_COVERED_FRONT_NE_SW = 19818,
	SPR_DINGHY_SLIDE_FLAT_TO_25_DEG_COVERED_FRONT_SE_NW = 19819,
	SPR_DINGHY_SLIDE_25_DEG_TO_FLAT_COVERED_SW_NE = 19820,
	SPR_DINGHY_SLIDE_25_DEG_TO_FLAT_COVERED_NW_SE = 19821,
	SPR_DINGHY_SLIDE_25_DEG_TO_FLAT_COVERED_NE_SW = 19822,
	SPR_DINGHY_SLIDE_25_DEG_TO_FLAT_COVERED_SE_NW = 19823,
	SPR_DINGHY_SLIDE_25_DEG_TO_FLAT_COVERED_FRONT_SW_NE = 19824,
	SPR_DINGHY_SLIDE_25_DEG_TO_FLAT_COVERED_FRONT_NW_SE = 19825,
	SPR_DINGHY_SLIDE_25_DEG_TO_FLAT_COVERED_FRONT_NE_SW = 19826,
	SPR_DINGHY_SLIDE_25_DEG_TO_FLAT_COVERED_FRONT_SE_NW = 19827,
	SPR_DINGHY_SLIDE_25_DEG_COVERED_SW_NE = 19828,
	SPR_DINGHY_SLIDE_25_DEG_COVERED_NW_SE = 19829,
	SPR_DINGHY_SLIDE_25_DEG_COVERED_NE_SW = 19830,
	SPR_DINGHY_SLIDE_25_DEG_COVERED_SE_NW = 19831,
	SPR_DINGHY_SLIDE_25_DEG_COVERED_FRONT_SW_NE = 19832,
	SPR_DINGHY_SLIDE_25_DEG_COVERED_FRONT_NW_SE = 19833,
	SPR_DINGHY_SLIDE_25_DEG_COVERED_FRONT_NE_SW = 19834,
	SPR_DINGHY_SLIDE_25_DEG_COVERED_FRONT_SE_NW = 19835,
	SPR_DINGHY_SLIDE_25_DEG_TO_60_DEG_COVERED_SW_NE = 19836,
	SPR_DINGHY_SLIDE_25_DEG_TO_60_DEG_COVERED_NW_SE = 19837,
	SPR_DINGHY_SLIDE_25_DEG_TO_60_DEG_COVERED_NE_SW = 19838,
	SPR_DINGHY_SLIDE_25_DEG_TO_60_DEG_COVERED_SE_NW = 19839,
	SPR_DINGHY_SLIDE_25_DEG_TO_60_DEG_COVERED_FRONT_SW_NE = 19840,
	SPR_DINGHY_SLIDE_25_DEG_TO_60_DEG_COVERED_FRONT_NW_SE = 19841,
	SPR_DINGHY_SLIDE_25_DEG_TO_60_DEG_COVERED_FRONT_NE_SW = 19842,
	SPR_DINGHY_SLIDE_25_DEG_TO_60_DEG_COVERED_FRONT_SE_NW = 19843,
	SPR_DINGHY_SLIDE_60_DEG_TO_25_DEG_COVERED_SW_NE = 19844,
	SPR_DINGHY_SLIDE_60_DEG_TO_25_DEG_COVERED_NW_SE = 19845,
	SPR_DINGHY_SLIDE_60_DEG_TO_25_DEG_COVERED_NE_SW = 19846,
	SPR_DINGHY_SLIDE_60_DEG_TO_25_DEG_COVERED_SE_NW = 19847,
	SPR_DINGHY_SLIDE_60_DEG_TO_25_DEG_COVERED_FRONT_SW_NE = 19848,
	SPR_DINGHY_SLIDE_60_DEG_TO_25_DEG_COVERED_FRONT_NW_SE = 19849,
	SPR_DINGHY_SLIDE_60_DEG_TO_25_DEG_COVERED_FRONT_NE_SW = 19850,
	SPR_DINGHY_SLIDE_60_DEG_TO_25_DEG_COVERED_FRONT_SE_NW = 19851,
	SPR_DINGHY_SLIDE_60_DEG_COVERED_SW_NE = 19852,
	SPR_DINGHY_SLIDE_60_DEG_COVERED_NW_SE = 19853,
	SPR_DINGHY_SLIDE_60_DEG_COVERED_NE_SW = 19854,
	SPR_DINGHY_SLIDE_60_DEG_COVERED_SE_NW = 19855,
	SPR_DINGHY_SLIDE_60_DEG_COVERED_FRONT_SW_NE = 19856,
	SPR_DINGHY_SLIDE_60_DEG_COVERED_FRONT_NW_SE = 19857,
	SPR_DINGHY_SLIDE_60_DEG_COVERED_FRONT_NE_SW = 19858,
	SPR_DINGHY_SLIDE_60_DEG_COVERED_FRONT_SE_NW = 19859,
};

static void dinghy_slide_track_flat(uint8 rideIndex, uint8 trackSequence, uint8 direction, int height, rct_map_element * mapElement)
{
	static const uint32 imageIds[2][4][2] = {
		{
			{ SPR_DINGHY_SLIDE_FLAT_SW_NE, SPR_DINGHY_SLIDE_FLAT_FRONT_SW_NE },
			{ SPR_DINGHY_SLIDE_FLAT_NW_SE, SPR_DINGHY_SLIDE_FLAT_FRONT_NW_SE },
			{ SPR_DINGHY_SLIDE_FLAT_SW_NE, SPR_DINGHY_SLIDE_FLAT_FRONT_SW_NE },
			{ SPR_DINGHY_SLIDE_FLAT_NW_SE, SPR_DINGHY_SLIDE_FLAT_FRONT_NW_SE },
		},
		{
			{ SPR_DINGHY_SLIDE_FLAT_CHAIN_SW_NE, SPR_DINGHY_SLIDE_FLAT_CHAIN_FRONT_SW_NE },
			{ SPR_DINGHY_SLIDE_FLAT_CHAIN_NW_SE, SPR_DINGHY_SLIDE_FLAT_CHAIN_FRONT_NW_SE },
			{ SPR_DINGHY_SLIDE_FLAT_CHAIN_SW_NE, SPR_DINGHY_SLIDE_FLAT_CHAIN_FRONT_SW_NE },
			{ SPR_DINGHY_SLIDE_FLAT_CHAIN_NW_SE, SPR_DINGHY_SLIDE_FLAT_CHAIN_FRONT_NW_SE },
		},
	};

	bool isChained = track_element_is_lift_hill(mapElement);
	uint32 imageId = imageIds[isChained][direction][0] | gTrackColours[SCHEME_TRACK];
	sub_98197C_rotated(direction, imageId, 0, 0, 32, 20, 2, height, 0, 6, height);

	imageId = imageIds[isChained][direction][1] | gTrackColours[SCHEME_TRACK];
	sub_98197C_rotated(direction, imageId, 0, 0, 32, 1, 26, height, 0, 27, height);

	if (track_paint_util_should_paint_supports(gPaintMapPosition)) {
		metal_a_supports_paint_setup(0, 4, 0, height, gTrackColours[SCHEME_SUPPORTS]);
	}

	paint_util_push_tunnel_rotated(direction, height, TUNNEL_0);

	paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_D0 | SEGMENT_C4 | SEGMENT_CC, direction), 0xFFFF, 0);
	paint_util_set_general_support_height(height + 32, 0x20);
}

static void dinghy_slide_track_flat_covered(uint8 rideIndex, uint8 trackSequence, uint8 direction, int height, rct_map_element * mapElement)
{
	static const uint32 imageIds[4][2] = {
		{ SPR_DINGHY_SLIDE_FLAT_COVERED_SW_NE, SPR_DINGHY_SLIDE_FLAT_COVERED_FRONT_SW_NE },
		{ SPR_DINGHY_SLIDE_FLAT_COVERED_NW_SE, SPR_DINGHY_SLIDE_FLAT_COVERED_FRONT_NW_SE },
		{ SPR_DINGHY_SLIDE_FLAT_COVERED_SW_NE, SPR_DINGHY_SLIDE_FLAT_COVERED_FRONT_SW_NE },
		{ SPR_DINGHY_SLIDE_FLAT_COVERED_NW_SE, SPR_DINGHY_SLIDE_FLAT_COVERED_FRONT_NW_SE },
	};

	uint32 imageId = imageIds[direction][0] | gTrackColours[SCHEME_TRACK];
	sub_98197C_rotated(direction, imageId, 0, 0, 32, 20, 2, height, 0, 6, height);

	imageId = imageIds[direction][1] | gTrackColours[SCHEME_TRACK];
	sub_98197C_rotated(direction, imageId, 0, 0, 32, 1, 26, height, 0, 27, height);

	if (track_paint_util_should_paint_supports(gPaintMapPosition)) {
		metal_a_supports_paint_setup(0, 4, 0, height, gTrackColours[SCHEME_SUPPORTS]);
	}

	paint_util_push_tunnel_rotated(direction, height, TUNNEL_0);

	paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_D0 | SEGMENT_C4 | SEGMENT_CC, direction), 0xFFFF, 0);
	paint_util_set_general_support_height(height + 32, 0x20);
}

static void dinghy_slide_track_25_deg_up_covered(uint8 rideIndex, uint8 trackSequence, uint8 direction, int height, rct_map_element * mapElement)
{
	static const uint32 imageIds[4][2] = {
		{ SPR_DINGHY_SLIDE_25_DEG_COVERED_SW_NE, SPR_DINGHY_SLIDE_25_DEG_COVERED_FRONT_SW_NE },
		{ SPR_DINGHY_SLIDE_25_DEG_COVERED_NW_SE, SPR_DINGHY_SLIDE_25_DEG_COVERED_FRONT_NW_SE },
		{ SPR_DINGHY_SLIDE_25_DEG_COVERED_NE_SW, SPR_DINGHY_SLIDE_25_DEG_COVERED_FRONT_NE_SW },
		{ SPR_DINGHY_SLIDE_25_DEG_COVERED_SE_NW, SPR_DINGHY_SLIDE_25_DEG_COVERED_FRONT_SE_NW },
	};

	uint32 imageId = imageIds[direction][0] | gTrackColours[SCHEME_TRACK];
	sub_98197C_rotated(direction, imageId, 0, 0, 32, 20, 2, height, 0, 6, height);

	imageId = imageIds[direction][1] | gTrackColours[SCHEME_TRACK];
	sub_98197C_rotated(direction, imageId, 0, 0, 32, 1, 50, height, 0, 27, height);

	if (track_paint_util_should_paint_supports(gPaintMapPosition)) {
		metal_a_supports_paint_setup(0, 4, 8, height, gTrackColours[SCHEME_SUPPORTS]);
	}

	if (direction == 0 || direction == 3) {
		paint_util_push_tunnel_rotated(direction, height - 8, TUNNEL_1);
	} else {
		paint_util_push_tunnel_rotated(direction, height + 8, TUNNEL_2);
	}

	paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_D0 | SEGMENT_C4 | SEGMENT_CC, direction), 0xFFFF, 0);
	paint_util_set_general_support_height(height + 56, 0x20);
}

static void dinghy_slide_track_60_deg_up_covered(uint8 rideIndex, uint8 trackSequence, uint8 direction, int height, rct_map_element * mapElement)
{
	static const uint32 imageIds[4][2] = {
		{ SPR_DINGHY_SLIDE_60_DEG_COVERED_SW_NE, SPR_DINGHY_SLIDE_60_DEG_COVERED_FRONT_SW_NE },
		{ SPR_DINGHY_SLIDE_60_DEG_COVERED_NW_SE, SPR_DINGHY_SLIDE_60_DEG_COVERED_FRONT_NW_SE },
		{ SPR_DINGHY_SLIDE_60_DEG_COVERED_NE_SW, SPR_DINGHY_SLIDE_60_DEG_COVERED_FRONT_NE_SW },
		{ SPR_DINGHY_SLIDE_60_DEG_COVERED_SE_NW, SPR_DINGHY_SLIDE_60_DEG_COVERED_FRONT_SE_NW },
	};

	uint32 imageId = imageIds[direction][0] | gTrackColours[SCHEME_TRACK];
	sub_98197C_rotated(direction, imageId, 0, 0, 32, 20, 2, height, 0, 6, height);

	imageId = imageIds[direction][1] | gTrackColours[SCHEME_TRACK];
	sub_98197C_rotated(direction, imageId, 0, 0, 32, 1, 98, height, 0, 27, height);

	if (track_paint_util_should_paint_supports(gPaintMapPosition)) {
		metal_a_supports_paint_setup(0, 4, 32, height, gTrackColours[SCHEME_SUPPORTS]);
	}

	if (direction == 0 || direction == 3) {
		paint_util_push_tunnel_rotated(direction, height - 8, TUNNEL_1);
	} else {
		paint_util_push_tunnel_rotated(direction, height + 56, TUNNEL_2);
	}

	paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_D0 | SEGMENT_C4 | SEGMENT_CC, direction), 0xFFFF, 0);
	paint_util_set_general_support_height(height + 104, 0x20);
}

static void dinghy_slide_track_flat_to_25_deg_up_covered(uint8 rideIndex, uint8 trackSequence, uint8 direction, int height, rct_map_element * mapElement)
{
	static const uint32 imageIds[4][2] = {
		{ SPR_DINGHY_SLIDE_FLAT_TO_25_DEG_COVERED_SW_NE, SPR_DINGHY_SLIDE_FLAT_TO_25_DEG_COVERED_FRONT_SW_NE },
		{ SPR_DINGHY_SLIDE_FLAT_TO_25_DEG_COVERED_NW_SE, SPR_DINGHY_SLIDE_FLAT_TO_25_DEG_COVERED_FRONT_NW_SE },
		{ SPR_DINGHY_SLIDE_FLAT_TO_25_DEG_COVERED_NE_SW, SPR_DINGHY_SLIDE_FLAT_TO_25_DEG_COVERED_FRONT_NE_SW },
		{ SPR_DINGHY_SLIDE_FLAT_TO_25_DEG_COVERED_SE_NW, SPR_DINGHY_SLIDE_FLAT_TO_25_DEG_COVERED_FRONT_SE_NW },
	};

	uint32 imageId = imageIds[direction][0] | gTrackColours[SCHEME_TRACK];
	sub_98197C_rotated(direction, imageId, 0, 0, 32, 20, 2, height, 0, 6, height);

	imageId = imageIds[direction][1] | gTrackColours[SCHEME_TRACK];
	sub_98197C_rotated(direction, imageId, 0, 0, 32, 1, 42, height, 0, 27, height);

	if (track_paint_util_should_paint_supports(gPaintMapPosition)) {
		metal_a_supports_paint_setup(0, 4, 3, height, gTrackColours[SCHEME_SUPPORTS]);
	}

	if (direction == 0 || direction == 3) {
		paint_util_push_tunnel_rotated(direction, height, TUNNEL_0);
	} else {
		paint_util_push_tunnel_rotated(direction, height, TUNNEL_2);
	}

	paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_D0 | SEGMENT_C4 | SEGMENT_CC, direction), 0xFFFF, 0);
	paint_util_set_general_support_height(height + 48, 0x20);
}

static void dinghy_slide_track_25_deg_up_to_60_deg_up_covered(uint8 rideIndex, uint8 trackSequence, uint8 direction, int height, rct_map_element * mapElement)
{
	static const uint32 imageIds[4][2] = {
		{ SPR_DINGHY_SLIDE_25_DEG_TO_60_DEG_COVERED_SW_NE, SPR_DINGHY_SLIDE_25_DEG_TO_60_DEG_COVERED_FRONT_SW_NE },
		{ SPR_DINGHY_SLIDE_25_DEG_TO_60_DEG_COVERED_NW_SE, SPR_DINGHY_SLIDE_25_DEG_TO_60_DEG_COVERED_FRONT_NW_SE },
		{ SPR_DINGHY_SLIDE_25_DEG_TO_60_DEG_COVERED_NE_SW, SPR_DINGHY_SLIDE_25_DEG_TO_60_DEG_COVERED_FRONT_NE_SW },
		{ SPR_DINGHY_SLIDE_25_DEG_TO_60_DEG_COVERED_SE_NW, SPR_DINGHY_SLIDE_25_DEG_TO_60_DEG_COVERED_FRONT_SE_NW },
	};

	uint32 imageId = imageIds[direction][0] | gTrackColours[SCHEME_TRACK];
	sub_98197C_rotated(direction, imageId, 0, 0, 32, 20, 2, height, 0, 6, height);

	imageId = imageIds[direction][1] | gTrackColours[SCHEME_TRACK];
	sub_98197C_rotated(direction, imageId, 0, 0, 32, 1, 66, height, 0, 27, height);

	if (track_paint_util_should_paint_supports(gPaintMapPosition)) {
		metal_a_supports_paint_setup(0, 4, 12, height, gTrackColours[SCHEME_SUPPORTS]);
	}

	if (direction == 0 || direction == 3) {
		paint_util_push_tunnel_rotated(direction, height - 8, TUNNEL_1);
	} else {
		paint_util_push_tunnel_rotated(direction, height + 24, TUNNEL_2);
	}

	paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_D0 | SEGMENT_C4 | SEGMENT_CC, direction), 0xFFFF, 0);
	paint_util_set_general_support_height(height + 72, 0x20);
}

static void dinghy_slide_track_60_deg_up_to_25_deg_up_covered(uint8 rideIndex, uint8 trackSequence, uint8 direction, int height, rct_map_element * mapElement)
{
	static const uint32 imageIds[4][2] = {
		{ SPR_DINGHY_SLIDE_60_DEG_TO_25_DEG_COVERED_SW_NE, SPR_DINGHY_SLIDE_60_DEG_TO_25_DEG_COVERED_FRONT_SW_NE },
		{ SPR_DINGHY_SLIDE_60_DEG_TO_25_DEG_COVERED_NW_SE, SPR_DINGHY_SLIDE_60_DEG_TO_25_DEG_COVERED_FRONT_NW_SE },
		{ SPR_DINGHY_SLIDE_60_DEG_TO_25_DEG_COVERED_NE_SW, SPR_DINGHY_SLIDE_60_DEG_TO_25_DEG_COVERED_FRONT_NE_SW },
		{ SPR_DINGHY_SLIDE_60_DEG_TO_25_DEG_COVERED_SE_NW, SPR_DINGHY_SLIDE_60_DEG_TO_25_DEG_COVERED_FRONT_SE_NW },
	};

	uint32 imageId = imageIds[direction][0] | gTrackColours[SCHEME_TRACK];
	sub_98197C_rotated(direction, imageId, 0, 0, 32, 20, 2, height, 0, 6, height);

	imageId = imageIds[direction][1] | gTrackColours[SCHEME_TRACK];
	sub_98197C_rotated(direction, imageId, 0, 0, 32, 1, 66, height, 0, 27, height);

	if (track_paint_util_should_paint_supports(gPaintMapPosition)) {
		metal_a_supports_paint_setup(0, 4, 20, height, gTrackColours[SCHEME_SUPPORTS]);
	}

	if (direction == 0 || direction == 3) {
		paint_util_push_tunnel_rotated(direction, height - 8, TUNNEL_1);
	} else {
		paint_util_push_tunnel_rotated(direction, height + 24, TUNNEL_2);
	}

	paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_D0 | SEGMENT_C4 | SEGMENT_CC, direction), 0xFFFF, 0);
	paint_util_set_general_support_height(height + 72, 0x20);
}

static void dinghy_slide_track_25_deg_up_to_flat_covered(uint8 rideIndex, uint8 trackSequence, uint8 direction, int height, rct_map_element * mapElement)
{
	static const uint32 imageIds[4][2] = {
		{ SPR_DINGHY_SLIDE_25_DEG_TO_FLAT_COVERED_SW_NE, SPR_DINGHY_SLIDE_25_DEG_TO_FLAT_COVERED_FRONT_SW_NE },
		{ SPR_DINGHY_SLIDE_25_DEG_TO_FLAT_COVERED_NW_SE, SPR_DINGHY_SLIDE_25_DEG_TO_FLAT_COVERED_FRONT_NW_SE },
		{ SPR_DINGHY_SLIDE_25_DEG_TO_FLAT_COVERED_NE_SW, SPR_DINGHY_SLIDE_25_DEG_TO_FLAT_COVERED_FRONT_NE_SW },
		{ SPR_DINGHY_SLIDE_25_DEG_TO_FLAT_COVERED_SE_NW, SPR_DINGHY_SLIDE_25_DEG_TO_FLAT_COVERED_FRONT_SE_NW },
	};

	uint32 imageId = imageIds[direction][0] | gTrackColours[SCHEME_TRACK];
	sub_98197C_rotated(direction, imageId, 0, 0, 32, 20, 2, height, 0, 6, height);

	imageId = imageIds[direction][1] | gTrackColours[SCHEME_TRACK];
	sub_98197C_rotated(direction, imageId, 0, 0, 32, 1, 34, height, 0, 27, height);

	if (track_paint_util_should_paint_supports(gPaintMapPosition)) {
		metal_a_supports_paint_setup(0, 4, 6, height, gTrackColours[SCHEME_SUPPORTS]);
	}

	if (direction == 0 || direction == 3) {
		paint_util_push_tunnel_rotated(direction, height - 8, TUNNEL_0);
	} else {
		paint_util_push_tunnel_rotated(direction, height + 8, TUNNEL_12);
	}

	paint_util_set_segment_support_height(paint_util_rotate_segments(SEGMENT_D0 | SEGMENT_C4 | SEGMENT_CC, direction), 0xFFFF, 0);
	paint_util_set_general_support_height(height + 40, 0x20);
}

static void dinghy_slide_track_25_deg_down_covered(uint8 rideIndex, uint8 trackSequence, uint8 direction, int height, rct_map_element * mapElement)
{
	dinghy_slide_track_25_deg_up_covered(rideIndex, trackSequence, (direction + 2) & 3, height, mapElement);
}

static void dinghy_slide_track_60_deg_down_covered(uint8 rideIndex, uint8 trackSequence, uint8 direction, int height, rct_map_element * mapElement)
{
	dinghy_slide_track_60_deg_up_covered(rideIndex, trackSequence, (direction + 2) & 3, height, mapElement);
}

static void dinghy_slide_track_flat_to_25_deg_down_covered(uint8 rideIndex, uint8 trackSequence, uint8 direction, int height, rct_map_element * mapElement)
{
	dinghy_slide_track_25_deg_up_to_flat_covered(rideIndex, trackSequence, (direction + 2) & 3, height, mapElement);
}

static void dinghy_slide_track_25_deg_down_to_60_deg_down_covered(uint8 rideIndex, uint8 trackSequence, uint8 direction, int height, rct_map_element * mapElement)
{
	dinghy_slide_track_60_deg_up_to_25_deg_up_covered(rideIndex, trackSequence, (direction + 2) & 3, height, mapElement);
}

static void dinghy_slide_track_25_deg_down_to_flat_covered(uint8 rideIndex, uint8 trackSequence, uint8 direction, int height, rct_map_element * mapElement)
{
	dinghy_slide_track_flat_to_25_deg_up_covered(rideIndex, trackSequence, (direction + 2) & 3, height, mapElement);
}

static void dinghy_slide_track_60_deg_down_to_25_deg_down_covered(uint8 rideIndex, uint8 trackSequence, uint8 direction, int height, rct_map_element * mapElement)
{
	dinghy_slide_track_25_deg_up_to_60_deg_up_covered(rideIndex, trackSequence, (direction + 2) & 3, height, mapElement);
}

TRACK_PAINT_FUNCTION get_track_paint_function_dinghy_slide(int trackType, int direction)
{
	switch (trackType) {
	case TRACK_ELEM_FLAT:
		return dinghy_slide_track_flat;

	case TRACK_ELEM_FLAT_COVERED:
		return dinghy_slide_track_flat_covered;
	case TRACK_ELEM_25_DEG_UP_COVERED:
		return dinghy_slide_track_25_deg_up_covered;
	case TRACK_ELEM_60_DEG_UP_COVERED:
		return dinghy_slide_track_60_deg_up_covered;
	case TRACK_ELEM_FLAT_TO_25_DEG_UP_COVERED:
		return dinghy_slide_track_flat_to_25_deg_up_covered;
	case TRACK_ELEM_25_DEG_UP_TO_60_DEG_UP_COVERED:
		return dinghy_slide_track_25_deg_up_to_60_deg_up_covered;
	case TRACK_ELEM_60_DEG_UP_TO_25_DEG_UP_COVERED:
		return dinghy_slide_track_60_deg_up_to_25_deg_up_covered;
	case TRACK_ELEM_25_DEG_UP_TO_FLAT_COVERED:
		return dinghy_slide_track_25_deg_up_to_flat_covered;
	case TRACK_ELEM_25_DEG_DOWN_COVERED:
		return dinghy_slide_track_25_deg_down_covered;
	case TRACK_ELEM_60_DEG_DOWN_COVERED:
		return dinghy_slide_track_60_deg_down_covered;
	case TRACK_ELEM_FLAT_TO_25_DEG_DOWN_COVERED:
		return dinghy_slide_track_flat_to_25_deg_down_covered;
	case TRACK_ELEM_25_DEG_DOWN_TO_60_DEG_DOWN_COVERED:
		return dinghy_slide_track_25_deg_down_to_60_deg_down_covered;
	case TRACK_ELEM_60_DEG_DOWN_TO_25_DEG_DOWN_COVERED:
		return dinghy_slide_track_60_deg_down_to_25_deg_down_covered;
	case TRACK_ELEM_25_DEG_DOWN_TO_FLAT_COVERED:
		return dinghy_slide_track_25_deg_down_to_flat_covered;
	}

	return NULL;
}
