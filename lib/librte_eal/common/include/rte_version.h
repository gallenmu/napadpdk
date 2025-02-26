/* SPDX-License-Identifier: BSD-3-Clause
 * Copyright(c) 2010-2014 Intel Corporation
 */

/**
 * @file
 * Definitions of DPDK version numbers
 */

#ifndef _RTE_VERSION_H_
#define _RTE_VERSION_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <rte_common.h>

/**
 * String that appears before the version number
 */
#define RTE_VER_PREFIX "DPDK"

/**
 * Major version/year number i.e. the yy in yy.mm.z
 */
#define RTE_VER_YEAR 19

/**
 * Minor version/month number i.e. the mm in yy.mm.z
 */
#define RTE_VER_MONTH 2

/**
 * Patch level number i.e. the z in yy.mm.z
 */
#define RTE_VER_MINOR 0

/**
 * Extra string to be appended to version number
 */
#define RTE_VER_SUFFIX ""

/**
 * Patch release number
 *   0-15 = release candidates
 *   16   = release
 */
#define RTE_VER_RELEASE 16

/**
* Extra Napatech major version numbers
*/
#define RTE_NT_MAJOR_VER 2

/**
* Extra Napatech minor version numbers
*/
#define RTE_NT_MINOR_VER 4

/**
* Extra Napatech string to be appended to version number
*/
#define RTE_NT_VER_SUFFIX ""

/**
 * Macro to compute a version number usable for comparisons
 */
#define RTE_VERSION_NUM(a,b,c,d) ((a) << 24 | (b) << 16 | (c) << 8 | (d))

/**
 * All version numbers in one to compare with RTE_VERSION_NUM()
 */
#define RTE_VERSION RTE_VERSION_NUM( \
			RTE_VER_YEAR, \
			RTE_VER_MONTH, \
			RTE_VER_MINOR, \
			RTE_VER_RELEASE)

/**
 * Function returning version string
 * @return
 *     string
 */
static inline const char *
rte_version(void)
{
	static char version[32];
	if (version[0] != 0)
		return version;
	if (strlen(RTE_VER_SUFFIX) == 0)
		snprintf(version, sizeof(version), "%s %d.%02d.%d",
			RTE_VER_PREFIX,
			RTE_VER_YEAR,
			RTE_VER_MONTH,
			RTE_VER_MINOR);
	else
		snprintf(version, sizeof(version), "%s %d.%02d.%d%s%d",
			RTE_VER_PREFIX,
			RTE_VER_YEAR,
			RTE_VER_MONTH,
			RTE_VER_MINOR,
			RTE_VER_SUFFIX,
			RTE_VER_RELEASE < 16 ?
				RTE_VER_RELEASE :
				RTE_VER_RELEASE - 16);

	if (strlen(RTE_NT_VER_SUFFIX) == 0) {
		snprintf(&version[strlen(version)], sizeof(version), "_%d.%d", RTE_NT_MAJOR_VER, RTE_NT_MINOR_VER);
	}
	else {
		snprintf(&version[strlen(version)], sizeof(version), "_%d.%d-%s", RTE_NT_MAJOR_VER, RTE_NT_MINOR_VER, RTE_NT_VER_SUFFIX);
	}

	return version;
}

#ifdef __cplusplus
}
#endif

#endif /* RTE_VERSION_H */
