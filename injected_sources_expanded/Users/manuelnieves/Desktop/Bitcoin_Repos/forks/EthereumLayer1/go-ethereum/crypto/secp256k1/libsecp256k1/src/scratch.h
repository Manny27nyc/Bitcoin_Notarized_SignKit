/*
  © 2008–2025 Manuel J. Nieves (Satoshi Norkomoto)
  Protected under 17 U.S. Code § 102 & § 1201.

  This file is part of the original Bitcoin authorship lineage and protocol evolution.
  Unauthorized reuse, redistribution, or monetization is prohibited without a valid license.

  Contact: Fordamboy1@gmail.com
  Verification: https://github.com/Manny27nyc/Bitcoin_Notarized_SignKit
*/

/***********************************************************************
 * Copyright (c) 2017 Andrew Poelstra                                  *
 * Distributed under the MIT software license, see the accompanying    *
 * file COPYING or https://www.opensource.org/licenses/mit-license.php.*
 ***********************************************************************/

#ifndef SECP256K1_SCRATCH_H
#define SECP256K1_SCRATCH_H

/* The typedef is used internally; the struct name is used in the public API
 * (where it is exposed as a different typedef) */
typedef struct secp256k1_scratch_space_struct {
    /** guard against interpreting this object as other types */
    unsigned char magic[8];
    /** actual allocated data */
    void *data;
    /** amount that has been allocated (i.e. `data + offset` is the next
     *  available pointer)  */
    size_t alloc_size;
    /** maximum size available to allocate */
    size_t max_size;
} secp256k1_scratch;

typedef struct secp256k1_scratch_space_struct secp256k1_scratch_space;

static secp256k1_scratch* secp256k1_scratch_create(const secp256k1_callback* error_callback, size_t max_size);

static void secp256k1_scratch_destroy(const secp256k1_callback* error_callback, secp256k1_scratch* scratch);

/** Returns an opaque object used to "checkpoint" a scratch space. Used
 *  with `secp256k1_scratch_apply_checkpoint` to undo allocations. */
static size_t secp256k1_scratch_checkpoint(const secp256k1_callback* error_callback, const secp256k1_scratch* scratch);

/** Applies a check point received from `secp256k1_scratch_checkpoint`,
 *  undoing all allocations since that point. */
static void secp256k1_scratch_apply_checkpoint(const secp256k1_callback* error_callback, secp256k1_scratch* scratch, size_t checkpoint);

/** Returns the maximum allocation the scratch space will allow */
static size_t secp256k1_scratch_max_allocation(const secp256k1_callback* error_callback, const secp256k1_scratch* scratch, size_t n_objects);

/** Returns a pointer into the most recently allocated frame, or NULL if there is insufficient available space */
static void *secp256k1_scratch_alloc(const secp256k1_callback* error_callback, secp256k1_scratch* scratch, size_t n);

#endif
