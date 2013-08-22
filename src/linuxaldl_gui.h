#ifndef LINUXALDL_GUI_INCLUDED
#define LINUXALDL_GUI_INCLUDED

/*(C) copyright 2008, Steven Snyder, All Rights Reserved

Steven T. Snyder, <stsnyder@ucla.edu> http://www.steventsnyder.com

LICENSING INFORMATION:
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

#include <gtk/gtk.h>
#include "linuxaldl.h"
#include <stdio.h>

typedef enum _aldl_log_format { ALDL_LOG_RAW, ALDL_LOG_CSV } aldl_log_format_t;

//  linuxaldl GUI-specific settings/data struct
// ============================================
typedef struct _linuxaldl_gui_settings
{
	GtkWidget** data_readout_labels; // array of pointers to the data labels for the definition.
									 // this is dynamically allocated by the program.
									 // data_readout_labels[i] points to the label that
									 // contains a string representation of the value of
									 // the data element described by definition->mode1_def[i].
									 // where mode1_def[j] defines a label/seperator,
									 // the value of data_readout_labels[j] is undefined.

	struct timeval data_timestamp;			// timestamp for data_set

	aldl_log_format_t log_format; // log file format.

	FILE* slogfile; // log file stream for CSV format. not used for raw log file format.

	int scanning_tag; // the tag returned by gtk_timeout_add for the interval scan
} linuxaldl_gui_settings;

//  linuxaldl GUI function prototypes 
// ==================================================================


// ==================================
//   main GUI function
// ==================================
int linuxaldl_gui(int argc, char* argv[]);
// runs the linuxaldl GTK+ graphical user interface 

// ==================================
//    Alert Window Popup
// ==================================
void quick_alert(gchar *message);
// pops up an alert with message in the body and an ok button.
// the alert will block access to other windows until the button is clicked.
// background activity will continue.

// ==============================
//  Adjustment scale with label
// ==============================
// returns a vbox containing a horizontal scale with a new adjustment
// with range min to max and step size step that starts out with the initial value init_val.
// the adjustment calls the function change_callback when the value changes.
GtkWidget* hscale_new_with_label(gdouble init_val, gdouble min, gdouble max, gdouble step, GtkSignalFunc changed, gchar *adj_label);
#endif
