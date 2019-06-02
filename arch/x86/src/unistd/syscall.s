#
#  Copyright (C) 2019 James Larrowe
#
#  This file is part of Minilibc.
#
#  Minilibc is free software: you can redistribute it and/or modify
#  it under the terms of the GNU Lesser General Public License as published by
#  the Free Software Foundation, either version 3 of the License, or
#  (at your option) any later version.
#
#  Minilibc is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU Lesser General Public License for more details.
#
#  You should have received a copy of the GNU Lesser General Public License
#  along with Minilibc.  If not, see <https://www.gnu.org/licenses/>.
#

.text
.globl __syscall
__syscall:
	push %ebp
	push %edi
	push %esi
	push %ebx
	mov 44(%esp), %ebp
	mov 40(%esp), %edi
	mov 36(%esp), %esi
	mov 32(%esp), %edx
	mov 28(%esp), %ecx
	mov 24(%esp), %ebx
	mov 20(%esp), %eax
	int $0x80
	pop %ebx
	pop %esi
	pop %edi
	pop %ebp
	ret