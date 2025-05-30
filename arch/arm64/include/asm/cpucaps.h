/* SPDX-License-Identifier: GPL-2.0-only */

#ifndef __ASM_CPUCAPS_H
#define __ASM_CPUCAPS_H

#include <asm/cpucap-defs.h>

#ifndef __ASSEMBLY__
#include <linux/types.h>
/*
 * Check whether a cpucap is possible at compiletime.
 */
static __always_inline bool
cpucap_is_possible(const unsigned int cap)
{
	compiletime_assert(__builtin_constant_p(cap),
			   "cap must be a constant");
	compiletime_assert(cap < ARM64_NCAPS,
			   "cap must be < ARM64_NCAPS");

	switch (cap) {
	case ARM64_HAS_PAN:
		return IS_ENABLED(CONFIG_ARM64_PAN);
	case ARM64_HAS_EPAN:
		return IS_ENABLED(CONFIG_ARM64_EPAN);
	case ARM64_SVE:
		return IS_ENABLED(CONFIG_ARM64_SVE);
	case ARM64_SME:
	case ARM64_SME2:
	case ARM64_SME_FA64:
		return IS_ENABLED(CONFIG_ARM64_SME);
	case ARM64_HAS_CNP:
		return IS_ENABLED(CONFIG_ARM64_CNP);
	case ARM64_HAS_ADDRESS_AUTH:
	case ARM64_HAS_GENERIC_AUTH:
		return IS_ENABLED(CONFIG_ARM64_PTR_AUTH);
	case ARM64_HAS_GIC_PRIO_MASKING:
		return IS_ENABLED(CONFIG_ARM64_PSEUDO_NMI);
	case ARM64_MTE:
		return IS_ENABLED(CONFIG_ARM64_MTE);
	case ARM64_BTI:
		return IS_ENABLED(CONFIG_ARM64_BTI);
	case ARM64_HAS_TLB_RANGE:
		return IS_ENABLED(CONFIG_ARM64_TLB_RANGE);
	case ARM64_HAS_S1POE:
		return IS_ENABLED(CONFIG_ARM64_POE);
	case ARM64_HAS_GCS:
		return IS_ENABLED(CONFIG_ARM64_GCS);
	case ARM64_HAFT:
		return IS_ENABLED(CONFIG_ARM64_HAFT);
	case ARM64_UNMAP_KERNEL_AT_EL0:
		return IS_ENABLED(CONFIG_UNMAP_KERNEL_AT_EL0);
	case ARM64_WORKAROUND_843419:
		return IS_ENABLED(CONFIG_ARM64_ERRATUM_843419);
	case ARM64_WORKAROUND_1742098:
		return IS_ENABLED(CONFIG_ARM64_ERRATUM_1742098);
	case ARM64_WORKAROUND_2645198:
		return IS_ENABLED(CONFIG_ARM64_ERRATUM_2645198);
	case ARM64_WORKAROUND_2658417:
		return IS_ENABLED(CONFIG_ARM64_ERRATUM_2658417);
	case ARM64_WORKAROUND_CAVIUM_23154:
		return IS_ENABLED(CONFIG_CAVIUM_ERRATUM_23154);
	case ARM64_WORKAROUND_NVIDIA_CARMEL_CNP:
		return IS_ENABLED(CONFIG_NVIDIA_CARMEL_CNP_ERRATUM);
	case ARM64_WORKAROUND_REPEAT_TLBI:
		return IS_ENABLED(CONFIG_ARM64_WORKAROUND_REPEAT_TLBI);
	case ARM64_WORKAROUND_SPECULATIVE_SSBS:
		return IS_ENABLED(CONFIG_ARM64_ERRATUM_3194386);
	case ARM64_MPAM:
		/*
		 * KVM MPAM support doesn't rely on the host kernel supporting MPAM.
		*/
		return true;
	case ARM64_HAS_PMUV3:
		return IS_ENABLED(CONFIG_HW_PERF_EVENTS);
	}

	return true;
}
#endif /* __ASSEMBLY__ */

#endif /* __ASM_CPUCAPS_H */
