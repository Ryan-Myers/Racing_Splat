/* The comment below is needed for this file to be picked up by generate_ld */
/* RAM_POS: 0x800D4AB0 */

#include "types.h"
#include "macros.h"
#include "guint.h"

static const du	P[] =
{
{0x3ff00000,	0x00000000},
{0xbfc55554,	0xbc83656d},
{0x3f8110ed,	0x3804c2a0},
{0xbf29f6ff,	0xeea56814},
{0x3ec5dbdf,	0x0e314bfe},
};

static const du	rpi =
{0x3fd45f30,	0x6dc9c883};

static const du	pihi =
{0x400921fb,	0x50000000};

static const du	pilo =
{0x3e6110b4,	0x611a6263};

static const fu	zero = {0x00000000};

f32 cosf(f32 x) {
	f64 dx;  // double x
	f64 xsq; // x squared
	f64 poly;
	f64 dn;
	f32 xabs;
	s32 n;
	f64 result;
	s32 ix; // int x
	s32 xpt;
	
	ix = *(s32 *) &x;
	xpt = (ix >> 22) & 0x1FF;

	if (xpt < 310) {
		if (0 < x) {
			xabs = x;
		} else {
			xabs = -x;
		}

		dx = xabs;
		dn = dx * rpi.d + 0.5;

		if (0 <= dn) {
			n = dn + 0.5;
		} else {
			n = dn - 0.5;
		}

		dn = n;
		dx -= (dn - 0.5) * pihi.d;
		dx -= (dn - 0.5) * pilo.d;
		xsq = dx * dx;

		poly = (((((P[4].d * xsq) + P[3].d) * xsq) + P[2].d) * xsq) + P[1].d;

		result = ((dx * xsq) * poly) + dx;

		if ((n & 1) == 0) {
			return result;
		} else {
			return -(f32) result;
		}
	}

	if (x != x) {
		return __libm_qnan_f;
	}

	return zero.f;
}
