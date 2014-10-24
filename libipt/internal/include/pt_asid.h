/*
 * Copyright (c) 2014, Intel Corporation
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *  * Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *  * Neither the name of Intel Corporation nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef __PT_ASID_H__
#define __PT_ASID_H__

struct pt_asid;


/* Read an asid provided by our user.
 *
 * Translate a user-provided asid in @user into @asid.  This uses default values
 * for fields that are not provided by the user and for all fields, if @user is
 * NULL.
 *
 * Fields set in @user that are not known (i.e. from a newer version of this
 * library) will be ignored.
 *
 * Returns zero on success, a negative error code otherwise.
 * Returns -pte_internal, if @asid is NULL.
 */
extern int pt_asid_from_user(struct pt_asid *asid, const struct pt_asid *user);

/* Match two asids.
 *
 * Asids match if all fields provide either default values or are identical.
 *
 * Returns a positive number if @lhs matches @rhs.
 * Returns zero if @lhs does not match @rhs.
 * Returns a negative error code otherwise.
 *
 * Returns -pte_internal if @lhs or @rhs are NULL.
 */
extern int pt_asid_match(const struct pt_asid *lhs, const struct pt_asid *rhs);

#endif /* __PT_ASID_H__ */