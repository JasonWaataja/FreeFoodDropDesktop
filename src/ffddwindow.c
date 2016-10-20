/*-
 * Copyright (c) 2016, Jason Waataja
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 * contributors may be used to endorse or promote products derived from this
 * software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include "ffddwindow.h"

struct _FfddWindow {
	GtkApplicationWindow parent;
};

struct _FfddWindowClass {
	GtkApplicationWindowClass parent_class;
};

typedef struct _FfddWindowPrivate FfddWindowPrivate;

struct _FfddWindowPrivate {
};

G_DEFINE_TYPE_WITH_PRIVATE(FfddWindow, ffdd_window,
    GTK_TYPE_APPLICATION_WINDOW);

static void
ffdd_window_init(FfddWindow *win)
{
	FfddWindow *priv;

	priv = ffdd_window_get_instance_private(win);
	gtk_widget_init_template(GTK_WIDGET(win));
}

static void
ffdd_window_class_init(FfddWindowClass *kclass)
{
	gtk_widget_class_set_template_from_resource(GTK_WIDGET_CLASS(kclass),
	    "/com/waataja/ffdd/ui/mainwindow.ui");
}

FfddWindow *
ffdd_window_new(FfddApplication *app)
{
	FfddWindow *win = g_object_new(FFDD_TYPE_WINDOW, "application", app,
	    NULL);

	return (win);
}
