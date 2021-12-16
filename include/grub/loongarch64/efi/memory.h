/*
 *  GRUB  --  GRand Unified Bootloader
 *  Copyright (C) 2021  Loongson Technology Corporation Limited
 *
 *  GRUB is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  GRUB is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with GRUB.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef GRUB_MEMORY_CPU_HEADER
#include <grub/efi/memory.h>

static inline grub_uint64_t
grub_efi_max_usable_address(void)
{
  grub_uint64_t addr;
  asm volatile ("csrrd %0, 0x181" : "=r" (addr));
  return addr |= 0xffffffffffUL;
}

#define GRUB_EFI_MAX_USABLE_ADDRESS grub_efi_max_usable_address()

#endif