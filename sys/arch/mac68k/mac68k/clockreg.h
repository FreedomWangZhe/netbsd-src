/*	$NetBSD: clockreg.h,v 1.9 2006/11/20 20:48:36 hauke Exp $	*/

/*-
 * Copyright (C) 1993	Allen K. Briggs, Chris P. Caputo,
 *			Michael L. Finch, Bradley A. Grantham, and
 *			Lawrence A. Kesteloot
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *	This product includes software developed by the Alice Group.
 * 4. The names of the Alice Group or any of its members may not be used
 *    to endorse or promote products derived from this software without
 *    specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE ALICE GROUP ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE ALICE GROUP BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

/*
 * The Macintosh 6522 VIAs are provided with a 783360 Hz E clock that
 * used to be 1/10 of the 68000 clock. On the Macintosh II family and
 * later models, the E clock is not provided by the 68020+ cpu, but
 * generated by the board chipset, in sync with CPU access.
 * (Guide to the Macintosh Family Hardware, 2nd Ed., p.149)
 */
#define CLK_FREQ	783360		/* VIA clock frequency (Hz) */

/* Clock needed to hit HZ ticks/sec. */
#define CLK_INTERVAL	((unsigned int)(CLK_FREQ / hz))

#define CLK_INTH	((CLK_INTERVAL >> 8) & 0xff)	/* high byte */
#define CLK_INTL	(CLK_INTERVAL & 0xff)		/* low byte */

#if !defined(PRF_INTERVAL)
#define PRF_INTERVAL CLK_INTERVAL
#endif
