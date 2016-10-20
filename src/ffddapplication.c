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

#include "ffddapplication.h"
#include "ffddwindow.h"

struct _FfddApplication {
	GtkApplication parent;
};

struct _FfddApplicationClass {
	GtkApplicationClass parent;
};

typedef struct _FfddApplicationPrivate FfddApplicationPrivate;

struct _FfddApplicationPrivate {
	FfddWindow *win;
};

G_DEFINE_TYPE_WITH_PRIVATE(FfddApplication, ffdd_application,
    GTK_TYPE_APPLICATION);

static void
ffdd_application_init(FfddApplication *app)
{
}

static void
ffdd_application_startup(GApplication *app)
{
	G_APPLICATION_CLASS(ffdd_application_parent_class)->startup(app);
}

static void
ffdd_application_activate(GApplication *app)
{
	FfddApplicationPrivate *priv;

	priv = ffdd_application_get_instance_private(FFDD_APPLICATION(app));
	priv->win = ffdd_window_new(FFDD_APPLICATION(app));

	gtk_window_present(GTK_WINDOW(priv->win));
}

static void
ffdd_application_class_init(FfddApplicationClass *kclass)
{
	G_APPLICATION_CLASS(kclass)->startup = ffdd_application_startup;
	G_APPLICATION_CLASS(kclass)->activate = ffdd_application_activate;
}

FfddApplication *
ffdd_application_new(void)
{
	return (g_object_new(FFDD_TYPE_APPLICATION, "application-id",
	    "com.waataja.ffdd", NULL));
}
