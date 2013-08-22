#ifndef LINUXALDL_INCLUDED
#define LINUXALDL_INCLUDED

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

// debug mode
//#define _LINUXALDL_DEBUG

#define MAX_CONNECT_ATTEMPTS 3

// macros

#define _ALDL_MESSAGE_MODE8 aldl_settings.definition->mode8_request,aldl_settings.definition->mode8_request_length
#define _ALDL_MESSAGE_MODE9 aldl_settings.definition->mode9_request,aldl_settings.definition->mode9_request_length

#define __MAX_REQUEST_SIZE 16 /* maximum size (bytes) of a request message to send to the ECM */

enum ALDL_OP { ALDL_OP_SCALAR=0,
	       ALDL_OP_MAP,
	       ALDL_OP_BIT,
	       ALDL_OP_SEPERATOR,
};

// ============================================================================
// ALDL DEFINITION STRUCTS
// ============================================================================

// See linuxaldl_definitions.h for instructions on how to make a new definition


// byte_def_t struct
typedef struct _linuxaldl_byte_definition{
	const char* label;
	unsigned char byte_offset; /* Offset from the 1st byte of the data part of the mode1 message */
	unsigned char bits; /* 8 or 16 are currently supported */
	enum ALDL_OP operation;
#if 0
	union {
		struct { /* (val*factor)+offset */
			float factor;
			float offset;
			const char* units; /* Text string */
		} scalar;
		struct {
			unsigned char bit;
			const char *set;   /* Display if set */
			const char *unset; /* Display if not set*/
		} bit;
	} op;
#endif
	float op_factor; // factor for the operation
	float op_offset; // offset for the operation
	const char* units; /* Text string */
} byte_def_t;

#define ALDL_DEF_SCALAR8(__label, __offset, __factor, __shift, __units ) \
	{ .label = __label, \
	  .byte_offset = __offset, \
	  .bits = 8, \
	  .operation = ALDL_OP_SCALAR, \
	  .op_factor = __factor, \
	  .op_offset = __shift,	\
	  .units = __units, \
       	}
#define ALDL_DEF_SCALAR16(__label, __offset, __factor, __shift, __units ) \
	{ .label = __label, \
	  .byte_offset = __offset, \
	  .bits = 16, \
	  .operation = ALDL_OP_SCALAR, \
	  .op_factor = __factor, \
	  .op_offset = __shift,	\
	  .units = __units, \
       	}
#define ALDL_DEF_SEPERATOR(__label) \
	{ .label = __label, \
	  .operation = ALDL_OP_SEPERATOR, \
	}
#define ALDL_DEF_END { .label = NULL }


typedef struct _linuxaldl_definition {
	const char* mask;
	const char* name;
	char mode1_request[__MAX_REQUEST_SIZE];  // the mode 1 request message, including the checksum
	unsigned int mode1_request_length;  // the length of the mode 1 message including the checksum

	unsigned int mode1_response_length; // the total length of the response from the ecm

	unsigned int mode1_data_length; // the number of data bytes in the mode1 message response

	unsigned int mode1_data_offset; // the byte offest from the start of the mode1 message response
									// to the first byte of the data. e.g. if the data part of the
									// message is the 4th byte onward, this should be 3. (1+3 = 4)

	byte_def_t* mode1_def; // pointer to start of table of byte_def_t structs.
							// the last element must be LINUXALDL_MODE1_END_DEF

	char mode8_request[__MAX_REQUEST_SIZE];  // the mode 8 (silence) request message, incl checksum
	unsigned int mode8_request_length;  // the length of the mode 8 message incl checksum

	char mode9_request[__MAX_REQUEST_SIZE];  // the mode 9 (un-silence) request message, incl checksum
	unsigned int mode9_request_length;  // the length of the mode 9 message including the checksum

	unsigned int basic_baudrate;  /* Fallback datarate */
	unsigned int ideal_baudrate;  /* Desired datarate -- 8192 or 160 */
} aldl_definition;

// looks up def_name in the aldl_definition_table until it finds the first 
// definition in the table with the name def_name or the mask defmask
// if the definition is not in the table, returns NULL
aldl_definition* aldl_get_definition(const char* defname, const char *defmask);

typedef struct _linuxaldl_settings
{
	/* Configuration fields */
	const char* aldlportname; // path to aldl interface port
	const char* logfilename; 	// filename for the log file
	const char* aldldefname; // name for the ALDL definition to be used

	unsigned int scan_interval; // msec between scan requests
	unsigned int scan_timeout; // msec to timeout on scan request.
				// note that read-sequence takes timeout in usec.				// usec = msec*1000

	/* Data definitions */
	aldl_definition** aldl_definition_table; // array of pointers to data definitions. (see linuxaldl_definitions.h)
	
	/* Runtime stuff */
	int faldl; 			// aldl serial interface file descriptor
	int flogfile; 		// file descriptor for log file
	int scanning; // 1 when the timer has been set for making scans, otherwise 0.
	aldl_definition* definition; // see linuxaldl_definitions.h

	char* data_set_raw;	// the current/most recent set of data from a mode1 message.
				// this is allocated when a definition is selected

	char** data_set_strings;	// pointer to array of data set in string format.
					// allocated when a definition is selected in the GUI

	float* data_set_floats;		// data set in float format
					// allocated when a definition is selected in the GUI

} linuxaldl_settings;

// function prototypes
// =================================================

int verifyaldl();
// wake up / verify the ALDL interface

int aldl_scan_and_log(int fd);
// listens for aldl data and writes it to the file descriptor fd 
// stops when terminate_scan = 1 in the global settings struct and
// returns number of bytes written to fd.

char get_checksum(char* buffer, unsigned int len);
// calculates the single-byte checksum, summing from the start of buffer
// through len bytes. the checksum is calculated by summing the bytes,
// dropping carried bits, then adding 1 and taking the two's complement
// (subtract from FF) 

int send_aldl_message(char* msg_buf, unsigned int size);
// sends an artibtrary aldl message contained in the buffer msg_buf.
// the checksum must be set in the buffer by the caller.
// the following macros can be used as arguments:
//		_ALDL_MESSAGE_MODE8
//		_ALDL_MESSAGE_MODE9
// which use the mode 8 and mode 9 message definitions from the
// current aldl definition.

int get_mode1_message(char* inbuffer, unsigned int size);
// requests a mode1 message from the ECM using the currently loaded
// aldl definition. 
// returns 0 if the message was received successfully, -1 no response
// or bad checksum. 

int aldl_listen_raw(char* inbuffer, unsigned int len, int timeout);
// reads up to len bytes into inbuffer from the interface.
// listens for a maximum of timeout seconds.
// returns -1 on failure, 0 on timeout with no bytes received,
// and otherwise returns the number of bytes received 

typedef enum _ALDL_UPDATE_FLAGS { ALDL_UPDATE_STRINGS=1, ALDL_UPDATE_FLOATS=2} ALDL_UPDATE_FLAGS_t;
void aldl_update_sets(int flags);
// updates data_set_floats and/or data_set_strings using the current data_set_raw bytes.
// if the flags argument is ALDL_UPDATE_STRINGS then both sets will be updated.
// if it is ALDL_UPDATE_FLOATS then only floats will be updated, and the data_set_strings
// array will not be modified in any way.

#endif
