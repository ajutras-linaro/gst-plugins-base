/* GStreamer
 * Copyright (C) <1999> Erik Walthinsen <omega@cse.ogi.edu>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */


#ifndef __GST_VIDEOSCALE_H__
#define __GST_VIDEOSCALE_H__


#include <gst/gst.h>
#include <gst/base/gstbasetransform.h>

#include "vs_image.h"

G_BEGIN_DECLS


GST_DEBUG_CATEGORY_EXTERN (videoscale_debug);
#define GST_CAT_DEFAULT videoscale_debug


#define GST_TYPE_VIDEOSCALE \
  (gst_videoscale_get_type())
#define GST_VIDEOSCALE(obj) \
  (G_TYPE_CHECK_INSTANCE_CAST((obj),GST_TYPE_VIDEOSCALE,GstVideoscale))
#define GST_VIDEOSCALE_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_CAST((klass),GST_TYPE_VIDEOSCALE,GstVideoscale))
#define GST_IS_VIDEOSCALE(obj) \
  (G_TYPE_CHECK_INSTANCE_TYPE((obj),GST_TYPE_VIDEOSCALE))
#define GST_IS_VIDEOSCALE_CLASS(obj) \
  (G_TYPE_CHECK_CLASS_TYPE((klass),GST_TYPE_VIDEOSCALE))


typedef enum {
  GST_VIDEOSCALE_POINT_SAMPLE,
  GST_VIDEOSCALE_NEAREST,
  GST_VIDEOSCALE_BILINEAR,
  GST_VIDEOSCALE_BICUBIC
} GstVideoScaleMethod;


typedef struct _GstVideoscale GstVideoscale;
typedef struct _GstVideoscaleClass GstVideoscaleClass;


struct _GstVideoscale {
  GstBaseTransform element;

  GstVideoScaleMethod method;

  /* negotiated stuff */
  int format;
  VSImage src;
  VSImage dest;
  guint src_size;
  guint dest_size;
  gint to_width;
  gint to_height;
  gint from_width;
  gint from_height;
  
  /* private */
  guint8 *tmp_buf;
};

struct _GstVideoscaleClass {
  GstBaseTransformClass parent_class;
};


GType gst_videoscale_get_type(void);


G_END_DECLS


#endif /* __GST_VIDEOSCALE_H__ */
