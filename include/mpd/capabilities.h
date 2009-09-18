/* libmpdclient
   (c) 2003-2009 The Music Player Daemon Project
   This project's homepage is: http://www.musicpd.org

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions
   are met:

   - Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

   - Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
   ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
   A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR
   CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
   EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
   PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
   PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
   LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
   NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
   SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef MPD_CAPABILITIES_H
#define MPD_CAPABILITIES_H

#include <stdbool.h>

struct mpd_connection;

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Requests a list of supported and allowed.  Use
 * mpd_recv_pair_named() to obtain the list of "command" pairs.
 *
 * @param connection the connection to MPD
 * @return true on success, false on error
 */
bool
mpd_send_commands(struct mpd_connection *connection);

/**
 * Requests a list of supported commands which are not allowed for
 * this connection.  Use mpd_recv_pair_named() to obtain the list of
 * "command" pairs.
 *
 * @param connection the connection to MPD
 * @return true on success, false on error
 */
bool
mpd_send_notcommands(struct mpd_connection *connection);

/**
 * Requests a list of supported URL handlers in the form "scheme://",
 * example: "http://".  Use mpd_recv_pair_named() to obtain the list
 * of "handler" pairs.
 *
 * @param connection the connection to MPD
 * @return true on success, false on error
 */
bool
mpd_send_urlhandlers(struct mpd_connection *connection);

/**
 * Requests a list of supported tag types.  Use mpd_recv_pair_named()
 * to obtain the list of "tagtype" pairs.
 *
 * @param connection the connection to MPD
 * @return true on success, false on error
 */
bool
mpd_send_tagtypes(struct mpd_connection *connection);

#ifdef __cplusplus
}
#endif

#endif
