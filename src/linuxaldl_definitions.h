#ifndef LINUXALDL_DEFINITIONS_INCLUDED
#define LINUXALDL_DEFINITIONS_INCLUDED

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

// ===================================================================
//		WRITING A DEFINITION FOR LINUXALDL
// ===================================================================

// Labels/names/units must not contain white space, commas, newlines, 
// or double quotes.
// They may contain: a-z A-Z 0-9 ~!@#$%^&*()-=_+|\/}{:<>?.[];'
// Label/names/units may not be NULL, except for units for seperators,
// and in the last element of the mode1_def[] array. (see below)

// The last element of the mode1_def[] array must be ALDL_DEF_END
// (which is a byte_def_t with label and units NULL and all other values 0).

// ===================================================================

// ==========================================
//   DF CODE MASK DEFINITION
// Engine: 1991-1993 3.4 DOHC V6 (LQ1) Vin "X"
// ===========================================
byte_def_t aldl_DF_mode1[]= {
	ALDL_DEF_SEPERATOR("---Basic Data---"),
	ALDL_DEF_SCALAR8("Engine RPM",		11,	25.0,		0.0,	"RPM"),
	ALDL_DEF_SCALAR8("Throttle Position", 	10, 	0.003906, 	0.00, 	"%"),
	ALDL_DEF_SCALAR8("Vehicle Speed", 	17, 	1.0, 		0.0, 	"MPH"),
	ALDL_DEF_SCALAR8("Engine Airflow", 	37, 	1.0, 		0.0, 	"gm/sec"),
	ALDL_DEF_SCALAR8("Coolant Temp", 	7, 	1.35, 		-40.0, 	"Deg F"),
	ALDL_DEF_SCALAR8("Intake Air Temp",	30,	1.0,		0.0,	"adc"),
	ALDL_DEF_SCALAR8("MAP",			29,	0.369,		10.354,	"kPa"),
	ALDL_DEF_SEPERATOR("----Fuel----"),
	ALDL_DEF_SCALAR8("Desired AFR",		41,	0.100,		0.0,	"A/F"),
	ALDL_DEF_SCALAR8("Narrowband O2",	19,	4.42,		0.0,	"mV"),
	ALDL_DEF_SCALAR16("Final Base Pulse Width", 42, 	0.015259,	0.0,	"mSec"),
	ALDL_DEF_SCALAR8("Current BLM Cell",	23,	1.0,		0.0,	""),
	ALDL_DEF_SCALAR8("BLM",			22,	1.0,		0.0,	"counts"),
	ALDL_DEF_SCALAR8("Integrator",		24,	1.0,		0.0,	"counts"),
	ALDL_DEF_SCALAR8("Base Pulse Fine Corr.",21,	1.0,		0.0,	"counts"),
	ALDL_DEF_SCALAR8("BLM Cell 0 Timer",	36,	1.0,		0.0,	"counts"),
	ALDL_DEF_SEPERATOR("--Ignition--"),
	ALDL_DEF_SCALAR8("Knock Events",	51,	1.0,		0.0,	"counts"),
	ALDL_DEF_SCALAR8("Spark Advance",	40,	0.351560,	0.0,	"degrees"),
	ALDL_DEF_SCALAR8("Knock Retard",	46,	0.175781,	0.0,	"degrees"),
	ALDL_DEF_SEPERATOR("--Accessory Data--"),
	ALDL_DEF_SCALAR16("PROM ID",		1,	1.0,		0.0,	"ID"),
	ALDL_DEF_SCALAR8("TPS Voltage",		9,	0.019531,	0.0,	"volts"),
	ALDL_DEF_SCALAR8("IAC Steps",		25,	1.0,		0.0,	"steps"),
	ALDL_DEF_SCALAR8("IAC Min Position",	22,	1.0,		0.0,	"steps"),
	ALDL_DEF_SCALAR8("Barometric Pressure",	28,	0.369,		10.3542,"kPa"),
	ALDL_DEF_SCALAR16("Engine Run Time",	48,	1.0,		0.0,	"secs"),
	ALDL_DEF_SCALAR8("Catalytic Conv Temp",	50,	3.0,		300.0,	"Deg C"),
	ALDL_DEF_SCALAR8("Fuel Pump Relay Volts", 31,	0.1,		0.0,	"volts"),
	ALDL_DEF_SCALAR8("O2 Cross-Count",	20,	1.0,		0.0,	"counts"),
	ALDL_DEF_SCALAR8("Desired Idle Speed",	27,	12.5,		0.0,	"RPM"),
	ALDL_DEF_SCALAR8("Battery Voltage",	34,	0.1,		0.0,	"volts"),
	ALDL_DEF_SCALAR8("CCP Duty Cycle",	45,	0.390650,	0.0,	"% CCP"),
	ALDL_DEF_SCALAR8("RPM/MPH",		47,	1.0,		0.0,	"RPM/MPH"),
	ALDL_DEF_SCALAR8("A/C Pressure Sensor",	33,	1.0,		0.0,	"A/D Counts"),
	ALDL_DEF_SCALAR8("Corrosivity Sensor",	44,	0.0196,		0.0,	"volts"),
	ALDL_DEF_END,
};

byte_def_t aldl_9A_mode1[]= {
	/* Label, offset, bits, operation, opfactor, opoffset, units */
	ALDL_DEF_SEPERATOR("---Basic Data---"),
	ALDL_DEF_SCALAR8("Vehicle Speed", 6, 1.0, 0.0, "MPH"), /* FILTMPH */
	ALDL_DEF_SCALAR8("Engine RPM", 8, 25.0, 0.0, "RPM"), /* NTRPMX */
	ALDL_DEF_SCALAR8("Throttle Position", 23, 0.39216, 0.0, "%"), /* NTPSLD */
	ALDL_DEF_SEPERATOR("----Fuel----"),
	ALDL_DEF_SCALAR8("Integrator", 10, 1.0, 0.0, "counts"), /* INT */
	ALDL_DEF_SCALAR8("Narrowband O2", 11, 4.425, 0.0, "mV"), /* ADO2A */
	ALDL_DEF_SCALAR8("BLM", 19, 1.0, 0.0, "counts"), /* BLM */
	ALDL_DEF_SEPERATOR("--Ignition--"),
	ALDL_DEF_SCALAR8("Knock Events", 18, 1.0, 0.0, "counts"), /* OLDPA3 */
	ALDL_DEF_SEPERATOR("--Accessory Data--"),
	ALDL_DEF_SCALAR16("PROM ID", 2, 1.0, 0.0, "ID"), /* PROMIDA+PROMIDB */
	ALDL_DEF_SCALAR8("IAC Steps", 4, 1.0, 0.0, "steps"), /* ISSPNP */
	ALDL_DEF_SCALAR8("MAP Voltage", 7, 0.019608, 0.0, "volts"), /* ADMAP */
	ALDL_DEF_SCALAR8("TPS Voltage",	9, 0.019608, 0.0, "volts"), /* ADTHROT */
	ALDL_DEF_SCALAR8("Battery Voltage", 16, 0.1, 0.0, "volts"), /* ADBAT */
	ALDL_DEF_SCALAR8("O2 Cross-Count", 20, 1.0, 0.0, "counts"), /* ALDLCNTR */
	ALDL_DEF_SCALAR8("Fuel Pump Relay Voltage", 21, 0.1, 0.0, "volts"), /* PPSWVLT */
	ALDL_DEF_SCALAR8("Desired Idle Speed", 22, 12.5, 0.0, "RPM"), /* DESSPD */
	ALDL_DEF_END,
};
/* ADCOOL (table), MW2, MALFFLG1, MALFFLG2, MALFFLG3, MWAF1, MCU2IO (all bitmasks!) */

aldl_definition aldl_DF = { .mask = "DF", 
			    .name = "91-93 3.4 DOHC LQ1 ($DF)",
			    .mode1_request = {0xF4, 0x57, 0x01, 0x00, 0xB4},
			    .mode1_request_length = 5, 
			    .mode1_response_length = 67,
			    .mode1_data_length = 63,
			    .mode1_data_offset = 3,
			    .mode1_def = aldl_DF_mode1,
			    .mode8_request = {0xF4, 0x56, 0x08, 0xAE},
			    .mode8_request_length = 4,
			    .mode9_request = {0xF4, 0x56, 0x09, 0xAD},
			    .mode9_request_length = 4,
			    .basic_baudrate = B9600,
			    .ideal_baudrate = 8192,
};

aldl_definition aldl_9A = { .mask = "9A",
			    .name = "92-94 L03/L05 Truck (VIN H/K) w/MT ($9A)",
			    .mode1_response_length = 24,
			    .mode1_data_length = 23,
			    .mode1_data_offset = 1,
			    .mode1_def = aldl_9A_mode1,
			    .basic_baudrate = B4800,
			    .ideal_baudrate = 160,
};

/* Definition table */
aldl_definition* aldl_definition_table[] = { &aldl_9A, &aldl_DF, NULL };


#endif
