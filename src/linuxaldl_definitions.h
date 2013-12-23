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


// ==========================================
//   9A CODE MASK DEFINITION
// Engine: 1992-1994 5.0/5.7L V8 (L03/L05) Vin H/K
// ===========================================
const float map_9A_ADCOOL[256] = {
	[0] = 200,
//	[1 .. 11] = -999,
	[12] = 150,
	[13] = 145,
	[14] = 140,
//	[15] = -999,
	[16] = 135,
//	[17] = -999,
	[18] = 130,
//	[19 .. 20] = -999,
	[21] = 125,
//	[22] = -999,
	[23] = 120,
//	[24 .. 25] = -999,
	[26] = 115,
//	[27 .. 29] = -999,
	[30] = 110,
//	[31 .. 33] = -999,
	[34] = 105,
//	[35 .. 38] = -999,
	[39] = 100,
//	[40 .. 43] = -999,
	[44] = 95,
//	[45 .. 49] = -999,
	[50] = 90,
//	[51 .. 55] = -999,
	[56] = 85,
//	[57 .. 63] = -999,
	[64] = 80,
//	[65 .. 71] = -999,
	[72] = 75,
//	[73 .. 80] = -999,
	[81] = 70,
//	[82 .. 91] = -999,
	[92] = 65,
//	[92 .. 101] = -999,
	[102] = 60,
//	[103 .. 113] = -999,
	[114] = 55,
	[126] = 50,
	[139] = 45,
	[152] = 40,
	[165] = 35,
	[177] = 30,
//	[178 .. 188] = -999,
	[189] = 25,
//	[190 .. 198] = -999,
	[199] = 20,
//	[200 .. 208] = -999,
	[209] = 15,
//	[210 .. 217] = -999,
	[218] = 10,
//	[219 .. 224] = -999,
	[225] = 5,
//	[226 .. 230] = -999,
	[231] = 0,
//	[233 .. 236] = -999,
	[237] = -5,
//	[237 .. 240] = -999,
	[241] = -10,
//	[242 .. 244] = -999,
	[245] = -15,
//	[246] = -999,
	[247] = -20,
//	[248 .. 249] = -999,
	[250] = -25,
	[251] = -30,
//	[252] = -999,
	[253] = -40,
//	[254 .. 255] = -999,
};

byte_def_t aldl_9A_mode1[]= {
	/* Label, offset, bits, operation, opfactor, opoffset, units */
	ALDL_DEF_SEPERATOR("---Basic Data---"),
	ALDL_DEF_MAP8("Coolant Temperature", 6, map_9A_ADCOOL, "Deg C"), /* ADCOOL */
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
	ALDL_DEF_SEPERATOR("--Signal Bits--"),
	ALDL_DEF_BIT("Road Speed Pulse", 1, 0, "Present", "Not Present"), /* MW2 B0 */
	ALDL_DEF_BIT("O/L Idle Flag", 1, 1, "Set", "Not Set"), /* MW2 B1 */
	ALDL_DEF_BIT("Reference Pulse", 1, 2, "Present", "Not Present"), /* MW2 B2 */
	ALDL_DEF_BIT("Diag Switch in Factory Test (3.9K Ohm)", 1, 3, "Set", "Not Set"), /* MW2 B3 */
	ALDL_DEF_BIT("Diag Switch in Diag (0 Ohm)", 1, 4, "Set", "Not Set"), /* MW2 B4 */
	ALDL_DEF_BIT("Diag Switch in ALDL (10K Ohm)", 1, 5, "Set", "Not Set"), /* MW2 B5 */
	ALDL_DEF_BIT("1st Time Idle", 1, 6, "1st Time", "Regular"), /* MW2 B6 */
	ALDL_DEF_BIT("Idle Flag", 1, 7, "Set", "Not Set"), /* MW2 B7 */
	ALDL_DEF_BIT("Air Switch", 17, 0, "Engaged", "Not Engaged"), /* MCU2IO B0 */
	ALDL_DEF_BIT("Air Divert", 17, 1, "Engaged", "Not Engaged"), /* MCU2IO B1 */
	ALDL_DEF_BIT("OF3 Governor Over Speed", 17, 2, "On", "Off"), /* MCU2IO B2 */
	ALDL_DEF_BIT("Torque Converter Locked/Shift Light (!93)", 17, 3, "Yes", "No"), /* MCU2IO B3 */
	ALDL_DEF_BIT("Park/Neutral", 17, 4, "Yes", "Drive"), /* MCU2IO B4 */
	ALDL_DEF_BIT("High Gear", 17, 5, "No", "Yes"), /* MCU2IO B5 */
	ALDL_DEF_BIT("FRTH (?)", 17, 6, "Set", "Not Set"), /* MCU2IO B6 */
	ALDL_DEF_BIT("Air Conditioner Request", 17, 7, "Not Set", "Set"), /* MCU2IO B7 */
	ALDL_DEF_BIT("Clear Flood Flag", 15, 0, "Set", "Not Set"), /* MWAF1 B0 */
	ALDL_DEF_BIT("Learn Control Enable", 15, 1, "Set", "Not Set"), /* MWAF1 B1 */
	ALDL_DEF_BIT("Low Battery", 15, 2, "Yes", "No"), /* MWAF1 B2 */
	ALDL_DEF_BIT("A/F Decay Interrupt Done", 15, 3, "Set", "Not Set"), /* MWAF1 B3 */
	ALDL_DEF_BIT("Async Pulse Flag", 15, 4, "Set", "Not Set"), /* MWAF1 B4 */
	ALDL_DEF_BIT("Closed Loop for Idle", 15, 5, "Set", "Not Set"), /* MWAF1 B5 */
	ALDL_DEF_BIT("Rich/Lean Flag", 15, 6, "Rich", "Lean"), /* MWAF1 B6 */
	ALDL_DEF_BIT("Closed/Open Loop Flag", 15, 7, "Closed", "Open"), /* MWAF1 B7 */
	ALDL_DEF_BIT("Malf Code 24", 12, 0, "VSS", ""), /* MALFFLG1 B0 */
	ALDL_DEF_BIT("Malf Code 23", 12, 1, "Unused", ""), /* MALFFLG1 B1 */
	ALDL_DEF_BIT("Malf Code 22", 12, 2, "TPS Low", ""), /* MALFFLG1 B2 */
	ALDL_DEF_BIT("Malf Code 21", 12, 3, "TPS High", ""), /* MALFFLG1 B3 */
	ALDL_DEF_BIT("Malf Code 15", 12, 4, "CT Low", ""), /* MALFFLG1 B4 */
	ALDL_DEF_BIT("Malf Code 14", 12, 5, "CT High", ""), /* MALFFLG1 B5 */
	ALDL_DEF_BIT("Malf Code 13", 12, 6, "O2 Sensor", ""), /* MALFFLG1 B6 */
	ALDL_DEF_BIT("Malf Code 12", 12, 7, "No Ref Pulse", ""), /* MALFFLG1 B7 */
	ALDL_DEF_BIT("Malf Code 42", 13, 0, "EST Monitor", ""), /* MALFFLG2 B0 */
	ALDL_DEF_BIT("Malf Code 41", 13, 1, "Unused", ""), /* MALFFLG2 B1 */
	ALDL_DEF_BIT("Malf Code 35", 13, 2, "Unused", ""), /* MALFFLG2 B2 */
	ALDL_DEF_BIT("Malf Code 34", 13, 3, "MAP Sensor Low", ""), /* MALFFLG2 B3 */
	ALDL_DEF_BIT("Malf Code 33", 13, 4, "MAP Sensor High", ""), /* MALFFLG2 B4 */
	ALDL_DEF_BIT("Malf Code 32", 13, 5, "EGR", ""), /* MALFFLG2 B5 */
	ALDL_DEF_BIT("Malf Code 31", 13, 6, "Unused", ""), /* MALFFLG2 B6 */
	ALDL_DEF_BIT("Malf Code 25", 13, 7, "Unused", ""), /* MALFFLG2 B7 */
	ALDL_DEF_BIT("Malf Code 55", 14, 0, "ADU", ""), /* MALFFLG3 B0 */
	ALDL_DEF_BIT("Malf Code 54", 14, 1, "Fuel Pump", ""), /* MALFFLG3 B1 */
	ALDL_DEF_BIT("Malf Code 53", 14, 2, "Unused", ""), /* MALFFLG3 B2 */
	ALDL_DEF_BIT("Malf Code 52", 14, 3, "CAL-PACK", ""), /* MALFFLG3 B3 */
	ALDL_DEF_BIT("Malf Code 51", 14, 4, "PROM", ""), /* MALFFLG3 B4 */
	ALDL_DEF_BIT("Malf Code 45", 14, 5, "O2 Sensor Rich", ""), /* MALFFLG3 B5 */
	ALDL_DEF_BIT("Malf Code 44", 14, 6, "O2 Sensor Lean", ""), /* MALFFLG3 B6 */
	ALDL_DEF_BIT("Malf Code 43", 14, 7, "ESC", ""), /* MALFFLG3 B7 */
	ALDL_DEF_END,
};

aldl_definition aldl_9A = { .mask = "9A",
			    .name = "92-94 L03/L05 Truck (VIN H/K) w/MT ($9A)",
			    .mode1_response_length = 24,
			    .mode1_data_length = 23,
			    .mode1_data_offset = 1,
			    .mode1_def = aldl_9A_mode1,
			    .basic_baudrate = B4800,
			    .ideal_baudrate = 1600,   /* ie basic baud rate / 3 */
};

/* Definition table */
aldl_definition* aldl_definition_table[] = { &aldl_9A, &aldl_DF, NULL };


#endif
