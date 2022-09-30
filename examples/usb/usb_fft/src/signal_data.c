/* ----------------------------------------------------------------------
* Copyright (C) 2010-2012 ARM Limited. All rights reserved.
*
* $Date:        17. January 2013
* $Revision: 	V1.4.0
*
* Project: 	    CMSIS DSP Library
* Title:	     	arm_fft_bin_data.c
*
* Description:	 Data file used for example code
*
* Target Processor: Cortex-M4/Cortex-M3/Cortex-M0
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions
* are met:
*   - Redistributions of source code must retain the above copyright
*     notice, this list of conditions and the following disclaimer.
*   - Redistributions in binary form must reproduce the above copyright
*     notice, this list of conditions and the following disclaimer in
*     the documentation and/or other materials provided with the
*     distribution.
*   - Neither the name of ARM LIMITED nor the names of its contributors
*     may be used to endorse or promote products derived from this
*     software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
* "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
* LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
* FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
* COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
* INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
* BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
* CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
* LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
* ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
* POSSIBILITY OF SUCH DAMAGE.
 * -------------------------------------------------------------------- */

#include "arm_math.h"

/*
 * Test Input signal contains 10KHz signal + Uniformly distributed white noise
 */
float32_t testInput_f32_1khz[128] = {
	0.00000000e+00,  1.96606441e+00,  3.85538344e+00,  5.59420747e+00,
	7.11466148e+00,  8.35739449e+00,  9.27389639e+00,  9.82839151e+00,
	9.99923511e+00,  9.77975832e+00,  9.17852840e+00,  8.21901439e+00,
	6.93867094e+00,  5.38747630e+00,  3.62598137e+00,  1.72294617e+00,
   -2.47344273e-01, -2.20797963e+00, -4.08242645e+00, -5.79751564e+00,
   -7.28629866e+00, -8.49066083e+00, -9.36358983e+00, -9.87101086e+00,
   -9.99311673e+00, -9.72514103e+00, -9.07754419e+00, -8.07560519e+00,
   -6.75843473e+00, -5.17744860e+00, -3.39436063e+00, -1.47877370e+00,
	4.94537199e-01,  2.44854382e+00,  4.30697148e+00,  5.99727639e+00,
	7.45347746e+00,  8.61873185e+00,  9.44755382e+00,  9.90759028e+00,
	9.98088370e+00,  9.66457306e+00,  8.97100557e+00,  7.92725465e+00,
	6.57406313e+00,  4.96425290e+00,  3.16066292e+00,  1.23369638e+00,
   -7.41427526e-01, -2.68760979e+00, -4.52888114e+00, -6.19336749e+00,
   -7.61609559e+00, -8.74152919e+00, -9.52573698e+00, -9.93810738e+00,
   -9.96254351e+00, -9.59809149e+00, -8.85897772e+00, -7.77405353e+00,
   -6.38566896e+00, -4.74801964e+00, -2.92503125e+00, -9.87864183e-01,
	9.87864183e-01,  2.92503125e+00,  4.74801964e+00,  6.38566896e+00,
	7.77405353e+00,  8.85897772e+00,  9.59809149e+00,  9.96254351e+00,
	9.93810738e+00,  9.52573698e+00,  8.74152919e+00,  7.61609559e+00,
	6.19336749e+00,  4.52888114e+00,  2.68760979e+00,  7.41427526e-01,
   -1.23369638e+00, -3.16066292e+00, -4.96425290e+00, -6.57406313e+00,
   -7.92725465e+00, -8.97100557e+00, -9.66457306e+00, -9.98088370e+00,
   -9.90759028e+00, -9.44755382e+00, -8.61873185e+00, -7.45347746e+00,
   -5.99727639e+00, -4.30697148e+00, -2.44854382e+00, -4.94537199e-01,
	1.47877370e+00,  3.39436063e+00,  5.17744860e+00,  6.75843473e+00,
	8.07560519e+00,  9.07754419e+00,  9.72514103e+00,  9.99311673e+00,
	9.87101086e+00,  9.36358983e+00,  8.49066083e+00,  7.28629866e+00,
	5.79751564e+00,  4.08242645e+00,  2.20797963e+00,  2.47344273e-01,
   -1.72294617e+00, -3.62598137e+00, -5.38747630e+00, -6.93867094e+00,
   -8.21901439e+00, -9.17852840e+00, -9.77975832e+00, -9.99923511e+00,
   -9.82839151e+00, -9.27389639e+00, -8.35739449e+00, -7.11466148e+00,
   -5.59420747e+00, -3.85538344e+00, -1.96606441e+00, -9.79717439e-15
};
