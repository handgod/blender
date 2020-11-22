/*
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

/** \file
 * \ingroup DNA
 */

#pragma once

#include "DNA_view3d_types.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct XrSessionSettings {
  /** Shading settings, struct shared with 3D-View so settings are the same. */
  struct View3DShading shading;

  char _pad[7];

  char base_pose_type; /* eXRSessionBasePoseType */
  /** Object to take the location and rotation as base position from. */
  Object *base_pose_object;
  float base_pose_location[3];
  float base_pose_angle;

  /** View3D draw flags (V3D_OFSDRAW_NONE, V3D_OFSDRAW_SHOW_ANNOTATION, ...). */
  char draw_flags;

  /** The eye (view) that will be used when projecting 3D to 2D (e.g. when performing GPU select).
   */
  char selection_eye;
  char _pad2[2];

  /** Clipping distance. */
  float clip_start, clip_end;

  int flag;

  /** Objects whose location and rotation will be constrained to the XR headset/controller poses.
   */
  Object *headset_object;
  Object *controller0_object;
  Object *controller1_object;

  char headset_flag;
  char controller0_flag;
  char controller1_flag;
  char _pad3[5];
} XrSessionSettings;

typedef enum eXrSessionFlag {
  XR_SESSION_USE_POSITION_TRACKING = (1 << 0),
  XR_SESSION_USE_ABSOLUTE_TRACKING = (1 << 1),
} eXrSessionFlag;

typedef enum eXRSessionBasePoseType {
  XR_BASE_POSE_SCENE_CAMERA = 0,
  XR_BASE_POSE_OBJECT = 1,
  XR_BASE_POSE_CUSTOM = 2,
} eXRSessionBasePoseType;

typedef enum eXrSessionEye {
  XR_EYE_LEFT = 0,
  XR_EYE_RIGHT = 1,
} eXrSessionEye;

typedef enum eXrSessionObjectFlag {
  XR_OBJECT_ENABLE = (1 << 0),
  XR_OBJECT_AUTOKEY = (1 << 1),
} eXrSessionObjectFlag;

#ifdef __cplusplus
}
#endif
